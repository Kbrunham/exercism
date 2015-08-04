#include <string>
#include <stdexcept>

#include "hamming.h"


size_t hamming::compute(const std::string& str1, const std::string& str2)
{
	size_t dist = 0;
    
    if (str1.length() != str2.length())
    {
        throw std::domain_error("String length not equal");
    }
    else
    {
        // Iterate over the string and count differences
        for (size_t i = 0; i < str1.length(); i++)
        {
            if (str1[i] != str2[i])
            {
                dist++;
            }
        }
    }
    
    return dist;
}