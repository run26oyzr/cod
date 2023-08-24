#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e6 + 5;
const int base = 4;
int getnum(char c){
    if (c == 'A')
        return 0;
    else if (c == 'G')
        return 1;
    else if (c == 'C')
        return 2;
    else if (c == 'T')
        return 3;
    return 0;
}
int k;
int Hash(char s[]){
    int n = k;
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = res * base + getnum(s[i]);
    return res;
}
char s[maxn], ss[15];
int cnt[maxn];
signed main(){
    int n;
    scanf("%s", s + 1);
    scanf("%d", &k);
    n = strlen(s + 1);
    for (int i = 1; i <= n - k + 1; i++){
        for (int j = 1; j <= k; j++){
            ss[j] = s[i + j - 1];
        }
        cnt[Hash(ss)]++;
    }
    int ans = 0;
    for (int i = 0; i < maxn; i++)
        ans = max(ans, cnt[i]);
    printf("%d", ans);
    return 0;
}