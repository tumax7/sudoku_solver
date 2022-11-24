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


// To Do
void detect_0_pos(int sudoku[9][9]){
	
	for (int i=0; i<9; i++){
		for (int j=0;j<9;j++){
			cout<<sudoku[i][j]<<' ';
			
			}
			cout <<'\n';
		}
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
	return 0;
}
