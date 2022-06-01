#include <catch.hpp>

#include "Memory.hpp"

TEST_CASE( "initially memory cells are set to 0", "[memory]" ) {
    Memory memory;
    REQUIRE( memory.get() == Memory::MemoryCell{0} );
}

TEST_CASE( "getting after setting gives the same value", "[memory]" ) {
    Memory memory;
    constexpr auto value = 42;
    memory.set(value);
    REQUIRE( memory.get() == value );
}

#if 0
TEST_CASE( "increment", "[memory]" ) {
    Memory memory;
    memory.set(0);
    memory.increment();
    REQUIRE( memory.get() == '1' );
}


TEST_CASE( "decrement", "[memory]" ) {
    Memory memory;
    memory.set(1);
    memory.decrement();
    REQUIRE( memory.get() == '0' );
}


TEST_CASE( "memory position can be moved around", "[memory]" ) {
    Memory memory;
    memory.set(0);
    memory.moveRight();
    memory.set(1);
    REQUIRE( memory.get() == '1' );
    memory.moveLeft();
    REQUIRE( memory.get() == '0' );
}

#endif

SCENARIO( "getting after setting gives the same value", "[memory-scen]" ) {

    GIVEN( "memory and a value" ) {
        Memory memory;
        constexpr auto value = 42;

        WHEN ("we set the value") {
            memory.set(value);

            THEN ( "getting value yields same value" ) {
                REQUIRE( memory.get() == value );
            }
        }
    }
}
