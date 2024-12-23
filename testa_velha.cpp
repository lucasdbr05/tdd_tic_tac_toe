#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Impossible game for X and O frequency", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {1, 2, 1},
        {2, 0, 1},
        {0, 1, 0},
    };

    REQUIRE(CheckTicTacToeResult(hash) == -2);
}

TEST_CASE("Impossible game for frequency greater than winner",
          "[CheckTicTacToeResult]") {
    int hash1[3][3] = {
        {1, 2, 0},
        {2, 1, 0},
        {2, 2, 1},
    };
    int hash2[3][3] = {
        {2, 1, 0},
        {1, 2, 0},
        {1, 1, 2},
    };
    
    REQUIRE(CheckTicTacToeResult(hash1) == -2);
    REQUIRE(CheckTicTacToeResult(hash2) == -2);
}

TEST_CASE("Impossible game for more than one winner",
          "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {1, 1, 1},
        {2, 2, 2},
        {0, 0, 0},
    };

    REQUIRE(CheckTicTacToeResult(hash) == -2);
}

TEST_CASE("X winner game by diagonal", "[CheckTicTacToeResult]") {
    int hash1[3][3] = {
        {1, 0, 0},
        {2, 1, 2},
        {0, 0, 1},
    };
    int hash2[3][3] = {
        {1, 2, 1},
        {2, 1, 2},
        {1, 0, 0},
    };

    REQUIRE(CheckTicTacToeResult(hash1) == 1);
    REQUIRE(CheckTicTacToeResult(hash2) == 1);
}

TEST_CASE("X winner game by row", "[CheckTicTacToeResult]") {
    int hash1[3][3] = {
        {2, 0, 0},
        {1, 1, 1},
        {0, 0, 2},
    };
    int hash2[3][3] = {
        {1, 1, 1},
        {2, 0, 0},
        {0, 0, 2},
    };
    int hash3[3][3] = {
        {2, 0, 0},
        {0, 0, 2},
        {1, 1, 1},
    };

    REQUIRE(CheckTicTacToeResult(hash1) == 1);
    REQUIRE(CheckTicTacToeResult(hash2) == 1);
    REQUIRE(CheckTicTacToeResult(hash3) == 1);
}

TEST_CASE("X winner game by column", "[CheckTicTacToeResult]") {
    int hash1[3][3] = {
        {1, 0, 0},
        {1, 2, 2},
        {1, 0, 0},
    };
    int hash2[3][3] = {
        {0, 1, 0},
        {2, 1, 2},
        {0, 1, 0},
    };
    int hash3[3][3] = {
        {0, 0, 1,},
        {2, 2, 1,},
        {0, 0, 1,},
    };

    REQUIRE(CheckTicTacToeResult(hash1) == 1);
    REQUIRE(CheckTicTacToeResult(hash2) == 1);
    REQUIRE(CheckTicTacToeResult(hash3) == 1);
}

TEST_CASE("O winner game by diagonal", "[CheckTicTacToeResult]") {
    int hash1[3][3] = {
        {2, 0, 0},
        {1, 2, 1},
        {0, 0, 2},
    };
    int hash2[3][3] = {
        {0, 0, 2},
        {1, 2, 1},
        {2, 0, 1},
    };

    REQUIRE(CheckTicTacToeResult(hash1) == 2);
    REQUIRE(CheckTicTacToeResult(hash2) == 2);
}

TEST_CASE("O winner game by row", "[CheckTicTacToeResult]") {
    int hash1[3][3] = {
        {2, 2, 2},
        {1, 1, 0},
        {0, 1, 0},
    };
    int hash2[3][3] = {
        {1, 1, 0},
        {2, 2, 2},
        {0, 1, 0},
    };
    int hash3[3][3] = {
        {1, 1, 0},
        {0, 1, 0},
        {2, 2, 2},
    };

    REQUIRE(CheckTicTacToeResult(hash1) == 2);
    REQUIRE(CheckTicTacToeResult(hash2) == 2);
    REQUIRE(CheckTicTacToeResult(hash3) == 2);
}

TEST_CASE("O winner game by column", "[CheckTicTacToeResult]") {
    int hash1[3][3] = {
        {1, 2, 0},
        {1, 2, 1},
        {2, 2, 0},
    };
    int hash2[3][3] = {
        {2, 1, 0},
        {2, 1, 1},
        {2, 2, 0},
    };
    int hash3[3][3] = {
        {1, 0, 2,},
        {1, 1, 2,},
        {2, 0, 2,},
    };

    REQUIRE(CheckTicTacToeResult(hash1) == 2);
    REQUIRE(CheckTicTacToeResult(hash2) == 2);
    REQUIRE(CheckTicTacToeResult(hash3) == 2);
}

TEST_CASE("Tie game", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {1, 2, 1},
        {2, 2, 1},
        {1, 1, 2},
    };

    REQUIRE(CheckTicTacToeResult(hash) == 0);
}

TEST_CASE("Empty hash game with undefined result", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };

    REQUIRE(CheckTicTacToeResult(hash) == -1);
}

TEST_CASE("Hash game with undefined result", "[CheckTicTacToeResult]") {
    int hash1[3][3] = {
        {1, 1, 2},
        {0, 2, 0},
        {1, 0, 0},
    };
    int hash2[3][3] = {
        {2, 1, 2},
        {1, 2, 0},
        {1, 2, 1},
    };
    int hash3[3][3] = {
        {1, 2, 1},
        {1, 1, 0},
        {2, 0, 2},
    };

    REQUIRE(CheckTicTacToeResult(hash1) == -1);
    REQUIRE(CheckTicTacToeResult(hash2) == -1);
    REQUIRE(CheckTicTacToeResult(hash3) == -1);
}