#include <stdio.h>

int lastElementIndexLessThanOrEqualTo(double arr[],int numElements, double value);

int main(void)
{
    double arr[10] = {3.2, 5.5, 9.0, 13.1, 22.0, 23.6, 40.1, 44.7, 52.2, 60.0};
    int index =  lastElementIndexLessThanOrEqualTo(arr,10, 24);
    printf("index = %d",index);
    return 0;
}

int lastElementIndexLessThanOrEqualTo(double arr[],int numElements, double value)
{
    int last_index = -1;// başlangıç değeri olarak -1 alsın. Eğer value dizideki hiç bir elemandan küçük değilse
    // -1 olarak dönsün.
    for(unsigned int i = 0;i < 10; i++)
    {
        if (value > arr[i])
        {
            last_index = i;
        }
//        printf("%.1lf\n",arr[i]);
    }
    return last_index;
}