#include <iostream>
using namespace std;
const int SIZE = 5;

class Map{
	int difficulty;
	char field[SIZE][SIZE];

   public:
	Map();
	void printField();
	string getField(int);
	int getDifficulty() {return difficulty;}
};

Map::Map(){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(i == 0){
				field[i][j] = '*';
			} else if (i == 4){
				field[i][j] = '+';
			} else {
				field[i][j] = ' ';
			}
		}
	}
}

string Map::getField(int loc){
	string retString = "     ";
	for(int i = 0; i < SIZE; i++){
		retString[i] = field[loc][i];
	}

	return retString;
}

void Map::printField(){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			cout << field[i][j];
		}
		cout << endl;
	}
}
