#include <iostream>
#include <string>
#include "Board.h"
//#include "Player.h"
using namespace std;

int main(){
	string pName;
	Player player1('X');
	Player player2('O');

	cout << "player 1 enter your name: ";
	cin >> pName;
	player1.setName(pName);
	cout << "player 2 enter your name: ";
	cin >> pName;

	player2.setName(pName);

	Board ttts;
	ttts.attachPlayer(player1);
	ttts.attachPlayer(player2);
	ttts.notifyObservers();
	
	return 0;
}