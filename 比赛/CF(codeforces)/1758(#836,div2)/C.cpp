#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    int n, x;
    while(T--){
        cin >> n >> x;
        if (n % x != 0) cout << -1 << endl;
        else{
            if (x == n){
                cout << x << ' ';
                for (int i = 2; i < n; i++) cout << i << ' ';
                cout << 1 << endl;
            }
            else{
                cout << x << ' ';
                for (int i = 2; i < x; i++) cout << i << ' ';
                cout << n << ' '; 
                for (int i = x + 1; i < n; i++) cout << i << ' ';
                cout << 1 << endl;
            }
        }
    }
    // system("pause");
    return 0;
}