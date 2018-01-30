#include "Player.h"

class Board{
	private:
		char board[3][3][3];
		Player* playerList[2];
		int noOfPlayers = 0;
		int moveCounter = 0;

	public:
		Board();
		virtual ~Board();
		void notifyObservers();
		void resetBoard();
		void attachPlayer(Player &player);
		void detachPlayer(Player &player);
		void drawBoard();
		bool checkWin();
};