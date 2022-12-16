#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

inline int read()
{
    register int x = 0,f = 1;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') 
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int bsize;
int book[maxn], a[maxn], sum[maxn], flag[maxn];
void change(int L, int R, int c){
    //前面非整块
    int e = min(R, book[L]*bsize);
    for(int i = L; i<=e; i++){
        sum[book[L]] += c;
        a[i] += c;
    }
    //中间的整段
    for (int i = book[L] + 1; i <= book[R] - 1; i++){
        sum[i] += bsize * c;
        flag[i] += c;
    }
    //后面非整块
    if (book[L] != book[R]){
        for (int i = (book[R] - 1) * bsize + 1; i <= R; i++){
            sum[book[i]] += c;
            a[i] += c;
        }
    }
}
int query(int L, int R){
    int res = 0;
    //前面非整块
    int e = min(R, book[L]*bsize);
    for(int i = L; i <= e; i++){
        res += a[i] + flag[book[i]];
    }
    //中间的整段
    for (int i = book[L] + 1; i <= book[R] - 1; i++){
        res += sum[i];
    }
    //后面非整块
    if (book[L] != book[R]){
        for (int i = (book[R] - 1) * bsize + 1; i <= R; i++){
            res += a[i] + flag[book[i]];
        }
    }
    return res;
}
int n, m;
void init(){
    n = read(), m = read();
    bsize = sqrt(n);
    for(int i = 1; i <= n; i++) book[i] = (i - 1) / bsize + 1;
    for(int i = 1; i <= n; i++){
        a[i] = read();
        sum[book[i]] += a[i];
    }
}
int main(){
    init();
    int opt, L, R, c;
    while(m--){
        cin >> opt >> L >> R;
        if (opt == 1){
            cin >> c;
            change(L, R, c);
        }
        else cout << query(L, R) << endl;
    }
}
