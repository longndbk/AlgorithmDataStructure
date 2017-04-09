#include <stdio.h>
#include <stdlib.h>


int n;
int c[100][100];
FILE *f;
int tour[100];
int temp[100];
int cost = 0;
int a = 1;
bool marked[100];


void readFile(char* fileName){
	f = fopen(fileName, "r");
	fscanf(f, "%d\n", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			fscanf(f, "%d", &c[i][j]);
		}
	}
}

void process(){
	int s = 0;
	for(int i = 1; i < n; i++){
		s += c[temp[i]][temp[i+1]];
	}
	s += c[temp[n]][1];

	if(s < cost || a == 1){
		cost = s;
		for(int i = 1; i <= n; i++){
			tour[i] = temp[i];
		}
	}
}

void Result(){
	printf("1 ->");
	for(int i = 2; i <=n; i++){
		printf("%d -> ", tour[i]);
	}
	printf("1\n");
	printf("Cost: %d\n", cost);
}

void TRY(int k){
	for(int v = 2; v <= n; v++){
		if(!marked[v]){
			temp[k] = v;
			marked[v] = true;
			if(k == n) process();
			else
				TRY(k+1);
			marked[v] = false;
		}
	}
}

int main(int argc, char** argv)
{ 
	readFile(argv[1]);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	temp[1] = 1;
	for(int i = 0; i <= n; i++){
		marked[i] = false;
	}
	TRY(2);
	Result();
	return 0;
}
