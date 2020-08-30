// Andr� Mobaier de Oliveira RA: 00101025
// Ci�ncia da Computa��o - 4� Semestre
// Exerc�cio �rvore Bin�ria de Busca - 24/08/2020

#include <stdio.h>

// Estrutura de n� que formar� a �rvore, definido por "node".
typedef struct {
	int key;
	struct node *rKey;
	struct node *lKey;
}node;

// Inicializar a �rvore com o primeiro n�
// O valor inserido ser� o intermedi�rio da �rvore
node* initialize(int x) {
	node *n;
	n = malloc(sizeof(node)); // Aloca��o din�mica
	printf("Binary Search Tree initialized!\n");
	return n;
}

// Retorna um n� com o par�metro inserido 
// e as duas subarvores.
node* newNode(int value) {
	node *n;
	n = malloc(sizeof(node)); // Aloca��o din�mica
	n->key = value;
	n->lKey = NULL;
	n->rKey = NULL;
	
	return n;
}

// Inserir elemento na �rvore
void insert() {
	//TODO
}

int main() {
	
	return 0;	
}
