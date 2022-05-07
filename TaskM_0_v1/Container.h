#pragma once
#include <iostream>
#include <vector>
#include "Box.h"

using namespace std;
namespace Cont {

	class Container
	{
	private:
		vector <Box> boxes;
		int length;
		int width;
		int height;
		double limitWeight;
		double sumWeights;

	public:
		Container();

		Container(const vector <Box>& boxes, int, int, int, double);

		void newBoxC(int, Box);

		void deleteBoxC(int);

		int countBoxesC() const;

		double sumWeightC() const;

		double sumValueC() const;

		Box getBoxC(int) const;

		int putBoxWithoutIndexC(Box);

		int getLengthC() const;

		void setLengthC(int);

		int getWidthC() const;

		void setWidthC(int);

		int getHeightC() const;

		void setHeightC(int);

		vector <Box> getBoxesC() const;

		void setBoxesC(vector <Box>);

		double getLimitWeightC() const;

		void setLimitWeightC(double);

		Box& operator [](const int i);

		friend ostream& operator <<(ostream&, const Container&);

		friend istream& operator >>(istream&, Container&);
	};




}