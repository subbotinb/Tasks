// ConsoleApplication7.cpp : Defines the entry point for the console application. 
// 

#include "stdafx.h"


#include <vector>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class Shape
{
public:
	virtual double getSquare() = 0;
	virtual string getName() = 0;
};

class Circle : public Shape
{
public:
	Circle(double radius)
	{
		if (radius <= 0)
			throw logic_error("Negative value");
		this->radius = radius;
	}

	double getSquare()
	{
		return round((3.14 * pow(radius, 2))*100)/100;
	}

	string getName()
	{
		return "Circle";
	}

private:
	double radius;
};

class Rectangle : public Shape
{
public:
	Rectangle(double length, double width)
	{
		if (length <= 0 || width <= 0)
			throw logic_error("Negative value");
		this->lenght = length;
		this->width = width;
	}

	double getSquare()
	{
		return round((lenght * width)*100)/100;
	}

	string getName()
	{
		return "Rectangle";
	}

private:
	double lenght;
	double width;
};

class Square : public Shape
{
public:
	Square(double side)
	{
		if (side <= 0)
			throw logic_error("Negative value");
		this->side = side;
	}

	double getSquare()
	{
		return round(pow(side, 2)*100)/100;
	}

	string getName()
	{
		return "Square";
	}

private:
	double side;
};


class ShapesProcessor
{
public:
	void push(Shape& figure)
	{
		v.push_back(&figure);
	}

	void clear()
	{
		v.clear();
	}

	vector<double> getSquare()
	{
		vector<double> squaresVector;
		for (unsigned int i = 0; i < v.size(); i++)
		{
			squaresVector.push_back(v[i]->getSquare());
		}
		return squaresVector;
	}

	Shape* maxSquare()
	{
		Shape* max = v[0];
		for (unsigned int i = 0; i < v.size(); i++)
		{
			if (v[i]->getSquare() > max->getSquare())
			{
				max = v[i];
			}
		}
		return max;
	}

	Shape* minSquare()
	{
		Shape* min = v[0];
		for (unsigned int i = 0; i < v.size(); i++)
		{
			if (v[i]->getSquare() < min->getSquare())
			{
				min = v[i];
			}
		}
		return min;
	}

	unsigned int sameSquaresOfSameType()
	{
		vector<double> Squares = getSquare();
		int max = 0;
		for (unsigned int i = 0; i < Squares.size(); i++)
		{
			int count = 0;
			for (unsigned int j = 0; j < Squares.size(); j++) //?????
			{
				if ((Squares[i] == Squares[j]) && (i != j))
				{
					count++; //?????
				}
			}
			if (count > max)
			{
				max = count;
			}
		}
		return max;
	}

	ShapesProcessor sameSquaresOfDifferentTypes()
	{
		ShapesProcessor result;
		ShapesProcessor temp;

		vector<double> Squares = getSquare();
		for (unsigned int i = 0; i < Squares.size(); i++)
		{
			temp.clear();
			for (unsigned int j = 0; j < Squares.size(); j++)
			{
				if ((Squares[i] == Squares[j]) && ((v[i]->getName() != v[j]->getName()) || (i == j)))
				{
					temp.push(*(v[j]));
				}
			}
			if (temp.v.size() > result.v.size())
			{
				result = temp;
			}
		}
		return result;
	}

	void print()
	{
		for (unsigned int i = 0; i < v.size(); i++)
		{
			cout << v[i]->getName() << ' ' << v[i]->getSquare() << endl;
		}
	}

	friend bool operator ==(const ShapesProcessor& v1, const ShapesProcessor& v2)
	{
		if (v1.v == v2.v)
			return true;
		return false;
	}

private:
	vector<Shape*> v;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Square s1(1.234);
	Rectangle r1(3, 7);
	Circle c1(1);
	Circle c2(3);

	ShapesProcessor Shapes;
	Shapes.push(s1);
	Shapes.push(r1);
	Shapes.push(c1);
	Shapes.push(c2);
	Shapes.print();

	cout << Shapes.minSquare()->getName() << " " << Shapes.minSquare()->getSquare() << endl;

	system("pause");
	return 0;
}


