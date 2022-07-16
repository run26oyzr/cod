#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5;
int a[maxn], tree[maxn], t[maxn];
int n;
int lowbit(int x) {return x & (-x);}
void change(int id, int val){
    while (id <= n){
        tree[id] += val;
        id += lowbit(id);
    }
}
int ask(int id){
    int res = 0;
    while (id >= 1){
        res += tree[id];
        id -= lowbit(id);
    }
    return res;
}
int main(){
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
        change(i, t[i] - t[i - 1]);
    }
    int x, y, z, xx;
    while (m--){
        cin >> x >> y;
        if (x == 1){
            cin >> z >> xx;
            change(y, xx);
            change(z + 1, -xx);
        }
        else if (x == 2){
            cout << ask(y) << endl;
        }
    }
    system("Pause");
    return 0;
}