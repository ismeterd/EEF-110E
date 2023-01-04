#include <stdio.h>

//  1'den n'e kadar olan sayıların toplamını döndüren fonksiyon tanimlandi, olusturuldu.
int sumUntilN(int n);

int main(void )
{
    printf("%d", sumUntilN(6));  // deneme amacıyla yazılmıştır.
}

//  recursive toplama fonksiyonu
int sumUntilN(int n)
{
    if(n == 1)
        return 1;
    else if (n == 0)
        return 0;
    else
        return n + sumUntilN(n-1);
}