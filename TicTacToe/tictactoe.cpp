#include <iostream>
using namespace std;

const int HEIGHT = 7;
const int LENGTH = 13;

void IsThereAWinner(string board[HEIGHT][LENGTH], bool& winnerpX, bool& winnerpO){
	if(board[1][2] == "X" && board[1][6] == "X" && board[1][10] == "X"){
		winnerpX = true;
	}
	else if(board[1][2] == "O" && board[1][6] == "O" && board[1][10] == "O"){
		winnerpO = true;
	}
	else if(board[3][2] == "X" && board[3][6] == "X" && board[3][10] == "X"){
		winnerpX = true;
	}
	else if(board[3][2] == "O" && board[3][6] == "O" && board[3][10] == "O"){
		winnerpO = true;
	}
	else if(board[5][2] == "X" && board[5][6] == "X" && board[5][10] == "X"){
		winnerpX = true;
	}
	else if(board[5][2] == "O" && board[5][6] == "O" && board[5][10] == "O"){
		winnerpO = true;
	}
	else if(board[1][2] == "X" && board[3][2] == "X" && board[5][2] == "X"){
		winnerpX = true;
	}
	else if(board[1][2] == "O" && board[3][2] == "O" && board[5][2] == "O"){
		winnerpO = true;
	}
	else if(board[1][6] == "X" && board[3][6] == "X" && board[5][6] == "X"){
		winnerpX = true;
	}
	else if(board[1][6] == "O" && board[3][6] == "O" && board[5][6] == "O"){
		winnerpO = true;
	}
	else if(board[1][10] == "X" && board[3][10] == "X" && board[5][10] == "X"){
		winnerpX = true;
	}
	else if(board[1][10] == "O" && board[3][10] == "O" && board[5][10] == "O"){
		winnerpO = true;
	}
	else if(board[1][2] == "X" && board[3][6] == "X" && board[5][10] == "X"){
		winnerpX = true;
	}
	else if(board[1][2] == "O" && board[3][6] == "O" && board[5][10] == "O"){
		winnerpO = true;
	}
	else if(board[1][10] == "X" && board[3][6] == "X" && board[5][2] == "X"){
		winnerpX = true;
	}
	else if(board[1][10] == "O" && board[3][6] == "O" && board[5][2] == "O"){
		winnerpO = true;
	}
	else{
		winnerpX = false;
		winnerpO = false;
	}
}

void FixingCoordinates(int& row, int& col){
	if(row == 0 && col == 0){
		row = 1;
		col = 2;
	}
	else if(row == 0 && col == 1){
		row = 1;
		col = 6;
	}
	else if(row == 0 && col == 2){
		row = 1;
		col = 10;
	}
	else if(row == 1 && col == 0){
		row = 3;
		col = 2;
	}
	else if(row == 1 && col == 1){
		row = 3;
		col = 6;
	}
	else if(row == 1 && col == 2){
		row = 3;
		col = 10;
	}
	else if(row == 2 && col == 0){
		row = 5;
		col = 2;
	}
	else if(row == 2 && col == 1){
		row = 5;
		col = 6;
	}
	else if(row == 2 && col == 2){
		row = 5;
		col = 10;
	}
}

void BuildingBoard(string board[HEIGHT][LENGTH], int row, int col, bool& pX, bool& pO){
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < LENGTH; j++){
			if(i % 2 == 0 && (j == 0 || j == 4 || j == 8 || j == 12)){
				board[i][j] = '+';
			}
			else if(i % 2 == 0 && (j != 0 || j != 4 || j != 8 || j != 12)){
				board[i][j] = '-';
			}
			else if(i % 2 != 0 && (j == 0 || j == 4 || j == 8 || j == 12)){
				board[i][j] = '|';
			}
			else if(row == i && col == j){
				if(pX && (board[i][j] == "\0" || board[i][j] == " ")){
					board[i][j] = 'X';
					pX = false;
					pO = true;
				}
				else if(pO && (board[i][j] == "\0" || board[i][j] == " ")){
					board[i][j] = 'O';
					pX = true;
					pO = false;
				}
				else{
					cout << "Cell already filled, please try again" << endl;
					if(pX){
						pX = true;
						pO = false;
					}
					else if(pO){
						pX = false;
						pO = true;
					}
				}
			}
			else if(i % 2 != 0 && (j % 2 != 0 || (j == 2 || j == 6 || j == 10))){
				if(board[i][j] == "\0"){
					board[i][j] = ' ';
				}	
			}
		}
	}
}

void PickingSide(){
	string side;
	cout << "Please enter 'X' or 'O': ";
	cin >> side;
	
	while(1){
		if(side == "X" || side == "x"){
			cout << "You've picked X player's, you start playing" << endl << endl;
			break;
		}
		else if(side == "O" || side == "o"){
			cout << "You've picked O player's, you play after X player's" << endl << endl;
			break;
		}
		else{
			cout << "Wrong input! Please, try again: ";
			cin >> side;
		}
	}
}

int main(){
	cout << "Tic Tac Toe Game!" << endl;
	PickingSide();
	string board[HEIGHT][LENGTH] = {"\0"};
	int row, col, gameCounter = 0;
	bool pX = true, pO, gameOver, winnerpX, winnerpO;
	
	do{
		if(pX){
			cout << "X player's' turn, please enter row and column: ";
			cin >> row >> col;
			FixingCoordinates(row,col);
			BuildingBoard(board,row, col, pX, pO);
			IsThereAWinner(board, winnerpX, winnerpO);
			system("cls");
			for(int i = 0; i < HEIGHT; i++){
				for(int j = 0; j < LENGTH; j++){
					cout << board[i][j];
				}
				cout << endl;
			}
			cout << endl;
			
			if(winnerpX){
				cout << endl;
				cout << "X player's has won!" << endl;
				gameOver = true;
			}
		}
		else if(pO){
			cout << "O player's turn, please enter row and column: ";
			cin >> row >> col;
			FixingCoordinates(row,col);
			BuildingBoard(board, row, col, pX, pO);
			IsThereAWinner(board, winnerpX, winnerpO);
			system("cls");
			for(int i = 0; i < HEIGHT; i++){
				for(int j = 0; j < LENGTH; j++){
					cout << board[i][j];
				}
				cout << endl;
			}
			cout << endl;
			
			if(winnerpO){
				cout << endl;
				cout << "O player's has won!" << endl;
				gameOver = true;
			}
		}
		if(((board[1][2] == "X" || board[1][2] == "O") && (board[1][6] == "X" || board[1][6] == "O") && (board[1][10] == "X" || board[1][10] == "O") &&
		(board[3][2] == "X" || board[3][2] == "O") && (board[3][6] == "X" || board[3][6] == "O") && (board[3][10] == "X" || board[3][10] == "O") &&
		(board[5][2] == "X" || board[5][2] == "O") && (board[5][6] == "X" || board[5][6] == "O") && (board[5][10] == "X" || board[5][10] == "O")) &&
		(!winnerpX && !winnerpO)){
			cout << "Draw!" << endl;
			gameOver = true;
		} 
	}while(!gameOver);
	
	return 0;	
}
