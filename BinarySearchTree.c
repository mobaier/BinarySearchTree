// André Mobaier de Oliveira RA: 00101025
// Ciência da Computação - 4º Semestre
// Exercício Árvore Binária de Busca - 31/08/2020

#include<stdio.h> 
#include<stdlib.h> 
  
// Estrutura de nó.
// Por algum motivo quando eu usava a 
// notação "no" gerava erros de casting.
struct node 
{ 
    int chave; 
    struct node *esquerda;
    struct node *direita; 
}; 
   
// Criar um novo nó a partir de um valor 
struct node *novoNo(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); // Alocação dinâmica
    temp->chave = item; 
    temp->esquerda = NULL;
    temp->direita = NULL; 
    return temp; 
} 
   
// Percorrer e exibir todos os nós da árvore
// usando o método In-Order. 
void exibir(struct node *raiz) 
{ 
    if (raiz != NULL) 
    { 
        exibir(raiz->esquerda); 
        printf("%d \n", raiz->chave); 
        exibir(raiz->direita); 
    } 
} 
   
// Inserir um valor na árvore
struct node* inserir(struct node* no, int chave) 
{ 
    // Se a árvore estiver vazia cria-se um novo nó e ela é iniciada
    if (no == NULL) return novoNo(chave); 
  
    // Colocar o valor no nó adequando se as regras de uma ABB
    if (chave < no->chave) 
        no->esquerda  = inserir(no->esquerda, chave); 
    else if (chave > no->chave) 
        no->direita = inserir(no->direita, chave);    
  
    return no; 
} 
   
// No main é requisitado ao usuário que insira 
// "n" valores na árvore. Em seguida a árvore é exibida
// ordenadamente
int main() 
{ 
    int entrada;
    int valor;

    struct node *arvore = NULL;
    do {
      printf("Insira um valor: ");
      scanf("%i", &valor);

      arvore = inserir(arvore, valor);
      printf("Deseja inserir outro valor? (0 = Negativo)");
      scanf("%i", &entrada);
    }while(entrada != 0);

    exibir(arvore);
    
    system("PAUSE");
    return 0; 
} 
