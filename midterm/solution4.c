#include <stdio.h>

int findDigitNumber(int number);
int findDigitSum(int number);
int isItDivisible(int number);

int main(void)
{
    for(unsigned int i = 1;i <= 200; i++)
    {
        if(isItDivisible(i) == 1) //bölünebilirse
        {
            printf("%d -> sum = %d; so it is divisible by sum of digits\n", i,findDigitSum(i));
        }
    }
}

int isItDivisible(int number)
{
    if(number % findDigitSum(number) == 0)
        return 1; //bölünebilir
    else
        return 0;
}

int findDigitSum(int number)
{
    int sum = 0;
    if(findDigitNumber(number) == 1)
    {
        sum = number;
        return sum;
    }
    else if(findDigitNumber(number) == 2)
    {
        sum += (number/10);
        sum += number%10;
        return sum;
    }
    else if(findDigitNumber(number) == 3)
    {
        sum += (number/100);
        sum += (number/10)%10;
        sum += (number%100)%10;
        return sum;
    }
}

int findDigitNumber(int number)
{
    if(number > 0 && number < 10)
        return 1;//1 basamaklı
    else if(number >= 10 && number < 100)
        return 2;
    else if(number >= 100 && number < 1000)
        return 3;
    else
        return -1;
}