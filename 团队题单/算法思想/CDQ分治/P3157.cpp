#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5, maxk = 1e5 + 5;
struct Node{
    int a, b, c;
    int id;
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
int K;
struct Tree_Array{
    int tree[maxk];
    int lowbit(int x){return x & (-x);}
    void add(int id, int val){
        while (id < maxk){
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
int ans1[maxn];
void cdq1(int L, int R){
    if (L == R)
        return;
    int mid = (L + R) >> 1;
    cdq1(L, mid);
    cdq1(mid + 1, R);
    int i = L, j = mid + 1, k = L;
    while (i <= mid && j <= R){
        if (t[i].b <= t[j].b){
            Tree.add(t[i].c, 1);
            tmp[k++] = t[i++];
        }else{
            ans1[t[j].id] += Tree.sum(K + 1) - Tree.sum(t[j].c);
            tmp[k++] = t[j++];
        }
    }
    int ii = i - 1;
    while (i <= mid)
        tmp[k++] = t[i++];
    while (j <= R){
        ans1[t[j].id] += Tree.sum(K + 1) - Tree.sum(t[j].c);
        tmp[k++] = t[j++];
    }
    for (int i = L; i <= ii; i++)
        Tree.add(t[i].c, -1);
    for (int i = L; i <= R; i++)
        t[i] = tmp[i];
}
int ans2[maxn];
void cdq2(int L, int R){
    if (L == R)
        return;
    int mid = (L + R) >> 1;
    cdq2(L, mid);
    cdq2(mid + 1, R);
    int i = L, j = mid + 1, k = L;
    while (i <= mid && j <= R){
        if (t[i].b >= t[j].b){
            Tree.add(t[i].c, 1);
            tmp[k++] = t[i++];
        }else{
            ans2[t[j].id] += Tree.sum(t[j].c);
            tmp[k++] = t[j++];
        }
    }
    int ii = i - 1;
    while (i <= mid)
        tmp[k++] = t[i++];
    while (j <= R){
        ans2[t[j].id] += Tree.sum(t[j].c);
        tmp[k++] = t[j++];
    }
    for (int i = L; i <= ii; i++)
        Tree.add(t[i].c, -1);
    for (int i = L; i <= R; i++)
        t[i] = tmp[i];
}
int pos[maxn];
signed main(){
    int n, m;
    cin >> n >> m;
    K = n;
    for (int i = 1; i <= n; i++)    
        t[i].b = i;
    for (int i = 1; i <= n; i++){
        cin >> t[i].c;
        pos[t[i].c] = i;
    }
    int x;
    for (int i = 1; i <= n; i++){
        t[i].id = 1;
        t[i].a = 1;
    }
    for (int i = 1; i <= m; i++){
        cin >> x;
        t[pos[x]].id = m - i + 1;
        t[pos[x]].a = m - i + 1;
    }
    sort(t + 1, t + n + 1);
    cdq1(1, n);
    sort(t + 1, t + n + 1);
    cdq2(1, n);
    for (int i = 1; i <= m; i++){
        ans1[i] = ans1[i] + ans1[i - 1];
        ans2[i] = ans2[i] + ans2[i - 1];
    }
    for (int i = m; i >= 1; i--)
        cout << ans1[i] + ans2[i] << endl;
}  