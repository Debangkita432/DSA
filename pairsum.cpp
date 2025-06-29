#include <iostream>
#include <vector>
using namespace std;

vector<int> pairsum(vector<int> nums, int target) {
    vector<int> ans;
    int i = 0;
    int j = nums.size() - 1;  // Fixed: 'n' is undefined

    while (i < j) {
        int sum = nums[i] + nums[j];  // Fixed: 'pairsum' is a function, use 'sum' instead

        if (sum > target) {
            j--;
        } else if (sum < target) {  // Fixed: 'elseif' → 'else if'
            i++;
        } else {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }

    return ans; // Add return in case no pair found
}

int main() {
    vector<int> nums = {2, 3, 4, 6, 11};
    int target = 17;

    vector<int> ans = pairsum(nums, target);

    if (!ans.empty()) {
        cout << ans[0] << "," << ans[1] << endl;
    } else {
        cout << "No valid pair found." << endl;
    }

    return 0;
}
