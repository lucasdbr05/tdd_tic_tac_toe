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


// Count the frequency of moves of players in a hash
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


// Check if main diagonal is equal
bool CheckMainDiagonal(int hash[3][3]) {
    return (hash[0][0] == hash[1][1] && hash[1][1] == hash[2][2]);
}

// Check if secondary diagonal is equal
bool CheckSecondaryDiagonal(int hash[3][3]) {
    return (hash[2][0] == hash[1][1] && hash[1][1] == hash[0][2]);
}

// Check if a row is equal
bool CheckRow(int hash[3][3], int row) {
    return (hash[row][0] == hash[row][1] && hash[row][1] == hash[row][2]);
}

// Check if a column is equal
bool CheckColumn(int hash[3][3], int col) {
    return (hash[0][col] == hash[1][col] && hash[1][col] == hash[2][col]);
}

// Check if a player is winner
bool PlayerIsWinner(int hash[3][3], int player) {
    bool flag = false;

    if (CheckMainDiagonal(hash) && hash[1][1] == player) {
        flag = true;
    }
    if (CheckSecondaryDiagonal(hash) && hash[1][1] == player) {
        flag = true;
    }

    for (int i = 0; i < 3; i++) {
        if (CheckRow(hash, i) && hash[i][0] == player) {
            flag = true;
        }
        if (CheckColumn(hash, i) && hash[0][i] == player) {
            flag = true;
        }
    }

    return flag;
}

bool XIsWinner(int hash[3][3]) { return PlayerIsWinner(hash, TileValue::X); }
bool OIsWinner(int hash[3][3]) { return PlayerIsWinner(hash, TileValue::O); }

// Check if the game is tied
bool IsTie(int hash[3][3]) {
    PlayersFrequency frequency = CountPlayersFrequency(hash);

    if ((frequency.x + frequency.o == 9) &&
        !(XIsWinner(hash) || OIsWinner(hash))) {
        return true;
    }

    return false;
}


// Check if the game is impossible
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
