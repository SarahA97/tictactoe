
#include <iostream>
using namespace std;

char board[3][3] = {
		{' ',' ',' '},
		{' ',' ',' '},
		{' ',' ',' '},
	};;

void makeBoard(){
	cout << "   " << "---------" << "   " <<  endl;
	cout << " | " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | " << endl;
	cout << " | " << "---------" << " | " << endl;
	cout << " | " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | " << endl;
	cout << " | " << "---------" << " | " <<  endl;
	cout << " | " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << endl;
	cout << "   " << "---------" << "   " <<  endl;
}

bool checkBoard(char xo){
	if(xo == ' '){
		return true;
	}
	else{
		return false;
	}
}

bool getInput(char xo, int input){
	bool x = false;
	switch(input){
		case 1:	if(checkBoard(board[0][0])){
					board[0][0] = xo;
					x = true;
				}
				break;
		case 2:	if(checkBoard(board[0][1])){
					board[0][1] = xo;
					x = true;
				}
				break;
		case 3:	if(checkBoard(board[0][2])){
					board[0][2] = xo;
					x = true;
				}
				break;
		case 4:	if(checkBoard(board[1][0])){
					board[1][0] = xo;
					x = true;
				}
				break;
		case 5:	if(checkBoard(board[1][1])){
					board[1][1] = xo;
					x = true;
				}
				break;
		case 6:	if(checkBoard(board[1][2])){
					board[1][2] = xo;
					x = true;
				}
				break;
		case 7:	if(checkBoard(board[2][0])){
					board[2][0] = xo;
					x = true;
				}
				break;
		case 8:	if(checkBoard(board[2][1])){
					board[2][1] = xo;
					x = true;
				}
				break;
		case 9:	if(checkBoard(board[2][2])){
					board[2][2] = xo;
					x = true;
				}
				break;
		default:break;
	}

	if(!x){
		cout << "Invalid input" << endl;
	}

	return x;
}

bool checkWin(){
	bool win = false;
	cout << board[0][0] << board[0][1] << board[0][2] << endl;
	if((board[0][0]==board[0][1]&& board[0][1]==board[0][2])//||(board[1][0]==board[1][1]==board[1][2]!=' ')
		//||(board[2][0]==board[2][1]==board[2][2]!=' ')||
		//(board[0][0]==board[1][0]==board[2][0]!=' ')||(board[0][1]==board[1][1]==board[2][1]!=' ')||(board[0][2]==board[1][2]==board[2][2]!=' ')||
		//(board[0][0]==board[1][1]==board[2][2]!=' ')||(board[0][2]==board[1][1]==board[2][0]!=' ')
		){
		win = true;
	}
	return win;
}

void startGame(){
	int input;
	while(true){
		while(true){
			cout << "Player 1:  " << endl;
			cin >> input;
			if(getInput('O',input)){
				makeBoard();
				if(checkWin()){
					cout << "player 1 wins" << endl;
				}
				break;
			}
		}
		while(true){
			cout << "Player 2:  " << endl;
			cin >> input;
			if(getInput('X',input)){
				makeBoard();
				if(checkWin()){
					cout << "player 2 wins" << endl;
				}
				break;
			}
		}
	}
}

int main(){
	cout << "Player 1 = O" << endl;
	cout << "Player 2 = X" << endl;
	cout << "Start" << endl;
	makeBoard();
	startGame();
	return 0;
}