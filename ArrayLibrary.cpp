#include <iostream>
#include "ArrayLibrary.h"
using namespace std;
//  Array.h   // 0.2.1

Array::Array(int newSize) {
    Size = newSize;
    ArrayItems = new int[newSize];
}
    
// getlength  

int Array::getlength() { return length; }

// getSize

int Array::getSize() { return Size; }

// fill

void Array::fill(int NumberOfItems) {
    if (NumberOfItems == -1) { NumberOfItems = Size; }
    if (NumberOfItems < 0 || NumberOfItems > Size) { return; }
    for (int item = 0; item < NumberOfItems; item++) {
        cin >> ArrayItems[item];
        length++;
    }
}

// display

void Array::display(int start, int stop, int step) {
    {
        // Validation

        if (step < 0) { cout << "Parameter 'Step' must be greater than 0 ..!?"; return; }
        if (start > length) { while (start > length) { start -= length; } }
        if (stop > length) { while (stop > length) { stop -= length; } }
        if (start < 0) { while (start < 0) { start += length; } }
        if (stop < 0) { while (stop < 0) { stop += length; } }

        // show all items

        if (start == 0 && stop == 0) {
            for (int item = start; item < length; item += step) {
                cout << ArrayItems[item] << endl;
            }
        }
        // show range of items reversliy .

        else if (start > stop && stop > 0) {
            for (int item = start; item >= stop; item -= step) {
                cout << ArrayItems[item] << endl;
            }
        }

        // show range of items.

        else if (start != 0 && stop != 0) {
            for (int item = start; item <= stop; item += step) {
                cout << ArrayItems[item] << endl;
            }
        }

        // show one item.

        else if (start != 0) { cout << ArrayItems[start] << endl; }

        else { cout << "Invalid Input\n"; return; }
    }
}

// Delete
    
void Array::Delete(int start, int stop, int step) {

    // Validation

    if (step < 0) { cout << "Parameter 'Step' must be greater than 0 ..!?"; return; }
    if (start > length) { while (start > length) { start -= length; } }
    if (stop > length) { while (stop > length) { stop -= length; } }
    if (start < 0) { while (start < 0) { start += length; } }
    if (stop < 0) { while (stop < 0) { stop += length; } }

    // delete all items.

    if (start == 0 && stop == 0) {
        for (int item = start; item < length; item += step) {
            ArrayItems[item] = 0;
        }
        length = 0;
    }


    // delete range of items.

    else if (start != 0 && stop != 0) {
        for (int item = stop; item >= start; item -= step) {
            reverseShift(start);
            length--;
        }
    }

    // delete one item.

    else if (start != 0 && stop == 0) {
        reverseShift(start);
        length--;
    }

    else {
        cout << "Invalid Input ..!?\n";
    }
}

// insert

// sort

// merge

// append

// pop


// isEmpty

bool Array::isEmpty() { return length > 0;}

// isFull

bool Array::isFull() { return length == Size; }

// push

void Array::push(int item) {
    if (isFull()) { int size = Size++;  enLarge(size); }
    ArrayItems[length++] = item;
}

// shift

void Array::shift(int Index) {
    if (isFull()) { return; }
    for (int item = length; item > Index; item--) {
        ArrayItems[item] = ArrayItems[item - 1];
    }
    length++;
}

// reverseShift

void Array::reverseShift(int Index) {
    if (isFull()) { return; }
    for (int item = Index; item < length; item++) {
        ArrayItems[item] = ArrayItems[item + 1];
    }
    length--;
}

// enlarge 

void Array::enLarge(int size) {
    int* old = ArrayItems;
    int* ArrayItems = new int[size];
    ArrayItems = old;
    delete[] old;
    Size = size;
}

// replace

void Array::replace(int item, int index) {
    ArrayItems[index] = item;
}

// search

int Array::search(int wantedItem) {
    int Index = -1;
    for (int item = 0; item < length; item++) {
        if (ArrayItems[item] == wantedItem) { Index = item; }
    }
    return Index;
}
