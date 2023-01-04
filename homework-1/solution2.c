#include <stdio.h>
#include <math.h>

//  yaklasimin hem degerini hem son terimini bulmak icin iki degisken tutan bir veri yapisi olusturuldu.
struct termAndResult {
    int terms;
    double result;
};

//  formulde kullanilmak uzere faktoriyel fonksiyonu olusturuldu, tanimlandi.
int factorial(int number);
//  yaklasımın verilen radyanın n. teriminindeki degerini göstermesi için formula adında fonksiyon olusturuldu, tanimlandi.
double formula(double radian, int iteration);
//  yaklasımı 0'dan n e kadar verilen toleransa kadar ilerleten fonksiyon olusturuldu, tanimlandi.
struct termAndResult CosApprox(double radian, double error);


int main(void )
{
//    gerekli degisken tanimlamalari yapildi.
    double radian, tollerance;
    struct termAndResult results;

    puts("WELCOME TO CALCULATE TAYLOR SERIES APPROMIXATION of COS(x)\n");
    printf("enter the radian:");
    scanf("%lf",&radian);
    printf("enter the error tolerance:");
    scanf("%lf",&tollerance);

    results = CosApprox(radian, tollerance);

    puts("------------------------------------");
    printf("Angle in radians: %lf\n", radian);
    printf("Angle in degrees: %lf\n", (radian * 180)/M_PI);
    printf("Error tolerance: %lf\n\n",tollerance);
    printf("Real Value: %lf\n", cos(radian));
    printf("Approximate Value: %lf\n", results.result);
    printf("Number of terms: %d\n", results.terms);
    puts("------------------------------------");
}

//  termAndResult veritipi altinda 2 degisken donduren, sigma toplami yapan fonksiton olusturuldu.
struct termAndResult CosApprox(double radian, double error)
{
    struct termAndResult results;
    int iteration = 0;
    double result = formula(radian, iteration);
    double difference = fabs(cos(radian) - result);
    while (difference > error)
    {
        iteration += 1;
        result += formula(radian, iteration);
//        farka bakmak için math.h icindeki fabs() fonksiyonu kullanildi.
        difference = fabs(cos(radian) - result);
    }
    results.terms = iteration;
    results.result = result;

    return results;
}

//  sigma icindeki formulun radian ve n. terime gore hesaplama yapacak fonksiyon tanimlandi.
double formula(double radian, int iteration)
{
//    formul kucuk parcalara bolundu.
    double f1 = pow(-1, (float)iteration);
    double f2 = pow(radian, 2 * (float)iteration);
    double f3 = factorial(2 * iteration);
    double result = (f1 * f2) / f3;
//    ufak tefek denemeler :)
//    printf("radian = %.2lf\n",radian);
//    printf("%d.iteration\n",iteration);
//    printf("f1 -> (-1)^%d = %.2lf\n",iteration,f1);
//    printf("f2 -> %.2lf^(2*%d) = %.2lf\n",radian,iteration,f2);
//    printf("f3 -> (2*%d)! = %.2lf\n",iteration,f3);
//    printf("result of %d.iteration = %lf\n",iteration, result);
//    puts("----------------------------------");
    return result;
}

//  ozyinelemeli faktoriyel fonksiyonu tanimlandi.
int factorial(int number)
{
    if(number == 1 || number == 0)
        return 1;
    return number * factorial(number-1);
}


