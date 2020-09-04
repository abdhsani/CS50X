#include <cs50.h>
#include <stdio.h>
#include <math.h>

//cards to test
//AMEX - 378282246310005
//MASTERCARD - 5555555555554444
//VISA - 4111111111111111

//testsum for me 4284180485991037

int main(void) //always in the begginning
{
    long long cm; //prompt user for a number
    do
    {
        cm = get_long_long("What is the card number?");
    }
    while (cm < 0);

    //get the first sum condition
    long long sum1;
    //counting from right to left and starting from 2nd digit
    int digit2 = ((cm % 100) / 10) * 2;
    int digit4 = ((cm % 10000) / 1000) * 2;
    int digit6 = ((cm % 1000000) / 100000) * 2;
    int digit8 = ((cm % 100000000) / 10000000) * 2;
    int digit10 = ((cm % 10000000000) / 1000000000) * 2;
    int digit12 = ((cm % 1000000000000) / 100000000000) * 2;
    int digit14 = ((cm % 100000000000000) / 10000000000000) * 2;
    int digit16 = ((cm % 10000000000000000) / 1000000000000000) * 2;

    //taking every single digit from the code abobe and sum it (use modular % for send digit anf division / for the 1st one)
    int check1 = (digit2 % 10) + (digit2 / 10);
    int check2 = (digit4 % 10) + (digit4 / 10);
    int check3 = (digit6 % 10) + (digit6 / 10);
    int check4 = (digit8 % 10) + (digit8 / 10);
    int check5 = (digit10 % 10) + (digit10 / 10);
    int check6 = (digit12 % 10) + (digit12 / 10);
    int check7 = (digit14 % 10) + (digit14 / 10);
    int check8 = (digit16 % 10) + (digit16 / 10);
    sum1 = check1 + check2 + check3 + check4 + check5 + check6 + check7 + check8;

    //take unused digits and sum them with sum1 results
    int digit1 = cm % 10;
    int digit3 = ((cm % 1000) / 100);
    int digit5 = ((cm % 100000) / 10000);
    int digit7 = ((cm % 10000000) / 1000000);
    int digit9 = ((cm % 1000000000) / 100000000);
    int digit11 = ((cm % 100000000000) / 10000000000);
    int digit13 = ((cm % 10000000000000) / 1000000000000);
    int digit15 = ((cm % 1000000000000000) / 100000000000000);
    long long sum2 = digit1 + digit3 + digit5 + digit7 + digit9 + digit11 + digit13 + digit15;
    long long tsum = sum1 + sum2;
    //printf("%lli\n", tsum);

    //general validation of last digit of total sum
    if ((tsum % 10) != 0)
    {
        printf("INVALID\n");
        return (0); //stop the code if conditions are not met
    }

    //counting amount of digits
    int cmCount = 0;
    long long amount = cm;
    while (amount > 0)
    {
        amount = amount / 10;
        cmCount++;
    }
    //condition for rejecting any amount of digits but 13, 15 and 16
    if (cmCount != 13 && cmCount != 15 && cmCount != 16)
    {
        printf("INVALID\n");
    }

    //AMEX check
    long long amex = (cm / 10000000000000); //to get first 2 digits
    if (cmCount == 15)
    {
        if (amex != 34 && amex != 37)
        {
            printf("INVALID\n");
        }
        else
        {
            printf("AMEX\n");
        }
    }

    //MASTERCARD and VISA 16 digits check
    long long mc = (cm / 100000000000000); //to get first 2 digits
    if (cmCount == 16)
    {
        //VISA part
        if (digit16 == 8)
        {
            printf("VISA\n");
        }
        //MASTERCARD part
        else
        {
            if (mc >= 51 && mc <= 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

    }

    //Visa check
    if (digit16 == 8 && cmCount == 13)
    {
        printf("VISA\n");
    }

}
// to test VISA 4111111111111113