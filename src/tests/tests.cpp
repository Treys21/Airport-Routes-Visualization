#include <string>
#include <vector>

#include "../readFromFile.hpp"


TEST_CASE("Verify that file_to_string works on a small example") {
	std::string res = file_to_string("tests/20_airpots.dat");
	// always check "expected" == "actual" --> be consistent
	REQUIRE("1\nGoroka\nPapua New Guinea\nGKA\nAYGA\n" == res);
}

TEST_CASE("Verify that file_to_vector works on a small example") {
	std::vector<std::string> res = file_to_vector("tests/20_airpots.dat");
	std::string expected[] = {"1", "Goroka Airpot", "Goroka", "Papua New Guinea", "GKA", "AYGA"};
	
	REQUIRE(6 == res.size());

	for (int i = 0; i < res.size(); i++) {
		REQUIRE(expected[i] == res[i]);
	}
}