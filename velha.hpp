#ifndef VELHA_HPP_
#define VELHA_HPP_

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

int CheckTicTacToeResult(int hash[3][3]);

PlayersFrequency CountPlayersFrequency(int hash[3][3]);

bool CheckMainDiagonal(int hash[3][3]);

bool CheckSecondaryDiagonal(int hash[3][3]);

bool CheckRow(int hash[3][3], int row);

bool CheckColumn(int hash[3][3], int column);


bool PlayerIsWinner(int hash[3][3], int player);

bool XIsWinner(int hash[3][3]);

bool OIsWinner(int hash[3][3]);

bool IsTie(int hash[3][3]);

bool IsImpossibleGame(int hash);

#endif  // VELHA_HPP_
