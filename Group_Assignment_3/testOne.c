#include "myLibrary.h"

int main(){
	int array[] = {31, -41, 59, 26, -53, 58, -6, 97, -93, -23};

	int length = (int)sizeof(array)/sizeof(int);

	struct closestToZero result = method(array, 0, length - 1);

	printf("Result: %d, i=%d, j=%d\n", result.closest, result.i, result.j);

	return 0;
}

struct closestToZero method(int *array, int start, int end){
	int divide;
	struct closestToZero temp, smallest;
	int i, j;
	struct methodOne *suffixSum, *prefixSum;
	divide = (start + end + 1)/2;

	printf("Divide: %d\n", divide);

	suffixSum = malloc((divide - start)*sizeof(struct methodOne));
	prefixSum = malloc((end - (divide - 1))*sizeof(struct methodOne));

	//sum the two arrays
	for(i = divide - 1; i >= 0; i--){
		if(i == divide - 1){
			suffixSum[i].sum = array[start + i];
			suffixSum[i].position = start + i;
		}
		else{
			suffixSum[i].sum = suffixSum[i + 1].sum + array[start + i];
			suffixSum[i].position = start + i;
		}

		printf("%d ", suffixSum[i].sum);
	}

	printf("\n");

	for(i = 0; i < end - (divide - 1); i++){
		if(i == 0){
			prefixSum[i].sum = array[divide + i];
			prefixSum[i].position = divide + i;
		}
		else{
			prefixSum[i].sum = prefixSum[i - 1].sum + array[divide + i];
			prefixSum[i].position = divide + i;
		}

		printf("%d ", prefixSum[i].sum);
	}

	printf("\n");

	smallest.closest = 100;
	for(i = 0; i < divide - start; i++){
		for(j = 0; j < end - (divide - 1); j++){
			temp.closest = abs(suffixSum[i].sum + prefixSum[j].sum);
			temp.i = suffixSum[i].position;
			temp.j = prefixSum[j].position;

			if(temp.closest < smallest.closest){
				smallest = temp;
			}
		}
	}

	return smallest;
}

int lengthOf(int *array){
	int *myArray = array;
	int size;
	size = (int)sizeof(myArray);
	printf("Size: %d\n", size);
	return size/sizeof(int);
}