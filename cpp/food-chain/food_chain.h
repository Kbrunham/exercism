#include <string>

#define EXERCISM_RUN_ALL_TESTS

namespace food_chain
{
    std::string verse(unsigned int);
    std::string verses(unsigned int, unsigned int);
    inline std::string sing() {return verses(1,8);}
}