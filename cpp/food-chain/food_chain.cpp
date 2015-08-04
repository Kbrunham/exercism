#include <string>
#include <vector>
#include <stdexcept>

#include "food_chain.h"

namespace
{
    static int max_verse = 8;

    static std::vector<std::string> first_sentence =
    {
        "fly.\n",
        "spider.\nIt wriggled and jiggled and tickled inside her.\n",
        "bird.\nHow absurd to swallow a bird!\n",
        "cat.\nImagine that, to swallow a cat!\n",
        "dog.\nWhat a hog, to swallow a dog!\n",
        "goat.\nJust opened her throat and swallowed a goat!\n",
        "cow.\nI don't know how she swallowed a cow!\n",
        "horse.\nShe's dead, of course!\n",
    };
    
    static std::vector<std::string> second_sentence =
    {
        "I don't know why she swallowed the fly. Perhaps she'll die.\n",
        "She swallowed the spider to catch the fly.\n",
        "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n",
        "She swallowed the cat to catch the bird.\n",
        "She swallowed the dog to catch the cat.\n",
        "She swallowed the goat to catch the dog.\n",
        "She swallowed the cow to catch the goat.\n",
    };
}

std::string food_chain::verse(unsigned int verse_num)
{
    if ((verse_num == 0) || (verse_num > max_verse))
    {
        throw std::domain_error("Illegal verse num");
    }
    
    // Construct the verse starting with the constart starting phrase,
    // then the animal and first sentence.
    std::string verse_str = std::string("I know an old lady who swallowed a ") + first_sentence[verse_num-1];
    // Add all other required sentences
    for (int i = verse_num-1; (i >=0) && (verse_num < max_verse); i--)
    {
        verse_str += second_sentence[i];
    }
    
    return verse_str;
}

std::string food_chain::verses(unsigned int start_verse, unsigned int end_verse)
{
    std::string verse_str;
    
    for (int i = start_verse; i <= end_verse; i++)
    {
        verse_str += verse(i) += "\n";
    }
    
    return verse_str;
}
