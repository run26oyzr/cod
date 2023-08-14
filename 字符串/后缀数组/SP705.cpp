#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e4 + 5, maxk = 128;
char ss[maxn];
int s[maxn];
struct Node{
	int first, second, id;
}a[maxn], b[maxn];
int idx[maxn], c[maxn];
int sa[maxn], rk[maxn];
int n;
void getSA(){
	memset(c, 0, sizeof(c));
    memset(idx, 0, sizeof(idx));
	for (int i = 1; i <= n; i++) c[s[i]]++;
	for (int i = 1; i <= maxk; i++) c[i] += c[i - 1];
	for (int i = n; i >= 1; i--) idx[c[s[i]]--] = i;
	
	int tot = 0;
	for (int i = 1; i <= n; i++)
		if (s[idx[i]] == s[idx[i - 1]]) rk[idx[i]] = tot;
		else rk[idx[i]] = ++tot;
	
	for (int L = 1; L < n; L <<= 1){
		for (int i = 1; i <= n; i++){
			a[i].first = rk[i];
			a[i].second = rk[i + L];
			a[i].id = i;
		}
		memset (c, 0, sizeof(c));
		for (int i = 1; i <= n; i++) c[a[i].second]++;
		for (int i = 1; i <= n; i++) c[i] += c[i - 1];
		for (int i = n; i >= 1; i--) b[c[a[i].second]--] = a[i];
		memset (c, 0, sizeof(c));
		for (int i = 1; i <= n; i++) c[b[i].first]++;
		for (int i = 1; i <= n; i++) c[i] += c[i - 1];
		for (int i = n; i >= 1; i--) a[c[b[i].first]--] = b[i];
		tot = 0;
		for (int i = 1; i <= n; i++){
			if (a[i].first == a[i - 1].first && a[i].second == a[i - 1].second) rk[a[i].id] = tot;
			else rk[a[i].id] = ++tot;
		}
		if (tot >= n) break;
	}
	for (int i = 1; i <= n; i++) sa[rk[i]] = i;
}
int height[maxn];
void getHeight(){
	int k = 0;
	for (int i = 1; i <= n; i++){
		if (k != 0) k--;
		while(s[sa[rk[i] - 1] + k] == s[i + k]) k++;
		height[rk[i]] = k;
	}
} 
void init(){
    memset(s, 0, sizeof(s));
    memset(sa, 0, sizeof(sa));
    memset(rk, 0, sizeof(rk));
    memset(height, 0, sizeof(height));
}
int main(){
	int T;
	cin >> T;
	while (T--){
        init();
		cin >> ss + 1;
		n = strlen(ss + 1);
		for (int i = 1; i <= n; i++)
			s[i] = ss[i];
		getSA();
		getHeight();
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += n - i + 1 - height[i];
		cout << ans << endl;
	}
	return 0;
}