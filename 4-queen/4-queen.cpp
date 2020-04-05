#include<iostream>
#include<stdlib.h>
using namespace std;

#define N 4

int board[N][N];
int solution = 1;

//function to print board
void Display(){
	int i, j;
	printf("Solusi %d\n", solution);
	solution++;
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			//printf("%d ", board[i][j]);
			//if row is the same with the mark then
			//that's where the queen placed
			if(board[i][j] == i){
				printf("1 ");
			}
			else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}
    
void Mark(int row, int t, int initial, int mrow){
	int i;
	board[row][t] = mrow;
	for(i = row; i <= N; i++){
		//diagonal left
		if(t-(i-row) > 0){
			if(board[i][t-(i-row)] == initial){
				board[i][t-(i-row)] = mrow;
			}
		}
		//every column
		if(board[i][t] == initial){
			board[i][t] = mrow;
		}
		//diagonal right
		if(t+(i-row) < N+2){
			if(board[i][t+(i-row)] == initial){
				board[i][t+(i-row)] = mrow;
			}
		}
	}
}

void Solve(int row){
	int i, j, k;
	if(row == N+1){
		Display();
		cin.get();
		return;
	}
	for(i = 1; i <= N; i++){
		if(board[row][i] == 0){
			Mark(row, i, 0, row);
			bool place = false;
			for(j = row + 1; j <= N; j++){
				place = true;
				for(k = 1; k <= N; k++){
					if(board[j][k]==0){
						place = false;
					}
				}
				if(place){ //if queen can't put in this row
					break;
				}
			}
			if(!place){ //if queen can be put in this row and column
				Solve(row+1);
			}
			Mark(row, i, row, 0);
		}
	}
}
int main(){
	//4-queen
	board[4][4]={0};
	Solve(1);
}
