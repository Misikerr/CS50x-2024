
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]);


    string plaintext = get_string ("Plaintext: ");

    printf("Cipertext: ");

    for (int j = 0; j < strlen(plaintext); j++)
    {
        if(isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 'A' + k) % 26 + 'A');
        }
         if(islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 'a' + k) % 26 + 'a');
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}
