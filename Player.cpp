#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

string playerName;
char token = '_';

Player::Player(){
}

Player::Player(char token){
	this->token = token;
}

void Player::setName(string name){
	playerName = name;
	return;
}

string Player::getName(){
	return playerName;
}

string Player::update(){
	string input;
	cout << playerName << "'s turn" << endl;
	cin >> input;
	return input;
}