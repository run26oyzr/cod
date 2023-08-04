#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3 * 1e6 + 5;
int a[maxn];
int nxt[maxn];
int n, m;
char p[maxn], s[maxn];
void getNext(char p[]){
    nxt[1] = 0;
    int k = 0;
    for (int i = 2; i <= m; i++){
        while(k != 0 && p[k + 1] != p[i]) k = nxt[k];
        if (p[k + 1] == p[i]) k++;
        nxt[i] = k;
    }
}
void kmp(char p[], char s[]){
    int k = 0;
    for (int i = 1; i <= n; i++){
        while(k != 0 && p[k + 1] != s[i]) k = nxt[k];
        if (p[k + 1] == s[i]) k++;
        if (k == m) a[i - m + 1] = 1;
    }
}

int RL[maxn];
void manacher(){
	int maxR = 0, pos = 0;
	RL[0] = 1;
	for(int i = 1; i <= n; i++){
		if(i < maxR) RL[i] = min(RL[pos * 2 - i], maxR - i);
		else RL[i] = 1;
		while(s[i + RL[i]] == s[i - RL[i]] && RL[i] < i) RL[i]++;
		if(maxR < i + RL[i]){maxR = i + RL[i]; pos = i;}
	}
}

int sum1[maxn], sum2[maxn];
signed main(){
    cin >> n >> m;
    cin >> s + 1 >> p + 1;
    getNext(p);
    kmp(p, s);
    for (int i = 1; i <= n; i++)
        sum1[i] = sum1[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
        sum2[i] = sum2[i - 1] + a[i] * i;
    manacher();
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int len = RL[i] - 1;
        int l = i - len;
        int r = i + len - m + 1;
        if (l > r) continue;
        int mid = (l + r) >> 1;
        ans += (sum2[mid] - sum2[l - 1]) - (sum1[mid] - sum1[l - 1]) * (l - 1);
        if (r > mid)
            ans += (sum1[r] - sum1[mid]) * (r + 1) - (sum2[r] - sum2[mid]); 
    }
    cout << ans % (long long)(pow(2, 32));
    return 0;
}