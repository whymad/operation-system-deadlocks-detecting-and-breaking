#include "detect.h"
#include "tasks.h"

// Task2: Execution time
int calculate_time(graphType* graph) {
	int current, max = 0;
	// Loop through all processes in the graph
	for (int i = 0; i < graph->numNode; i++) {
		if (graph->arrayList[i]->type == PROCESSES) {
			current = 0;
			for (int j = 0; j < graph->numNode; j++) {
				if (graph->arrayList[j]->type == PROCESSES) {
					if (graph->arrayList[i]->next->id ==
						graph->arrayList[j]->next->id) {
						current += 1;
					}
				}
			}
		}
		if (current > max) {
			max = current;
		}
	}
	return max += 1;
}

// Task3: Deadlock detection
int detect_deadlock(graphType* graph) {
	int i;
	for (i = 0; i < graph->numNode; i++) {
		if (find_cycle(graph->arrayList[i]) == TRUE) {
			return TRUE;
		}
	}
	return FALSE;
}

// Find if a node is in a cycle or not
int find_cycle(nodeType* node) {
	int max = MAXNODE;
	nodeType** visited = malloc(sizeof(nodeType*) * max);
	int count = 0;
	nodeType* start = node;
	int visit = FALSE;
	while (node->next != NULL) {
		for (int i = 0; i < count; i++) {
			if (node == visited[i]) {
				visit = TRUE;
			}
		}
		if (visit == FALSE) {
			visited[count] = node;
			count += 1;
			node = node->next;
			if (node == start) {
				return TRUE;
			}
			if (count >= max) {
				max *= 2;
				visited = realloc(visited, sizeof(nodeType*) * max);
			}
		}
		else {
			return FALSE;
		}
	}
	return FALSE;
}

// Task 4: Breaking deadlocks
int break_deadlock(nodeType** list, graphType* graph) {
	int i;
	int len = 0;
	// Loop through all processes in the graph
	for (i = 0; i < graph->numNode; i++) {
		nodeType* node = graph->arrayList[i];
		if (node->type == PROCESSES && node->visited == FALSE) {
			if (find_cycle(node) == TRUE) {
				// Find the smallest id
				nodeType* start = node;
				nodeType* current = node;
				while (node->next != start) {
					if (node->id < current->id) {
						current = node;
					}
					node->visited = TRUE;
					node = node->next;
				}
				list[len] = current;
				len += 1;
			}
		}
	}
	return len;
}

// Challenge task
void challenge(int list[][MAXROW], int line) {
	int count = 0, time = 0, len;
	int picked[line][MAXROW];
	for (int i = 0; i < line; i++) {
		picked[i][0] = -1;
		picked[i][1] = -1;
		picked[i][2] = -1;
	}
	while (count != line) {
		len = 0;
		for (int i = 0; i < line; i++) {
			if (list[i][0] != -1 && check(list[i][1], list[i][2], picked, len) == TRUE) {
				picked[len][0] = list[i][0];
				picked[len][1] = list[i][1];
				picked[len][2] = list[i][2];
				len += 1;
				count += 1;
				list[i][0] = -1;
			}
		}
		for (int i = 0; i < len; i++) {
			printf("%d ", time);
			printf("%d ", picked[i][0]);
			printf("%d,", picked[i][1]);
			printf("%d\n", picked[i][2]);
		}
		time += 1;
	}
	printf("Simulation time %d\n", time);
}
// Check if the row in the array or not
int check(int a, int b, int picked[][MAXROW], int len) {
	for (int i = 0; i < len; i++) {
		if ((picked[i][1] == a) || (picked[i][1] == b) || (picked[i][2] == a) || (picked[i][2] == b)) {
			return FALSE;
		}
	}
	return TRUE;
}