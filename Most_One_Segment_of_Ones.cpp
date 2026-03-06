#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.find("01") == string::npos)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}