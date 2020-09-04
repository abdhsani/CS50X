#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// formula Ci = (((Pi + 'a') + key) - 'a') % 26 same for capitals 'A'

int main(int argc, string argv[]) //No main for this task to pass values
{
    if (argc == 2 && isdigit(*argv[1])) //argc has to be 2 strings, argv second value has to be a digit
    {

        // for error "handles non-numeric key"
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            int x = argv[1][i];
            // Returns error message if key includes anything other than digits
            if (x == 0 || !isdigit(x))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        string plainText = get_string("plaintext: "); //asking a user for a plaintext
        printf("ciphertext: "); // printing ciphertext
        int key = atoi(argv[1]); //atoi to change string value in argv to an integer


        for (int i = 0, b = strlen(plainText); i < b; i++) //checking every letter
        {
            if (plainText[i] >= 'a' && plainText[i] <= 'z') //checking lowercase
            {
                printf("%c", (((plainText[i] - 'a') + key) % 26) + 'a'); // printing lowercase
            }
            else if (plainText[i] >= 'A' && plainText[i] <= 'Z') // checking uppercase
            {
                printf("%c", (((plainText[i] - 'A') + key) % 26) + 'A'); // printing uppercase
            }
            else
            {
                printf("%c", plainText[i]); // any punctuations
            }

        }
        printf("\n");
        return 0;
    }

    else
    {
        printf("Usage: ./caesar key\n"); //if conditions are wrong
        return 1;
    }
}