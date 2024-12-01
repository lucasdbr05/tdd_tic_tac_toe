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








int CheckTicTacToeResult( int hash[3][3] ){
    auto frequency = countPlayersFrequency(hash);

    if(abs(frequency.x - frequency.y) > 1) 
        return -2;
    
    bool flag = true;

    if((hash[0][0]==hash[1][1] && hash[1][1]!=hash[2][2]) && hash[0][0] != 0) {
            flag = false;
        }
    if((hash[0][2]==hash[1][1] && hash[1][1]!=hash[2][0]) && hash[0][0] != 0) {
            flag = false;
        }
    for(int i=0; i<3; i++){
        if((hash[i][0]==hash[i][1] && hash[i][1]!=hash[i][2]) && hash[i][0] != 0) {
            flag = false;
        }
        if((hash[0][i]==hash[1][i] && hash[1][i]!=hash[2][i]) && hash[0][i] != 0) {
            flag = false;
        }
    }

    if(flag) return -1;
    return -5; 
}
