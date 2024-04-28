#include "iostream"

using namespace std;

void bubble_sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    int min_index;
    int temp;
    for (int i = 0; i < n; i++) {
        min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void insertion_sort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main() {
    int unsorted_arr[7] = {12, 3, 15, 18, 10, 7, 35};

    cout << "Unsorted array: ";
    for (int i = 0; i < 7; i++) {
        cout << unsorted_arr[i] << '\t';
    }
    cout << endl;

    bubble_sort(unsorted_arr, 7); // time complexity: O(n^2)
    // selection_sort(unsorted_arr, 7); // time complexity: O(n^2)
    // insertion_sort(unsorted_arr, 7); // time complexity: O(n^2)
    // merge_sort(unsorted_arr, 0, 6); // time complexity: O(n log n)
    // quick_sort(unsorted_arr, 0, 6); // time complexity: O(n log n)
    cout << "Sorted array: ";
    for (int i = 0; i < 7; i++) {
        cout << unsorted_arr[i] << '\t';
    }
    cout << endl;

    return 0;
}