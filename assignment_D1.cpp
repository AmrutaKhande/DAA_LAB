#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSubsets(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ansList) {
    ansList.push_back(ds);
    for (int i = ind; i < nums.size(); i++) {
        if (i != ind && nums[i] == nums[i - 1])
            continue;

        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ansList);
        ds.pop_back();
    }
}

vector<vector<int>> AllSubsets(int arr[], int n) {
    vector<int> nums(arr, arr + n);
    vector<int> ds;
    sort(nums.begin(), nums.end());
    vector<vector<int>> ansList;
    findSubsets(0, nums, ds, ansList);
    return ansList;
}

int main() {
    int n;
    cout << "Enter the size of the set: ";
    cin >> n;

    int* set = new int[n];
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    vector<vector<int>> subsets = AllSubsets(set, n);

    cout << "Subsets of the given set are:" << endl;
    for (auto subset : subsets) {
        cout << "{";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) {
                cout << " ";
            }
        }
        cout << "}, ";
    }

    delete[] set; // Free dynamically allocated memory
    return 0;
}
