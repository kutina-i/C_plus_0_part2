#pragma once
#include <iostream>
using namespace std;
class Errors : public exception
{
private:
	string error;
public:
	explicit Errors(string error)
		: error(move(error))
	{
	}
	const char* what() const noexcept override { return error.c_str(); }
};
