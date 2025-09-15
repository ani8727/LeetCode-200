//  1544. Make The String Great
#include <iostream>
using namespace std;

string makeGreat(string s) {
    string ans = "";  // act like stack

    for (char ch : s) {
        if (!ans.empty() && abs(ch - ans.back()) == 32) {
            // same letter, different case
            ans.pop_back();
        } else {
            ans.push_back(ch);
        }
    }

    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << makeGreat(s) << endl;
    return 0;
}
