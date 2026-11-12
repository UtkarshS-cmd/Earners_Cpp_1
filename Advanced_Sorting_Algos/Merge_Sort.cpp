
#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted parts of the array ->Compare, Push & Combine
void merge(vector<int>& arr, int low, int mid, int high) {

    vector<int> temp;

    int i = low;       // Left subarray pointer
    int j = mid + 1;   // Right subarray pointer

    // Compare elements and insert smaller one
    while (i <= mid && j <= high) {

        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining left elements
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining right elements
    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back into original array
    for (int k = 0; k < temp.size(); k++) {
        arr[low + k] = temp[k];
    }
}

// Recursive Merge Sort function->Divides 
void mergeSort(vector<int>& arr, int low, int high) {

    // Base condition
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    // Divide into two halves
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // Merge sorted halves
    merge(arr, low, mid, high);
}

int main() {

    vector<int> arr = {38, 12, 27, 43, 9, 31, 18, 25};

    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
