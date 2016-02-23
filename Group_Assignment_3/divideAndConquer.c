#include "myLibrary.h"

int main(){
	int array[] = {498671, -159612, 172067, 367095, -450520, 160060, 429766, 95681, 440449, 194774, -294374, 455483, -250387, 488891, -478708, 412076, -135339, -490317, 347356, -250773, -206039, -390013, -221854, -177484, 5339, 366700, -426507, -386674, 80689, -58293, -280145, 195230, 411132, -23406, 173655, -332329, 484655, -342933, -325278, -432448, -426540, -462414, 112604, 319403, 328291, -166122, 122286, -252549, -489098, -13418, 482563, 156249, -251165, -332449, -165171, -125634, 123436, 161417, 495151, -1886, 483228, -25738, 292159, 54856, 211061, 200338, 447276, -371663, -175857, 231851, -405944, -429147, 414150, 437494, -48022, -476189, 413141, -154967, -408523, 63471, -220470, 130745, -25280, -475969, 13469, -167430, -53864, -99891, 116323, 354332, 32683, 132157, -316695, 417480, -319800, 5557, -227929, 74911, -342771, -357566};
	int arrayLength = (int)sizeof(array)/sizeof(int);

	printf("%d unit\n", arrayLength);

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
		//printf("%d\n", combine.closest);
		return combine;
	}else{
		//printf("%d\n", temp.closest);
		return temp;
	}
}

struct closestToZero methodOne(int *array, int start, int end){
	//printf("i = %d, j = %d", start, end);
	int divide;
	struct closestToZero temp, smallest;
	int i, j;
	struct method *suffixSum, *prefixSum;
	divide = (start + end + 1)/2;

	//printf("Divide: %d\n", divide);

	suffixSum = malloc((divide - start)*sizeof(struct method*));
	prefixSum = malloc((end - (divide - 1))*sizeof(struct method*));

	//sum the two arrays
	for(i = divide - 1, j = divide - start - 1; i >= start; i--, j--){
		if(i == divide - 1){
			suffixSum[j].sum = array[i];
			suffixSum[j].position = i;
		}
		else{
			suffixSum[j].sum = suffixSum[j + 1].sum + array[i];
			suffixSum[j].position = i;
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
	//printf(" Smallest from method 1: %d i = %d, j = %d\n", smallest.closest, smallest.i, smallest.j);

	//free(prefixSum);
	//free(suffixSum);

	return smallest;
}

//method 2
struct closestToZero methodTwo(int *array, int start, int end){

	int divide; 
	int sum;
	struct closestToZero temp, smallest;
	int i, j, l, r;
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
	}

	for(i = 0; i < end - (divide - 1); i++){
		if(i == 0){
			prefixSum[i].sum = array[divide + i];
			prefixSum[i].position = divide + i;
		}
		else{
			prefixSum[i].sum = prefixSum[i - 1].sum + array[divide + i];
			prefixSum[i].position = divide + i;
		}
	}

	bubblesort(suffixSum,divide);
	bubblesort(prefixSum,end - (divide - 1));


	l = 0; r = end - divide;
    smallest.closest = prefixSum[r].sum + suffixSum[l].sum;

	while(l < r){
        sum = suffixSum[l].sum + prefixSum[r].sum;
        if(abs(sum) < abs(smallest.closest))
        {
            smallest.closest = sum;
            smallest.i = l;
            smallest.j = r;
        }
        if(sum < 0)
            l++;
        else
            r--;
    }
	printf("%d i:%d j:%d\n", smallest.closest, smallest.i ,smallest.j);
    return smallest;
}

void bubblesort(struct method *arr, int length){
	struct method temp;
	int i, j;
	for(i = 0; i < length-1; i++){
		for(j = 0; j < length-i-1; j++){
			if(arr[j].sum > arr[j+1].sum){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

//method 3
struct closestToZero methodThree(int *array, int start, int end){
	//printf("start: %d, end: %d\n", start, end);
	int divide;
	struct closestToZero temp, smallest;
	int i, j, k;
	struct method *suffixSum, *prefixSum, *combine;
	divide = (start + end + 1)/2;

	//printf("Divide: %d\n", divide);

	suffixSum = malloc((divide - start)*sizeof(struct method));
	prefixSum = malloc((end - (divide - 1))*sizeof(struct method));
	combine = malloc((end - start + 1)*sizeof(struct method));

	//sum the two arrays
	for(i = divide - 1, j = divide - start -1, k = 0; i >= start; i--, j--, k++){
		if(i == divide - 1){
			suffixSum[j].sum = array[i];
			suffixSum[j].position = i;
		}
		else{
			suffixSum[j].sum = suffixSum[j + 1].sum + array[i];
			suffixSum[j].position = i;
		}

		combine[k].sum = suffixSum[j].sum;
		combine[k].position = suffixSum[j].position;
		//printf("%d i = %d ", suffixSum[i].sum, i);
	}

	//printf(" ==> suffixSum\n");

	for(i = 0; i < end - (divide - 1); i++, k++){
		if(i == 0){
			prefixSum[i].sum = array[divide + i];
			prefixSum[i].position = divide + i;
		}
		else{
			prefixSum[i].sum = prefixSum[i - 1].sum + array[divide + i];
			prefixSum[i].position = divide + i;
		}

		prefixSum[i].sum = prefixSum[i].sum;

		combine[k].sum = -prefixSum[i].sum;
		combine[k].position = prefixSum[i].position;
		//printf("%d ", prefixSum[i].sum);
	}

	//printf("==> prefixSum, Combine: ");

	sort(combine, end - start + 1);
	/*for(i = 0; i < end - start + 1; i++){
		printf("%d ", combine[i].sum);
	}
	printf("\n");*/

	smallest.closest = 1000000;

	for(i = 0; i < end - start; i++){
		temp.closest = abs(combine[i].sum - combine[i+1].sum);
		temp.i = combine[i].position;
		temp.j = combine[i+1].position;

		if(temp.closest < smallest.closest){
			smallest = temp;
		}
	}

	//printf("check 1 smallest: %d\n", smallest.closest);

	//free(combine);
	//free(prefixSum);
	//free(suffixSum);

	return smallest;
}

void sort(struct method *combine, int length){
	struct method temp;
	int i, j;

	for(i = 1; i < length; i++){
		for(j = i; j > 0; j--){
			if(combine[j].sum < combine[j-1].sum){
				temp = combine[j-1];
				combine[j-1] = combine[j];
				combine[j] = temp;
			}
		}
	}
}
