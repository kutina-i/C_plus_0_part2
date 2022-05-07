#include "errors.h"
#include "Box.h"

using namespace std;

namespace Cont {
	Box::Box() : length(1), width(1), height(1), weight(1), value(1) {

		}

	Box::Box(int length, int width, int height, double weight, int value) {
			if (length <= 0) {
				throw Errors("Некорректная длина");
			}
			this->length = length;
			if (width <= 0) {
				throw Errors("Некорректная ширина");
			}
			this->width = width;
			if (height <= 0) {
				throw Errors("Некорректная высота");
			}
			this->height = height;
			if (weight <= 0) {
				throw Errors("Некорректный вес");
			}
			this->weight = weight;
			if (value <= 0) {
				throw Errors("Некорректная стоимость");
			}
			this->value = value;
		}

		int Box::getLength() const {
			return length;
		}

		void Box::setLength(int length) {
			if (length <= 0) {
				throw Errors("Некорректная длина");
			}
			this->length = length;
		}

		int Box::getWidth() const {
			return width;
		}

		void Box::setWidth(int width) {
			if (width <= 0) {
				throw Errors("Некорректная ширина");
			}
			this->width = width;
		}

		int Box::getHeight() const {
			return height;
		}

		void Box::setHeight(int height) {
			if (height <= 0) {
				throw Errors("Некорректная высота");
			}
			this->height = height;
		}

		double Box::getWeight() const {
			return weight;
		}

		void Box::setWeight(double weight) {
			if (weight <= 0) {
				throw Errors("Некорректный вес");
			}
			this->weight = weight;
		}

		int Box::getValue() const {
			return value;
		}

		void Box::setValue(int value) {
			if (value <= 0) {
				throw Errors("Некорректная стоимость");
			}
			this->value = value;
		}

		bool Box::equal(const Box& box) const {
			return length == box.length && width == box.width && height == box.height && weight == box.weight && value == box.value;
		}

		int sumValue(int n, const Box* const arr) {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum = sum + arr[i].value;
			}
			return sum;
		}

		bool checkSumBox(int n, const Box* const arr, int param) {
			for (int i = 0; i < n; i++) {
				if (arr[i].length + arr[i].width + arr[i].height > param) {
					return false;
				}
			}
			return true;
		}

		double maxWeight(int n, const Box* const arr, int maxV) {
			double max = 0;
			for (int i = 0; i < n; i++) {
				if (arr[i].length * arr[i].width * arr[i].height <= maxV && max < arr[i].weight) {
					max = arr[i].weight;
				}
			}
			return max;
		}

		bool checkSizes(int n, const Box* const arr) {
			int k = 0, l = ((n - 1) * n) / 2;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i].length < arr[j].length && arr[i].width < arr[j].width && arr[i].height < arr[j].height) {
						k++;
					}
				}
			}
			return k == l;
		}

	ostream& operator<<(ostream& out, const Box& box) {
		out << "length: " << box.getLength() << ", width: " << box.getWidth() <<
			", height: " << box.getHeight() << ", weight: " << box.getWeight() <<
			", value: " << box.getValue();
		return out;
	}

	istream& operator >>(istream& in, Box& box) {
		int length, width, height, value;
		double weight;
		in >> length >> width >> height >> weight >> value;
		if (length <= 0) {
			throw Errors("Некорректная длина");
		}
		box.setLength(length);
		if (width <= 0) {
			throw Errors("Некорректная ширина");
		}
		box.setWidth(width);
		if (height <= 0) {
			throw Errors("Некорректная высота");
		}
		box.setHeight(height);
		if (weight <= 0) {
			throw Errors("Некорректный вес");
		}
		box.setWeight(weight);
		if (value <= 0) {
			throw  Errors("Некорректная стоимость");
		}
		box.setValue(value);
		return in;
	}

}