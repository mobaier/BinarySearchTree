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

// Dado uma ABB n�o vazia, retornar o n� com a menor chave daqula sub�rvore  
struct node * menorValorNo(struct node* node) 
{ 
    struct node* atual = node; 
  
    // Percorrer a �rvore at� o chegar no valor mais a esquerda da ABB
    while (atual && atual->esquerda != NULL) 
        atual = atual->esquerda; 
  
    return atual; 
} 

// Remover n� da �rvore
struct node* remover(struct node* raiz, int chave) 
{ 
    // �rvore sem itens 
    if (raiz == NULL) return raiz; 
  
    // Se a chave a ser deletada for menor que a raiz, 
    // ent�o ela fica na �rvore da direita. 
    if (chave < raiz->chave) 
        raiz->esquerda = remover(raiz->esquerda, chave); 
  
    // Se a chave a ser deletada for maior que a raiz, 
    // ent�o ela fica na �rvore da esquerda.
    else if (chave > raiz->chave) 
        raiz->direita = remover(raiz->direita, chave); 
  
    // Se a chave for igual o n� � removido
    else
    { 
        // N� com 1 ou menos sub�rvores
        if (raiz->esquerda == NULL) 
        { 
        	struct node *temp = raiz->direita;
            free(raiz); 
            return temp; 
        } 
        else if (raiz->direita == NULL) 
        { 
            struct node *temp = raiz->esquerda; 
            free(raiz); 
            return temp; 
        } 
  
        // N� com 2 sub�rvores: Pegar o sucessor pelo ordem (menor da �rvore da direita) 
        struct node* temp = menorValorNo(raiz->direita); 

        // Passar o conte�do do sucessor para este n�
        raiz->chave = temp->chave; 
  
        // Remover o sucessor 
        raiz->direita = remover(raiz->direita, temp->chave); 
    } 
    return raiz; 
} 
   
/* --------------------------------------------------------------
LISTA DE FUN��ES:
- struct node *novoNo(int item)
- void exibir(struct node *raiz)
- struct node* inserir(struct node* no, int chave)
- struct node * menorValorNo(struct node* node)
- struct node* remover(struct node* raiz, int chave) 	
--------------------------------------------------------------*/	
int main(void) 
{ 
    struct node *arvore = NULL;

    arvore = inserir(arvore, 10);
    arvore = inserir(arvore, 2);
    arvore = inserir(arvore, 6);
    arvore = inserir(arvore, 8);
    arvore = remover(arvore, 6);
    exibir(arvore);
    
    system("PAUSE");
    return 0; 
} 
