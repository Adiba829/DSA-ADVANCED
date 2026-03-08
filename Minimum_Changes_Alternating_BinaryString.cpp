#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;   // number of test cases

    while(t--) {
        string s;
        cin >> s;

        int change1 = 0, change2 = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != (i % 2 ? '1' : '0'))
                change1++;

            if (s[i] != (i % 2 ? '0' : '1'))
                change2++;
        }

        cout << min(change1, change2) << endl;
    }

    return 0;
}