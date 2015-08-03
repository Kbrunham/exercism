#include <string>

#include "hamming.h"


unsigned int hamming::compute(const std::string& str1, const std::string& str2)
{
    unsigned int dist = 0;
    
    if (str1.length() != str2.length())
    {
        throw std::domain_error("String length not equal");
    }
    else
    {
        // Iterate over the string and count differences
        for (int i = 0; i < str1.length(); i++)
        {
            if (str1[i] != str2[i])
            {
                dist++;
            }
        }
    }
    
    return dist;
}
