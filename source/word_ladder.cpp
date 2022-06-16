#include <comp6771/word_ladder.hpp>

namespace word_ladder {

	[[nodiscard]] auto generate(std::string const& from,
	                            std::string const& to,
	                            std::unordered_set<std::string> const& lexicon)
	   -> std::vector<std::vector<std::string>> {
        std::vector<std::vector<std::string>> ret = {};
        auto length = from.size();
        // Check if no word is passed into the function if so return empty vector
		if(from.empty() || to.empty()){
				return ret;
		}
		// get set of words with same length in lexicon
        auto smallLexicon = getSmallLexicon(length, lexicon);
        std::cout <<"starting: "<< from << std::endl;
        for(auto i:smallLexicon){
        std::cout << i << std::endl;
        }
        return ret;
	}

} // namespace word_ladder

// Function to get a unordered_set of words with a certain length in the lexicon
auto getSmallLexicon(int const& length,
                     std::unordered_set<std::string> const& lexicon)
    ->std::unordered_set<std::string>{
    std::unordered_set<std::string> ret = {};
    for(auto const& i : lexicon){
        if(i.size() == length){
            ret.emplace(i);
        }
    }
    return ret;
}