#include "..\include\nav.h"

namespace parseutil
{
	Nav::Nav(const std::string& string, const char delimiter) : m_navString{ string }, m_delimiter{ delimiter }
	{
		this->reset();
	}

	Nav::~Nav() = default;

	void Nav::reset()
	{
		this->m_subEnd = std::string::npos;
		this->navigate();
	}

	int Nav::delimiterCount() const
	{
		int count{ 0 };
		for (const char& character : this->m_navString)
		{
			if (character == this->m_delimiter)
				++count;
		}

		return count;
	}

	bool Nav::canNavigate() const
	{
		// If m_subEnd == npos the navigator will be allowed to navigate for resetting
		return !(this->m_subEnd >= this->m_navString.size() && this->m_subEnd != std::string::npos);
	}

	bool Nav::navigate(const int count)
	{
		for (int navigations{ 0 }; navigations < count; ++navigations)
		{
			if (!this->canNavigate())
				return false;

			// Resetting
			if (this->m_subEnd != std::string::npos)
				++this->m_subEnd;
			else
				this->m_subEnd = 0;

			size_t nextDelimiter{ this->m_navString.find_first_of(this->m_delimiter, this->m_subEnd) };

			this->m_subStart = this->m_subEnd;
			this->m_subEnd = nextDelimiter != std::string::npos ? nextDelimiter : this->m_navString.size();
		}

		return true;
	}

	bool Nav::getSubstring(std::string& stringOut, const int navigate, const char trimParam)
	{
		if (this->m_subStart >= this->m_subEnd)
			return false;

		std::string subString{ this->m_navString.substr(this->m_subStart, this->m_subEnd - this->m_subStart) };

		stringOut = trim(subString, trimParam);

		if (navigate && !this->navigate(navigate))
			return false;

		return true;
	}

	std::vector<std::string> Nav::split(const bool ignoreEmpty, const char trimParam)
	{
		std::vector<std::string> stringFragments;
		stringFragments.reserve(this->delimiterCount() + 1);
			
		this->reset();
		do
		{
			std::string curFragment;

			if (this->getSubstring(curFragment, false, trimParam))
				stringFragments.push_back(curFragment);
			else if (!ignoreEmpty)
				stringFragments.push_back(std::string{ "" });

		} while (this->navigate());

		return stringFragments;
	}

}