#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check if there is exactly one argument (the key)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the key is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert the key from a string to an integer
    int k = atoi(argv[1]);

    // Normalize the key to ensure it's within 0-25
    k = k % 26;

    // Get plaintext from user
    string plaintext = get_string("Plaintext: ");

    // Print the ciphertext label
    printf("Ciphertext: ");

    // Iterate over each character in the plaintext
    for (int j = 0; j < strlen(plaintext); j++)
    {
        // Check if the character is an uppercase letter
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 'A' + k) % 26 + 'A');
        }
        // Check if the character is a lowercase letter
        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 'a' + k) % 26 + 'a');
        }
        // If it's not a letter, print the character as it is
        else
        {
            printf("%c", plaintext[j]);
        }
    }

    // Print a newline at the end
    printf("\n");
    return 0;
}
