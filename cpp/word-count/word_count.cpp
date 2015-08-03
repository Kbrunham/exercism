#include <string>
#include <map>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>

#include "word_count.h"


std::map<std::string, int> word_count::words(const std::string& str)
{
	std::map<std::string, int> counts;

    // Using a boost tokenizer with punctuation. This overrides the default
    // as it removes single quotes as a valid delimieter
    boost::char_separator<char> sep(" ,!&@$%^&:\n\t.");
    boost::tokenizer<boost::char_separator<char>> tok(str, sep);
	for(auto it = tok.begin(); it != tok.end(); ++it)
	{
		// Convert current string to lower case
		std::string cur_str = *it;
		boost::algorithm::to_lower(cur_str);
        
        // Remove leading and trailing single quote '
        boost::algorithm::trim_if(cur_str, [](char c){return c == '\'';});

        // Remove leading and trailing space
        boost::algorithm::trim(cur_str);

        if (!cur_str.empty())
        {
            // Add the word
            auto cit = counts.find(cur_str);
            if (cit != counts.end())
            {
                cit->second++;
            }
            else
            {
                counts.insert(std::make_pair(cur_str, 1));
            }
        }
	}

	return counts;
}
