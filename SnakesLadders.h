#include <iostream>

typedef struct{
    int x, y;               //this is useful so that i could return coordinates
}coordinate;

class SnakeLadder{          //class declaration
private:
    int board[10][10];
    int player;
public:
    SnakeLadder();                  //default constructor
    void setCell(int x, int y);     //change the position of the player based on the passed coordinate
    int checkWinner();              //checks if winner exists
    int setter(int);                //adjusts the game according to how many players will be there
    int content(int x, int y){return board[x][y];}      //return the content of the passed coordinate
    int setPlayer(int m){player = player%m + 1;}        //sets player
    int getPlayer(){return player;}                     //getter
    coordinate getPos();           //position of the player
};
