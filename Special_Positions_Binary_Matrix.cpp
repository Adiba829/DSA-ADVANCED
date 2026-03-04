#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t; 

    while(t--) {
        int m, n;
        cin >> m >> n; 

        vector<vector<int>> mat(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }

        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 &&
                    rowCount[i] == 1 &&
                    colCount[j] == 1) {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}