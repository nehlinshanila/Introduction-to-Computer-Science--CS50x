#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string s = get_string("Text: ");



    int letter = 0;
    int words = 0;
    int sentence = 0;
    int len = strlen(s);


    for ( int i = 0; i < len; i++)

  {
   if (isalpha(s[i]))

   {
       letter++;
   }

   if ((i == 0 && s[i] != ' ') || (i != len - 1 && s[i] == ' ' && s[i + 1] != ' '))
   {
       words++;
   }

   if (s[i] == '!' || s[i] == '?' || s[i] == '.')
   {
       sentence++;
   }
  }

     float L = (100 * (letter / (float) words));
     float S = (100 * (sentence / (float) words));
     int index = round(0.0588 * L - 0.296 * S - 15.8);
     
    if (index < 1)
    {
        printf("Before grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16 +\n");
    }
    else 
    {
        printf("Grade %i\n", index);
    }
 
}