#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// prototype converts chars in aint alphaPos(char letter);
string caesar(string text, string key);


int main(int argc, string argv[])
{
    // assing argv[1] to a string
    string key = argv[1];

    // 't' used to store strlen of text
    int t;


    // check number of arguments
    if (argc != 2)
    {
        printf("Give me 1 argument please.\n");
        return 1;
    }
    // check if key is only alphabetic characters and convert to alpha values
    for (int i = 0, keyLength = strlen(key); i < keyLength; i++ )
    {
        if ( isdigit(key[i]) )
        {
            printf("Only alphabetic characters please.\n");
            return 1;
            printf("\n");
        }
    }




    // get text to encode from user
    printf("plaintext: ");
    string text = get_string();
    // determine and store length of text
    t = strlen(text);
    // implement caesar function and print its output for the duration of the texts length
    string encoded = caesar(text, key);
    printf("ciphertext: ");
    for (int i = 0; i < t; i++)
    {
        printf("%c", encoded[i]);
    }
    printf("\n");

}

string caesar(string text, string key)
{

    // alpha numeric value of the key upper and lower case
    int normalkey;
    int keyLength = strlen(key);
    int textLength = strlen(text);
    string cipher = text;

    for (int i = 0, j = 0; i < textLength; i++)
    {
        int keyIndex = j % keyLength;

        if (islower(key[keyIndex]))
        {
            normalkey = (key[keyIndex] - 97);
        }
        else
        {
            normalkey = (key[keyIndex] - 65);
        }

        // skip over spaces
        if (text[i] == ' ')
        {
            cipher[i] = text[i];
        }
        else if (isalpha(text[i]))
        {
            // if char is lower case
            if (islower(text[i]))
            {
                cipher[i] = (((text[i] - 97) + normalkey)  % 26)  + 97;
            }
            else
            {
                cipher[i] = (((text[i] - 65) + normalkey) % 26) + 65;
            }
            // increment j if text isalpha
            j++;
            cipher[i] = text[i];
        }
    }
    return cipher;

}


