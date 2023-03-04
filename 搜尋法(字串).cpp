#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

string arr[MAX_SIZE];
int arraySize = 0;

void insert(string x) {
    int i = arraySize;
    while (i > 0 && arr[i - 1] > x) {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[i] = x;
    arraySize++;
}

void linearSearch(string x) {
	 int i;
    for ( i = 0; i < arraySize; i++) {
        cout << i << ": " << arr[i] << endl;
        if (arr[i] == x) {
            cout << "found: " << x << endl;
            return;
        }
    }
    cout << "not found " << x << endl;
}

void binarySearch(string x) {
    int left = 1;
    int right = arraySize - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        cout << mid << ": " << arr[mid] << endl;
        if (arr[mid] == x) {
            cout << "found: " << x << endl;
            return;
        }
        else if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            }
    }
    cout << "not found " << x << endl;
}

void print() {
    for (int i = 0; i < arraySize; i++) {
        cout  << arr[i]<< " " ;
    }
    cout << endl;
}

int main() {
    int choice;
    do {
       
        cin >> choice;
        switch (choice) {
            case 1: {
                string x;
                cin >> x;
                insert(x);
                break;
            }
            case 2: {
                string x;                
                cin >> x;
                linearSearch(x);
                break;
            }
            case 3: {
                string x;               
                cin >> x;
                binarySearch(x);
                break;
            }
            case 4: {
                print();
                break;
            }
            case 5: 
                break;
        }
    } while (choice != 5);
    return 0;
}