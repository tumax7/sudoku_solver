#include <iostream>
using namespace std;

//struct coordinates int 

void print_sudoku(int sudoku[9][9]){
	
	for (int i=0; i<9; i++){
		for (int j=0;j<9;j++){
			cout<<sudoku[i][j]<<' ';
			
			}
			cout <<'\n';
		}
	}


bool solved(int sudoku[9][9]){
	int total_row = 0;
	int total_col = 0;
	int total_sq = 0;

	for (int i = 0;i<9;i++){
		total_row = 0;
		total_col = 0;
		for (int j = 0;j<9;j++){
			
			total_row += sudoku[i][j];
			total_col += sudoku[j][i];
			}		
		if (total_row!=45||total_col!=45){
			return false;
			}
		
	}

	for (int l=0;l<7;l=l+3){
		for (int k=0;k<7;k=k+3){
			total_sq=0;
			for (int i = l;i<l+3; i++){
				for (int j = k;j<k+3;j++){
					total_sq += sudoku[i][j];
					}
				}
			if (total_sq!=45){
				return false;
				}
		}
	}
	return true;
}

bool possible_value_position(int sudoku[9][9], int row,int col,int val){

	// Check row
	for (int i=0;i<9;i++){
		if (sudoku[row][i]==val){
			return false;
		}
	}
	// Check col
	for (int i=0;i<9;i++){
		if (sudoku[i][col]==val){
			return false;
		}
	}

	//Check square
	for (int i=(row - row%3);i<(row-row%3+3);i++){
		for (int j=(col - col%3);j<(col-col%3+3);j++){
			if (sudoku[i][j]==val){
				return false;
			}
		}
	}
	return true;
}

bool solve(int sudoku[9][9],int row, int col){

	//End case
	if (row==8&&col==9){
		return true;		
	}

	//Roll over to next row
	if (col==9){
		col=0;
		row +=1; 
	}

	// If not empty continue

	if (sudoku[row][col]>0){
		return solve(sudoku,row,col+1);
	}

	// Start solving
	for (int i=1; i<=9; i++){
		if (possible_value_position(sudoku,row,col,i)){
			sudoku[row][col] = i;

			if (solve(sudoku,row,col+1)){
				return true;
			}
		}
		sudoku[row][col] = 0;
	}
	
	return false;
}


int main(){
	int sudoku[9][9] = {{7,2,6,4,9,3,8,1,5},
		            {3,1,5,7,2,8,9,4,6},
	                    {4,8,9,6,5,1,2,3,7},
			    {8,5,2,1,4,7,6,9,3},
			    {6,7,3,9,8,5,1,2,4},
		            {9,4,1,3,6,2,7,5,8},
	                    {1,9,4,8,3,6,5,7,2},
			    {5,6,7,2,1,4,3,8,9},
			    {2,0,8,5,7,9,4,6,1}};
	print_sudoku(sudoku);
	cout << solved(sudoku)<< '\n';
	solve(sudoku,0,0);
	print_sudoku(sudoku);
	cout << solved(sudoku)<< '\n';
	return 0;
}
