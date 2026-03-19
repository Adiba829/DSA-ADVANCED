#include <iostream>
#include <vector>
using namespace std;

int numberOfSubmatrices(vector<vector<char>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> px(m, vector<int>(n, 0));
    vector<vector<int>> py(m, vector<int>(n, 0));

    int ans = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            // Build prefix for X and Y
            px[i][j] = (grid[i][j] == 'X');
            py[i][j] = (grid[i][j] == 'Y');

            if(i > 0) {
                px[i][j] += px[i-1][j];
                py[i][j] += py[i-1][j];
            }

            if(j > 0) {
                px[i][j] += px[i][j-1];
                py[i][j] += py[i][j-1];
            }

            if(i > 0 && j > 0) {
                px[i][j] -= px[i-1][j-1];
                py[i][j] -= py[i-1][j-1];
            }

            // Check condition
            if(px[i][j] == py[i][j] && px[i][j] > 0) {
                ans++;
            }
        }
    }

    return ans;
}

int main() {

    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    cout << numberOfSubmatrices(grid);

    return 0;
}