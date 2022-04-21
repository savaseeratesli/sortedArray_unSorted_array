#include <iostream>
#include "array.h"

using namespace std;

int main()
{
    unsortedArray usArray(10);
    sortedArray sArray(10);

    usArray.addItem(19);
    usArray.addItem(7);
    usArray.addItem(9);
    usArray.addItem(8);
    usArray.addItem(98);
    usArray.addItem(69);
    usArray.addItem(35);

    usArray.removeIndexItem(0);
    usArray.removeItem(7);

    cout << usArray.findIndex(10) << endl;

    usArray.printItems();

    sArray.addItem(19);
    sArray.addItem(7);
    sArray.addItem(9);
    sArray.addItem(8);
    sArray.addItem(98);
    sArray.addItem(69);
    sArray.addItem(35);

    sArray.removeIndexItem(1);
    sArray.removeItem(69);

    cout << sArray.findIndex(10) << endl;

    sArray.printItems();

    return 0;
}

