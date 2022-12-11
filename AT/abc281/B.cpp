#include <bits/stdc++.h>
using namespace std;
bool check(string s){
    if (s[0] > 'Z' || s[0] < 'A') return false;
    if (s[s.length() - 1] > 'Z' || s[s.length() - 1] < 'A') return false;
    if (s.length() - 2 != 6) return false;
    if (s[1] == '0') return false;
    for (int i = 1; i < s.length() - 1; i++){
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}
int main(){
    string s;
    cin >> s;
    if(check(s)) cout << "Yes";
    else cout << "No";
    return 0;
}