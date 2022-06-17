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

// testing the comapreWord function for small words
TEST_CASE("testing compareWord small") {
	std::string a = "a";
	std::string b = "b";
	CHECK(compareWord(a, b));
	CHECK(!compareWord("abc", "dec"));
	CHECK(compareWord("aec", "dec"));
	// THIS CASE SHOULD NOT HAPPEN AS WE ONLY HAVE WORDS WITH SAME LENGTH FROM PREVIOUS FUNCTIONS
	a = "AB";
	b = "A";
	CHECK(!(compareWord(a, b)));
}
// Test empty string
TEST_CASE("compareWord empty string") {
	CHECK(compareWord("", ""));
	CHECK(compareWord(" ", " "));
}
// Test for numbers instead of letters
TEST_CASE("compareWord numbers") {
	CHECK(compareWord("123", "124"));
	CHECK(!compareWord("12345", "12409"));
	CHECK(compareWord("1", "2"));
}
// Test for same word
TEST_CASE("compareWord same word") {
	CHECK(compareWord("a", "a"));
	CHECK(compareWord("abc", "abc"));
}
// Test for space in the word
TEST_CASE("compareWord with space in word") {
	std::string a = "my name is bob";
	std::string b = "my name is boa";
	CHECK(compareWord(a, b));
	a = "      b";
	b = "      a";
	CHECK(compareWord(a, b));
	a = "      ba";
	b = "      a ";
	CHECK(!compareWord(a, b));
	a = "hello     ";
	b = "h e l l o ";
	CHECK(!compareWord(a, b));
}
// Test for larger words
TEST_CASE("compareWord large word") {
	std::string a = "abcdefghijklmnopqrstuvwxyzasdasdasdsdfjndsajfnds;jkafjioewgiovknsdcuvharusifh";
	std::string b = "abcdefghijklmnopqrstuvwxyzasdasdbsdsdfjndsajfnds;jkafjioewgiovknsdcuvharusifh";
	CHECK(compareWord(a, b));
	a = "abcdefghijklmnmpqrstuvwxyzasdasdasdsdfjndsajfnds;jkafjioewgiovknsdcuvsarusifh";
	b = "abcdefghijklmnopqrstuvwxyzasdasdbsdsdfjndsajfnds;jkafjioewgiovknsdcuvharusifh";
	CHECK(!compareWord(a, b));
}