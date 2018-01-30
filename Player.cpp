#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

string playerName;
char token;

Player::Player(){
}

Player::Player(char _token){
	token = _token;
}

void Player::setName(string name){
	playerName = name;
	return;
}

string Player::getName(){
	return playerName;
}

char Player::getToken(){
	return token;
}

string Player::update(){
	string input;
	cout << playerName << "'s turn: ";
	cin >> input;
	return input;
}