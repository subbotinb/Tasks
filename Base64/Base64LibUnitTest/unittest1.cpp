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
			std::string in = "a";
			std::string test = Base64::encode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(ab_encode)
		{
			std::string expected = "YWI=";
			std::string in = "ab";
			std::string test = Base64::encode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abc_encode)
		{
			std::string expected = "YWJj";
			std::string in = "abc";
			std::string test = Base64::encode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcd_encode)
		{
			std::string expected = "YWJjZA==";
			std::string in = "abcd";
			std::string test = Base64::encode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcde_encode)
		{
			std::string expected = "YWJjZGU=";
			std::string in = "abcde";
			std::string test = Base64::encode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcdef_encode)
		{
			std::string expected = "YWJjZGVm";
			std::string in = "abcdef";
			std::string test = Base64::encode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(empty_encode)
		{
			std::string expected = "";
			std::string in = "";
			std::string test = Base64::encode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(empty_decode)
		{
			std::string expected = "";
			std::string in = "";
			std::string test = Base64::decode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(one_sym_decode)
		{
			std::string expected = "";
			std::string in = "h";
			std::string test = Base64::decode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(a_decode)
		{
			std::string expected = "a";
			std::string in = "YQ==";
			std::string test = Base64::decode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(ab_decode)
		{
			std::string expected = "ab";
			std::string in = "YWI=";
			std::string test = Base64::decode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abc_decode)
		{
			std::string expected = "abc";
			std::string in = "YWJj";
			std::string test = Base64::decode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcd_decode)
		{
			std::string expected = "abcd";
			std::string in = "YWJjZA==";
			std::string test = Base64::decode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcde_decode)
		{
			std::string expected = "abcde";
			std::string in = "YWJjZGU=";
			std::string test = Base64::decode(in);
			Assert::AreEqual(expected, test);
		}

		TEST_METHOD(abcdef_decode)
		{
			std::string expected = "abcdef";
			std::string in = "YWJjZGVm";
			std::string test = Base64::decode(in);
			Assert::AreEqual(expected, test);
		}
	};
}