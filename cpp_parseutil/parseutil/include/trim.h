#ifndef STRINGTRIM_H
#define STRINGTRIM_H

#include <string>

namespace parseutil
{
	enum TrimParam
	{
		TRIM_NONE = 0,
		TRIM_LEFT = (1 << 0),
		TRIM_RIGHT = (1 << 1),
		TRIM_ALL = TRIM_LEFT | TRIM_RIGHT
	};

	// Trims a string from the select trimParam side from the selected trimChars character array.
	std::string& trim(std::string& stringRef, const unsigned char trimParam = TRIM_ALL, const char* trimChars = "\t\n\v\f\r ");

}

#endif
