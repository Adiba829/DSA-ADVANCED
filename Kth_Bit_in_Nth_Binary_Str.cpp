#include <iostream>
using namespace std;

char findKthBit(int n, int k) {
    if (n == 1) 
        return '0';

    int len = (1 << n) - 1;
    int mid = (len / 2) + 1;

    if (k == mid)
        return '1';

    if (k < mid)
        return findKthBit(n - 1, k);

    // if k > mid
    int newK = len - k + 1;
    char bit = findKthBit(n - 1, newK);

    return (bit == '0') ? '1' : '0';
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        cout << findKthBit(n, k) << endl;
    }

    return 0;
}