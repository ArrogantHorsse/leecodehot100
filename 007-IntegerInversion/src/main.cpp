#include <iostream>
#include <queue>
#include <string>
using std::cin;
using std::cout;
using std::endl;

int getInversion(int x) {
    int fuhao = 1;
    int result = 0;
    if (x == -2147483648) {
        return 0;
    }
    if (x < 0) {
        x = -x;
        fuhao = 0;
    }
    while (x != 0) {
        int n = x % 10;
        if (result < 214748365) {
            result = result * 10 + n;
            x = (x - n) / 10;
        } else {
            result = 0;
            break;
        }
    }
    if (fuhao == 0) {
        result = -result;
    }
    return result;
}

int main() {
    int x;
    cout << "Please input the number you need to invert:" << endl;
    cin >> x;
    int result = getInversion(x);
    cout << "result = " << result << endl;
}