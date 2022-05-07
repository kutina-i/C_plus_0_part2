#include "Container.h"
using namespace std;

int main()
{
	Cont::Box box1(3, 5, 8, 2, 50);
	Cont::Box box2(8, 1, 2, 4, 100);
	Cont::Box box3(1, 8, 8, 3, 10);
	Cont::Box box4(5, 2, 5, 8, 11);
	Cont::Box box5(8, 2, 7, 7, 150);
	Cont::Box arr[5] = { box1, box2, box3, box4, box5 };
	Cont::Box boxTest(8, 2, 7, 7, 150);

	cout << sumValue(5, arr) << endl;
	cout << checkSumBox(5, arr, 20) << endl;
	cout << maxWeight(5, arr, 37) << endl;

	Cont::Box box11(3, 3, 4, 2, 50);
	Cont::Box box22(5, 6, 6, 4, 100);
	Cont::Box box33(1, 1, 1, 3, 10);
	Cont::Box box44(2, 2, 3, 8, 11);
	Cont::Box box55(19, 10, 11, 7, 150);

	Cont::Box arrNew[5] = {box11, box22, box33, box44, box55};

	Cont::Box box1new;

	cout << checkSizes(5, arrNew) << endl;

	cin >> box1new;
	cout << box1new << endl;



	Cont::Box box12(3, 3, 4, 2, 50);

	cout << box11.equal(box12);

	vector <Cont::Box> boxes = { box11, box22, box33, box44, box55 };

	Cont::Container cont1(boxes, 2, 3, 4, 1000);

	cout << cont1.countBoxesC() << endl;

	cout << cont1.sumWeightC() << endl;

	cout << cont1.sumValueC() << endl;

	cout << cont1.getBoxC(2) << endl;

	Cont::Box box66(11, 21, 17, 8, 450);

	int i_66 = cont1.putBoxWithoutIndexC(box66);

	cout << cont1.getBoxC(i_66) << endl;

	cont1.deleteBoxC(2);

	cout << cont1.getBoxC(2) << endl;

	cont1.newBoxC(1, box33);

	cout << cont1.getBoxC(1) << cont1.getBoxC(2) << endl;


	Cont::Container contNew;

	cin >> contNew;

	cout << contNew << endl;

	cout << contNew[1] << endl;

	contNew[1] = box11;

	cout << contNew << endl;

}
