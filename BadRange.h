#pragma once
#include <exception>

/*Exception class for bad range condition*/
class BadRange : public std::exception //inheritated from exception class
{
public:
	BadRange(int index);
		
	const char* what() const override;

private:
	int badrange;
};

