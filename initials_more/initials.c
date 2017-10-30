#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    string name;
    // get users first and last name
    name = get_string();
    // create a variable for the first char of string name
    char first = name[0];
    // if char is not a space print it out
    if (first != ' ') {
        printf("%c", toupper(first));
    }
    // loop through the string and print out the chars that are not spaces
    // and are preceded by a space
    for (int i = 0; i < strlen(name); i++) {
        if (name[i] != ' ' && name[i-1] == ' ') {
            printf("%c", toupper(name[i]));
        }
    }
    printf("\n");
}