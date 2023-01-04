#include <stdio.h>
#include <math.h>

//  aydaki gun sayisini tutacak fonksiyon olusturuldu. 30 gun girmeye gerek kalmadan test imkani sağladi.
#define DAY_NUMBER 30

//  dizideki en kucuk elemanın indeksini donduren fonksiyon tanimlandi, olusturuldu.
int findLowestInArrAsIndex(double  arr[],int size);
//  dizideki en buyuk elemanın indeksini donduren fonksiyon tanimlandi, olusturuldu.
int findLargestInArrAsIndex(double  arr[],int size);
//  verilen dizinin aritmetik ortalamasini bulan fonksiyon tanimlandi, olusturuldu.
double calculateAverageInArr(double  arr[],int size);
//  verilen dizi icinde hedef sayisina en yakin elemanin donduren fonksiyon tanimlandi, olusturuldu.
int findTheClosestNumInArr(double arr[], int size, double goal_number);

int main(void)
{
//    gerekli degiskenler tanimlandi.
    double temperature_data[DAY_NUMBER];
    int min_index, max_index, closest_index;
    double average;

//    gun gun sıcaklik girmek icin for dongusu olusturuldu.
    for (int i = 0; i < DAY_NUMBER; i++)  //  created the array data which stores temperature day by day
    {
        printf("Enter the %d. day temperature:", i+1);
        scanf("%lf", &temperature_data[i]);
    }

    puts("--------------------------------------------------------------");
    puts("                METEOROLOGICAL DATA  day by day               ");

//    sicaklik degerleri sirasiyla yazdirildi.
    for (int i = 0; i < DAY_NUMBER; i++)
    {
        printf("Jan, %d: %.2lf Celcius Degree\n",i+1,temperature_data[i]);
    }
    puts("--------------------------------------------------------------");
    puts("                      METEOROLOGICAL DATA                     ");

//    istenen degerlerle degiskenler birbirine esitlendi.
    min_index = findLowestInArrAsIndex(temperature_data, DAY_NUMBER);
    max_index = findLargestInArrAsIndex(temperature_data, DAY_NUMBER);
    average = calculateAverageInArr(temperature_data, DAY_NUMBER);
    closest_index = findTheClosestNumInArr(temperature_data, DAY_NUMBER, average);

    printf("MIN: Jan, %d         ->  temperature: %.2lf Celcius Degree\n", min_index + 1, temperature_data[min_index]);
    printf("MAX: Jan, %d         ->  temperature: %.2lf Celcius Degree\n", max_index + 1, temperature_data[max_index]);
    printf("AVERAGE             ->  temperature: %.2lf Celcius Degree\n", average);
    printf("CLOSEST DAY: Jan, %d ->  temperature: %.2lf Celcius Degree\n", closest_index + 1, temperature_data[closest_index]);

    puts("--------------------------------------------------------------");

    return 0;
}

int findLowestInArrAsIndex(double  arr[],int size)
{
    int index = 0;
    double min = arr[0];
    for(int i = 1; i<size; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    }
    return index;
}

int findLargestInArrAsIndex(double  arr[], int size)
{
    int index = 0;
    double max = arr[0];
    for(int i = 1; i<size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

double calculateAverageInArr(double  arr[], int size)
{
    double sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (sum/size);
}

int findTheClosestNumInArr(double arr[], int size, double goal_number)
{
    int closest_index = 0;
//    sayilar arasindaki uzakligi bulmak icin fabs(float absolute) mutlak deger fonksiyonu kullanildi.
    double distance = fabs(goal_number - arr[closest_index]);

    for (int i = 1; i < size; ++i)
    {
        if (distance > fabs(goal_number - arr[i]))
        {
            distance = fabs(goal_number - arr[i]);
            closest_index = i;
        }
    }
    return closest_index;
}