#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int maxlen = 1e5 + 5;
const int base = 167;
int h1[maxlen], h2[maxlen];
void Hash(char s[], int h[]){
    int n = strlen(s + 1);
    int res = 0;
    h[0] = 0;
    for (int i = 1; i <= n; i++){
        h[i] = h[i - 1] * base + s[i];
    }
}
int base_pow[maxlen];
int getSub(int L, int R, int h[]){
    return h[R] - h[L - 1] * base_pow[R - L + 1];
}
void init(){
    base_pow[0] = 1;
    for (int i = 1; i < maxlen; i++)
        base_pow[i] = base_pow[i - 1] * base;
}
char s[maxlen], ss[maxlen];
int f[15][maxlen];
int start_[15], len_[15];
int sum[maxlen];
signed main(){
    init();
    cin >> s + 1;
    int len = strlen(s + 1), m = 1;
    s[0] = '!'; start_[1] = 1;
    for (int i = 1; i <= len; i++)
        if (s[i] == '*' || s[i] == '?'){
            if (i == 1)
                m--;
            m++;
            start_[m] = i + 1;
            len_[m - 1] = start_[m] - start_[m - 1] - 1;
        }
    len_[m] = len - start_[m] + 1;
    Hash(s, h1);
    int n;
    cin >> n;
    while (n--){
        cin >> ss + 1;
        Hash(ss, h2);
        int Len = strlen(ss + 1);
        memset(f, 0, sizeof(f)); //一开始忘清空了
        f[0][0] = 1;
        for (int i = 0; i <= Len; i++)
            sum[i] = 1;
        for (int i = 1; i <= m; i++){
            char c = s[start_[i] - 1];
            for (int j = len_[i]; j <= Len; j++){
                if (len_[i] == 0 || getSub(start_[i], start_[i] + len_[i] - 1, h1) == getSub(j - len_[i] + 1, j, h2)){
                    if (c == '!')
                        f[i][j] = f[i - 1][j - len_[i]];
                    else if (c == '?') //写成 if 了
                        f[i][j] = f[i - 1][j - len_[i] - 1];
                    else
                        f[i][j] = sum[j - len_[i]];
                }
            }
            sum[0] = 0;
            for (int j = 1; j <= Len; j++)
                sum[j] = sum[j - 1] | f[i][j]; //写成了 sum[i]
        }
        cout << (f[m][Len] ? "YES" : "NO") << endl;
    }
    return 0;
}