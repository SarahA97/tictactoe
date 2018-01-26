#include <iostream>
#include "Board.h"
using namespace std;

char board[3][3][3];
Player player[2];
int noOfPlayers = 0;


Board::Board(){
	resetBoard();
}

Board::~Board() { //destructor
	cout << "Game has ended";
}

void Board::notifyObservers(){
	while(true){
		for(int i=0;i<noOfPlayers;i++){
			bool validInput = false;
			while(!validInput){
				string input = player[i].update();
				if(input.length()>=4){
					int x = (input.at(0))-49;
					int y = (input.at(2))-49;
					int z = (input.at(4))-49;
					if((x>=0&&x<3)&&(y>=0&&y<3)&&(z>=0&&z<3)){
						cout << x << y << z << endl;
						if(board[x][y][z]=='_'){
							board[x][y][z] = player[i].token;
							drawBoard();
							validInput = true;
							if(checkWin()){
								cout << "player " << player[i].getName() << " wins" << endl;
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

void Board::attachPlayer(Player _player){
	if(noOfPlayers < 2){
		player[noOfPlayers] = _player;
		noOfPlayers ++;
	}
	cout << "player "<< player[noOfPlayers-1].getName() <<" added" << endl;
	return;
}

/* v void Board::detachPlayer(Player _player){
	for(int i = 0; i < noOfPlayers; i++){
		if(player[i].getName()==_player.getName()	){
			//player[i] = NULL;
		}
		cout << "player " << player [i].getName();<< " removed" << endl;
	}
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
					if((board[0][y][z] == board[1][y][z] && board[0][y][z] == board[2][y][z] && board[0][y][z] != '_') || 
						(board[x][0][z] == board[x][1][z] && board[x][0][z] == board[x][2][z] && board[x][0][z] != '_') ||
						(board[x][y][0] == board[x][y][1] && board[x][y][0] == board[x][y][2] && board[x][y][2] != '_')||
						(board[1][1][z] == board[0][0][z] && board[1][1][z] == board[2][2][z] && board[1][1][z] != '_')||
						(board[1][1][z] == board[2][0][z] && board[1][1][z] == board[0][2][z] && board[1][1][z] != '_')||
						(board[1][1][1] == board[0][0][0] && board[1][1][1] == board[2][2][2] && board[1][1][1] != '_')||
						(board[1][1][1] == board[0][2][0] && board[1][1][1] == board[2][0][2] && board[1][1][1] != '_')||
						(board[1][1][1] == board[2][0][0] && board[1][1][1] == board[0][2][2] && board[1][1][1] != '_')||
						(board[1][1][1] == board[2][2][0] && board[1][1][1] == board[0][0][2] && board[1][1][1] != '_')){
						win = true;
					}
				}
			}
		}
	cout << win << endl;
	return win;
}