#include<stdlib.h>
#include<stdio.h>

// void swap(int & a, int & b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

int main()
{
    int a = 2;
    int &b = a;
    b += 1;
    printf("a = %d\n",a);

    return 0;
}

