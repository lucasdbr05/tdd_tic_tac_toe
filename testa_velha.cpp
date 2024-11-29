#include <catch2/catch_test_macros.hpp>
#include "velha.hpp"



TEST_CASE("Empty hash game", "[CheckTicTacToeResult]") {
    int hash[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };
    REQUIRE(CheckTicTacToeResult(hash) == -1);
}



