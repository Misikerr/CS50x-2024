#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the average of the RGB values
            int average_rgb = round((image[i][j].rgbtRed +
                                     image[i][j].rgbtGreen +
                                     image[i][j].rgbtBlue) / 3.0);

            // Set all color components to the average (grayscale)
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average_rgb;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue;

    // Loop through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Apply the sepia formula to calculate new values
            sepiaRed   = round(0.393 * image[i][j].rgbtRed +
                               0.769 * image[i][j].rgbtGreen +
                               0.189 * image[i][j].rgbtBlue);
            sepiaGreen = round(0.349 * image[i][j].rgbtRed +
                               0.686 * image[i][j].rgbtGreen +
                               0.168 * image[i][j].rgbtBlue);
            sepiaBlue  = round(0.272 * image[i][j].rgbtRed +
                               0.534 * image[i][j].rgbtGreen +
                               0.131 * image[i][j].rgbtBlue);

            // Cap each value at 255 if it exceeds that (valid RGB range)
            if (sepiaRed > 255) sepiaRed = 255;
            if (sepiaGreen > 255) sepiaGreen = 255;
            if (sepiaBlue > 255) sepiaBlue = 255;

            // Assign the sepia-toned values back to the pixel
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;

    // Loop through each row
    for (int i = 0; i < height; i++)
    {
        // Swap pixels from left to right for horizontal reflection
        for (int j = 0; j < width / 2; j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the original image to prevent overwriting during blur
    RGBTRIPLE image_replica[height][width];

    // Loop through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum_red = 0, sum_green = 0, sum_blue = 0;
            float total_pixels = 0;

            // Check the surrounding pixels in a 3x3 grid
            for (int updated_i = i - 1; updated_i <= i + 1; updated_i++)
            {
                for (int updated_j = j - 1; updated_j <= j + 1; updated_j++)
                {
                    // Skip pixels that are out of bounds
                    if (updated_i >= 0 && updated_j >= 0 && updated_i < height && updated_j < width)
                    {
                        sum_red += image[updated_i][updated_j].rgbtRed;
                        sum_green += image[updated_i][updated_j].rgbtGreen;
                        sum_blue += image[updated_i][updated_j].rgbtBlue;
                        total_pixels++;
                    }
                }
            }

            // Set the pixel to the average of the surrounding colors
            image_replica[i][j].rgbtRed = round(sum_red / total_pixels);
            image_replica[i][j].rgbtGreen = round(sum_green / total_pixels);
            image_replica[i][j].rgbtBlue = round(sum_blue / total_pixels);
        }
    }

    // Copy blurred image back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image_replica[i][j];
        }
    }
    return;
}
