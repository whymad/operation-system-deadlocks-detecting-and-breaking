// Task 2
int calculate_time(graphType* graph);

// Task 3
int detect_deadlock(graphType* graph);
int find_cycle(nodeType* node);

// Task 4
int break_deadlock(nodeType** list, graphType* graph);

// Task challenge
void challenge(int list[][MAXROW], int line);
int check(int a, int b, int picked[][MAXROW], int len);