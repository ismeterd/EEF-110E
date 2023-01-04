#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fx(double x);
double Secant(double (*f)(double), double error, double xk, double xk_1);

int main()
{
    double root = Secant(fx, 0.001,2,1);
    printf("root of function -> %lf",root);
}

double fx(double x)
{
    /*
     * Verilen fonksiyon
     */
    return (pow(x,2) * fabs(sin(pow(x,0.5)))) - 10;
}

double Secant(double (*f)(double), double error, double xk, double xk_1)
{
    /*
     * Verilen sekant iterasyonunun fonksiyonlaşmış yazımı
     * Bulunan kök değeri error değerinden küçük olana kadar iterasyon dönmektedir.
     */
    double root = 0;
    while (fabs(f(root)) >= error)
    {
//        printf("Value -> %lf\n",f(root));
        root = xk - (f(xk) * (xk - xk_1)) / (f(xk) - f(xk_1));
        xk_1 = xk;
        xk = root;
    }
    return root;
}



