#include <bits/stdc++.h>
using namespace std;
int rand(int l, int r){
    return rand() % (r - l + 1) + l;
}
int main(){
    srand(time(0));
    int n = rand(1, 2 * 1e3);
    int m = rand(1, 2 * 1e3);
    cout << n << ' ' << m << endl;
    int opt;
    int l, r, val;
    while(m--){
        opt = rand(1, 2);
        cout << opt << ' ';
        l = rand(1, n);
        r = rand(l, n);
        cout << l << ' ' << r;
        if (opt == 1){
            cout << endl;
        }else{
            val = rand(1, 1000);
            cout << ' ' << val << endl;
        }
    }
    return 0;
}