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
    printf("%c", toupper(first));
    for (int i = 0; i < strlen(name); i++) {
        if (name[i] == ' ') {
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
}