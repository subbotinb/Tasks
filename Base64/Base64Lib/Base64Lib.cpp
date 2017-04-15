#include "Base64Lib.h"

const std::string Base64::CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string Base64::encode(std::string input) {
	size_t length = input.length();
	uchar B64code;
	std::string output;
	for (size_t i = 0; i < length; i += 3) {
		B64code = (input[i] & 0xFC) >> 2;
		output += Base64::CODES[B64code];
		B64code = (input[i] & 0x03) << 4;
		if (i + 1 < length) {
			B64code |= (input[i + 1] & 0xF0) >> 4;
			output += Base64::CODES[B64code];
			B64code = (input[i + 1] & 0x0F) << 2;
			if (i + 2 < length) {
				B64code |= (input[i + 2] & 0xC0) >> 6;
				output += Base64::CODES[B64code];
				B64code = (input[i + 2] & 0x3F);
				output += Base64::CODES[B64code];
			}
			else {
				output += Base64::CODES[B64code];
				output += std::string("=");
			}
		}
		else {
			output += Base64::CODES[B64code];
			output += std::string("==");
		}
	}
	return output;
}

std::string Base64::decode(std::string input) {
	size_t length = input.length();
	uchar UTF8code;
	uchar B64code[4];
	std::string output;
	try {
		if (length % 4 != 0)
			throw "Длина входной строки должна быть кратна 4";
	}
	catch (const char* i) {
		std::cout << i << std::endl;
		return "";
	}
	for (size_t i = 0; i < length; i += 4) {
		B64code[0] = (uchar)Base64::CODES.find(input[i]);
		B64code[1] = (uchar)Base64::CODES.find(input[i + 1]);
		B64code[2] = (uchar)Base64::CODES.find(input[i + 2]);
		B64code[3] = (uchar)Base64::CODES.find(input[i + 3]);
		UTF8code = B64code[0] << 2 | B64code[1] >> 4;
		output += UTF8code;
		if (B64code[2] < 64) {
			UTF8code = B64code[1] << 4 | B64code[2] >> 2;
			output += UTF8code;
			if (B64code[3] < 64) {
				UTF8code = B64code[2] << 6 | B64code[3];
				output += UTF8code;
			}
		}
	}
	return output;
}