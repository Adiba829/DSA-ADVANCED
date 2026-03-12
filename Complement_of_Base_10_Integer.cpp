<<<<<<< HEAD
#include <iostream>
using namespace std;

int bitwiseComplement(int n) {

    if (n == 0) return 1;

    int mask = 0;
    int temp = n;

    while (temp) {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }

    return mask ^ n;
}

int main() {

    int n;
    cin >> n;

    cout << bitwiseComplement(n);

    return 0;
=======
#include <iostream>
using namespace std;

int bitwiseComplement(int n) {

    if (n == 0) return 1;

    int mask = 0;
    int temp = n;

    while (temp) {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }

    return mask ^ n;
}

int main() {

    int n;
    cin >> n;

    cout << bitwiseComplement(n);

    return 0;
>>>>>>> 77f8565a05a3e9b307013f22823b037b0e9aa6eb
}