#include <iostream>
#include "Board.h"
using namespace std;

char board[3][3][3];
Player playerList[2];
int noOfPlayers = 0;
int moveCounter = 0;

Board::Board(){ //constructor
	resetBoard();
}

Board::~Board() { //deconstructor
	cout << "Game has ended" << endl;
}

void Board::notifyObservers(){
	while(true){
		for(int i=0;i<2;i++){
			cout << "Enter input as format x,y,z" << endl;
			while(true){
				string input = playerList[i]->update();
				if(input.length()>=4){
					int x = (input.at(0))-49; //-48 for conversion from ascii and -1 for use in array
					int y = (input.at(2))-49;
					int z = (input.at(4))-49;
					if((x>=0&&x<3)&&(y>=0&&y<3)&&(z>=0&&z<3)){ //checks if input is in range
						if(board[x][y][z]=='_'){ //checks if spot if available
							board[x][y][z] = playerList[i]->getToken();
							drawBoard();
							moveCounter++;
							if(checkWin()){
								cout << "player " << playerList[i]->getName() << " wins" << endl;
								return;
							}
							else if(moveCounter==27){ //checks if board is full
								cout << "It's a tie!" << endl;
								return;
							}
						}
						else{
							cout << "Spot taken" << endl; 
						}
					}
					else{
						cout << "Invalid input" << endl;
					}
				}
				else{
					cout << "Invalid input" << endl;
				}
			}
		}
	}
	return;
}

void Board::attachPlayer(Player &player){ //adds player from the game
	if(noOfPlayers < 2){
		playerList[noOfPlayers] = &player;
		noOfPlayers ++;
	}
	cout << "player "<< playerList[noOfPlayers-1]->getName() <<" added" << endl;
	return;
}

void Board::detachPlayer(Player &player){//removes player from the game
	for(int i = 0; i < 2; i++){
		if(playerList[i] == &player){
			playerList[i] = nullptr;
			noOfPlayers--;
		}
	}	
	return;
}

void Board::resetBoard() {
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			for(int k = 0; k<3; k++){
				board[i][j][k] = '_';
			}
		}
	}	
	drawBoard();
	return;
}

void Board::drawBoard() {

	cout << "   x  1  2  3     1  2  3     1  2  3" << endl;
	cout << " y  -----------------------------------" << endl;
	for(int y = 0; y<3; y++){	
		cout << ' ' << y+1;
		for(int z = 0; z<3; z++){
			cout << " | ";
			for(int x = 0; x<3; x++){
				cout  << ' ' << board[x][y][z] << ' ';
			}
		}
		cout << " | "<< endl;
	}
	cout << "    -----------------------------------" << endl;
	cout << "   z     1           2           3   " << endl;
	return;
}

bool Board::checkWin(){
	bool win = false;
		for (int z = 0; z < 3; z++) {
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					if((board[0][y][z] == board[1][y][z] && board[0][y][z] == board[2][y][z] && board[0][y][z] != '_') ||//checks horizontal
						(board[x][0][z] == board[x][1][z] && board[x][0][z] == board[x][2][z] && board[x][0][z] != '_')||//checks vertical
						(board[x][y][0] == board[x][y][1] && board[x][y][0] == board[x][y][2] && board[x][y][2] != '_')||//checks straight on z-axis
						(board[1][1][z] == board[0][0][z] && board[1][1][z] == board[2][2][z] && board[1][1][z] != '_')||//checks diagonally
						(board[1][1][z] == board[2][0][z] && board[1][1][z] == board[0][2][z] && board[1][1][z] != '_')||//checks diagonally
						(board[1][1][1] == board[0][0][0] && board[1][1][1] == board[2][2][2] && board[1][1][1] != '_')||//checks diagonally on z-axis
						(board[1][1][1] == board[0][2][0] && board[1][1][1] == board[2][0][2] && board[1][1][1] != '_')||//checks diagonally on z-axis
						(board[1][1][1] == board[2][0][0] && board[1][1][1] == board[0][2][2] && board[1][1][1] != '_')||//checks diagonally on z-axis
						(board[1][1][1] == board[2][2][0] && board[1][1][1] == board[0][0][2] && board[1][1][1] != '_')){//checks diagonally on z-axis
						win = true;
					}
				}
			}
		}
	return win;
}