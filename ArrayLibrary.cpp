#include <iostream>
using namespace std;
//  Array.h   // 0.0.2
class Array {
    int Size;
    int length;
    int* ArrayItems = new int[1];
public:
    // constructor
    Array(int newSize) {
        Size = newSize;
        int* ArrayItems = new int[newSize];
    }
    
    // setSize
    int setSize(int newSize) {
        int* ArrayItems = new int[newSize];
    }

    // getlength , getSize

    int getlength() { return length; }
    int getSize() { return Size; }


    // fill
    void fill(int NumberOfItems) {
        if (NumberOfItems > 0 && NumberOfItems <= Size) {
            for (int item = 0; item < NumberOfItems; item++) {
                cin >> ArrayItems[item];
                length++;
            }
        }
        else { return; }
    }

    // display

    void display(int start = 0, int stop = 0, int step = 1) {    
        {
            // Validation

            if (step < 0) { return; }
            if (stop < 0) { stop += length; }
            if (start < 0) { start += length; }
            if (start > Size  || stop > Size) { return; }
            
            // display();   // show all items.

            if (start == 0 && stop == 0) {
                for (int item = start; item < length; item+=step) {
                    cout << ArrayItems[item] << endl;
                }
            }

            // display(1,5);    // show range of items.

            else if (start != 0 && stop != 0) {
                for (int item = start; item <= stop; item += step) {
                    cout << ArrayItems[item] << endl;
                }
            }

            // display(3);  // show one item.

            else if (start != 0) {
                cout << ArrayItems[start] << endl;
            }

            else { return; }
        }
    }

    // delete

    // enlarge

    // replace

    // insert

    // sort

    // merge

    // append

    // pop

    // search

    // puch

    // shift

    //
};
int main()
{
    Array arr1(5);
    cout << "Enter array items \n";
    arr1.fill(5);
    arr1.display(0,-2);
}
