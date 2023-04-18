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

int bsize, n, m;
int book[maxn], a[maxn], num[maxn], pos[maxn];
void change(int x, int c){
    a[x] = c;
    for (int i = x; i >= (book[x] - 1) * bsize + 1; i--){
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
int ans, ans2;
void query(int i){
    int res = 0;
    int nowpos = i;
    while (nowpos <= n){
        ans = nowpos;
        int oldpos = nowpos;
        res += num[nowpos];
        nowpos = pos[nowpos];
        if (nowpos > n){
            int tmp = oldpos;
            while(oldpos + a[oldpos] <= min(book[tmp] * bsize, n)){
                oldpos = oldpos + a[oldpos];
            }
            ans = oldpos;
        }
        ans2 = res;
    }
    return;
}
void init(){
    n = read(); m = read();
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
    int opt, i, k;
    // for (int i = 1; i <= n; i++){
    //     cout << num[i] << ' ' << pos[i] << endl;
    // }
    while(m--){
        opt = read(); i = read();
        if (opt == 0){
            k = read();
            change(i, k);
            // for (int i = 1; i <= n; i++){
            //     cout << num[i] << ' ' << pos[i] << endl;
            // }
        }
        else{
            query(i);
            printf("%d %d\n", ans, ans2);
        }
    }
}
