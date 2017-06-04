#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Shapes/Shapes.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(SquareOfSquare1)
		{
			Square s(2.123456);
			double square = 4.51;
			Assert::AreEqual(square, s.getSquare());
		}

		TEST_METHOD(SquareConstructorNegativeValue)
		{
			auto func = [this] { new Square(-5); };
			Assert::ExpectException<logic_error>(func);
		}

		TEST_METHOD(SquareOfCircle1)
		{
			Circle c(3.14);
			double square = 30.96;
			Assert::AreEqual(square, c.getSquare());
		}

		TEST_METHOD(SquareOfCircle2)
		{
			Circle c(1);
			double square = 3.14;
			Assert::AreEqual(square, c.getSquare());
		}

		TEST_METHOD(CircleConstructorNegativeValue)
		{
			auto func = [this] { new Circle(-5); };
			Assert::ExpectException<logic_error>(func);
		}

		TEST_METHOD(SquareOfRectangle1)
		{
			Rectangle r(1.23, 4.56);
			double square = 5.61;
			Assert::AreEqual(square, r.getSquare());
		}

		TEST_METHOD(RectangleConstructorNegativeValue1)
		{
			auto func = [this] { new Rectangle(-5, 5); };
			Assert::ExpectException<logic_error>(func);
		}

		TEST_METHOD(RectangleConstructorNegativeValue2)
		{
			auto func = [this] { new Rectangle(5, -5); };
			Assert::ExpectException<logic_error>(func);
		}

		TEST_METHOD(RectangleConstructorNegativeValue3)
		{
			auto func = [this] { new Rectangle(-5, -5); };
			Assert::ExpectException<logic_error>(func);
		}

		TEST_METHOD(SquaresVector)
		{
			Square s1(5);
			Rectangle r1(3, 7);
			Circle c1(1);
			Circle c2(3);

			ShapesProcessor Shapes;
			Shapes.push(s1);
			Shapes.push(r1);
			Shapes.push(c1);
			Shapes.push(c2);

			vector<double> Squares;

			Squares.push_back(s1.getSquare());
			Squares.push_back(r1.getSquare());
			Squares.push_back(c1.getSquare());
			Squares.push_back(c2.getSquare());
			Assert::IsTrue(Squares == Shapes.getSquare());
		}

		TEST_METHOD(MaxSquare)
		{
			Square s1(5);
			Rectangle r1(3, 7);
			Circle c1(1);
			Circle c2(3);

			ShapesProcessor Shapes;
			Shapes.push(s1);
			Shapes.push(r1);
			Shapes.push(c1);
			Shapes.push(c2);

			Assert::AreEqual(c2.getSquare(), Shapes.maxSquare()->getSquare());
		}
		
		TEST_METHOD(MinSquare)
		{
			Square s1(5);
			Rectangle r1(3, 7);
			Circle c1(1);
			Circle c2(3);

			ShapesProcessor Shapes;
			Shapes.push(s1);
			Shapes.push(r1);
			Shapes.push(c1);
			Shapes.push(c2);

			Assert::AreEqual(c1.getSquare(), Shapes.minSquare()->getSquare());
		}

		TEST_METHOD(SameSquaresOfSameType)
		{
			Square s1(5);
			Rectangle r1(9, 3.14);
			Circle c1(3);
			Circle c2(3);

			ShapesProcessor Shapes;
			Shapes.push(s1);
			Shapes.push(r1);
			Shapes.push(c1);
			Shapes.push(c2);

			unsigned int amount = 2;
			Assert::AreEqual(amount, Shapes.sameSquaresOfSameType());
		}

		TEST_METHOD(SameSquaresOfDifferentTypes)
		{
			Square s1(5);
			Rectangle r1(9, 3.14);
			Circle c1(3);
			Circle c2(3);

			ShapesProcessor Shapes;
			Shapes.push(s1);
			Shapes.push(r1);
			Shapes.push(c1);
			Shapes.push(c2);

			ShapesProcessor Shapes2;
			Shapes2.push(r1);
			Shapes2.push(c1);
			Shapes2.push(c2);
			Assert::IsTrue(Shapes2 == Shapes.sameSquaresOfDifferentTypes());
		}
	};
}