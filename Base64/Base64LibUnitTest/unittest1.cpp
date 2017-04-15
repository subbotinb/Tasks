#include "stdafx.h"
#include "CppUnitTest.h"
#include "Base64Lib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Base64LibUnitTest
{		
	TEST_CLASS(Test)
	{
	public:
		
		TEST_METHOD(a_encode)
		{
			std::string expected = "YQ==";
			std::string test = Base64::encode("a");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(ab_encode)
		{
			std::string expected = "YWI=";
			std::string test = Base64::encode("ab");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abc_encode)
		{
			std::string expected = "YWJj";
			std::string test = Base64::encode("abc");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcd_encode)
		{
			std::string expected = "YWJjZA==";
			std::string test = Base64::encode("abcd");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcde_encode)
		{
			std::string expected = "YWJjZGU=";
			std::string test = Base64::encode("abcde");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcdef_encode)
		{
			std::string expected = "YWJjZGVm";
			std::string test = Base64::encode("abcdef");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(empty_encode)
		{
			std::string expected = "";
			std::string test = Base64::encode("");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(empty_decode)
		{
			std::string expected = "";
			std::string test = Base64::decode("");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(one_sym_decode)
		{
			std::string expected = "";
			std::string test = Base64::decode("h");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(a_decode)
		{
			std::string expected = "a";
			std::string test = Base64::decode("YQ==");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(ab_decode)
		{
			std::string expected = "ab";
			std::string test = Base64::decode("YWI=");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abc_decode)
		{
			std::string expected = "abc";
			std::string test = Base64::decode("YWJj");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcd_decode)
		{
			std::string expected = "abcd";
			std::string test = Base64::decode("YWJjZA==");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcde_decode)
		{
			std::string expected = "abcde";
			std::string test = Base64::decode("YWJjZGU=");
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcdef_decode)
		{
			std::string expected = "abcdef";
			std::string test = Base64::decode("YWJjZGVm");
			Assert::AreEqual(expected, test);
		}
	};
}