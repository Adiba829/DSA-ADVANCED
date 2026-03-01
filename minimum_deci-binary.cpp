#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    cin >> n;   // input number as string
    
    int maxDigit = 0;

    for (char c : n) {
        maxDigit = max(maxDigit, c - '0');
    }

    cout << maxDigit << endl;  // output result
    
    return 0;
}