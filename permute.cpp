#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int a[MAX];
int n;

void process(){
	for(int i = 1; i <= n; i++){
			printf("%d", a[i]);
		}
		printf("\n");
}
bool check(int v,int k){
	for(int i = 1; i < k; i++){
		if(a[i] == v) return false;
	}
	return true;
}
void TRY(int k){
	for(int v = 1; v <= n; v++){
		if(check(v,k)){
			a[k] = v;
			if(k == n)
				process();
			else
				TRY(k+1);
		}
	}
}

int main(int argc, char**argv){
	n = 3;
	TRY(1);
}
