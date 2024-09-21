#include <iostream>
#include <string>

using namespace std;

int minInsertionsDeletionsToMakeValid(string s) {
    int balance = 0;  
    int insertionsOrDeletions = 0;

    for (char c : s) {
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            balance--;
            if (balance < 0) {

                insertionsOrDeletions++;
                balance = 0;  
            }
        }
    }

    insertionsOrDeletions += balance;

    return insertionsOrDeletions;
}

int main() {
    string s;
    cin >> s;

    int result = minInsertionsDeletionsToMakeValid(s);
    cout << result << endl;

    return 0;
}
