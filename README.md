# gtk-password-strength-tool
Simple GTK-based password strength checker written in C that evaluates passwords based on length and character complexity.

Password Strength Checker (C + GTK)
Overview

This project is a simple desktop application written in C using the GTK library. It provides a graphical interface where users can enter a password and check its strength based on basic security rules.

The goal of this project is to demonstrate GUI programming in C and implement fundamental password validation techniques.

Features

Simple and user-friendly GTK interface

Checks password length (8 to 16 characters)

Evaluates password based on:

Uppercase letters

Lowercase letters

Numbers

Special characters

Displays strength as:

Weak

Medium

Strong

How It Works

The program analyzes the password entered by the user and assigns a score based on character diversity:

+1 if it contains uppercase letters

+1 if it contains lowercase letters

+1 if it contains digits

+1 if it contains special characters

Strength Levels

Strong → All 4 conditions met

Medium → Any 3 conditions met

Weak → Less than 3 conditions

If the password length is outside 8–16 characters, the program shows an error message.

Technologies Used

C Programming Language

GTK (GIMP Toolkit) for GUI

Standard Libraries:

string.h

ctype.h

Installation
Install GTK (Linux)

On Ubuntu/Debian:

sudo apt update
sudo apt install libgtk-3-dev
Compilation
gcc password_checker.c -o password_checker `pkg-config --cflags --libs gtk+-3.0`
Run
./password_checker
Project Structure
password_checker.c
README.md
Possible Improvements

Real-time password checking

Password visibility toggle

Strength meter (progress bar)

Better UI design

License

This project is open-source and free to use for educational purposes.

Author

Sandesh Pantha
