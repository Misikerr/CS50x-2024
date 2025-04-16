#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt the user for a height between 1 and 8 (inclusive)
    do
    {
        height = get_int("Enter height here: ");
    }
    while (height < 1 || height > 8);

    // Loop through each row
    for (int row = 0; row < height; row++)
    {
        // Print spaces to align the pyramid to the right
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        // Print left-aligned hashes
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }

        // Print the fixed extra hash to form the right side of the pyramid
        printf("#");

        // Move to the next line after each row
        printf("\n");
    }
}
