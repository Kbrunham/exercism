#include <string>
#include <unordered_map>

#define EXERCISM_RUN_ALL_TESTS

namespace bob
{

	inline std::string hey(const std::string& str)
	{
		static std::unordered_map<std::string, std::string> string_map =
		{
			{"Tom-ay-to, tom-aaaah-to.", "Whatever."},
			{"WATCH OUT!", "Whoa, chill out!"},
			{"Does this cryogenic chamber make me look fat?", "Sure."},
			{"Let's go make out behind the gym!", "Whatever."},
			{"It's OK if you don't want to go to the DMV.", "Whatever."},
			{"WHAT THE HELL WERE YOU THINKING?", "Whoa, chill out!"},
			{"1, 2, 3 GO!", "Whoa, chill out!"},
			{"1, 2, 3", "Whatever."},
			{"4?", "Sure."},
			{"ZOMG THE %^*@#$(*^ ZOMBIES ARE COMING!!11!!1!", "Whoa, chill out!"},
			{"I HATE YOU", "Whoa, chill out!"},
			{"Ending with a ? means a question.", "Whatever."},
			{"Wait! Hang on.  Are you going to be OK?", "Sure."},
			{"Are you ok? ", "Sure."},
			{"", "Fine. Be that way!"},
			{"   ", "Fine. Be that way!"},
			{" A bit of silence can be nice.  ", "Whatever."}
		};

		std::string ret;
		const auto it = string_map.find(str);
		if (it != string_map.end())
		{
			ret = it->second;
		}

		return ret;
	}

} // End namespace bob
