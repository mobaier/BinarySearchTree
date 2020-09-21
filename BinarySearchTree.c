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
struct node* novoNo(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); // Alocação dinâmica
    temp->chave = item; 
    temp->esquerda = NULL;
    temp->direita = NULL; 
    return temp; 
} 
   
// Percorrer e exibir todos os nós da árvore
// usando o método In-Order. 
void exibirIO(struct node *raiz) 
{ 
	// Árvore vazia
    if (raiz == NULL) return;
    
	// Recursão no nó esquerdo
	exibirIO(raiz->esquerda); 
    
    // Imprimir nó
	printf("%d ", raiz->chave); 
    
    // Recursão no nó direito
	exibirIO(raiz->direita); 
	 
}

// Percorrer e exibir todos os nós da árvore
// usando o método Pre-Order.
void exibirPreO(struct node* node) 
{ 
	// Árvore vazia
    if (node == NULL) return; 
  
    // Imprimir nó 
    printf("%d ", node->chave);   
  
    // Recursão no nó esquerdo 
    exibirPreO(node->esquerda);   
  
    // Recursão no nó direito
    exibirPreO(node->direita); 
}

// Percorrer e exibir todos os nós da árvore
// usando o método Post-Order.
void exibirPosO(struct node* node) 
{ 	
	// Árvore vazia
    if (node == NULL) return; 
  
    // Recursão no nó esquerdo 
    exibirPosO(node->esquerda); 
  
    // Recursão no nó direito
    exibirPosO(node->direita); 
  
    // Imprimir nó 
    printf("%d ", node->chave); 
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

// Dado uma ABB não vazia, retornar o menor valor da árvore 
struct node* menorValorNo(struct node* node) 
{ 
    struct node* atual = node; 
  
    // Percorrer a árvore até o chegar no valor mais a esquerda da ABB
    while (atual && atual->esquerda != NULL) {
	    atual = atual->esquerda; 
    }
    return atual; 
} 

// Remover nó da árvore
struct node* remover(struct node* raiz, int chave) 
{ 
    // Árvore sem itens 
    if (raiz == NULL) return raiz; 
  
    // Se a chave a ser deletada for menor que a raiz, 
    // então ela fica na árvore da direita. 
    if (chave < raiz->chave) 
        raiz->esquerda = remover(raiz->esquerda, chave); 
  
    // Se a chave a ser deletada for maior que a raiz, 
    // então ela fica na árvore da esquerda.
    else if (chave > raiz->chave) 
        raiz->direita = remover(raiz->direita, chave); 
  
    // Se a chave for igual o nó é removido
    else
    { 
        // Nó com 1 ou menos subárvores
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
  
        // Nó com 2 subárvores: Pegar o sucessor pelo ordem (menor da árvore da direita) 
        struct node* temp = menorValorNo(raiz->direita); 

        // Passar o conteúdo do sucessor para este nó
        raiz->chave = temp->chave; 
  
        // Remover o sucessor 
        raiz->direita = remover(raiz->direita, temp->chave); 
    } 
    return raiz; 
} 
   
/* --------------------------------------------------------------
LISTA DE FUNÇÕES:
- struct node* novoNo(int item)
- void exibirPosO(struct node* node) 
- void exibirPreO(struct node* node) 
- void exibirIO(struct node *raiz)
- struct node* inserir(struct node* no, int chave)
- struct node* menorValorNo(struct node* node)
- struct node* remover(struct node* raiz, int chave) 	
--------------------------------------------------------------*/	
int main(void) 
{ 	
    struct node *arvore = NULL;

    arvore = inserir(arvore, 10);
    arvore = inserir(arvore, 2);
    arvore = inserir(arvore, 10);
    arvore = inserir(arvore, 3);
    arvore = inserir(arvore, 13);
    exibirIO(arvore);
    
    
    
    putchar('\n');    
    system("PAUSE");
    return 0; 
} 
