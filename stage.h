#ifndef __STAGE_H__
#define __STAGE_H__

const int BOARDSIZE = 10;
const int OBSTACLENUMBER = 10;

class Stage{
	std::string name;
	std::string description;
	std::string board[BOARDSIZE][BOARDSIZE];
	int stageSet;
	void addObstacles(std::string, unsigned int);
	int clasify(int, int);
	int relocate(std::string, int, int);
   public:
   	Stage(std::string, std::string, int, unsigned int);
   	std::string getName() {return name;}
   	std::string getDescription() {return description;}
   	std::string getBoardLocation(int y, int x) {return (((x < BOARDSIZE) && (y < BOARDSIZE)) ? board[y][x] : "NULL");}
   	void printStage();
};

#endif
