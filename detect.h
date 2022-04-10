#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define PROCESSES 0
#define FILES 1
#define MAXNODE 20
#define MAXROW 3

// Struct of nodes
typedef struct node nodeType;
struct node {
	unsigned int id;
	int type;
	int visited;
	nodeType* next;
};

// Struct of graphs
typedef struct {
	nodeType** arrayList;
	int numNode;
	int numProcess;
	int numFile;
	int maxNode;
}graphType;

// Compare
int cmp(const void* a, const void* b);