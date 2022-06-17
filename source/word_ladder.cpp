#include <comp6771/word_ladder.hpp>

namespace word_ladder {

	[[nodiscard]] auto generate(std::string const& from,
	                            std::string const& to,
	                            std::unordered_set<std::string> const& lexicon)
	   -> std::vector<std::vector<std::string>> {
        std::vector<std::vector<std::string>> ret;
        auto length = from.size();
        // Check if no word is passed into the function if so return empty vector
		if(from.empty() or to.empty()){
				return ret;
		}
		// get set of words with same length as from in lexicon
        auto smallLexicon = getSmallLexicon(length, lexicon);
        // get a mapping of all the words that are related to the from word using BFS
        // on smallLexicon set that we have and get words related to those word to try to find to.
        auto const& mapping = BFS_Set(from, smallLexicon);
        // then use the BFS function through the mapping to find to parameter, returns solution
        ret = BFS_Map(from, to, mapping);
        return ret;
	}

} // namespace word_ladder

auto getSmallLexicon(int const& length,
                     std::unordered_set<std::string> const& lexicon)
    ->std::unordered_set<std::string>{
    // return value
    std::unordered_set<std::string> ret;
    // loop through the lexicon and any word with the same size as length is added to set
    for(auto const& i : lexicon){
        if(i.size() == length){
            ret.emplace(i);
        }
    }
    return ret;
}

auto compareWord(std::string const& firstString, std::string const& secondString)->bool{
    if(firstString.size() != secondString.size()){
        return false;
    }
    // counter to check the number of difference in the word
    auto diff = 0;
    auto firstIt = firstString.cbegin();
    auto secondIt = secondString.cbegin();
    // loop until end of string
    while(firstIt != firstString.cend()){
        // if the letter is different then increment the counter
        if(not (diff) and *firstIt != *secondIt){
            diff += 1;
        }
        // if there is already a different letter and another letter is different then return false
        else if(diff and *firstIt != *secondIt){
            return false;
        }
        // increment both iterator
        firstIt += 1;
        secondIt += 1;
    }
    return true;
}

auto BFS_Set(std::string const& from, std::unordered_set<std::string> lexicon)
    ->std::unordered_map<std::string, std::vector <std::string>>{
    // return value
    std::unordered_map<std::string, std::vector<std::string>> ret;
    // the queue to keep track of what need to be searched
    std::queue<std::string> que;
    // push the starting word to the queue to start
    que.push(from);
    // remove the word from the lexicon
    lexicon.erase(from);
    // while the queue is not empty continue looking using BFS
    while(not (que.empty())){
        // set of string to erase from the lexicon every loop
        std::unordered_set<std::string> toErase;
        // the front string of the queue to start looking
        std::string frontString = que.front();
        // remove the front string from the queue
        que.pop();
        // loop through the lexicon
        for(auto const& lexi:lexicon){
            // compare the front string to words in lexicon, if there are only 1 letter difference
            if(compareWord(frontString,lexi)){
                // the mapping of the front word will contain a vector where we add words
                // with 1 letter difference
                ret[frontString].push_back(lexi);
                // push the word with 1 letter difference to the queue as it can be a path
                // to destination word
                que.push(lexi);
                // emplace the lexicon word into the set to erase later
                toErase.emplace(lexi);
                // Was going to erase here but changing the lexicon mid loop is a bad idea
            }
        }
        // loop through the set to erase from lexicon so there are no duplicates or circular ladder
        for(auto const& era:toErase){
            lexicon.erase(era);
        }
    }

    return ret;
}

auto BFS_Map(std::string const& from, std::string const& to,
             std::unordered_map<std::string, std::vector <std::string>> mapping)
    -> std::vector<std::vector<std::string>>{
    // return value
    std::vector<std::vector<std::string>> ret;
    // the queue to keep track of what need to be searched
    std::queue<std::vector<std::string>> que;
    // a single ladder for the lexicon
    std::vector<std::string> ladder;
    // initialize the from string into a vector of strings and add to the queue to start
    std::vector<std::string> initialize;
    initialize.push_back(from);
    que.push(initialize);
    // while the queue is not empty continue looking using BFS
    while(not (que.empty())){
        // set the ladder as the front of the queue and then remove from the queue
        std::vector<std::string> ladder = que.front();
        que.pop();
        // the previous element that was being looked at using BFS in the ladder
        auto const& predecessor = ladder.back();
        // if the predecessor is our destination word then we can add it to the return value as 1
        // complete ladder
        if(predecessor == to){
            ret.push_back(ladder);
        }
        // Since map has only unique keys a count() would just be used to check if predecessor
        // is in the mapping itself
        if(mapping.count(predecessor)){
            // since the predecessor is in the mapping we can use a for loop to go through
            // the string vector that it is mapped to
            for(auto const& word:mapping[predecessor]){
                // for every string in that vector we can make a new ladder, which can be a valid
                // solution by copying the current ladder that leads to this word
                auto newLadder = ladder;
                // we add the string in the vector to the end of the new ladder
                newLadder.push_back(word);
                // then push that new ladder as a vector that needs to use BFS to search for solution
                que.push(newLadder);
            }
        }
    }
    // sort the solution in lexicographical order then return
    sort(ret.begin(), ret.end());
    return ret;
}