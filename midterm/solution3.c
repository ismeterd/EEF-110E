#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(void);
int findArrayNumber(int arr[], int number);

int main(void)
{
    int array[100];
    int array2[100];
    int array3[100] = {0};
    int counter = 0;
    srand(time(NULL));
    printf("    Array1\nindeks  ||  value\n");
    for(unsigned int i = 0; i < 100; i++) //rastgele sayılar tanımlandı
    {
        array[i] = generateRandomNumber();
        printf("%d index ->  %d\n",i,array[i]);
    }
    for(unsigned int i = 0; i<100; i++)
    {
        if(array[i]%2 != 0)
        {
//            printf("indeks %d tek\n",i);
            array2[counter] = array[i];
            counter++;
        }
    }
    for(unsigned int i = 0; i<100; i++)
    {
        if(array[i]%2 == 0)
        {
//            printf("indeks %d cift\n",i);
            array2[counter] = array[i];
            counter++;
        }
    }
    puts("----------------");
    printf("    Array2\nindeks  ||  value\n");
    counter = 0;
    for(unsigned int i = 0; i < 100; i++) //rastgele sayılar tanımlandı
    {

        printf("%d index ->  %d\n",i,array2[i]);
    }

    for(unsigned int i = 0; i < 100; i++)
    {
        if(i == 0)// ilk başta
        {
            array3[counter] = array[i];
            counter++;
        }
        else
        {
            if(findArrayNumber(array3,array[i]) == 0) //eğer array deki sayı array3 ün içinde yoksa:
            {
                array3[counter] = array[i];
                counter++;
            }
        }
    }
    puts("----------------");
    printf("    Array3\nindeks  ||  value\n");
    for(unsigned int i = 0; i < 100; i++)
    {
        if(array3[i] != 0)
            printf("%d index ->  %d\n",i,array3[i]); //array3 en iyi durumda 100 elemanlı olacağı için sayıların tekrarı durumunda son elemanları 0 olarak kalacaktır.
        // Bu durumu çıktıya yansıtmamak için array sonunda kalan 0lı elemanlar yazdırılmamıştır.
    }

}

int generateRandomNumber(void)
{
    return (rand()%100 + 1);
}

int findArrayNumber(int arr[], int number)
{
    for(unsigned int i = 0; i < 100; i++)
    {
        if(number == arr[i])
            return 1;//sayı bulundu anlamında 1 döndürecek
    }
    return 0;//bulamazsa 0 döndürecek
}
