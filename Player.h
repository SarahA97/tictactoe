#include "Observer.h"
#include <string>
using namespace std;	

class Player : public Observer{
	private:
		string playerName;
	public:
		Player();
		Player(char token);
		void setName(string name);
		string getName();
		string update();
		char token;
};