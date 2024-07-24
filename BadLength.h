#pragma once
#include <exception>

/*Exception class for bad length condition*/
class BadLength : public std::exception // inheritated from exception class
{
public:
	BadLength(int length);
	
	const char* what() const override;

private:
	int badlength;
};