#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct closestToZero{
	int i;
	int j;
	int closest;
};

struct method{
	int position;
	int sum;
};

struct closestToZero find(int *array, int i, int j);
int lengthOf(int *array);
struct closestToZero method(int *array, int start, int end);
struct closestToZero methodThree(int *array, int start, int end);
struct closestToZero min(struct closestToZero suffix, struct closestToZero prefix, struct closestToZero combine);
void sort(struct method *combine, int size);