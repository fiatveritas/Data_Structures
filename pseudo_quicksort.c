#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int *quicksort(int[], int);
int *arrange(int[], const int, int);
int exchange(int, int);
int make_index(const int);

int main(){

	srand(time(0));

	const int SIZE = rand() % 20 + 2;
	int A[SIZE];
	int index = make_index(SIZE);

	printf("xxxxxxxxxxxx\n");
	printf("size = %d\n", SIZE);
	printf("xxxxxxxxxxxx\n");

	for (int j = 0; j < SIZE; j++){
		A[j] = rand() % 20;
		printf("%d ", A[j]);
	}

	printf("\nxxxxxxxxxxxx\n");
	printf("index %d\n", index);
	printf("pivot number %d\n", A[index]);
	//printf("xxxxxxxxxxxx\n");
	int *sorted;
	sorted = quicksort(A, index);
	//printf("%d \t %u \n", *sorted, sorted);
	printf("xxxxxxxxxxxx\n");
	int *ptr = arrange(A, SIZE, index);
	for(int i = 0; i < SIZE; i++){
		printf("%d ", ptr[i]);
	}
	ptr = NULL;
	sorted = NULL;

	return 0;
}

int *quicksort(int A[], int index){
	return &A[index];
}

int *arrange(int A[], const int SIZE, int index){
	int *B;
	B = (int *) malloc(SIZE * sizeof(int));
	int a = 0, b = SIZE - 1; //a = start of array, b = end of array
	for (int i = 0; i < SIZE; i++){
		B[i] = A[index];
		//printf("%d\n", B[i]);
		//printf("xxxxxxxxxxxx\n");
	}
	for(int i = 0; i < SIZE; i++){
		//code here
		if (A[i] < A[index]){
			B[a] = A[i];
			//printf("B less%d\n", B[a]);
			a++;
		}
		else if ( A[i] > A[index]){
			B[b] = A[i];
			//printf("B greater%d\n", B[b]);
			b--;
		}
		else{
			continue;
		}
	}
	return B;
}

int exchange(int a, int b){
	if (a < b){
		return a;
	}
	else if (a > b){
		return b;
	}
	else{
		return a;
	}
}

int make_index(const int SIZE){
	int index = rand();
	while(!(index >= 0 && index < SIZE) ){
		index = index % SIZE;
	}
	return index;
}
