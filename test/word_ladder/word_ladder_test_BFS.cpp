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

/*
This test file is used to test both BFS_Set and BFS_Map to ensure it works normally since lexicon
is such a big file i will make my own sets in order to test it works properly
*/
TEST_CASE("BFS_Set small") {
	std::unordered_set<std::string> lexicon = {"a", "b"};
	std::unordered_map<std::string, std::vector<std::string>> mapping;
	mapping = BFS_Set("a", lexicon);
	std::vector<std::string> b = {"b"};
	CHECK(mapping.size() == 1);
	CHECK(mapping["a"] == b);
}

TEST_CASE("BFS_Set empty") {
	std::unordered_set<std::string> lexicon = {};
	std::unordered_map<std::string, std::vector<std::string>> mapping;
	mapping = BFS_Set("a", lexicon);
	CHECK(mapping.size() == 0);
}

TEST_CASE("BFS_Set Larger") {
	std::unordered_set<std::string> lexicon =
	   {"Hello", "Yello", "Tello", "Yella", "Yelli", "Tella", "Telli"};
	std::unordered_map<std::string, std::vector<std::string>> mapping;
	mapping = BFS_Set("Hello", lexicon);
	CHECK(mapping.size() == 3);
}

TEST_CASE("BFS_Map empty") {
	std::unordered_set<std::string> lexicon = {};
	std::unordered_map<std::string, std::vector<std::string>> mapping;
	mapping = BFS_Set("a", lexicon);
	CHECK(mapping.size() == 0);
	std::vector<std::vector<std::string>> ladders;
	ladders = BFS_Map("a", "b", mapping);
	CHECK(ladders.size() == 0);
}

TEST_CASE("BFS_Map small") {
	std::unordered_set<std::string> lexicon = {"abc", "abd", "cbd", "tbc"};
	std::unordered_map<std::string, std::vector<std::string>> mapping;
	mapping = BFS_Set("abc", lexicon);

	std::vector<std::vector<std::string>> ladders;
	ladders = BFS_Map("abc", "cbd", mapping);
	CHECK(ladders.size() == 1);
}

TEST_CASE("BFS_Map Larger") {
	std::unordered_set<std::string> lexicon =
	   {"Hello", "Yello", "Tello", "Yella", "Yelli", "Tella", "Telli", "Helli"};
	std::unordered_map<std::string, std::vector<std::string>> mapping;
	mapping = BFS_Set("Hello", lexicon);
	CHECK(mapping.size() == 4);

	std::vector<std::vector<std::string>> ladders;
	ladders = BFS_Map("Hello", "Telli", mapping);
	CHECK(ladders.size() == 2);
}