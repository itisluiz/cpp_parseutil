#ifndef WIDECONVERT_H
#define WIDECONVERT_H

#include <string>

namespace parseutil
{
	// Converts a wide character into a regular character. (Possible data loss)
	inline char switchCharWidth(const wchar_t wideChar);
	// Converts a regular character into a wide character.
	inline wchar_t switchCharWidth(const char regChar);

	// Converts a wide string into a regular string. (Possible data loss)
	std::string switchStrWidth(const std::wstring& wideStr);
	// Converts a regular string into a wide string.
	std::wstring switchStrWidth(const std::string& regStr);
}

#endif