#include <iostream>
#include <vector>
using namespace std;

int coin_change(vector<int> &coins, int sum) {
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int j = coin; j <= sum; ++j) {
            dp[j] += dp[j - coin];
        }
    }

    return dp[sum];
}

int main() {
    int n, sum;
    cout << "Enter the number of coin types: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coin values: ";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    cout << "Enter the sum to make: ";
    cin >> sum;

    cout << "Number of ways to make sum " << sum << " with given coins is: " << coin_change(coins, sum) << endl;

    return 0;
}

