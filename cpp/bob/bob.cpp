#include <string>
#include <boost/regex.hpp>

#include "bob.h"

namespace
{
	bool is_question(const std::string& str)
	{
        // Match any string ending with a question mark
        static const boost::regex e(".+\\?\\s*");
        return (!str.empty() && boost::regex_match(str, e));
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
        return (str.empty() || (str.find_first_not_of(" ") == std::string::npos));
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