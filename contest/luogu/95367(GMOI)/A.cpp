#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
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
char c[maxn][maxn];
int a[10];
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            c[i][j] = '.';
        }
    }
    for (int i = 0; i <= k; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        int val = 0;
        for (int j = 0; j <= k; j++){
            val += a[j] * pow(i - 1, j);
        }
        // cout << i - 1 << ' ' << val << endl;
        if (val < m) c[i][val + 1] = '*';
    }
    for (int i = m; i >= 1; i--){
        for (int j = 1; j <= n; j++){
            cout << c[j][i];
        }
        cout << endl;
    }
    return 0;
}