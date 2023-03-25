#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2505];
signed main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for (int i = 1; i <= n * n; i++){
            if (i % 2 == 1) a[i] = (i + 1) / 2;
            else a[i] = n * n - i / 2 + 1;
        }
        for (int i = 1; i <= n; i++){
            if (i % 2 == 1){
                for (int j = 1; j <= n; j++){
                    cout << a[(i - 1) * n + j] << ' ';
                }
            }else{
                for (int j = n; j >= 1; j--){
                    cout << a[(i - 1) * n + j] << ' ';
                }
            }
            cout << endl;
        }
    }
    return 0;
}