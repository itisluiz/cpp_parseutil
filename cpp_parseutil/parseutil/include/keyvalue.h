#ifndef KEYVALUE_H
#define KEYVALUE_H

#include "nav.h"

namespace parseutil
{
	// Class for parsing values and keys out of strings in the format of key = value, with '=' being any set character delimiter.
	class KeyValue
	{
		std::string m_key, m_value;
		bool m_success{ false };
	public:
		KeyValue(const std::string& string, const char delimiter, const char trimParam_key = TRIM_NONE, const char trimParam_value = TRIM_NONE);
		~KeyValue();

		bool pairObtained() const;
		std::string const& key() const;
		std::string const& value() const;
	};
}

#endif
