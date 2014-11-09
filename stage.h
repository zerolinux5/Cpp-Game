#ifndef __STAGE_H__
#define __STAGE_H__

const int BOARDSIZE = 10;

class Stage{
	std::string name;
	std::string description;
	std::string board[BOARDSIZE][BOARDSIZE];
   public:
   	Stage(std::string, std::string);
   	std::string getName() {return name;}
   	std::string getDescription() {return description;}
   	std::string getBoardLocation(int x, int y) {return board[x][y];}
   	void printStage();
};

#endif
