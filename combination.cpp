#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int a[MAX];
int n;
int k;

void process(){
		for(int i = 1; i <= k; i++){
			printf("%d", a[i]);
		}
		printf("\n");
}
void TRY(int i){
	int v;
	for(v = a[i-1] + 1; v <= n-k+i; v++){
		a[i] = v;
		if(i == k){
			process();
		}
		else
			TRY(i+1);
	}
}

int main(int argc, char** argv){
	k = atoi(argv[1]);
	n = atoi(argv[2]);
	if(k > n){
		printf("Do not exist combination\n" );
	}
	else
		TRY(1);
}