#ifndef STRINGTRIM_H
#define STRINGTRIM_H

#include <string>

namespace parseutil
{
	/// Enum containing trim parameters  
	enum TrimParam
	{
		TRIM_NONE = 0,
		TRIM_LEFT = (1 << 0),
		TRIM_RIGHT = (1 << 1),
		TRIM_ALL = TRIM_LEFT | TRIM_RIGHT
	};

	/// <summary>Trim specified characters from strings by the left, right or both sides</summary>
	/// <param name="stringRef">The input string reference which will be trimmed</param>
	/// <param name="trimParam">Enumerator that picks which parts of the output string should have their empty characters trimmed out</param>
	/// <param name="trimChars">Character array of characters that should be trimmed off</param>
	/// <returns>The string parameter that was passed in</returns>
	std::string& trim(std::string& stringRef, const unsigned char trimParam = TRIM_ALL, const char* trimChars = "\t\n\v\f\r ");

}

#endif
