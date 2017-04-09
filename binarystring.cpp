#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int a[MAX];
int b[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int n;
int T;
/*
void process(){
	for(int i = 1; i <= n; i++){
		printf("%d", a[i]);
	}
	printf("\n");
}
*/
void process(){
	int t = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 1){
			t += b[i];
		}
	}
	if(t == T){
		for(int i = 1; i <= n; i++){
			if(a[i] == 1)
				printf("%d", b[i]);
		}
		printf("\n");
	}
}
void TRY(int k){
	int v;
	for(v = 0; v <= 1; v++){
		a[k] = v;
		if(k == n){
			process();
		}
		else
			TRY(k+1);
	}
}

int main(int argc, char** argv){
	n = atoi(argv[1]);
	T = atoi(argv[2]);
	TRY(1);
}