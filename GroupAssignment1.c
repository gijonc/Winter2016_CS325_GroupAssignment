#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void inflate(int *array, long int size);

int main(){
	//int array[10] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
	double timeElapsed;
	clock_t start, end;
	int array[1000]; 

	inflate(array, 1000);

	start = clock();
	int largest1 = maxArrayWithAlOne(array, 1000);
	end = clock();
	timeElapsed = (end - start);
	///CLOCKS_PER_SEC;
	printf("Time Elapsed: %f\n", timeElapsed);	

	start = clock();
	int largest2 = maxArrayWithAlTwo(array, 1000);
	end = clock();
	timeElapsed = (end - start);
	///CLOCKS_PER_SEC;
	printf("Time Elapsed: %f\n", timeElapsed);	

	printf("Max is %d.\n", largest1);
	printf("Max is %d.\n", largest2);

	return 0;
}

int maxArrayWithAlOne(int *array, long int size){
	int largest = 0;
	int temp = 0;
	int i = 0;			//counter
	int j = 0;
	int z = 0;	
	
	largest = array[0];
	for(; i < size; i++){
		for(j = i + 1; j < size; j++){
			temp = 0;
			for(z = i; z < j; z++){
				temp += array[z]; 
			}
			if(temp > largest)
				largest = temp;		
		}
	}

	return largest;
}

int maxArrayWithAlTwo(int *array, long int size){
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

//random number generator
void inflate(int *array, long int size){
	srand(getpid());
	long int i = 0;
	int temp = 0;
	for(; i < size; i++){
		temp = rand() % 1000;
		temp = temp * pow(-1, temp);
		array[i] = temp;
		//printf("%d,", temp);
	}
}
