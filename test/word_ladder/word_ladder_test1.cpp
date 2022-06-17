//
//  Copyright UNSW Sydney School of Computer Science and Engineering
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#include <comp6771/word_ladder.hpp>

#include <string>
#include <vector>

#include <catch2/catch.hpp>

/* This testing file is used in order to test the main function making sure that it works
for both the lexicon that it is given as well as custom smaller sets to ensure that edge cases are
accounted for. Also making sure that it is returning the right solutions that are in the specs.
Should account for a variety of situation and outside of the assignment should work.
Checking for edges case under the assumption such as:
You can assume that the start word and end word have the same length (i.e. number of characters).
You can assume that both the start and the end word are in the lexicon.
You can assume the start word and the end word will not be the same word
*/


// Test case given by the school
TEST_CASE("at -> it") {
	auto const english_lexicon = word_ladder::read_lexicon("english.txt");
	auto const ladders = word_ladder::generate("at", "it", english_lexicon);

	CHECK(std::size(ladders) == 1);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	CHECK(std::count(ladders.begin(), ladders.end(), std::vector<std::string>{"at", "it"}) == 1);
}

// test a bigger word by writing my own set and have a solution the function should generate
TEST_CASE("weeknights->weekenders"){
    std::unordered_set<std::string> lexicon = {"a", "b", "weeknights", "weekenders", "weekeights",
    "ac","ab","ad","aasdasdasd","weednights","weeknnghts","weekenghts","weekendhts","weekendets"};

	auto const ladders = word_ladder::generate("weeknights", "weekenders", lexicon);

	std::vector<std::string> solution = {"weeknights", "weekeights", "weekenghts","weekendhts",
	"weekendets", "weekenders"};

	CHECK(std::size(ladders) == 1);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	CHECK(std::count(ladders.begin(), ladders.end(), solution) == 1);
}

// Test case for when there shouldn't be a solution
TEST_CASE("abc -> def"){
    std::unordered_set<std::string> lexicon = {"a", "b", "abc", "def", "abf", "zed", "lop", "top"};
    auto const ladders = word_ladder::generate("adc", "def", lexicon);

	CHECK(std::size(ladders) == 0);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));
}

// Checking the check for empty string, makes sure that for every ladder it returns 1 object
// then check that it is sorted as well as the empty vector is returned
// Then check that for if from and to is empty or both is empty same results.
TEST_CASE("empty string"){
    std::unordered_set<std::string> lexicon = {"a", "b"};
    std::string empty1 = {};
    std::string empty2;
    std::string a = "a";
    auto const ladders1 = word_ladder::generate(empty1, empty2, lexicon);
    CHECK(std::size(ladders1) == 0);
	CHECK(std::is_sorted(ladders1.begin(), ladders1.end()));

    auto const ladders2 = word_ladder::generate(empty1, a, lexicon);
    CHECK(std::size(ladders2) == 0);
	CHECK(std::is_sorted(ladders2.begin(), ladders2.end()));

    auto const ladders3 = word_ladder::generate(empty1, a, lexicon);
    CHECK(std::size(ladders3) == 0);
	CHECK(std::is_sorted(ladders3.begin(), ladders3.end()));
}