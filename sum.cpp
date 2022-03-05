#include "catch.hpp"

int sum(int x, int y){
    return x + y;
}
TEST_CASE( "computing sums", "[sum]" ) {
    REQUIRE( sum(1,1) == 2 );
    REQUIRE( sum(2,2) == 4 );
   
}

