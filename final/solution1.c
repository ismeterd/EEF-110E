#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(double arr[][2], int row, int column);
void insertAt(double arr[][2],int numElements, double x, double y, int insertIndex);

int main()
{
    /*
     * Ornekteki 2 boyutlu dizi olusturuldu
     */
    double arr[4][2] = {{0,0},
                        {0,0},
                        {0,0},
                        {0,0}};



    printArray(arr,4,2);
    insertAt(arr,4,2,3,1);
    puts("");
    printArray(arr,4,2);
    insertAt(arr,4,1,2,1);
    puts("");
    printArray(arr,4,2);
    insertAt(arr,4,3,5,0);
    puts("");
    printArray(arr,4,2);

}

void insertAt(double arr[][2],int numElements, double x, double y, int insertIndex)
{
    /*
     * Fonksiyon yeni değerleri insert etmeden önce
     * Insert edilecek yerdeki değerleri kendisinden bir sonraki yere
     * taşımak için aşağıdaki if şartı ve for duogusu kullanilmistir.
     * Bu şekilde insert edilen yerden sonra elemanlar birer indeks atlamis oalcaktir
     */
    if(insertIndex < numElements - 1)
    {
        for(int i = numElements - 1; i >= insertIndex + 1; i--)
        {
            arr[i][0] = arr[i-1][0];
            arr[i][1] = arr[i-1][1];
        }
    }

    /*
     * Burada da konulması gereken değerleri indekse yerlestirilmektedir.
     */
    arr[insertIndex][0] = x;
    arr[insertIndex][1] = y;
}


/*
 * Durumu gormek icin array print fonksiyonu
 */
void printArray(double arr[][2], int row, int column)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            printf("%.2lf  ",arr[i][j]);
        }
        printf("%s","\n");
    }
}

