#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

void inflate(int *array, int size);

int main(){
	//*****************************test arrays**************************************
	int array1[] = {-11, 44, 40, -26, -5, 48, 19, -6, 25, 48, -28, 1, 23, -16, 24, 37, 12, -19, -3, -19, -13, 22, -11, 47, -16, -5, 0, 16, 29, -46, 1};
	int array2[] = {-20, 4, -19, 43, -18, 17, 50, 7, 40, -4, 13, 34, 42, -15, -17, -38, -49, 20, -46, -35, -41, -16, 42, 22, 0, -38, 9, 28, 25, 15, -37, 34, 17, -12, 43, 12, -37, -44, -45, 45, -39, 10, -46, -9, 27, 11, -27, -32, -3, 50};
	int array3[] = {-42, 26, 10, -38, 27, 4, 28, -16, 32, -38, -49, -26, 18, -44, 24, -24, -16, 11, 41, 38, -40, 23, -13, -37, -42, 21, 23, 47, -17, 3, -23, 15, 5, 47, -13, -35, 3, 26, -4, 8, 8};
	int array4[] = {-8, 6, 38, 35, 23, 30, 16, -2, -50, -41, -13, -38, 17, -12, -16, -12, 20, -47, -40, -39, 37, -46, 36, 26, 16, 13};
	int array5[] = {34, 36, -37, 23, 23, 8, -2, -15, -36, 5, 44, 21, -42, 17, -14, -30, 37, 21, -16, 18, 49, 36, -36, -8, 38, -40, -14, 40, -4, 0, -35, -34};
	int array6[] = {-50, 31, 25, -12, 13, -20, 46, -12, -32, 44, -25, -50, 16, -5, -30, 25, -25, -34, -6, -28, 4, 6, -41, 6, 44, -50, 5, 18, 44, -39, 9, 28, 2, -12, -2, -21, -39, -17, 1, 27, 22, 41, -20, -27, 36, 46, 43};
	int array7[] = {-46, -35, -15, -50, 45, -6, 19, 25, 25, -5, -50, -31, 49, -25, -30, -21, -11, -48, 9, -27, 32, 3, -9, -41, 20, -45, 22, 47, -33, 6, 40, -30};
	int array8[] = {21, -44, -19, -17, 23, -43, -26, 17, -44, 39, -6, 12, -28, -16, -36, -23, -27, 42, -26, -12, 8, 48, -41, -41, -11, 46, 44, -30, -44, -49, 15, 43, 47, -22};
	int array9[] = {26, -17, 8, -18, 32, 16, -50, -43, 22, -25, -23, 32, 27, -14, -44, -3, 8, -19, 28, -45, -6, 29, 30, -24, -37};
	int array10[] = {-5, -22, -26, -42, -40, -33, 10, 15, -27, 26, 21, 2, 49, 13, 44, 43, 35, 30, 9, 12, 49, -39, 33, 34, 2, 34, -40, -13, 0, 14};
	int array11[] = {36, 40, -8, 28, 38, -38, 24, -33, -27, -18, 26, 9, 9, 38, -35, 11, 36, -17, 20, 45, -9, 27, -24, -27, -28, -25, 41, -46, 29, 27, 34, -28, -44, -6, 26, 42, -16, 40, 27, 14, 22, 37, -26, 46, 21, 45, -40, -25, 5, 50};
	int array12[] = {5, 12, 34, 10, 20, 50, -38, 39, -27, 37, 23, 34, 19, 0, 18, -9, -14, 2, -8, -16, 34, 2};
	int array13[] = {-11, -14, -21, -2, -28, 37, -9, -35, -33, -18, -42, -44, 25, -32, 33, -44, -16, -42, 44, -43, -25, -39, -3, 31, -46, -41, 38, -49, 11, 11, 28, -22, -44};
	int array14[] = {-38, -22, 46, -43, 16, -47, 21, -31, 34, 43, -9, -40, -41, 17, 32, -7, -46, -39, 44, 10, -8, 23, -23, 31, 3, 2, -10, -11, 10};
	int array15[] = {2, -11, -7, 31, -18, 11, 10, 12, 33, -36, -44, 33, 4, 28, 39, 20, 1, 45, 38, -48, -26, 26, 35, 50, 26, -7, -45, -25, -29, 28, -47, -50, 15, 38, -3, -6, -39, 20, 45, 4, -32, 23, 48, 39, 3};
	int array16[] = {-4, 46, -30, 37, 33, 38, 1, -24, -39, 22, 0, 14, -1, 31, 28, -1, 15, 15, 40, 0, 12, 49, 38, -33, 16, -9, -49, 44, 41, -33, -8, -32, -29, -47, 16, 44, -45, 47, -25};
	int array17[] = {47, -5, -6, -22, -2, -37, 37, 21, -45, 3, 7, -42, 24, -12, -12, 15, -3, -12, 1, 29, -47, -1, -30, -31, 23, 28, 23, 38, 39, 42, -5, -4, -31, -31};
	int array18[] = {26, -14, 38, 44, -9, -18, 17, 41, 24, -1, 42, -36, 37, -17, -28, -26, -44, -23, 1, -16, -9, 9, 14, -48, -11, 49, 36, -3, 43, -15, 4, -17, 17, -1, 44, 28, -14, 50, -21, -3, 13, -6, -44, -22, -37, 40, -10};
	int array19[] = {-44, -47, -48, 17, 47, 3, -3, -20, -3, -20, 9, -4, -25, -22, 13, 11, -3, 12, -13, -20, 3};	
	//**************************************************************************

	int *arrays[19] = {array1, array2, array3, array4, array5, array6, array7, array8, array9, array10, array11, array12, array13, array14, array15, array16, array17, array18, array19};

	double timeElapsed;
	clock_t start, end;

	int i;					//counter
	int _arraySize[19];
	_arraySize[0] = elementInArray(sizeof(array1), (int)sizeof(int));
	_arraySize[1] = elementInArray(sizeof(array2), (int)sizeof(int));	
	_arraySize[2] = elementInArray(sizeof(array3), (int)sizeof(int));	
	_arraySize[3] = elementInArray(sizeof(array4), (int)sizeof(int));	
	_arraySize[4] = elementInArray(sizeof(array5), (int)sizeof(int));	
	_arraySize[5] = elementInArray(sizeof(array6), (int)sizeof(int));	
	_arraySize[6] = elementInArray(sizeof(array7), (int)sizeof(int));	
	_arraySize[7] = elementInArray(sizeof(array8), (int)sizeof(int));	
	_arraySize[8] = elementInArray(sizeof(array9), (int)sizeof(int));	
	_arraySize[9] = elementInArray(sizeof(array10), (int)sizeof(int));	
	_arraySize[10] = elementInArray(sizeof(array11), (int)sizeof(int));	
	_arraySize[11] = elementInArray(sizeof(array12), (int)sizeof(int));	
	_arraySize[12] = elementInArray(sizeof(array13), (int)sizeof(int));	
	_arraySize[13] = elementInArray(sizeof(array14), (int)sizeof(int));	
	_arraySize[14] = elementInArray(sizeof(array15), (int)sizeof(int));	
	_arraySize[15] = elementInArray(sizeof(array16), (int)sizeof(int));	
	_arraySize[16] = elementInArray(sizeof(array17), (int)sizeof(int));	
	_arraySize[17] = elementInArray(sizeof(array18), (int)sizeof(int));		
	_arraySize[18] = elementInArray(sizeof(array19), (int)sizeof(int));	

	FILE *fp = fopen("results.txt", "w");
	if(fp != NULL)
		fprintf(fp, "Algorithm 1: ");
	else{
		printf("Fail to create file\n");
		return 1;
	}
	//algorithm 1
	for(i = 0; i < 19; i++){
		start = clock();
		int largest1 = maxArrayWithAlOne(arrays[i], _arraySize[i]);
		end = clock();
		timeElapsed = (end - start) * 1000 /CLOCKS_PER_SEC;	
		fprintf(fp, "%d ", largest1);
	}
	fprintf(fp, "\n");

	//algorithm 2
	fprintf(fp, "Algorithm 2: ");
	for(i = 0; i < 19; i++){
		start = clock();
		int largest2 = maxArrayWithAlTwo(arrays[i], _arraySize[i]);
		end = clock();
		timeElapsed = (end - start) * 1000 / CLOCKS_PER_SEC;
		fprintf(fp, "%d ", largest2);
	}
	fprintf(fp, "\n");

	//algorithm 3
	fprintf(fp, "Algorithm 3: ");
	for(i = 0; i < 19; i++){
		start = clock();
		int mid = _arraySize[i] / 2;
		int largest3 = Max(maxArrayWithAlThree(arrays[i], 0, mid), 
					maxArrayWithAlThree(arrays[i], mid + 1, _arraySize[i] - 1), 
					crossSum(arrays[i], 0, mid, _arraySize[i] - 1));
		end = clock();
		timeElapsed = (end - start) * 1000 / CLOCKS_PER_SEC;
		fprintf(fp, "%d ", largest3);
	}
	fprintf(fp, "\n");
	close(fp);

	return 0;
}

