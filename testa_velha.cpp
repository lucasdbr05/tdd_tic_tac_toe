#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
  


TEST_CASE("Empty hash game with undefined result", "[CheckTicTacToeResult]" ) {
	int hash[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };
    REQUIRE(CheckTicTacToeResult(hash) == -1);
} 

TEST_CASE("Impossible game for X and O frequency", "[CheckTicTacToeResult]" ) {
	int hash[3][3] = {
        {1, 2, 1},
        {2, 0, 1},
        {0, 1, 0},
    };
    REQUIRE(CheckTicTacToeResult(hash) == -2);
} 

TEST_CASE("Impossible game for more than one winner", "[CheckTicTacToeResult]" ) {
	int hash[3][3] = {
        {1, 1, 1},
        {2, 2, 2},
        {0, 0, 0},
    };
    REQUIRE(CheckTicTacToeResult(hash) == -2);
} 
 
