#include "BadLength.h"
#include <string>

const char* BadLength::what() const
{
		return "Bad Length ";
}

BadLength::BadLength(int length)
{
	badlength = length;
}