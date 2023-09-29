#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxk = 2e5 + 5;
struct Node{
    int a, b, c;
    int id;
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
int k;
struct Tree_Array{
    int tree[maxk];
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
    int i = L, j = mid + 1, k = L, sum = 0;
    while (i <= mid && j <= R){
        if (t[i].b <= t[j].b){
            Tree.add(t[i].c, t[i].cnt);
            tmp[k++] = t[i++];
        }else{
            ans[t[j].id] += Tree.sum(t[j].c);
            tmp[k++] = t[j++];
        }
    }
    int ii = i - 1;
    while (i <= mid)
        tmp[k++] = t[i++];
    while (j <= R){
        ans[t[j].id] += Tree.sum(t[j].c);
        tmp[k++] = t[j++];
    }
    for (int i = L; i <= ii; i++)
        Tree.add(t[i].c, -t[i].cnt);
    for (int i = L; i <= R; i++)
        t[i] = tmp[i];
}
int cnt[maxn];
int main(){
    int n;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        scanf("%d %d %d", &t[i].a, &t[i].b, &t[i].c);
        t[i].id = i;
    }
    sort(t + 1, t + n + 1);
    int pos = 0;
    for (int i = 1; i <= n; i++){
        if (t[i].a == t[i - 1].a && t[i].b == t[i - 1].b && t[i].c == t[i - 1].c)
            t[pos].cnt++;
        else
            t[++pos] = t[i], t[pos].cnt = 1;
    }
    cdq(1, pos);
    for (int i = 1; i <= pos; i++)
        cnt[ans[t[i].id] + t[i].cnt - 1] += t[i].cnt;
    for (int i = 0; i < n; i++)
        cout << cnt[i] << endl;
}  
