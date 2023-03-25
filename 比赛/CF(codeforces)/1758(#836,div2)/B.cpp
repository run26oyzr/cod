#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    int n;
    while(T--){
        cin >> n;
        if (n % 2 == 1){
            for (int i = 1; i <= n; i++) cout << 1 << ' ';
        }
        else{
            cout << 1 << ' ' << 3 << ' ';
            for (int i = 3; i <= n; i++) cout << 2 << ' ';
        }
        cout << endl;
    }
    return 0;
}