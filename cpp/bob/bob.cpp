#include <string>
#include <algorithm>
#include "bob.h"

namespace
{
	bool is_question(const std::string& str)
	{
        // Find the last non-whitespace character and see if it is a question mark
        auto it = std::find_if(str.rbegin(), str.rend(), [](char c){return !std::isspace(c);});
		return ((it != str.rend()) && (*it == '?'));
    }

	bool is_yelling(const std::string& str)
	{
        // Yelling is any non empty string that contains all uppercase letters and no lower case letters.
        // We could use regexp here, but it has more overhead
        return (!str.empty() && (str.find_first_of(std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), 1) != std::string::npos) && (str.find_first_of(std::string("abcdefghijklmnopqrstuvwxyz"), 1) == std::string::npos));
	}

	bool is_not_saying_anything(const std::string& str)
	{
        // Not saying anything is empty or whitespace text
        return (std::find_if(str.begin(), str.end(), [](char c){return !std::isspace(c);}) == str.end());
	}
}


std::string bob::hey(const std::string& str)
{
	/*
	Bob answers 'Sure.' if you ask him a question.
	He answers 'Whoa, chill out!' if you yell at him.
	He says 'Fine. Be that way!' if you address him without actually saying anything.
	He answers 'Whatever.' to anything else.
	*/

	if (is_yelling(str))
	{
		return "Whoa, chill out!";
	}
	else if (is_not_saying_anything(str))
	{
		return "Fine. Be that way!";
	}
    else if (is_question(str))
    {
        return "Sure.";
    }
	else
	{
		return "Whatever.";
	}
}