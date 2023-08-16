#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int fa[maxn], c[maxn];
struct node{
    int x, y, val;
    bool operator < (const node T)const{
        return val > T.val;
    }
}t[maxn];
int getfather(int x){
    if (fa[x] == x) return x;
    int fx = getfather(fa[x]);
    c[x] = (c[x] + c[fa[x]]) % 2;
    return fa[x] = fx;
}
bool check(int d, int x, int y){
    int fx = getfather(x);
    int fy = getfather(y);
    if (fx == fy){
        return (c[x] + d - 1) % 2 == c[y];
    }
    else{
        fa[fy] = fx;
        c[fy] = (c[x] + d - 1 - c[y] + 2) % 2;
        return true;
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        fa[i] = i;
    }
    for (int i = 1; i <= k; i++){
        cin >> t[i].x >> t[i].y >> t[i].val;
    }
    sort(t + 1, t + k + 1);
    for (int i = 1; i <= k; i++){
        if (!check(2, t[i].x, t[i].y)){
            cout << t[i].val;
            system("Pause");
            return 0;
        }
    }
    cout << 0;
    system("Pause");
    return 0;
}