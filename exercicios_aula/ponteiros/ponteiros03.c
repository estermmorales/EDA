#include <stdio.h>
int main(){
    int a;
    int *p;

    p = &a;
    *p = 2;
    printf("\n%d", a);
    
    return 0;
}