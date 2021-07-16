#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int *arrange(int[], const int, int);
int make_index(const int);

int main(){

	srand(time(0));

	const int SIZE = rand() % 20 + 2;
	int A[SIZE];
	int index = make_index(SIZE);

	printf("xxxxxxxxxxxx\n");
	printf("size = %d\n", SIZE);
	printf("xxxxxxxxxxxx\n");
	printf("generating random array:\n");

	for (int j = 0; j < SIZE; j++){
		A[j] = rand() % 20;
	}
	printf("xxxxxxxxxxxx\n");
	printf("index %d\n", index);
	printf("pivot number %d\n", A[index]);
	printf("xxxxxxxxxxxx\n");
	printf("original array:\n");
	for (int j = 0; j < SIZE; j++){
		printf("%d ", A[j]);
	}
	printf("\nmodified array:\n");
	int *ptr = arrange(A, SIZE, index);
	for(int i = 0; i < SIZE; i++){
		printf("%d ", ptr[i]);
	}
	printf("\n");
	//ptr = NULL;
	free(ptr);

	return 0;
}

int *arrange(int A[], const int SIZE, int index){
	int *B;
	B = (int *) malloc(SIZE * sizeof(int));
	int a = 0, b = SIZE - 1; //a = start of array, b = end of array
	for (int i = 0; i < SIZE; i++){
		B[i] = A[index];
	}
	for(int i = 0; i < SIZE; i++){
		if (A[i] < A[index]){
			B[a] = A[i];
			a++;
		}
		else if ( A[i] > A[index]){
			B[b] = A[i];
			b--;
		}
		else{
			continue;
		}
	}
	return B;
}

int make_index(const int SIZE){
	int index = rand();
	while(!(index >= 0 && index < SIZE) ){
		index = index % SIZE;
	}
	return index;
}
