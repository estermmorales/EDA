#include <stdio.h>
#include <string.h>

void main(){
    int i, contador=0, num=0;
    char frase[80];
    printf("Informe uma frase: \n");
    gets(frase);
    num = strlen(frase);
    for (i=0; i< num; ++i){
        if ((frase[i] == 'a') || (frase[i] == 'A'))
            contador++;
    }
    printf("\nExistem %d caracteres com \"a\" na frase.", contador);

}
