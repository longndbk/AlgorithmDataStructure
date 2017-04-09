all:	dynamic_programming number-perfect binarystring combination permute permute_marked travelling total_S xephau sudoku sudoku-array-mark list sudoku_test


list: list.o
	g++ -o list list.o 
list.o: list.cpp 
	g++ -c list.cpp

sudoku_test: sudoku_test.o 
	g++ -o sudoku_test sudoku_test.o
sudoku_test.o:sudoku_test.cpp 
	g++ -c sudoku_test.cpp

sudoku-array-mark: sudoku-array-mark.o 
	g++ -o sudoku-array-mark sudoku-array-mark.o 
sudoku-array-mark.o: sudoku-array-mark.cpp
	g++ -c sudoku-array-mark.cpp

sudoku: sudoku.o
	g++ -o sudoku sudoku.o
sudoku.o: sudoku.cpp
	g++ -c sudoku.cpp

xephau: xephau.o
	g++ -o xephau xephau.o
xephau.o: xephau.cpp
	g++ -c xephau.cpp
combination: combination.o
	g++ -o combination combination.o
combination.o: combination.cpp
	g++ -c combination.cpp

binarystring: binarystring.o
	g++ -o binarystring binarystring.o

binarystring.o: binarystring.cpp
	g++ -c binarystring.cpp	

number-perfect: number-perfect.o
	g++ -o number-perfect number-perfect.o
number-perfect.o: number-perfect.cpp
	g++ -c number-perfect.cpp
dynamic_programming: dynamic_programming.o
	g++ -o dynamic_programming dynamic_programming.o
dynamic_programming.o: dynamic_programming.cpp
	g++ -c dynamic_programming.cpp
permute: permute.o
	g++ -o permute permute.o
permute.o: permute.cpp
	g++ -c permute.cpp
permute_marked: permute_marked.o
	g++ -o permute_marked permute_marked.o
permute_marked.o: permute_marked.cpp
	g++ -c permute_marked.cpp
travelling: travelling.o
	g++ -o travelling travelling.o
travelling.o: travelling.cpp
	g++ -c travelling.cpp

total_S: total_S.o
	g++ -o total_S total_S.o
total_S.o: total_S.cpp
	g++ -c total_S.cpp


clean:
	rm -f