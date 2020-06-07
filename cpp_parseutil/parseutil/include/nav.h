#ifndef STRINGNAV_H
#define STRINGNAV_H

#include <vector>
#include "trim.h"

namespace parseutil
{
	/// Class for navigating strings using a set delimeter occurrences as stops.
	class Nav
	{
		const std::string m_navString;
		const char m_delimiter;
		size_t m_subStart;
		size_t m_subEnd;

	public:
		/// <summary>Default constructor for Nav</summary>
		/// <param name="string">The string containing delimiters to be navigated</param>
		/// <param name="delimiter">The string character that delimits the string</param>
		Nav(const std::string& string, const char delimiter);

		/// Default destructor for Nav
		~Nav();

		/// <summary>Navigate back to the beggining of the string</summary>
		void reset();

		/// <summary>Counts the delimiters present in the string</summary>
		/// <returns>The number of delimiters</returns>
		int delimiterCount() const;

		/// <summary>Checks if navigating is possible, that is, the last delimiter wasn't yet reached</summary>
		/// <returns>True if it is possible to navigate further</returns>
		bool canNavigate() const;

		/// <summary>Navigate forwards in the string by the amount of times specified</summary>
		/// <param name="count">How many delimiters forward should the navigator go to</param>
		/// <returns>The success of the operation</returns>
		bool navigate(const int count = 1);

		/// <summary>Gets a substring contained wihin the current delimiters the navigator is at</summary>
		/// <param name="stringOut">The reference to an output string</param>
		/// <param name="navigate">If greater than zero, the navigator will attempt to navigate the specified amount of times after the substring is extracted</param>
		/// <param name="trimParam">Enumerator that picks which parts of the output string should have their empty characters trimmed out</param>
		/// <returns>True if the string which was extracted wasn't nothing and the navigation procedure didn't fail</returns>
		bool getSubstring(std::string& stringOut, const int navigate = 0, const char trimParam = TRIM_NONE);

		/// <summary>Get whatever is left from the current delimiter to the end of the initial string</summary>
		/// <param name="stringOut">The reference to an output string</param>
		/// <param name="trimParam">Enumerator that picks which parts of the output string should have their empty characters trimmed out</param>
		/// <returns>True if the string which was extracted wasn't nothing</returns>
		bool getRemains(std::string& stringOut, const char trimParam = TRIM_NONE);

		/// <summary>Get key and value from a string in the format of "key = value", where '=' is the chosen delimiter</summary>
		/// <param name="keyOut">The reference to an output key string</param>
		/// <param name="valueOut">The reference to an output value string</param>
		/// <param name="keyTrim">Enumerator that picks which parts of the output key string should have their empty characters trimmed out</param>
		/// <param name="valueTrim">Enumerator that picks which parts of the output value string should have their empty characters trimmed out</param>
		/// <returns>True if the format was found and extracted, even if one or both the strings are empty</returns>
		bool getKeyValue(std::string& keyOut, std::string& valueOut, const char keyTrim = TRIM_NONE, const char valueTrim = TRIM_NONE);

		/// <summary>Splits all of the substrings enveloped in delimiters and puts them into a string vector</summary>
		/// <param name="ignoreEmpty">Should empty strings be ignored instead of put into the vector</param>
		/// <param name="trimParam">Enumerator that picks which parts of every evalued string should have their empty characters trimmed out</param>
		/// <returns>A string vector that contains the substrings</returns>
		std::vector<std::string> split(const bool ignoreEmpty = true, const char trimParam = TRIM_NONE);
	};
}

#endif
