#ifndef __STAGE_H__
#define __STAGE_H__

const int BOARDSIZE = 10;

class Stage{
	std::string name;
	std::string description;
	std::string board[BOARDSIZE][BOARDSIZE];
	int stageSet;
   public:
   	Stage(std::string, std::string, int);
   	std::string getName() {return name;}
   	std::string getDescription() {return description;}
   	std::string getBoardLocation(int y, int x) {return board[y][x];}
   	void printStage();
};

#endif
