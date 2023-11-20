#include <cs50.h>
#include <math.h>
#include <stdio.h>

int other_digit(long credit_card);
int operation(int last_digit);
int number_digit(long credit_card);
bool isValidAmex(long credit_card, int numDigit);
bool isValidMasterCard(long credit_card, int numDigit);
bool isValidVisa(long credit_card, int numDigit);

int main(void)
{
    long credit_card = get_long("Credit Card: ");
    int sum_other_digit = other_digit(credit_card);
    int numDigit = number_digit(credit_card);
    bool amex = isValidAmex(credit_card, numDigit);
    bool master = isValidMasterCard(credit_card, numDigit);
    bool visa = isValidVisa(credit_card, numDigit);

    if (sum_other_digit % 10 != 0)
    {
        printf("INVALID\n");
        return 1;
    }
    else if (amex == true)
    {
        printf("AMEX\n");
        return 0;
    }
    else if (master == true)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else if (visa == true)
    {
        printf("VISA\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

bool isValidAmex(long credit_card, int numDigit)
{
    int first_two_digits = credit_card / pow(10, 13);
    if ((numDigit == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValidVisa(long credit_card, int numDigit)
{
    if (numDigit == 13)
    {
        int first_digit = credit_card / pow(10, 12);
        if (first_digit == 4)
        {
            return true;
        }
    }
    else if (numDigit == 16)
    {
        int first_digit = credit_card / pow(10, 15);
        if (first_digit == 4)
        {
            return true;
        }
    }
    return false;
}

bool isValidMasterCard(long credit_card, int numDigit)
{
    int first_two_digits = credit_card / pow(10, 14);
    if ((numDigit == 16) && (first_two_digits > 50 && first_two_digits < 56))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int number_digit(long credit_card)
{
    int count = 0;
    while (credit_card > 0)
    {
        count = count + 1;
        credit_card = credit_card / 10;
    }
    return count;
}

int other_digit(long credit_card)
{
    int sum = 0;
    bool isAlternateDigit = false;
    while (credit_card > 0)
    {
        if (isAlternateDigit == true)
        {
            int last_digit = credit_card % 10;
            int product = operation(last_digit);
            sum = sum + product;
        }
        else
        {
            int last_digit = credit_card % 10;
            sum = sum + last_digit;
        }
        isAlternateDigit = !isAlternateDigit;
        credit_card = credit_card / 10;
    }
    return sum;
}

int operation(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int last_digit_multiply = multiply % 10;
        sum = sum + last_digit_multiply;
        multiply = multiply / 10;
    }
    return sum;
}