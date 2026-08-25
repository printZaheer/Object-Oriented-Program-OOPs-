#include <iostream>
using namespace std;

bool isPalindrome(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    int start = 0;
    int end = len - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int main() {
    char word[100];
    cout << "Enter a word: ";
    cin >> word;
    if (isPalindrome(word)) {
        cout << "Palindrome: Yes" << endl;
    } else {
        cout << "Palindrome: No" << endl;
    }
    return 0;
}
