#include <string>
#include <vector>

#define EXERCISM_RUN_ALL_TESTS

namespace anagram
{
    class finder
    {
        public:
            explicit finder(const std::string& in_word);
            finder() = delete;
            ~finder() = default;
        
            // Find the matches for the input word in the dictionary
            std::vector<std::string> matches(const std::vector<std::string>& dict);
        
        private:
            std::string m_sorted_word;
            std::string m_original_word;
    };
    
    inline finder anagram(const std::string& instr)
    {
        return finder(instr);
    }
}

