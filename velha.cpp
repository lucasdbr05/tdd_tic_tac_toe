#include "velha.hpp"


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





int CheckTicTacToeResult( int hash[3][3] ){
	int x_count = 0;
    int y_count = 0;
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
