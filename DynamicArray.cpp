#include <iostream>
#include <stdexcept>
using namespace std;

struct DynamicArray {
    int* array;
    int size;
    int head;
    int length;
    DynamicArray() {
        size = 1;
        array = new int[size];
        head = -1;
        length = 0;
    }

    ~DynamicArray() {
        delete[] array;
    }

    void resizeForFirst() {
        int newSize = size + length;
        int* newArray = new int[newSize];
        for (int i = 0; i < length; i++) {
            newArray[length + i] = array[head + i];
        }
        delete[] array;
        array = newArray;
        size = newSize;
        head = length;
    }

    void resizeForLast() {
        int newSize = size + length;
        int* newArray = new int[newSize];
        for (int i = 0; i < length; i++) {
            newArray[i] = array[head + i];
        }
        delete[] array;
        array = newArray;
        size = newSize;
    }

    void addFirst(int value) {
        if (head == 0 || head == -1) {
            resizeForFirst();
        }
        if (head == -1) {
            head = size / 2;
        }
        head--;
        array[head] = value;
        length++;
    }

    void addLast(int value) {
        if (head == -1) {
            head = 0;
        }
        if (head + length == size) {
            resizeForLast();
        }
        array[head + length] = value;
        length++;
    }

    int delFirst() {
        if (length == 0) {
            throw out_of_range("Array is empty");
        }
        int value = array[head];
        array[head] = 0;
        head++;
        length--;
        if (length == 0) {
            head = -1;
        }
        return value;
    }

    int delLast() {
        if (length == 0) {
            throw out_of_range("Array is empty");
        }
        int tail = head + length - 1;
        int value = array[tail];
        array[tail] = 0;
        length--;
        if (length == 0) {
            head = -1;
        }
        return value;
    }

    int get(int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        }
        return array[head + index];
    }
};
