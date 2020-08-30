// André Mobaier de Oliveira RA: 00101025
// Ciência da Computação - 4º Semestre
// Exercício Árvore Binária de Busca - 24/08/2020

#include <stdio.h>

// Estrutura de nó que formará a Árvore, definido por "node".
typedef struct {
	int key;
	struct node *rKey;
	struct node *lKey;
}node;

// Inicializar a Árvore com o primeiro nó
// O valor inserido será o intermediário da Árvore
node* initialize(int x) {
	node *n;
	n = malloc(sizeof(node)); // Alocação dinâmica
	printf("Binary Search Tree initialized!\n");
	return n;
}

// Retorna um nó com o parâmetro inserido 
// e as duas subarvores.
node* newNode(int value) {
	node *n;
	n = malloc(sizeof(node)); // Alocação dinâmica
	n->key = value;
	n->lKey = NULL;
	n->rKey = NULL;
	
	return n;
}

// Inserir elemento na árvore
void insert() {
	//TODO
}

int main() {
	
	return 0;	
}
