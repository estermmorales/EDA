#include <stdio.h>

int main(){
    /* variavel inteiro */
    int a;
    /* variavel ponteiro para inteiro */
    int *p;
    /* a recebe valor 5 */
    a = 5;

    /*p recebe o enderço de a */
    p = &a;
    /* conteudo de p recebe valor de 6 */
    *p = 6;

    printf("\n %d", a);
    printf("\n %d", *p);
    printf("\n %d", p);
    printf("\n %d", &a);

}