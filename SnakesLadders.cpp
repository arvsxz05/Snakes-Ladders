#include "SnakesLadders.h"

SnakeLadder::SnakeLadder(){             //default constructor
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            board[i][j] = 0;
    player = 3;
    board[9][0] = 7;
}

int SnakeLadder::setter(int m){         //adjusts the game according to how many players will be there
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            board[i][j] = 0;
    if(m==2){
        board[9][0] = 4;
        player = 2;
    }
    if(m==3){
        board[9][0] = 7;
        player = 3;
    }
}

void SnakeLadder::setCell(int x, int y){            //change the position of the player based on the passed coordinate
    int i, j, flag=0;
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            if(player == 1)
                if(board[i][j]==1||board[i][j]==4||board[i][j]==5||board[i][j]==7){
                    flag=1;
                    break;
                }
            if(player == 2)
                if(board[i][j]==2||board[i][j]==4||board[i][j]==6||board[i][j]==7){
                    flag=1;
                    break;
                }
            if(player == 3)
                if(board[i][j]==3||board[i][j]==5||board[i][j]==6||board[i][j]==7){
                    flag=1;
                    break;
                }
        }
        if(flag == 1)
            break;
    }
    if(player == 1){
        if(board[i][j] == 1)
            board[i][j] = 0;
        if(board[i][j] == 4)
            board[i][j] = 2;
        if(board[i][j] == 5)
            board[i][j] = 3;
        if(board[i][j] == 7)
            board[i][j] = 6;
        if(board[x][y] == 0)
            board[x][y] = 1;
        if(board[x][y] == 2)
            board[x][y] = 4;
        if(board[x][y] == 3)
            board[x][y] = 5;
        if(board[x][y] == 6)
            board[x][y] = 7;

    }
    if(player == 2){
        if(board[i][j] == 2)
            board[i][j] = 0;
        if(board[i][j] == 4)
            board[i][j] = 1;
        if(board[i][j] == 6)
            board[i][j] = 3;
        if(board[i][j] == 7)
            board[i][j] = 5;
        if(board[x][y] == 0)
            board[x][y] = 2;
        if(board[x][y] == 1)
            board[x][y] = 4;
        if(board[x][y] == 3)
            board[x][y] = 6;
        if(board[x][y] == 5)
            board[x][y] = 7;
    }
    if(player == 3){
        if(board[i][j] == 3)
            board[i][j] = 0;
        if(board[i][j] == 5)
            board[i][j] = 1;
        if(board[i][j] == 6)
            board[i][j] = 2;
        if(board[i][j] == 7)
            board[i][j] = 4;
        if(board[x][y] == 0)
            board[x][y] = 3;
        if(board[x][y] == 1)
            board[x][y] = 5;
        if(board[x][y] == 2)
            board[x][y] = 6;
        if(board[x][y] == 4)
            board[x][y] = 7;
    }
}

int SnakeLadder::checkWinner(){             //checks if winner exists
    if(board[0][0]==1)
        return 1;
    if(board[0][0]==2)
        return 2;
    if(board[0][0]==3)
        return 3;
    else
        return 0;
}

coordinate SnakeLadder::getPos(){               //position of the player
    coordinate xy;
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++){
            xy.x = i;
            xy.y = j;
            if(player == 1)
                if(board[i][j]==1||board[i][j]==4||board[i][j]==5||board[i][j]==7)
                    return xy;
            if(player == 2)
                if(board[i][j]==2||board[i][j]==4||board[i][j]==6||board[i][j]==7)
                    return xy;
            if(player == 3)
                if(board[i][j]==3||board[i][j]==5||board[i][j]==6||board[i][j]==7)
                    return xy;
        }
}

coordinate getCoor(int x, int y, int moves){            //determines where the player would land after 'moves' moves
    coordinate ret;
    if(x!=0){
        if(x%2==0){
            if(y-moves<0){
                ret.x = x - 1;
                ret.y = moves - y - 1;
                return ret;
            }
            else{
                ret.x = x;
                ret.y = y - moves;
                return ret;
            }
        }
        if(x%2==1){
            if(y+moves>9){
                ret.x = x - 1;
                ret.y = 10-(moves-(9-y));
                return ret;
            }
            else{
                ret.x = x;
                ret.y = y + moves;
                return ret;
            }
        }
    }
    else if(x==0){
        if(y-moves>=0)
            y -= moves;
        else if(y-moves<0){
            moves -= y;
            y = moves;
        }
    }
    ret.x = x;
    ret.y = y;
    return ret;
}

coordinate SnaOrLad(coordinate z){          //determines the coordinates with ladder or snake
    if(z.x==9&&z.y==1){
        z.x = 8; z.y = 2;
        return z;
    }
    if(z.x==8&&z.y==9){
        z.x = 6; z.y = 9;
        return z;
    }
    if(z.x==8&&z.y==8){
        z.x = 7; z.y = 7;
        return z;
    }
    if(z.x==7&&z.y==1){
        z.x = 6; z.y = 0;
        return z;
    }
    if(z.x==7&&z.y==0){
        z.x = 8; z.y = 5;
        return z;
    }
    if(z.x==7&&z.y==2){
        z.x = 9; z.y = 5;
        return z;
    }
    if(z.x==7&&z.y==8){
        z.x = 8; z.y = 5;
        return z;
    }
    if(z.x==6&&z.y==4){
        z.x = 3; z.y = 1;
        return z;
    }
    if(z.x==6&&z.y==5){
        z.x = 8; z.y = 2;
        return z;
    }
    if(z.x==5&&z.y==5){
        z.x = 4; z.y = 5;
        return z;
    }
    if(z.x==5&&z.y==6){
        z.x = 6; z.y = 8;
        return z;
    }
    if(z.x==5&&z.y==6){
        z.x = 6; z.y = 8;
        return z;
    }
    if(z.x==5&&z.y==0){
        z.x = 4; z.y = 1;
        return z;
    }
    if(z.x==4&&z.y==8){
        z.x = 6; z.y = 2;
        return z;
    }
    if(z.x==3&&z.y==9){
        z.x = 0; z.y = 6;
        return z;
    }
    if(z.x==2&&z.y==3){
        z.x = 1; z.y = 3;
        return z;
    }
    if(z.x==2&&z.y==9){
        z.x = 6; z.y = 6;
        return z;
    }
    if(z.x==1&&z.y==4){
        z.x = 0; z.y = 3;
        return z;
    }
    if(z.x==1&&z.y==1){
        z.x = 4; z.y = 1;
        return z;
    }
    if(z.x==0&&z.y==5){
        z.x = 2; z.y = 2;
        return z;
    }
    if(z.x==0&&z.y==1){
        z.x = 2; z.y = 1;
        return z;
    }
    return z;
}
