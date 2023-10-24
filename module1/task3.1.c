#include <stdio.h>

int main() {
    
    int s=20*20;
    
    for (int n=19;n>=1;n--)
        s-=n*n;
    
    printf("%d",s);
    
    return 0;
}