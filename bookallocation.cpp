#include <iostream>
#include <vector>
using namespace std;

bool isValid(const vector<int>& arr, int n, int m, int maxAllowedPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        // if one book alone exceeds the limit bail out..
        if (arr[i] > maxAllowedPages) 
            return false;

        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
            if (students > m) 
                return false;
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    if (m > n) 
        return -1;

    // total pages and the largest single book
    int total = 0;
    int largest = arr[0];
    for (int i = 0; i < n; i++) {
        total += arr[i];
        if (arr[i] > largest)
            largest = arr[i];
    }

    int st = largest;
    int end = total;
    int answer = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (isValid(arr, n, m, mid)) {
            answer = mid;
            end = mid - 1;   // try to find an even smaller max
        } else {
            st = mid + 1;    // need to allow more pages
        }
    }

    return answer;
}

int main() {
    vector<int> arr = {15, 17, 20};
    int n = arr.size();//books
    int m = 2; //students
    cout << allocateBooks(arr, n, m) << "\n";  
    return 0;
}
