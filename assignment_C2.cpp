#include <iostream>
#include <vector>
using namespace std;

// Function to check if there's a subset with sum equal to given sum
bool isSubsetSum(const vector<int>& set, int sum) {
    int n = set.size();
    
    // Create a 2D array to store results of subproblems
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    
    // A sum of 0 is always possible (with empty subset)
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }
    
    // Fill the dp array
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (set[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[n][sum];
}

int main() {
    int n, sum;
    
    // Taking input from the user
    cout << "Enter the number of elements in the set: ";
    cin >> n;
    
    vector<int> set(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; ++i) {
        cin >> set[i];
    }
    
    cout << "Enter the sum to check: ";
    cin >> sum;
    
    // Check if a subset with the given sum exists
    if (isSubsetSum(set, sum)) {
        cout << "Yes, there is a subset with the given sum." << endl;
    } else {
        cout << "No, there is no subset with the given sum." << endl;
    }
    
    return 0;
}

