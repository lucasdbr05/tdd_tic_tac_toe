#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
  


TEST_CASE( "Empty hash game with undefined result", "[CheckTicTacToeResult]" ) {
	int hash[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };
    REQUIRE(CheckTicTacToeResult(hash) == -1);


} 
 
