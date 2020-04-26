#include "..\include\keyvalue.h"

namespace parseutil
{
	KeyValue::KeyValue(const std::string& string, const char delimiter, const char trimParam_key, const char trimParam_value)
	{
		Nav kvParsingNav(string, delimiter);
			
		// The operators && and || guarantee that the left-hand side expression will be fully evaluated (and all side effects applied)
		this->m_success = kvParsingNav.getSubstring(this->m_key, true, trimParam_key) && kvParsingNav.getSubstring(this->m_value, false, trimParam_value);
	}
		
	KeyValue::~KeyValue() = default;

	bool KeyValue::pairObtained() const
	{
		return this->m_success;
	}

	std::string const& KeyValue::key() const
	{
		return this->m_key;
	}

	std::string const& KeyValue::value() const
	{
		return this->m_value;
	}

}