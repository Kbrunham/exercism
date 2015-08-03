#include <string>
#include <map>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

#include "word_count.h"


std::map<std::string, int> word_count::words(const std::string& str)
{
	std::map<std::string, int> counts;


	boost::tokenizer<> tok(str);
	for(auto it = tok.begin(); it != tok.end(); ++it)
	{
		// Add the word
		std::string cur_str = *it;
		boost::algorithm::to_lower(cur_str);

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

	return counts;
}
