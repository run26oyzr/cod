#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int T;
    cin >> T;
    while(T--){
        cin >> s;
        cout << s;
        int len = s.length();
        for (int i = len - 1; i >= 0; i--){
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}