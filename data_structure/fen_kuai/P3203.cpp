#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;

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

int bsize, n;
int book[maxn], a[maxn], num[maxn], pos[maxn];
void change(int x, int c){
    
    if (x + c <= min(n, book[x] * bsize)){
        num[x] = num[x + c] + 1;
        pos[x] = pos[x + c];
    }
    else{
        num[x] = 1;
        pos[x] = x + c;
    }
    
    for (int i = x - 1; i >= (book[x] - 1) * bsize + 1; i--){
        if (i + a[i] <= min(n, book[x] * bsize)){
            num[i] = num[i + a[i]] + 1;
            pos[i] = pos[i + a[i]];
        }
        else{
            num[i] = 1;
            pos[i] = i + a[i];
        }
    }
}
int query(int i){
    int res = 0;
    int nowpos = i;
    while (nowpos <= n){
        res += num[nowpos];
        nowpos = pos[nowpos];
    }
    return res;
}
void init(){
    n = read();
    bsize = sqrt(n);
    for(int i = 1; i <= n; i++) book[i] = (i - 1) / bsize + 1;
    for(int i = 1; i <= n; i++){
        a[i] = read();
    }
    // num[n] = 1; pos[n] = n + 1;
    for (int i = n; i >= 1; i--){
        if (i + a[i] <= min(n, book[i] * bsize)){
            num[i] = num[i + a[i]] + 1;
            pos[i] = pos[i + a[i]];
        }
        else{
            num[i] = 1;
            pos[i] = i + a[i];
        }
    }
}
int main(){
    init();
    int m = read();
    int opt, i, k;
    // for (int i = 1; i <= n; i++){
    //     cout << num[i] << ' ' << pos[i] << endl;
    // }
    while(m--){
        opt = read(); i = read();
        if (opt == 2){
            k = read();
            change(i + 1, k);
            // for (int i = 1; i <= n; i++){
            //     cout << num[i] << ' ' << pos[i] << endl;
            // }
        }
        else cout << query(i + 1) << endl;
    }
}
