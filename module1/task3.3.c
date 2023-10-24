#include <stdio.h>
#include <math.h>

unsigned long long int factorial(long long int num) {
    if (num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}

int main() 
{
    int n;
    long long int x;
    double result = 0;

    scanf("%d %lld", &n, &x);

    for(int i = 0; i < n; i++)
        result += (float)(pow(x, i) / factorial(i) * pow(-1, i));

    printf("%2.3f", result);
    
    return 0;
}