int maxArrayWithAlOne(int *array, int size){
	int largest = 0;
	int temp = 0;
	int i, j, z;			//counter	
	
	largest = array[0];
	for(i = 0; i < size; i++){
		for(j = i; j < size; j++){
			temp = 0;
			for(z = i; z <= j; z++){
				temp += array[z]; 
			}
			if(temp > largest)
				largest = temp;		
		}
	}                            

	return largest;
}

int maxArrayWithAlTwo(int *array, int size){
	int largest = 0;
	int temp = 0;
	int i = 0;			//counter
	int j = 0;

	largest = array[0];
	for(i = 0; i < size; i++){
		temp = array[i];
		if(temp > largest)
			largest = temp;
		for(j = i + 1; j < size; j++){
			temp = temp + array[j];
			if(temp > largest)
				largest = temp;
		} 
	}

	return largest;
}

int maxArrayWithAlThree(int *array, int start, int end){
	if(start == (end - 1)){
		return Max(array[start], array[end], array[start] + array[end]);
	}

	if(start == end)
		return array[start];

	int mid = (start + end) / 2;

	int left = maxArrayWithAlThree(array, start, mid);
	int right = maxArrayWithAlThree(array, mid + 1, end);

	return Max(left, right, crossSum(array, start, mid, end));
}

int crossSum(int *array, int start, int mid, int end){
	int i;			//counter
	int sum;
	int largestLeft = array[mid];
	int largestRight = array[mid + 1];

	//left side
	for(i = mid, sum = 0; i >= start; i--){
		sum += array[i];
		if(sum > largestLeft) largestLeft = sum;
	}

	//right side
	for(i = mid + 1, sum = 0; i <= end; i++){
		sum += array[i];
		if(sum > largestRight) largestRight = sum;
	}

	return (largestLeft + largestRight);
}

//compare 3 numbers and return the biggest
int Max(int a, int b, int c){
	int temp = 0;
	if(a > b) temp = a;
	else temp = b;

	if(temp < c) temp = c;

	return temp;
}

//random number generator
void inflate(int *array, int size){
	srand(getpid());
	long int i = 0;
	int temp = 0;
	for(; i < size; i++){
		temp = rand() % 1000;
		temp = temp * pow(-1, temp);
		array[i] = temp;
		//printf("%d ", temp);
	}
	//printf("\n");
}

int elementInArray(int totalSize, int elementSize){
	return (totalSize / elementSize);
}
