#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;
const int N = 10;
int count1 = 0;
float timeEnd;
string drawBoard;


void Draw(int board[N][N]) {
	printf("\n\n");
	for (int i = 0; i < N; i++) {
		printf("\t\t");
		for (int y = 0; y < N; y++) {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 15);
			if (board[i][y] == 1) {
				SetConsoleTextAttribute(hConsole, 12);
				cout << board[i][y] << " ";
			}
			else {
				cout << board[i][y] << " ";
			}
		}
		printf("\n");
	}
	printf("\n\n\n");
}

int RCCheck(int board[N][N], int row, int column) {
	int i, j;
	for (i = 0; i < column; i++) {
		if (board[row][i])
			return false;
	}
	for (i = row, j = column; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j])
			return false;
	}
	for (i = row, j = column; i >= 0 && i < N; i++, j--) {
		if (board[i][j])
			return false;
	}
	return true;
}

int Solve(int board[N][N], int column) {
	if (column >= N)
		return true;
	for (int i = 0; i < N; i++) {
		if (RCCheck(board, i, column)) {
			board[i][column] = 1;
			if (Solve(board, column + 1) == true) {
				if (drawBoard != "false") {
					Draw(board);
				}
				count1++;
			}
			board[i][column] = 0;
		}
	}
}

int SolveBT() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Started!" << endl << endl;
	SetConsoleTextAttribute(hConsole, 15);
	int board[N][N] = { 0 };
	Solve(board, 0);
	return true;
}

int outPut() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (count1 == 0) {
		SetConsoleTextAttribute(hConsole, 12);
		cout << "Solution does not exist" << endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {
		SetConsoleTextAttribute(hConsole, 10);
		cout << "Numbers of solutions : " << count1 << endl << endl;
		Sleep(1000);
		cout << "Found all of the " << N << "*" << N << " board results in - " << timeEnd << " seconds!" << endl << endl;
		Sleep(1000);
		if (drawBoard != "false") {
			SetConsoleTextAttribute(hConsole, 12);
			cout << "For a more accurate result, dont draw the board" << endl;
			Sleep(1000);
		}else {cout << endl;}
		SetConsoleTextAttribute(hConsole, 15);
	}
	return true;
}

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Do you want to draw the " << N << "*" << N << " grid?, please type true / false" << endl;
	SetConsoleTextAttribute(hConsole, 14);
	cin >> drawBoard;
	clock_t time;
	time = clock();
	SolveBT();
	time = clock() - time;
	timeEnd = ((float)time) / CLOCKS_PER_SEC;
	outPut();
	printf("\n");
	SetConsoleTextAttribute(hConsole, 14);
	system("pause");
	return 0;
}
