#include "challenge.h"

// Challenge task
void challenge(int list[][3], int line) {
	int count = 0, time = 0, len;
	int picked[line][3];
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
int check(int a, int b, int picked[][3], int len) {
	for (int i = 0; i < len; i++) {
		if ((picked[i][1] == a) || (picked[i][1] == b) || (picked[i][2] == a) || (picked[i][2] == b)) {
			return FALSE;
		}
	}
	return TRUE;
}