#pragma once
// Base64.cpp

#include <iostream>
#include <string>

typedef unsigned char uchar;

class Base64
{
public:
	// Returns encoded string
	static std::string encode(const std::string &input);

	// Returns decoded string
	static std::string decode(const std::string &input);

private:
	// Stores Base64 symbols table
	static const std::string CODES;
};