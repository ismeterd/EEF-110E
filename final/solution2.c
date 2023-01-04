#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Köklerin reel ve imaginer kısmı olduğu için
 * ComplexSt adında struct oluşturuldu
 * Kullanım kolaylgi olması için type definitipn ile complex veri tipi üretildi
 */
struct ComplexSt{
    double re, im;
};

typedef struct ComplexSt complex;

complex* SolveEqn(double a, double b, double c);

int main()
{
    /*
     * solution ismindeki complex pointeri fonksiyonun döndürdüğü köklerin adresini tutmaktadır.
     */
    complex* solution;
    solution = SolveEqn(2,-6,5);

    /*
     * Kökler bu şekilde ifade edilmistir.
     */
    printf("root1.re -> %.2lf\n",solution[0].re);
    printf("root1.im -> %.2lf\n",solution[0].im);
    printf("root2.re -> %.2lf\n",solution[1].re);
    printf("root2.im -> %.2lf\n",solution[1].im);
}

/*
 * Denklem çözecek olan fonksiyonun çıktıları iki kök olması nedeniyle çıktının
 * complex pointeri ile dönülmesi sağlanmıştır. Bir çeşit kök dizisi gibi.
 */
complex* SolveEqn(double a, double b, double c)
{
    complex* results;
    /*
     * Pointerin tutulacak değerleri için calloc ile yer ayrıldı
     */
    results = calloc(2 , sizeof(complex));

    double delta = 0;

    puts("Equation:");
    printf("%.2lfx^2 + %.2lfx + %.2lf\n", a, b, c);
    puts("");
    /*
     * Delta çözümde önemli olduğu için hesaplandı
     */
    delta = pow(b,2) - 4 * a * c;
    printf("delta = %.2lf\n\n", delta);

    if(delta >= 0)
    {
        /*
         * Delta 0 dan buyuk oldugunda imaginer kısımlar 0,
         * reel kısımlar -b +- kök delta / 2*a ile bulunmuştur
         * Delta = 0 için de bu if statement i gereken görevi
         * yerine getirmektedir.
         */

        /*
         * Arary index notasyon ile pointerın dgerleri girilmistir
         */
        results[0].im = 0;
        results[0].re = (-b + sqrt(delta)) / (2 * a);
        results[1].im = 0;
        results[1].re = (-b - sqrt(delta)) / (2 * a);
    }

    else
    {
        /*
         * bu sefer imaginer kısımlar da doldurulmuştur.
         */
        results[0].im = (+sqrt(-delta)/(2*a));
        results[0].re = (-b) / (2 * a);
        results[1].im = (-sqrt(-delta)/(2*a));
        results[1].re = (-b) / (2 * a);
    }

    /*
     * complex pointeri burada return edilmistir.
     */
    return results;
}



