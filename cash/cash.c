#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
   float dollars;
  
    do
    {
       dollars = get_float("Change owed?: ");
    }
    while (dollars <= 0);
   int cents = round(dollars * 100);
   int coins = 0;

    while ( cents >= 25)
    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }
    while ( cents >= 10)
    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }
    while ( cents >= 5)
    while (cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }
    while ( cents >= 1)
    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }
    printf("%i\n", coins);
}
