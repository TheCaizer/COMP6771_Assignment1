// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#ifndef COMP6771_WORD_LADDER_HPP
#define COMP6771_WORD_LADDER_HPP

#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

// Function to get a unordered_set of words with a certain length in the lexicon
auto getSmallLexicon(int const& length,
                     std::unordered_set<std::string> const& lexicon)
    ->std::unordered_set<std::string>;
// Function used to comapre two words if there is only only 1 difference in letter or more
auto compareWord(std::string const& firstString, std::string const& secondString)->bool;
// Using breadth first search to find a mapping of all words related to from parameter
// to a vector of words that are 1 letter different from the word and then use a queue to find
// related words to the vector of words generated until no words are realted to each other.
auto BFS_Set(std::string const& from, std::unordered_set<std::string> lexicon)
    ->std::unordered_map<std::string, std::vector <std::string>>;
// using breadth first search of a map of string to vectors that are 1 letter different from the
// string in order to find a ladder to that to parameter
auto BFS_Map(std::string const& from, std::string const& to,
             std::unordered_map<std::string, std::vector <std::string>> mapping)
    -> std::vector<std::vector<std::string>>;

namespace word_ladder {
	[[nodiscard]] auto read_lexicon(std::string const& path) -> std::unordered_set<std::string>;

	// Given a start word and destination word, returns all the shortest possible paths from the
	// start word to the destination, where each word in an individual path is a valid word per the
	// provided lexicon. Pre: ranges::size(from) == ranges::size(to) Pre: valid_words.contains(from)
	// and valid_words.contains(to)
	[[nodiscard]] auto generate(std::string const& from,
	                            std::string const& to,
	                            std::unordered_set<std::string> const& lexicon)
	   -> std::vector<std::vector<std::string>>;
} // namespace word_ladder

#endif // COMP6771_WORD_LADDER_HPP
