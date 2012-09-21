#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "tuzz/numbered_string.hpp"

TEST_CASE( "tuzz/utility/numbered_string/ctor", "Construction" ) {
	REQUIRE_THROWS_AS(tuzz::numbered_string(""), tuzz::numbered_string_format_error);
	REQUIRE_THROWS_AS(tuzz::numbered_string("fu"), tuzz::numbered_string_format_error);
	REQUIRE_THROWS_AS(tuzz::numbered_string("fu%"), tuzz::numbered_string_format_error);
	REQUIRE_THROWS_AS(tuzz::numbered_string("fu%4"), tuzz::numbered_string_format_error);
	REQUIRE_THROWS_AS(tuzz::numbered_string("fu%-2n"), tuzz::numbered_string_format_error);
	REQUIRE_THROWS_AS(tuzz::numbered_string("fu%0x2n"), tuzz::numbered_string_format_error);
	REQUIRE_THROWS_AS(tuzz::numbered_string("fu%0n"), tuzz::numbered_string_format_error);
	REQUIRE_THROWS_AS(tuzz::numbered_string("fu%20n"), tuzz::numbered_string_format_error);

	REQUIRE_NOTHROW(tuzz::numbered_string ns("%n"));
	REQUIRE_NOTHROW(tuzz::numbered_string ns("%1n"));
	REQUIRE_NOTHROW(tuzz::numbered_string ns("%5n"));
	REQUIRE_NOTHROW(tuzz::numbered_string ns("a%nb"));
	REQUIRE_NOTHROW(tuzz::numbered_string ns("a%3nb"));
}

TEST_CASE( "tuzz/utility/numbered_string/str", "String creation" ) {
	{
		tuzz::numbered_string ns("%2n");
		REQUIRE( ns.str(0) == "00" );
		REQUIRE( ns.str(1) == "01" );
		REQUIRE( ns.str(12) == "12" );
		REQUIRE( ns.str(123) == "123" );
	}

	{
		tuzz::numbered_string ns("fu%2n");
		REQUIRE( ns.str(0) == "fu00" );
		REQUIRE( ns.str(1) == "fu01" );
		REQUIRE( ns.str(12) == "fu12" );
		REQUIRE( ns.str(123) == "fu123" );
	}

	{
		tuzz::numbered_string ns("%2nbar");
		REQUIRE( ns.str(0) == "00bar" );
		REQUIRE( ns.str(1) == "01bar" );
		REQUIRE( ns.str(12) == "12bar" );
		REQUIRE( ns.str(123) == "123bar" );
	}

	{
		tuzz::numbered_string ns("fu%2nbar");
		REQUIRE( ns.str(0) == "fu00bar" );
		REQUIRE( ns.str(1) == "fu01bar" );
		REQUIRE( ns.str(12) == "fu12bar" );
		REQUIRE( ns.str(123) == "fu123bar" );
	}
}


TEST_CASE( "tuzz/utility/numbered_string/nonalpha", "Non alpha characters" ) {
	REQUIRE_NOTHROW(tuzz::numbered_string ns(R"(!@#$^&*()+{}[]_%n_<>,."'\|/)"));
}
