#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool can(long long T, int mountainHeight, vector<int>& workerTimes) {

    long long total = 0;

    for(long long t : workerTimes) {

        long long k = T / t;

        long long x = (sqrt(1 + 8.0 * k) - 1) / 2;

        total += x;

        if(total >= mountainHeight)
            return true;
    }

    return false;
}

long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

    long long left = 0;
    long long right = 1e18;
    long long ans = right;

    while(left <= right) {

        long long mid = (left + right) / 2;

        if(can(mid, mountainHeight, workerTimes)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {

    int mountainHeight;
    cin >> mountainHeight;

    int n;
    cin >> n;

    vector<int> workerTimes(n);

    for(int i = 0; i < n; i++)
        cin >> workerTimes[i];

    cout << minNumberOfSeconds(mountainHeight, workerTimes);

    return 0;
}
