#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int a[55];
signed main(){
    int T;
    cin >> T;
    int x;
    while(T--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1, cmp);
        if (a[1] == a[n]) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            a[0] = a[n];
            for (int i = 0; i < n; i++){
                cout << a[i] << ' ';       
            }
            cout << endl;
        }
    }
    return 0;
}