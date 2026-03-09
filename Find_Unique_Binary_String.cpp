#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<string> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    string ans = "";

    for(int i = 0; i < n; i++){
        if(nums[i][i] == '0')
            ans += '1';
        else
            ans += '0';
    }

    cout << ans;

}