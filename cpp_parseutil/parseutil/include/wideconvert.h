#ifndef WIDECONVERT_H
#define WIDECONVERT_H

#include <string>

namespace parseutil
{
	/// <summary>Converts a wide char into a regular char (Possible data loss)</summary>
	/// <param name="wideChar">The wide char to be converted</param>
	/// <returns>A regular char made from the passed wide char, will be '?' if the wide char was out of range for the regular char</returns>
	inline char switchCharWidth(const wchar_t wideChar);

	/// <summary>Converts a regular char into a wide char</summary>
	/// <param name="regChar">The regular char to be converted</param>
	/// <returns>A wide char made from the passed wide char</returns>
	inline wchar_t switchCharWidth(const char regChar);

	/// <summary>Convert an entire wide string into a regular string (Possible data loss)</summary>
	/// <param name="wideStr">The wide string to be converted</param>
	/// <returns>A regular string made from the passed wide string, the chars that were couldn't handle the wide char will be '?'</returns>
	std::string switchStrWidth(const std::wstring& wideStr);
	
	/// <summary>Convert an entire regular string into a wide string</summary>
	/// <param name="regStr">The regular string to be converted</param>
	/// <returns>A wide string made from the passed regular string</returns>
	std::wstring switchStrWidth(const std::string& regStr);
}

#endif