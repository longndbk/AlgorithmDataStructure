#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef SYMBOL
#define MAX 1000000
#endif
int a[MAX];
int n;
FILE* f;


void generateNumber(int n, char* fileName){
	FILE *f = fopen(fileName, "w");
	//Print number
	fprintf(f, "%d\n", n);
	//Generate n elements
	for(int i = 0; i < n; i++){
		a[i] = 50 - rand() % 100;
		fprintf(f, "%d ", a[i]);
	}
}

void readFile(char* fileName){
	f = fopen(fileName, "r");
	fscanf(f, "%d\n", &n);
	for(int i = 0; i < n; i++){
		fscanf(f, "%d", &a[i]);
	}
	fclose(f);
}

void subTotal(){
	int max = 0;
	for(int i = 0; i < n; i++){
		int s = 0;
		for (int j = i; j < n; j++)
		{
			s += a[j];
			if(s > max){
				max = s;
			}
		}
	}
	printf("%d\n", max);
	fclose(f);
}
//Recursive

int maxLeft(int *a, int i, int j){
	int maxSum = -999999;
	int sum = 0;
	for(int k = j; k > i; k--){
		sum += a[k];
		maxSum < sum ? sum : maxSum; 
	}
	return maxSum;
}
int maxRight(int *a, int i, int j){
	int maxSum = -999999;
	int sum = 0;
	for(int k = i; k <= j; k++){
		sum += a[k];
		maxSum < sum ? sum : maxSum; 
	}
	return maxSum;
}
int maxSub(int *a, int i, int j){
	if(i == j) return a[i];
	else{
		int m = (i + j) / 2;
		int wL = maxSub(a,i,m);
		int wR = maxSub(a,m+1,j);
		int wM = maxLeft(a,i,m) + maxRight(a,m+1,j);
		return wL>wR?(wL>wM?wL:wM):(wR>wM?wR:wM);
	}
}

//Dynamic Programming
void dynamicProgramming(){
	int s = a[0];
	int max = s;
	int k = 0;
	int start = 0;
	int end = 0;
	for(int i = 1; i < n; i++){
		if(s > 0){
			s += a[i];
			//printf("%d", start);
		}
		else{
			s = a[i];
			if(a[i] > 0){
				k = i;
			}
			start = end;
		}

		if(s > max){
			max = s;
			start = k;
			end = i;
		}
	}

	printf("[%d - %d] = %d\n", start, end, max);
	fclose(f);
}
int main(int argc, char** argv){
	clock_t t;
	t = clock();
	//Time time;
	//generateNumber(atoi(argv[1]), argv[2]);

	//time.getEscapedTime();
	
	readFile(argv[1]);
	//the first way
	//subTotal();

	//the second way
	printf("%d\n",maxSub(a,0,10000000));

	//the third way
	//dynamicProgramming();
	t = clock() - t;
	printf("Time = %.5f s\n", (float) t / CLOCKS_PER_SEC);
}