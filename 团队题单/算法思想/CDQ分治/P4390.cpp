#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
struct Node{
    int a, b, c;
    int id, op;
    int cnt;
    bool operator < (const Node T) const{
        if (a == T.a)
            if (b == T.b)
                return c < T.c;
            else
                return b < T.b;
        else
            return a < T.a;
    }
}t[maxn], tmp[maxn];
int ans[maxn];
int k = 2e5;
struct Tree_Array{
    int tree[maxn];
    int lowbit(int x){return x & (-x);}
    void add(int id, int val){
        while (id <= k){
            tree[id] += val;
            id += lowbit(id);
        }
    }
    int sum(int id){
        int res = 0;
        while (id > 0){
            res += tree[id];
            id -= lowbit(id);
        }
        return res;
    }
}Tree;
void cdq(int L, int R){
    if (L == R)
        return;
    int mid = (L + R) >> 1;
    cdq(L, mid);
    cdq(mid + 1, R);
    int i = L, j = mid + 1, k = L;
    while (i <= mid && j <= R){
        if (t[i].b <= t[j].b){
            if (t[i].op == 0)
                Tree.add(t[i].c, t[i].cnt);
            tmp[k++] = t[i++];
        }else{
            if (t[j].op == 1)
                ans[t[j].id] -= Tree.sum(t[j].c);
            if (t[j].op == 2)
                ans[t[j].id] += Tree.sum(t[j].c);
            tmp[k++] = t[j++];
        }
    }
    int ii = i - 1;
    while (i <= mid)
        tmp[k++] = t[i++];
    while (j <= R){
        if (t[j].op == 1)
            ans[t[j].id] -= Tree.sum(t[j].c);
        if (t[j].op == 2)
            ans[t[j].id] += Tree.sum(t[j].c);
        tmp[k++] = t[j++];
    }
    for (int i = L; i <= ii; i++)
        if (t[i].op == 0)
            Tree.add(t[i].c, -t[i].cnt);
    for (int i = L; i <= R; i++)
        t[i] = tmp[i];
}
signed main(){
    int nothing;
    cin >> nothing >> nothing;
    int n = 0, cnt = 0;
    int op, x1, y1, x2, y2;
    while (op != 3){
        cin >> op;
        if (op == 1){
            cin >> t[++n].a >> t[n].b >> t[n].cnt;
            t[n].op = 0;
            t[n].c = n;
        }else if (op == 2){
            cin >> x1 >> y1; //左下角
            cin >> x2 >> y2; //右上角
            ++cnt;
            //a, b, c, id, op, cnt
            t[++n] = {x1 - 1, y1 - 1, n, cnt, 2, 0}; //左下角，+
            t[++n] = {x2, y2, n, cnt, 2, 0}; //右上角，+
            t[++n] = {x1 - 1, y2, n, cnt, 1, 0}; //左上角，-
            t[++n] = {x2, y1 - 1, n, cnt, 1, 0}; //右下角，-
        }
    }
    sort(t + 1, t + n + 1);
    cdq(1, n);
    for (int i = 1; i <= cnt; i++)
        cout << ans[i] << endl;
}  