#ifndef STRINGNAV_H
#define STRINGNAV_H

#include <vector>
#include "trim.h"

namespace parseutil
{
	// Class for navigating strings using a set delimeter occurrences as stops.
	class Nav
	{
		const std::string m_navString;
		const char m_delimiter;
		size_t m_subStart;
		size_t m_subEnd;

	public:
		Nav(const std::string& string, const char delimiter);
		~Nav();

		void reset();
		int delimiterCount() const;
		bool canNavigate() const;
		bool navigate(const int count = 1);
		bool getSubstring(std::string& stringOut, const int navigate = 0, const char trimParam = TRIM_NONE);
		std::vector<std::string> split(const bool ignoreEmpty = true, const char trimParam = TRIM_NONE);
	};
}

#endif
