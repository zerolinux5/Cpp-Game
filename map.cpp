#include <iostream>
using namespace std;

class Map{
	string mon1;
	string mon2;
	string neutral;
	string player2;
	string player1;
	int difficulty;

   public:
	Map(string, string, string, string, string, int);
	Map();
	string getMon1() { return mon1;}
	string getMon2() {return mon2;}
	string getNeutral() {return neutral;}
	string getPlayer2() {return player2;}
	string getPlayer1() {return player1;}
	int getDifficulty() {return difficulty;}
};

Map::Map(string inM1, string inM2, string inN, string inP2, string inP1, int inD){
	mon1 = inM1;
	mon2 = inM2;
	neutral = inN;
	player2 = inP2;
	player1 = inP1;
	difficulty = inD;
}

Map::Map(){
	mon1 = "*****";
	mon2 = "     ";
	neutral = "     ";
	player2 = "     ";
	player1 = "+++++";
	difficulty = 1;
}
