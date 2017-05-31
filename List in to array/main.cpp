#include <iostream>
#include "LinkedList.h"


using namespace std;



int main()
{
	LinkedList<int> tested;


	tested.addEnd(100);
	tested.addEnd(50);
	tested.addEnd(70);
	tested.addEnd(50);
	tested.addEnd(70);
	tested.addEnd(51);
	tested.addEnd(100);
	//tested.add(89);
	//cout <<  << endl;
	
	tested.removeStart();
	tested.removeEnd();
	cout << tested.isEmpty() << endl << endl;//Вернёт 0(false) список не пустой
	node<int>* i;
	for (i = tested.getStart(); !tested.isEnd(i); i=tested.getNext(i))
	{
		cout << tested.get(i) <<endl;
	}
	cout << tested.get(i) << endl;

	cin.get();


	return 0;
}