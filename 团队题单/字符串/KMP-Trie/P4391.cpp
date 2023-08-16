#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int nxt[maxn];
char p[maxn], s[maxn]; //都是从1开始输入 p+1 s+1
void getNext(char p[]){
    int n = strlen(p + 1);
    nxt[1] = 0;
    int k = 0;
    for (int i = 2; i <= n; i++){
        while(k != 0 && p[k + 1] != p[i]) k = nxt[k];
        if (p[k + 1] == p[i]) k++;
        nxt[i] = k;
    }
}
void kmp(char p[], char s[]){ //p模式串, s文本串
    int n = strlen(s + 1);
    int m = strlen(p + 1);
    nxt[1] = 0;
    int k = 0;
    for (int i = 1; i <= n; i++){
        while(k != 0 && p[k + 1] != s[i]) k = nxt[k];
        if (p[k + 1] == s[i]) k++;
        if (k == m)
            printf("%d\n", i - m + 1);
    }
}
int main(){
    int n;
    cin >> n;
    cin >> p + 1;
    getNext(p);
    int ans = n - nxt[n];
    cout << ans;
    return 0;
}