#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    int lens = s.length();
    int lent = t.length();
    if (lens < lent){
        cout << "No";
        // system("pause");
        return 0;
    }
    for (int i = 0; i < lens - lent + 1; i++){
        for (int j = 0; j < lent; j++){
            if (s[i + j] != t[j]) break;
            if (j == lent - 1){
                cout << "Yes";
                // system("pause");
                return 0;
            }
        }
    }
    cout << "No";
    // system("pause");
    return 0;
}