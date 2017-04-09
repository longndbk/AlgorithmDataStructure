#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//Array store value need to find
int a[9][9];

int I, J;


void process(){
	for(int i = 0; i <= 8; i++){
		for(int j = 0; j <= 8; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("---------------------\n");
	return;
}
//Check number in square I, J 
bool checkSquare(int number){
	for(int ii = 0; ii <= 2; ii++)
		for(int jj = 0; jj <= 2; jj++)
			if(a[3*I + ii][3*J + jj] == number) return false;

		return true;
}
//Chack value at col and row
bool check(int number, int row, int col){
	// Do number check exist in before row?
	for(int i = 0; i <= row - 1; i++)
		if(a[i][col] == number) return false;
	// Do number check exist in before column?
	for(int j = 0; j <= col - 1; j++)
		if(a[row][j] == number) return false;
	//Change big-sudoku to small-sudoku 
	I = row/3;
	J = col/3;
	
	
	if(!checkSquare(number)) return false; // 
	return true;
}
/*
void readFile(char* fileName){
	FILE* f = fopen(fileName, "r");

	for(int i = 1; i <= 9; i++){
		for (int j = 1; j <= 9; j++)
		{
			fscanf(f, "%d\n", &a[i][j]);
		}
	}
}*/
void TRY(int row, int col){
		if(row == 8 && col == 9){
			process();
		}
		else{
			if(col == 9){
				TRY(row + 1, 0);
			}
			else{
				for(int v = 1; v <= 9; v++){
					if(check(v, row, col)){
						int old = a[row][col];
						a[row][col] = v;
						TRY(row, col+1);
						a[row][col] = old;
						}
					}
				}
		
			}	
	}


int main(int argc, char** argv){
	//n = atoi(argv[2]);
	//readFile(argv[3]);
	for (int i = 0; i <= 8; i++)
	{
		for(int j = 0; j <= 8; j++){
			a[i][j] = 0;
		}
	}
	for (int i = 0; i <= 8; i++)
	{
		for(int j = 0; j <= 8; j++){
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	printf("Start! \n");

	TRY(0, 0);
}
