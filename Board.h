#include "Subject.h"
#include "Player.h"

class Board : public Subject{
	private:
		int noOfPlayers;

	public:
		Board();
		virtual ~Board();
		void notifyObservers();
		void resetBoard();
		void drawBoard();
		bool checkWin();
		void attachPlayer(Player _player);
		//void detachPlayer(Player _player);
};