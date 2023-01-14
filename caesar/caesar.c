#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])

   {if (argc == 2 && isdigit(*argv[1]))
    
        {

         string plaintext = get_string("plaintext: ");
         printf("ciphertext: ");
        
         int key = atoi(argv[1]);
         for (int i = 0; i < strlen(plaintext); i++)
         
          {
             if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
             {
                 printf("%c", (((plaintext[i] - 'A') + key) % 26) + 'A');
             }
             
             else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
             {
                 printf("%c", (((plaintext[i] - 'a') + key) % 26) + 'a'); 
             }
             else
             {
                 printf("%c", plaintext[i]);
             }
          }

         printf("\n");
         return 0;
       }
    
       else 
      {
           printf("Usage: ./caesar k\n");
           return 1;
      }
   }
