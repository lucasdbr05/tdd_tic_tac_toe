#include "velha.hpp"

#include <math.h>

/**
 * @brief Count the frequency of moves of players in a hash
 * @param  hash data about the game situation
 */
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

/**
 * @brief if main diagonal is equal
 * @param  hash data about the game situation
 */
bool CheckMainDiagonal(int hash[3][3]) {
    return (hash[0][0] == hash[1][1] && hash[1][1] == hash[2][2]);
}

/**
 * @brief Check if secondary diagonal is equal
 * @param  hash data about the game situation
 */
bool CheckSecondaryDiagonal(int hash[3][3]) {
    return (hash[2][0] == hash[1][1] && hash[1][1] == hash[0][2]);
}

/**
 * @brief  Check if a row is equal
 * @param  hash data about the game situation
 * @param  row current checked row
 */
bool CheckRow(int hash[3][3], int row) {
    return (hash[row][0] == hash[row][1] && hash[row][1] == hash[row][2]);
}

/**
 * @brief  Check if a column is equal
 * @param  hash data about the game situation
 * @param  col current checked column
 */
bool CheckColumn(int hash[3][3], int col) {
    return (hash[0][col] == hash[1][col] && hash[1][col] == hash[2][col]);
}

/**
 * @brief  Check if a player is the winner
 * @param  hash data about the game situation
 * @param  player 1 if player is 'X', 2 if player is 'O'
 */
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

/**
 * @brief  Check if X is the winner
 * @param  hash data about the game situation
 */
bool XIsWinner(int hash[3][3]) { return PlayerIsWinner(hash, TileValue::X); }

/**
 * @brief  Check if O is the winner
 * @param  hash data about the game situation
 */
bool OIsWinner(int hash[3][3]) { return PlayerIsWinner(hash, TileValue::O); }

/**
 * @brief Check if the game is tied
 * @param  hash data about the game situation
 */
bool IsTie(int hash[3][3]) {
    PlayersFrequency frequency = CountPlayersFrequency(hash);

    if ((frequency.x + frequency.o == 9) &&
        !(XIsWinner(hash) || OIsWinner(hash))) {
        return true;
    }

    return false;
}

/**
 * @brief Check if the game is impossible
 * @param  hash data about the game situation
 */
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

/**
 * @brief Check what is the game result for a given hash
 * @param  hash data about the game situation
 */
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
