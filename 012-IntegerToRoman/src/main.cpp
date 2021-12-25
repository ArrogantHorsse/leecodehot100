#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string intToRoman(int num) {
    int arr[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int arr2[13] = {0};
    string s[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;
    string result = "";
    while (num != 0) {
        int value = num / arr[i];
        num = num % arr[i];
        arr2[i] = value;
        ++i;
    }
    for (int m = 0; m < 13; m++) {
        string temp = s[m];
        for (int j = 0; j < arr2[m]; j++) {
            result = result + temp;
        }
    }
    return result;
}
int main() {
    int num;
    cout << "Please input the number you want to translate:" << endl;
    cin >> num;
    cout << intToRoman(num) << endl;
}