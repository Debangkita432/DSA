#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target) {
    int st = 0, end = arr.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (arr[mid] == target) return mid;

        // Left half is sorted
        if (arr[st] <= arr[mid]) {
            if (target >= arr[st] && target < arr[mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (target > arr[mid] && target <= arr[end]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2}; 
    int target1 = 0;
    cout << "Index of " << target1 << ": " << binarySearch(arr1, target1) << endl;

    vector<int> arr2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << "Index of " << target2 << ": " << binarySearch(arr2, target2) << endl;

    return 0;
}
