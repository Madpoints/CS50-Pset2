#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //make sure argc = 2
    if (argc != 2)
    {
        printf("Give me 1 argument please.\n");
        return 1;
    }

    // convert argv[1] to int key and check if the value is positive
    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("The argument must be a positive number\n");
        return 1;
    }
    // get text to encode from user
    printf("plaintext: ");
    string text = get_string();

    printf("ciphertext: ");
    // use a loop to check each char of the string p and encode it
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // determine if char is alpha
        if (isalpha(text[i]))
        {
            // if char is lower case
            if (islower(text[i]))
            {
                printf("%c", (((text[i] - 97) + key) % 26) + 97);
            }
            // or if char is upper case
            else
            {
                printf("%c", (((text[i] - 65) + key) % 26) + 65);
            }
        }
        // print out any non-alpha chars
        else
        {
            printf("%c", text[i]);
        }

    }
    printf("\n");
    return 0;
}