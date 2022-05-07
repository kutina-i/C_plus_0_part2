#include "errors.h"
#include "Container.h"

namespace Cont {
	Container::Container(): boxes(), length(1), width(1), height(1), limitWeight(1) {}

	Container::Container(const vector <Box>& boxes, int length, int width, int height, double limitWeight) {
		sumWeights = 0;
		for (int i = 0; i < boxes.size(); i++) {
			sumWeights += boxes[i].getWeight();
		}
		if (sumWeights > limitWeight) {
			throw Errors("Превышение лимита веса");
		}
		this->boxes = boxes;
		this->length = length;
		this->width = width;
		this->height = height;
		this->limitWeight = limitWeight;
	}

	//добавление коробки в контейнер по индексу
	void Container::newBoxC(int i, Box box) {

		if (i < 0 || i >= boxes.size()) {
			throw Errors("Некорректный индекс");
		}
		double sum = sumWeights + box.getWeight();
		if (sum > limitWeight) {
			throw Errors("Превышение лимита веса");
		}
		sumWeights = sum;
		boxes.insert(boxes.cbegin() + i, box);
	}

	//удаление коробки по индексу
	void Container::deleteBoxC(int i) {
		if (i < 0 || i >= boxes.size()) {
			throw Errors("Некорректный индекс");
		}
		sumWeights = sumWeights - boxes[i].getWeight();
		boxes.erase(boxes.cbegin() + i - 1);
	}

	//кол-во коробок в контейнере
	int Container::countBoxesC() const {
		return boxes.size();
	}

	//суммарн вес содержим контейнера
	double Container::sumWeightC() const {
		return sumWeights;
	}

	//суммарн стоимость содержим
	double Container::sumValueC() const {
		double sum = 0;
		for (int i = 0; i < boxes.size(); i++) {
			sum += boxes[i].getValue();
		}
		return sum;
	}

	//получение коробки по индексу
	Box Container::getBoxC(int i) const {
		if (i < 0 || i >= boxes.size()) {
			throw Errors("Некорректный индекс");
		}
		return boxes[i];
	}

	//добавление коробки в контейнер без индекса
	int Container::putBoxWithoutIndexC(Box box) {
		double sum = sumWeights + box.getWeight();
		if (sum > limitWeight) {
			throw Errors("Превышение лимита веса");
		}
		sumWeights = sum;
		boxes.push_back(box);
		return boxes.size() - 1;
	}

	int Container::getLengthC() const {
		return length;
	}

	void Container::setLengthC(int length) {
		if (length <= 0) {
			throw Errors("Некорректная длина");
		}
		this->length = length;
	}

	int Container::getWidthC() const {
		return width;
	}

	void Container::setWidthC(int width) {
		if (width <= 0) {
			throw Errors("Некорректная ширина");
		}
		this->width = width;
	}

	int Container::getHeightC() const {
		return height;
	}

	void Container::setHeightC(int height) {
		if (height <= 0) {
			throw Errors("Некорректная высота");
		}
		this->height = height;
	}

	vector <Box> Container::getBoxesC() const {
		return boxes;
	}

	void Container::setBoxesC(vector <Box> boxes) {
		this->boxes = boxes;
	}

	double Container::getLimitWeightC() const {
		return limitWeight;
	}

	void Container::setLimitWeightC(double limitWeight) {

		if (limitWeight <= 0) {
			throw Errors("Не может быть меньше 0");
		}
		if (sumWeights > limitWeight) {
			throw Errors("Превышение лимита веса");
		}
		this->limitWeight = limitWeight;
	}

	Box& Container::operator [](const int i) {
		return boxes[i];
	}

	ostream& operator<<(ostream& out, const Container& container) {
		out << "boxes: " << endl;
		for (const Box& box : container.boxes) {
			out << box << std::endl;
		}
		out << "length: " << container.getLengthC() << ", width: " << container.getWidthC() <<
			", height: " << container.getHeightC() << ", limitWeight: " << container.getLimitWeightC();
		return out;
	}

	istream& operator >>(istream& in, Container& container) {
		vector <Box> boxes;
		Box box;
		int length, width, height;
		double limitWeight;
		int n;
		in >> n >> length >> width >> height >> limitWeight;
		if (length <= 0) {
			throw Errors("Некорректная длина");
		}
		container.setLengthC(length);
		if (width <= 0) {
			throw Errors("Некорректная ширина");
		}
		container.setWidthC(width);
		if (height <= 0) {
			throw Errors("Некорректная высота");
		}
		container.setHeightC(height);
		if (limitWeight <= 0) {
			throw Errors("Некорректный вес");
		}
		container.setLimitWeightC(limitWeight);

		for (int i = 0; i < n; i++) {
			in >> box;
			container.putBoxWithoutIndexC(box);
		}

		return in;
	}
}
