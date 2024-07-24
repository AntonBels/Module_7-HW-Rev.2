#include "BadRange.h"
#include <string>

const char* BadRange::what() const
{
	return "Bad Range ";
}

BadRange::BadRange(int index)
{
	badrange = index;
}