#include <iostream>
#include "Board.h"
using namespace std;

char board[3][3][3];
Player player[2];
int noOfPlayers = 0;


Board::Board(){
	resetBoard();
}

/*Board::~Board() { //destructor
	cout << "Game over";
}*/

void Board::notifyObservers(){
	bool game = true;
	while(game){
		for(int i=0;i<noOfPlayers;i++){
			bool validInput = false;
			while(!validInput){
				string input = player[i].update();
				int x = (input.at(0))-49;
				int y = (input.at(2))-49;
				int z = (input.at(4))-49;
				if((x>=0&&x<3)&&(y>=0&&y<3)&&(z>=0&&z<3)){
					cout << x << y << z << endl;
					if(board[x][y][z]=='_'){
						board[x][y][z] = player[i].token;
						drawBoard();
						validInput = true;
					}
					else{
						cout << "Spot taken" << endl; 
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

void Board::attachPlayer(Player _player){
	if(noOfPlayers < 2){
		player[noOfPlayers] = _player;
		noOfPlayers ++;
	}
	cout << "player "<< player[noOfPlayers-1].getName() <<" added" << endl;
	return;
}

/*void Board::detachPlayer(Player xplayer){
	for(int i = 0; i < noOfPlayers; i++){
		if(3 > 0){
			*player[i] = NULL;
		}
	}
	cout << "player removed" << endl;
	return;
}*/

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
	for(int x = 0; x<3; x++){	
		cout << ' ' << x+1;
		for(int z = 0; z<3; z++){
			cout << " | ";
			for(int y = 0; y<3; y++){
				cout  << ' ' << board[x][y][z] << ' ';
			}
		}
		cout << " | "<< endl;
	}
	cout << "    -----------------------------------" << endl;
	cout << "   z     1           2           3   " << endl;
	return;
}