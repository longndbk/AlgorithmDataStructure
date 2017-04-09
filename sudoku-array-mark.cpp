#include <stdio.h>

bool markcol[9][10], markrow[9][10], marksquare[3][3][10];
int a[8][8];
int I, J;

void process(){
	for(int i = 0; i <= 8; i++){
		for(int j = 0; j <= 8; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("---------------------\n");
}

bool check(int v, int r, int c){
	if(markrow[r][v] == true) return false;
	if(markcol[c][v] == true) return false;
	I = r/3; J = c/3;
	if(marksquare[r][c][v] == true) return false;
	return true;
}

void TRY(int r, int c){
	if(a[r][c] != 0){
		if(r == 8 && c == 8) process();
		else{
			if(c == 8) TRY(r + 1, 0);
			else TRY(r, c + 1);
		}
	}
	else{
		for(int v = 1; v <= 9; v++){
			if(check(v, r, c)){
				a[r][c] = v;
				markrow[r][v] = true;
				markcol[c][v] = true;
				marksquare[r/3][c/3][v] = true;
				if(r == 8 && c == 8){
					process();
					return;
				}	
					
				else{
					if(c == 8) TRY(r + 1, 0);
					else TRY(r, c + 1);
				}
				markrow[r][v] = false;
				markcol[c][v] = false;
				marksquare[r/3][c/3][v] = false;
			}
		}
	}
}

void readData(char* fn){
	FILE* f = fopen(fn, "r");
	for(int i = 0; i <= 8; i++)
		for(int j = 0; j <= 8; j++)
			fscanf(f, "%d", &a[i][j]);
	fclose(f);
}

int main(int argc, char **argv){
	readData("test-case-sudoku.txt");
	TRY(0,0);
}