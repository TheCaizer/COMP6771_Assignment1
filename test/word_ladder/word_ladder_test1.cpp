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
// Test case given by the school
TEST_CASE("at -> it") {
	auto const english_lexicon = word_ladder::read_lexicon("english.txt");
	auto const ladders = word_ladder::generate("at", "it", english_lexicon);

	CHECK(std::size(ladders) == 1);
	CHECK(std::is_sorted(ladders.begin(), ladders.end()));

	CHECK(std::count(ladders.begin(), ladders.end(), std::vector<std::string>{"at", "it"}) == 1);
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

// Testing function getSmallLexicon to make sure it is getting all the right words in the larger set
TEST_CASE("testing getSmallLexicon"){
    std::unordered_set<std::string> lexicon = {"a", "aaa", "aa", "ab", "ac", "abc", "b"};
    std::string from = "ac";
    auto length = from.size();
    CHECK(length == 2);
	auto const ladders = getSmallLexicon(length, lexicon);
	CHECK(ladders.size() == 3);
	std::unordered_set<std::string> lexiconTest ={"aa", "ab", "ac"};
	CHECK(ladders == lexiconTest);
}
// testing the comapreWord function for smalle words
TEST_CASE("testing comapreWord small"){
    std::string a = "a";
    std::string b = "b";
    CHECK(compareWord(a,b));

    // THIS CASE SHOULD NOT HAPPEN AS WE ONLY HAVE WORDS WITH SAME LENGTH FROM PREVIOUS FUNCTIONS
    a = "AB";
    b = "A";
    CHECK(!(compareWord(a,b)));
}