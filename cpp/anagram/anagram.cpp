#include <string>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>

#include "anagram.h"

// Constructor
anagram::finder::finder(const std::string& in_word) :
    m_sorted_word(in_word),
    m_original_word(in_word)
{
    boost::algorithm::to_lower(m_original_word);

    // Create the key for the anagrams. This is the lexagraphically sorted and lower case
    // version of the input word.
    boost::algorithm::to_lower(m_sorted_word);
    std::sort(m_sorted_word.begin(), m_sorted_word.end());
}


// Find the matches for the input word in the dictionary
std::vector<std::string> anagram::finder::matches(const std::vector<std::string>& dict)
{
    std::vector<std::string> res;
    
    // iterate through the dictionary vector and return all matches
    for (const auto& word : dict)
    {
        // It is an anagram if the lexagrapically sorted and lower case
        // version of the dictionary word matches the same operation on the
        // original input word.
        if (word.length() == m_sorted_word.length())
        {
            std::string sorted_word = word;
            boost::algorithm::to_lower(sorted_word);
            
            // Initial check for self
            if (sorted_word != m_original_word)
            {
                std::sort(sorted_word.begin(), sorted_word.end());
                if (sorted_word == m_sorted_word)
                {
                    res.emplace_back(word);
                }
            }
        }
    }
    
    
    return res;
}
