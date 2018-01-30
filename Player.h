#include <string>
using namespace std;	

class Player{
	private:
		string playerName;
		char token;
	public:
		Player();
		Player(char _token);
		void setName(string name);
		string getName();
		char getToken();
		string update();
};