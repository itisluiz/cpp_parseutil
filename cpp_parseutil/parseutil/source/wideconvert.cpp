#include "..\include\wideconvert.h"

namespace parseutil
{
	inline char switchCharWidth(const wchar_t wideChar)
	{
		if (wideChar > 255) // Not ascii
			return '?';

		return static_cast<char>(wideChar);
	}

	inline wchar_t switchCharWidth(const char regChar)
	{
		const wchar_t wideChar(regChar); // Allocate a new variable, casting could result in returing garbage
		return wideChar;
	}

	std::string switchStrWidth(const std::wstring& wideStr)
	{
		std::string regStr;
		regStr.reserve(wideStr.length());

		for (const wchar_t& wideChar : wideStr)
			regStr.push_back(switchCharWidth(wideChar));

		return regStr;
	}

	std::wstring switchStrWidth(const std::string& regStr)
	{
		std::wstring wideStr;
		wideStr.reserve(regStr.length());

		for (const char& regChar : regStr)
			wideStr.push_back(switchCharWidth(regChar));

		return wideStr;
	}
}