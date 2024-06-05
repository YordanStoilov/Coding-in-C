# This is a program from my CS50 course, that reads a binary file by name passed in the terminal and finds JPEG images if there are any

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

bool check_for_jpeg_header(unsigned char buffer[]);

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");

    if (argc != 2 || f == NULL)
    {
        printf("Invalid input!\n");
        return 1;
    }

    unsigned char buffer[512];
    int number_of_jpegs = 0;
    char current_name[8];
    FILE *img;

    while (true)
    {
        // Reading first 512 bytes of raw file if there are 512 bytes available:
        if (fread(buffer, 512, 1, f) == 1)
        {

            // If there is a JPEG header present
            if (check_for_jpeg_header(buffer))
            {
                // If it's not the first file, close the previous first
                if (number_of_jpegs > 0)
                {
                    fclose(img);
                }
                // Make new name in the required format
                sprintf(current_name, "%03i.jpg", number_of_jpegs);

                // Increment number to keep up with the format
                number_of_jpegs++;

                // Open the new image file
                img = fopen(current_name, "w");
            }

            if (number_of_jpegs > 0)
            {
                // Write 512 bytes from buffer to image file
                fwrite(buffer, 512, 1, img);
            }

            else
            {
                continue;
            }
        }
        else
        {
            if (number_of_jpegs > 0)
            {
                fclose(img);
            }
            fclose(f);
            break;
        }
    }
}

bool check_for_jpeg_header(unsigned char buffer[])
{
    if (buffer[0] != 0xff)
    {
        return false;
    }
    else if (buffer[1] != 0xd8)
    {
        return false;
    }
    else if (buffer[2] != 0xff)
    {
        return false;
    }
    else if ((buffer[3] & 0xf0) != 0xe0)
    {
        return false;
    }
    return true;
}
