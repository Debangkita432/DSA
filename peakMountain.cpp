#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int st = 0, end = arr.size() - 1;

    while (st < end) {
        int mid = st + (end - st) / 2;

        if (arr[mid] < arr[mid + 1]) {
            // We are in the increasing part of the mountain
            st = mid + 1;
        } else {
            // We are in the decreasing part or at the peak
            end = mid;
        }
    }

    // st == end and pointing to the peak index
    return st;
}

int main() {
    vector<int> arr1 = {0, 1, 0};
    vector<int> arr2 = {0, 2, 1, 0};
    vector<int> arr3 = {0, 10, 24, 2};

    cout << "Peak index (arr1): " << peakIndexInMountainArray(arr1) << endl;
    cout << "Peak index (arr2): " << peakIndexInMountainArray(arr2) << endl;
    cout << "Peak index (arr3): " << peakIndexInMountainArray(arr3) << endl;

    return 0;
}

