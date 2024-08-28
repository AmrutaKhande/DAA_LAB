#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1); 
    int i = left, j = mid + 1, k = 0;


    while (i <= mid && j <= right) {
        if (arr[i] != 0) {
            temp[k++] = arr[i++]; 
        } else if (arr[j] != 0) {
            temp[k++] = arr[j++];
        } else {
            i++; 
            j++; 
        }
    }


    while (i <= mid) {
        if (arr[i] != 0) {
            temp[k++] = arr[i];
        }
        i++;
    }


    while (j <= right) {
        if (arr[j] != 0) {
            temp[k++] = arr[j];
        }
        j++;
    }


    int zeroCount = right - left + 1 - k;


    while (zeroCount--) {
        temp[k++] = 0;
    }


    for (i = left, k = 0; i <= right; ++i, ++k) {
        arr[i] = temp[k];
    }
}

// Function to implement divide and conquer approach
void moveZeroesToEnd(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point

        // Recursively solve for the left and right halves
        moveZeroesToEnd(arr, left, mid);
        moveZeroesToEnd(arr, mid + 1, right);

        // Merge the two halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr);

    moveZeroesToEnd(arr, 0, arr.size() - 1);

    cout << "Array after moving zeroes to the end: ";
    printArray(arr);

    return 0;
}
