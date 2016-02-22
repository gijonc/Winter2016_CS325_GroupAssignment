#include "myLibrary.h"

int main(){
	int array[] = {31, -41, 59, 26, -53, 58, -6, 97, -93, -23};

	int arrayLength = (int)sizeof(array)/sizeof(int);

	printf("%d\n", arrayLength);

	struct closestToZero result;
	result = find(array, 0, arrayLength-1);

	printf("Result: cloest: %d, from %d to %d\n", result.closest, result.i, result.j);

	return 0;
}

struct closestToZero find(int *array, int i, int j){
	struct closestToZero suffix;
	struct closestToZero prefix;
	struct closestToZero combine;
	struct closestToZero result;
	int temp;
	int divide;

	if((j-i) == 1){
		temp = abs(array[i] + array[j]);
		if(temp < abs(array[i]) && temp < abs(array[j])){
			result.i = i;
			result.j = j;
			result.closest = temp;
		}else if(abs(array[i]) > abs(array[j])){
			result.i = j;
			result.j = j;
			result.closest = abs(array[j]);
		}else{
			result.i = i;
			result.j = i;
			result.closest = abs(array[i]);
		}
		return result;
	}else if(i == j){
		result.i = i;
		result.j = j;
		result.closest = abs(array[i]);
		return result;
	}

	divide = (i + j)/2;
	//printf("Divide in find : %d i= %d j = %d\n", divide, i, j);
	suffix = find(array, i, divide);
	prefix = find(array, divide + 1, j);
	combine = methodThree(array, i, j);

	return min(suffix, prefix, combine);
}

struct closestToZero min(struct closestToZero suffix, struct closestToZero prefix, struct closestToZero combine){
	struct closestToZero temp;
	if(suffix.closest < prefix.closest)
		temp = suffix;
	else
		temp = prefix;

	if(combine.closest < temp.closest){
		printf("%d\n", combine.closest);
		return combine;
	}else{
		printf("%d\n", temp.closest);
		return temp;
	}
}

struct closestToZero method(int *array, int start, int end){
	int divide;
	struct closestToZero temp, smallest;
	int i, j;
	struct method *suffixSum, *prefixSum;
	divide = (start + end + 1)/2;

	//printf("Divide: %d\n", divide);

	suffixSum = malloc((divide - start)*sizeof(struct method));
	prefixSum = malloc((end - (divide - 1))*sizeof(struct method));

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

		//printf("%d ", suffixSum[i].sum);
	}

	//printf("\n");

	for(i = 0; i < end - (divide - 1); i++){
		if(i == 0){
			prefixSum[i].sum = array[divide + i];
			prefixSum[i].position = divide + i;
		}
		else{
			prefixSum[i].sum = prefixSum[i - 1].sum + array[divide + i];
			prefixSum[i].position = divide + i;
		}

		//printf("%d ", prefixSum[i].sum);
	}

	//printf("\n");

	smallest.closest = 100000000;
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
	printf("Smallest from method 1: %d\n", smallest.closest);
	return smallest;
}

//method 2
//struct closestToZero methorTwo(int *array, int start, int end){
//}

//method 3
struct closestToZero methodThree(int *array, int start, int end){
	int divide;
	struct closestToZero temp, smallest;
	int i, j;
	struct method *suffixSum, *prefixSum, *combine;
	divide = (start + end + 1)/2;

	//printf("Divide: %d\n", divide);

	suffixSum = malloc((divide - start)*sizeof(struct method));
	prefixSum = malloc((end - (divide - 1))*sizeof(struct method));
	combine = malloc((end - start + 1)*sizeof(method));

	//sum the two arrays
	for(i = divide - 1, j = 0; i >= 0; i--, j++){
		if(i == divide - 1){
			suffixSum[i].sum = array[start + i];
			suffixSum[i].position = start + i;
		}
		else{
			suffixSum[i].sum = suffixSum[i + 1].sum + array[start + i];
			suffixSum[i].position = start + i;
		}

		combine[j].sum = suffixSum[i].sum;
		combine[j].position = suffixSum[i].position;
		//printf("%d ", suffixSum[i].sum);
	}

	//printf("\n");

	for(i = 0; i < end - (divide - 1); i++, j++){
		if(i == 0){
			prefixSum[i].sum = array[divide + i];
			prefixSum[i].position = divide + i;
		}
		else{
			prefixSum[i].sum = prefixSum[i - 1].sum + array[divide + i];
			prefixSum[i].position = divide + i;
		}

		prefixSum[i].sum = -prefixSum[i].sum;

		combine[j].sum = prefixSum[i].sum;
		combine[j].position = prefixSum[i].position;
		//printf("%d ", prefixSum[i].sum);
	}

	sort(combine, end - start + 1);

	smallest.closest = 1000000;

	for(i = 0; i < end - start; i++){
		temp.closest = combine[i].sum + combine[i+1].sum;
		temp.i = combine[i].position;
		temp.j = combine[i+1].position;

		if(temp.closest < smallest.closest){
			smallest = temp;
		}
	}

	return smallest;
}

void sort(struct method *combine, int length){
	struct method temp;
	int i, j;

	for(i = 1; i < length; i++){
		for(j = i; j>= 0; j--){
			if(combine[j].sum < combine[j-1].sum){
				temp = combine[j-1];
				combine[j-1] = combine[j];
				combine[j] = temp;
			}
		}
	}
}