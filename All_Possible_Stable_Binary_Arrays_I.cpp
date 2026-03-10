#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;

int limit;
int dp[201][201][2];

int solve(int z, int o, int last) {
    if (z == 0 && o == 0) return 1;

    if (dp[z][o][last] != -1)
        return dp[z][o][last];

    long long ans = 0;

    if (last == 0) {
        for (int i = 1; i <= min(limit, o); i++) {
            ans = (ans + solve(z, o - i, 1)) % MOD;
        }
    } 
    else {
        for (int i = 1; i <= min(limit, z); i++) {
            ans = (ans + solve(z - i, o, 0)) % MOD;
        }
    }

    return dp[z][o][last] = ans;
}

int main() {

    int zero, one;
    cin >> zero >> one >> limit;

    memset(dp, -1, sizeof(dp));

    long long ans = 0;

    for (int i = 1; i <= min(limit, zero); i++)
        ans = (ans + solve(zero - i, one, 0)) % MOD;

    for (int i = 1; i <= min(limit, one); i++)
        ans = (ans + solve(zero, one - i, 1)) % MOD;

    cout << ans;

    return 0;
}


