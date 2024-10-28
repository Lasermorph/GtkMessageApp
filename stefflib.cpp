#include "stefflib.h"

std::string SteffLib::ReverseString(const std::string& str)
{
	char* buff = new char[str.length() + 1];
	for (size_t i = 0; i < str.length(); i++)
	{
		buff[i] = str.at(str.length()-i-1);
	}
	
	buff[str.length()] = '\0';
	std::string ret = std::string(buff);
	delete buff;
	return ret;
}