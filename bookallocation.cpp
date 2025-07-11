#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// Helper: is it possible to allocate with maxAllowedPages per student?
bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedPages) return false;

        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }

        if (students > m) return false;
    }

    return true;
}

int allocatebook(vector<int> arr, int n, int m) {
    if (m > n) return -1;

    int sum = accumulate(arr.begin(), arr.end(), 0);
    int st = *max_element(arr.begin(), arr.end()); // Start from max book
    int end = sum;
    int result = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid)) {
            result = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> arr = {15, 17, 20};
    int n = arr.size(); // Fixing value of n
    int m = 2;
    cout << allocatebook(arr, n, m) << endl;

    return 0;
}
