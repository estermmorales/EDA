typedef struct fila Fila;
Fila* cria(); /*Aloca memoria dinamicamente*/
void insere(Fila* fila, float valor); /*Insere elemento no fim*/
float retira(Fila* fila);/*Retira elemento do inicio*/
int vazia(Fila* fila);/*Verifica se a fila esta vazia*/
void libera(Fila* fila);/*Destroi estrutura*/

