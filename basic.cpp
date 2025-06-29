// #include <iostream>
// using namespace std;

// int main(){
// cout<< "Hello World";
// return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the length: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
