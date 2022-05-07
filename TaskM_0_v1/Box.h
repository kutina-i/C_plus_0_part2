#pragma once
#include <iostream>
using namespace std;
namespace Cont {
	class Box {
	private:
		int length;
		int width;
		int height;
		double weight;
		int value;

	public:
		Box();

		Box(int, int, int, double, int);

		int getLength() const;

		void setLength(int);

		int getWidth() const; 

		void setWidth(int);

		int getHeight() const;

		void setHeight(int);

		double getWeight() const;

		void setWeight(double);

		int getValue() const;

		void setValue(int);

		bool equal(const Box&) const;

		friend int sumValue(int, const Box* const arr);

		friend bool checkSumBox(int, const Box* const arr, int);

		friend double maxWeight(int, const Box* const arr, int);

		friend bool checkSizes(int, const Box* const arr);

		friend ostream& operator<<(ostream&, const Box&);

		friend istream& operator >>(istream&, Box&);
	};

}