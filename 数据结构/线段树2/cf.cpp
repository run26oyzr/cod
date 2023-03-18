#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int cnt_odd = 0, cnt_even = 0;
        int n;
        cin >> n;
        int x;
        for (int i = 1; i <= n; i++){
            cin >> x;
            if (x % 2 == 0) cnt_even ++;
            else cnt_odd ++;
        }
        cout << min(cnt_even, cnt_odd) << endl;
    }
    // system("Pause");
    return 0;
}