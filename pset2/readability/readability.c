#include <stdio.h>
#include <cs50.h>
#include <string.h> // to use strlen() function
#include <math.h> // to use round() function

int main(void)
{
    string text = get_string("Text: \n");

    int letterCount = 0; //to count letters
    int wordCount = 1; //to count words
    int sentenseCount = 0; //to count sentenses

    for (int i = 0; i < strlen(text); i++)
    {
        //Alphabet as an array and counting between the letters
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letterCount++;
        }
        else if (text[i]  == ' ') //Space between words for wordCound, there is no space at the beginnig so wordCount = 1 not 0
        {
            wordCount++;
        }
        //For counting sentenses (you should consider any sequence of characters that ends with a . or a ! or a ? to be a sentence)
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentenseCount++;
        }

    }
    //to check that my code is correct
    //printf("Letter(s) %i word(s) %i Sentense(s) %i", letterCount, wordCount, sentenseCount);
    //index = 0.0588 * L - 0.296 * S - 15.8

    float index = 0.0588 * ((100 * (float)letterCount / (float)wordCount)) -
                  (0.296 * (100 * (float)sentenseCount / (float)wordCount)) - 15.8;

    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int)round(index)); //checking main condition
    }
    else if (index > 16) //checking if more than 16
    {
        printf("Grade 16+\n");
    }
    else //anything below 1
    {
        printf("Before Grade 1\n");
    }

}