#include "detect.h"
#include "utils.h"

// Create structures and put the file data in
graphType* creat_graph() {
	graphType* lockGraph = malloc(sizeof(graphType));
	lockGraph->numProcess = 0;
	lockGraph->numFile = 0;
	lockGraph->numNode = 0;
	lockGraph->maxNode = MAXNODE;
	lockGraph->arrayList = malloc(sizeof(nodeType*) * lockGraph->maxNode);
	return lockGraph;
}

// Create a new node
nodeType* create_node(int val, int typ, graphType* graph) {
	nodeType* new;
	if ((new = contains(val, typ, graph)) != NULL) {
		return new;
	}
	new = malloc(sizeof(nodeType));
	new->type = typ;
	new->id = val;
	new->visited = FALSE;
	new->next = NULL;
	insert_node(graph, new);
	if (typ == PROCESSES) {
		graph->numProcess += 1;
	}
	else {
		graph->numFile += 1;
	}
	return new;
}

// Check if a node is in the graph already or not
nodeType* contains(int val, int typ, graphType* graph) {
	int i = 0;
	while (i < graph->numNode) {
		if (((graph->arrayList[i]->id) == val) &&
			((graph->arrayList[i]->type) == typ)) {
			return graph->arrayList[i];
		}
		i++;
	}
	return NULL;
}

// Insert a node into the graph
void insert_node(graphType* graph, nodeType* new_node) {
	if (graph->numNode >= graph->maxNode) {
		graph->maxNode *= 2;
		graph->arrayList = realloc(graph->arrayList,
			sizeof(nodeType*) * graph->maxNode);
	}
	graph->arrayList[graph->numNode] = new_node;
	graph->numNode += 1;
}
