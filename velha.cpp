#include "velha.hpp"

#include <math.h>

enum TileValue {
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

struct PlayersFrequency {
    int x = 0;
    int o = 0;
};

PlayersFrequency CountPlayersFrequency(int hash[3][3]) {
    PlayersFrequency frequency;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            frequency.x += (hash[i][j] == TileValue::X);
            frequency.o += (hash[i][j] == TileValue::O);
        }
    }

    return frequency;
}

bool PlayerIsWinner(int hash[3][3], int player) {
    bool flag = false;

    if ((hash[0][0] == hash[1][1] && hash[1][1] == hash[2][2]) &&
        hash[1][1] == player) {
        flag = true;
    }
    if ((hash[0][2] == hash[1][1] && hash[1][1] == hash[2][0]) &&
        hash[1][1] == player) {
        flag = true;
    }

    for (int i = 0; i < 3; i++) {
        if ((hash[i][0] == hash[i][1] && hash[i][1] == hash[i][2]) &&
            hash[i][0] == player) {
            flag = true;
        }
        if ((hash[0][i] == hash[1][i] && hash[1][i] == hash[2][i]) &&
            hash[0][i] == player) {
            flag = true;
        }
    }

    return flag;
}

bool XIsWinner(int hash[3][3]) { return PlayerIsWinner(hash, TileValue::X); }
bool OIsWinner(int hash[3][3]) { return PlayerIsWinner(hash, TileValue::O); }

bool IsTie(int hash[3][3]) {
    auto frequency = CountPlayersFrequency(hash);

    if ((frequency.x + frequency.o == 9) &&
        !(XIsWinner(hash) || OIsWinner(hash))) {
        return true;
    }

    return false;
}

bool IsImpossibleGame(int hash[3][3]) {
    auto frequency = CountPlayersFrequency(hash);

    if (abs(frequency.x - frequency.o) > 1) {
        return true;
    }

    if (XIsWinner(hash) && OIsWinner(hash)) {
        return true;
    }

    if (XIsWinner(hash) && (frequency.o > frequency.x)) {
        return true;
    }

    if (OIsWinner(hash) && (frequency.x > frequency.o)) {
        return true;
    }

    return false;
}



int CheckTicTacToeResult(int hash[3][3]) {
    if (IsImpossibleGame(hash)) {
        return GameResult::IMPOSSIBLE;
    }

    if (IsTie(hash)) {
        return GameResult::TIE;
    }

    if (XIsWinner(hash)) {
        return GameResult::X_WIN;
    }
    if (OIsWinner(hash)) {
        return GameResult::O_WIN;
    }

    return GameResult::UNDEFINED;
}
