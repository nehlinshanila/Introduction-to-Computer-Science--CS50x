#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            float average = (image[i][j].rgbtBlue + image[i][j].rgbtRed +image[i][j].rgbtGreen)/3.0;
            int avg = round(average);
            
            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = avg;

        }
    }
    
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
          int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
          int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
          int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
         
         image[i][j].rgbtBlue = sepiaBlue;
         image[i][j].rgbtRed = sepiaRed;
         image[i][j].rgbtGreen = sepiaGreen;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i=0; i<height; i++)
    {
        for(int j=0; j<(width/2); j++)
        {
            int red =image[i][j].rgbtRed;
            int blue =image[i][j].rgbtBlue;
            int green =image[i][j].rgbtGreen;
            
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            
            image[i][width - j - 1].rgbtRed = red;
            image[i][width - j - 1].rgbtGreen = green;
            image[i][width - j - 1].rgbtBlue = blue;
            
        }
    }
            
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
             int avgBlue = 0;
             int avgRed = 0;
             int avgGreen = 0;
             float counter = 0.0;
             
             for(int k = -1; k < 2; k++)
             {
                 for (int h = -1; h < 2; h++)
                 {
                     if(i + k < 0 || i + k > height - 1 || j + h > width - 1)
                     {
                         continue;
                     }
                     avgBlue += image[i+k][j+h].rgbtBlue;
                     avgRed += image[i+k][j+h].rgbtRed;
                     avgGreen += image[i+k][j+h].rgbtGreen;
                     
                     counter++;
                 }
             }
             
             temp[i][j].rgbtBlue = round(avgBlue/counter);
             temp[i][j].rgbtRed = round(avgRed/counter);
             temp[i][j].rgbtGreen = round(avgGreen/counter);
        }
    }
     
     for(int i = 0; i < height; i++)
     {
         for(int j = 0; j < width; j++)
         {
             image[i][j].rgbtRed = temp[i][j].rgbtRed;
             image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
             image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
         }
     }
    return;
}
