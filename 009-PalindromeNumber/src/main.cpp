#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int x;
    cout << "Please input the number you need to judge:" << endl;
    cin >> x;
    bool isPdNum = true;
    int arr[10];
    int i = 0;
    if (x < 0) {
        return false;
    }
    while (x != 0) {
        int n = x % 10;
        x = (x - n) / 10;
        arr[i] = n;
        // cout << arr[i] << endl;
        i++;
    }
    for (int j = 0; j < i / 2; j++) {
        cout << j << ":" << arr[j] << "  " << i - j - 1 << ":" << arr[i - j - 1] << endl;
        if (arr[j] != arr[i - j - 1]) {
            isPdNum = false;
            break;
        }
    }

    cout << isPdNum << endl;
}