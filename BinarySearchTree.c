// Andr� Mobaier de Oliveira RA: 00101025
// Ci�ncia da Computa��o - 4� Semestre
// Exerc�cio �rvore Bin�ria de Busca - 31/08/2020

#include<stdio.h> 
#include<stdlib.h> 
  
// Estrutura de n�.
// Por algum motivo quando eu usava a 
// nota��o "no" gerava erros de casting.
struct node 
{ 
    int chave; 
    struct node *esquerda;
    struct node *direita; 
}; 
   
// Criar um novo n� a partir de um valor 
struct node *novoNo(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); // Aloca��o din�mica
    temp->chave = item; 
    temp->esquerda = NULL;
    temp->direita = NULL; 
    return temp; 
} 
   
// Percorrer e exibir todos os n�s da �rvore
// usando o m�todo In-Order. 
void exibir(struct node *raiz) 
{ 
    if (raiz != NULL) 
    { 
        exibir(raiz->esquerda); 
        printf("%d \n", raiz->chave); 
        exibir(raiz->direita); 
    } 
} 
   
// Inserir um valor na �rvore
struct node* inserir(struct node* no, int chave) 
{ 
    // Se a �rvore estiver vazia cria-se um novo n� e ela � iniciada
    if (no == NULL) return novoNo(chave); 
  
    // Colocar o valor no n� adequando se as regras de uma ABB
    if (chave < no->chave) 
        no->esquerda  = inserir(no->esquerda, chave); 
    else if (chave > no->chave) 
        no->direita = inserir(no->direita, chave);    
  
    return no; 
} 
   
// No main � requisitado ao usu�rio que insira 
// "n" valores na �rvore. Em seguida a �rvore � exibida
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
