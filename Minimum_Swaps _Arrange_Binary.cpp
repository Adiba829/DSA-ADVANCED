#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;   // number of test cases

    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> grid(n, vector<int>(n));

        // Input grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        vector<int> zeros(n);

        // Step 1: count trailing zeros
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                count++;
            }
            zeros[i] = count;
        }

        int swaps = 0;
        bool possible = true;

        // Step 2: greedy placement
        for (int i = 0; i < n; i++) {
            int required = n - i - 1;
            int j = i;

            while (j < n && zeros[j] < required)
                j++;

            if (j == n) {
                possible = false;
                break;
            }

            while (j > i) {
                swap(zeros[j], zeros[j - 1]);
                swaps++;
                j--;
            }
        }

        if (!possible)
            cout << -1 << endl;
        else
            cout << swaps << endl;
    }

    return 0;
}