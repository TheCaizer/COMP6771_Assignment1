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
This file is used to test the smallLexicon function to ensure that it works and returns the right
result to ensure it works by itself and outside of the assignment scope as well as any edge cases.
I want to test edge cases that are uncommon to make sure that it works fine.
*/

// Testing function getSmallLexicon to make sure it is getting all the right words in the larger set
TEST_CASE("testing getSmallLexicon") {
	std::unordered_set<std::string> lexicon = {"a", "aaa", "aa", "ab", "ac", "abc", "b"};
	std::string from = "ac";
	auto length = from.size();
	CHECK(length == 2);
	auto const ladders = getSmallLexicon(length, lexicon);
	CHECK(ladders.size() == 3);
	std::unordered_set<std::string> lexiconTest = {"aa", "ab", "ac"};
	CHECK(ladders == lexiconTest);
}
// testing for negative number
TEST_CASE("test getSmallLexicon negative") {
	std::unordered_set<std::string> lexicon = {"a", "aaa", "aa", "ab", "ac", "abc", "b"};
	std::string from = "ac";
	auto length = -1;
	CHECK(length == -1);
	auto const ladders = getSmallLexicon(length, lexicon);
	CHECK(ladders.size() == 0);
	std::unordered_set<std::string> lexiconTest = {};
	CHECK(ladders == lexiconTest);
}

// testing for zero
TEST_CASE("test getSmallLexicon zero") {
	std::unordered_set<std::string> lexicon = {"a", "aaa", "aa", "ab", "ac", "abc", "b"};
	std::string from;
	auto length = from.size();
	CHECK(length == 0);
	auto const ladders = getSmallLexicon(length, lexicon);
	CHECK(ladders.size() == 0);
	std::unordered_set<std::string> lexiconTest = {};
	CHECK(ladders == lexiconTest);
}

// testing for empty lexicon
TEST_CASE("test getSmallLexicon empty set") {
	std::unordered_set<std::string> lexicon = {};
	std::string from = "abc";
	auto length = from.size();
	CHECK(length == 3);
	auto const ladders = getSmallLexicon(length, lexicon);
	CHECK(ladders.size() == 0);
	std::unordered_set<std::string> lexiconTest = {};
	CHECK(ladders == lexiconTest);
}

// testing for numbers inside the string instead of charcters
TEST_CASE("test getSmallLexicon for numbers") {
	std::unordered_set<std::string> lexicon =
	   {"1", "12", "2", "3", "10", "100", "123", "156", "200", "999"};
	std::string from = "156";
	auto length = from.size();
	CHECK(length == 3);
	auto const ladders = getSmallLexicon(length, lexicon);
	CHECK(ladders.size() == 5);
	std::unordered_set<std::string> lexiconTest = {"100", "123", "156", "200", "999"};
	CHECK(ladders == lexiconTest);
}

// Testting for singular
TEST_CASE("test for from string by itself") {
	std::unordered_set<std::string> lexicon =
	   {"a", "b", "c", "abc", "abcd", "qwert", "asdasdasdjasdsad", "mynameisasadas"};
	std::string from = "abc";
	auto length = from.size();
	CHECK(length == 3);
	auto const ladders = getSmallLexicon(length, lexicon);
	CHECK(ladders.size() == 1);
	std::unordered_set<std::string> lexiconTest = {"abc"};
	CHECK(ladders == lexiconTest);
}
// Testing for 1 other match
TEST_CASE("only 1 other match") {
	std::unordered_set<std::string> lexicon =
	   {"a", "b", "c", "abc", "abcd", "qwert", "asdasdasdjasdsad", "mynameisasadas", "fud"};
	std::string from = "abc";
	auto length = from.size();
	CHECK(length == 3);
	auto const ladders = getSmallLexicon(length, lexicon);
	CHECK(ladders.size() == 2);
	std::unordered_set<std::string> lexiconTest = {"abc", "fud"};
	CHECK(ladders == lexiconTest);
}
// Testing for doesnt exist in the lexicon
TEST_CASE("test for no match") {
	std::unordered_set<std::string> lexicon =
	   {"a", "b", "c", "abc", "abcd", "qwert", "asdasdasdjasdsad", "mynameisasadas", "fud"};
	std::string from = "abcdef";
	auto length = from.size();
	CHECK(length == 6);
	auto const ladders = getSmallLexicon(length, lexicon);
	CHECK(ladders.size() == 0);
	std::unordered_set<std::string> lexiconTest = {};
	CHECK(ladders == lexiconTest);
}
// Testing for a large word
TEST_CASE("test for large word") {
	std::unordered_set<std::string> lexicon = {"abcdefghijklmnopqrstuvwxyz",
	                                           "abcdefghijklmnopqrstuvwxya",
	                                           "abcdefghijklmnopqrstuvwxyd",
	                                           "abcdefghijklmnopqrstuvwxyc",
	                                           "abcdefghijklmnopqrstuvwxyv",
	                                           "abcdefghijklmnopqrstuvwxyb",
	                                           "a"};
	std::string from = "abcdefghijklmnopqrstuvwxyz";
	auto length = from.size();
	CHECK(length == 26);
	auto const ladders = getSmallLexicon(length, lexicon);
	CHECK(ladders.size() == 6);
	std::unordered_set<std::string> lexiconTest = {"abcdefghijklmnopqrstuvwxyz",
	                                               "abcdefghijklmnopqrstuvwxya",
	                                               "abcdefghijklmnopqrstuvwxyd",
	                                               "abcdefghijklmnopqrstuvwxyc",
	                                               "abcdefghijklmnopqrstuvwxyv",
	                                               "abcdefghijklmnopqrstuvwxyb"};
	CHECK(ladders == lexiconTest);
}