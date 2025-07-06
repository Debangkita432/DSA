#include <iostream>
#include <vector>
using namespace std;

int singleElement(vector<int>& arr) {
    int st = 0, end = arr.size() - 1;

    if (arr.size() == 1) {
        return arr[0];
    }

    while (st <= end) {
        int mid = (st + end) / 2;

        // edge cases
        if ((mid == 0 && arr[mid] != arr[mid + 1]) ||
            (mid == arr.size() - 1 && arr[mid] != arr[mid - 1])) {
            return arr[mid];
        }

        // mid is the req element
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
            return arr[mid];
        }

        // if mid is even
        if (mid % 2 == 0) {
            if (arr[mid] == arr[mid + 1]) {
                st = mid + 2;
            } else {
                end = mid - 1;
            }
        }

        // if mid is odd
        else {
            if (arr[mid] == arr[mid - 1]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> arr1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "single Element in (arr1): " << singleElement(arr1) << endl;
    return 0;
}
