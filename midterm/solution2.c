#include <stdio.h>

int main(void)
{
    int student_grade = 0;
    int n[50] = {0};
    int student_number = 0;
    unsigned int sum = 0;
    do
    {
        printf("enter the student number(it must be between [1-50]):");
        scanf("%d",&student_number);
        if (student_number > 50)
            printf("Maximum 50 students!\n");
        else if (student_number <= 0)
            printf("Student count should be positive\n");
    }
    while (student_number <= 0 || student_number > 50);
//    printf("%d",student_number);

    for(unsigned int i = 0; i < student_number; i++)
    {
        printf("Enter the %d. student grade:",i+1);
        scanf("%d",&student_grade);
        if(student_grade < 0 || student_grade > 100)
        {
            printf("Grades must be between 0 and 100\n");
            i--;
            continue;
        }
        else
        {
            n[i] = student_grade;
        }
    }
    for(unsigned int i = 0; i < student_number; i++)
    {
        printf("%d.student -> grade:%d\n",i+1,n[i]);
        sum += n[i];
    }
    printf("Class Average = %.2lf",(double)sum/(double)student_number);
}

