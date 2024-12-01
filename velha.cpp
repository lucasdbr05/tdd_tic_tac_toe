#include "velha.hpp"
#include <math.h>

enum Value {
    EMPTY = 0,
    X = 1,
    O = 2,
};

enum GameResult {
    IMPOSSIBLE = -2,
    UNDEFINED = -1,
    TIE = 0,
    X_WIN = 1,
    O_WIN = 2,
};


struct PlayersFrequency
{
    int x = 0;
    int y = 0;
};


PlayersFrequency countPlayersFrequency(int hash[3][3]){
    PlayersFrequency frequency;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            frequency.x += (hash[i][j]==1);
            frequency.y += (hash[i][j]==2);
        }
    }

    return frequency;
}

bool playerIsWinner(int hash[3][3], int player) {
    bool flag = false;

    if((hash[0][0]==hash[1][1] && hash[1][1]==hash[2][2]) && hash[1][1] == player) {
        flag = true;
    }
    if((hash[0][2]==hash[1][1] && hash[1][1]==hash[2][0]) && hash[1][1] == player) {
        flag = true;
    }

    for(int i=0; i<3; i++){
        if((hash[i][0]==hash[i][1] && hash[i][1]==hash[i][2]) && hash[i][0] == player) {
            flag = true;
        }
        if((hash[0][i]==hash[1][i] && hash[1][i]==hash[2][i]) && hash[0][i] == player) {
            flag = true;
        }
    }

    return flag;
}



bool XIsWinner(int hash[3][3]){
    return playerIsWinner(hash, 1);
}
bool OIsWinner(int hash[3][3]){
    return playerIsWinner(hash, 2);
}

bool isTie(int hash[3][3]){
    auto frequency = countPlayersFrequency(hash);

    if((frequency.x + frequency.y == 9) && !(XIsWinner(hash) || OIsWinner(hash)))
        return true;

    return false;
}

bool isImpossibleGame(int hash[3][3]){
    auto frequency = countPlayersFrequency(hash);

    if(abs(frequency.x - frequency.y) > 1) 
        return true;

    if(XIsWinner(hash) && OIsWinner(hash))
        return true;

    if(XIsWinner(hash) and (frequency.y > frequency.x))
        return true;

    if(OIsWinner(hash) and (frequency.x > frequency.y))
        return true;

    return false;
}





int CheckTicTacToeResult(int hash[3][3] ){
    if(isImpossibleGame(hash)){
        return -2;
    }

    if(isTie(hash)){
        return 0;
    }

    if(XIsWinner(hash)) {
        return 1;
    }
    if(OIsWinner(hash)) {
        return 2;
    }

    return -1;
}
