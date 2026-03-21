#include <gtk/gtk.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

// Functions to check password strength
void check_password_strength(char* password, GtkWidget* result_label) {
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int score = 0;

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        gtk_label_set_text(GTK_LABEL(result_label), "Password must be between 8 and 16 characters.");
        return;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else if (ispunct(password[i])) hasSpecial = 1;
    }

    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    if (score == 4) {
        gtk_label_set_text(GTK_LABEL(result_label), "Password is Strong");
    } else if (score == 3) {
        gtk_label_set_text(GTK_LABEL(result_label), "Password is Medium");
    } else {
        gtk_label_set_text(GTK_LABEL(result_label), "Password is Weak");
    }
}

// Callback for the "Check" button
void on_check_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget* entry = GTK_WIDGET(data);
    const char* password = gtk_entry_get_text(GTK_ENTRY(entry));
    GtkWidget* result_label = g_object_get_data(G_OBJECT(widget), "result_label");
    check_password_strength((char*)password, result_label);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Password Strength Checker");

    // Create a grid
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create a password entry field
    GtkWidget *password_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), password_entry, 0, 0, 2, 1);

    // Create a button to check the password
    GtkWidget *check_button = gtk_button_new_with_label("Check Strength");
    gtk_grid_attach(GTK_GRID(grid), check_button, 0, 1, 2, 1);

    // Create a label to show the result
    GtkWidget *result_label = gtk_label_new("Password strength will be shown here");
    gtk_grid_attach(GTK_GRID(grid), result_label, 0, 2, 2, 1);

    // Set callback for button
    g_object_set_data(G_OBJECT(check_button), "result_label", result_label);
    g_signal_connect(check_button, "clicked", G_CALLBACK(on_check_button_clicked), password_entry);

    // Configure window properties
    gtk_widget_show_all(window);

    // Start GTK main loop
    gtk_main();

    return 0;
}
