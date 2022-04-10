// Include the head files
#include "detect.h"
#include "utils.h"
#include "tasks.h"

// Main
int main(int argc, char** argv) {
	int e = FALSE, c = FALSE;
	FILE* pf;
	FILE* pf1;
	int var1, var2, var3;
	// Read the argurments
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-e") == 0) {
			e = TRUE;
		}
		if (strcmp(argv[i], "-c") == 0) {
			c = TRUE;
		}
		if (strcmp(argv[i], "-f") == 0) {
			pf = fopen(argv[i + 1], "r");
			pf1 = fopen(argv[i + 1], "r");
		}
	}

	graphType* graph = creat_graph();
	nodeType* procNode,* lockNode,* waitNode;
	// Read through the file line by line
	while (fscanf(pf, "%d %d %d", &var1, &var2, &var3) != EOF) {
		procNode = create_node(var1, PROCESSES, graph);
		lockNode = create_node(var2, FILES, graph);
		waitNode = create_node(var3, FILES, graph);
		procNode->next = waitNode;
		lockNode->next = procNode;
	}

	// Challenge
	if (c == TRUE) {
		int line = graph->numProcess;
		int var01, var02, var03;
		int thelist[line][MAXROW];
		int row = 0;
		// Scan all data into a array of rows
		while (fscanf(pf1, "%d %d %d", &var01, &var02, &var03) != EOF) {
			thelist[row][0] = var01;
			thelist[row][1] = var02;
			thelist[row][2] = var03;
			row += 1;
		}
		// Run the challenge function
		challenge(thelist, line);
	}
	// If not challenge task
	else {
		// Print for task1
		printf("Processes %d\n", graph->numProcess);
		printf("Files %d\n", graph->numFile);

		// Task2
		if (e == TRUE) {
			int time = calculate_time(graph);
			printf("Execution time %d\n", time);
		}
		else {
			// Detect deadlocks
			if (detect_deadlock(graph) == TRUE) {
				printf("Deadlock detected\n");
				// Break deadlocks
				nodeType** processlist = malloc(sizeof(nodeType*) * graph->numProcess);
				int len = break_deadlock(processlist, graph);
				qsort(processlist, len, sizeof(nodeType*), cmp);
				printf("Terminate");
				for (int a = 0; a < len; a++) {
					printf(" %d", processlist[a]->id);
				}
				printf("\n");
			}
			else {
				printf("No deadlocks\n");
			}
		}
	}
	// Close the file
	fclose(pf);
	fclose(pf1);
} 
// Comprsion function for the qsort
int cmp(const void* a, const void* b) {
	const nodeType* oa = a;
	const nodeType* ob = b;
	return (oa->id > ob->id) - (oa->id < ob->id);
}