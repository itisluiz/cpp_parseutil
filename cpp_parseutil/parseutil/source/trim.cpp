#include "..\include\trim.h"

namespace parseutil
{
	std::string& trim(std::string& stringRef, const unsigned char trimParam, const char* trimChars)
	{
		if (trimParam & TRIM_LEFT && !stringRef.empty())
			stringRef.erase(0, stringRef.find_first_not_of(trimChars));

		if (trimParam & TRIM_RIGHT && !stringRef.empty())
			stringRef.erase(stringRef.find_last_not_of(trimChars) + 1);

		return stringRef;
	}
}