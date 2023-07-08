#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 1e4 + 5, maxk = 128;
char ss[maxn];
int s1[maxn];
int s2[maxn]; 
struct Node{
	int first, second, id;
}a[maxn], b[maxn];
int idx[maxn], c[maxn];
int sa1[maxn], rk1[maxn << 1];
int sa2[maxn], rk2[maxn << 1];
int n;
void getSA(int *s, int *sa, int *rk){
	memset(c, 0, sizeof(c));
    memset(idx, 0, sizeof(idx));
	for (int i = 1; i <= n; i++) c[s[i]]++;
	for (int i = 1; i <= 128; i++) c[i] += c[i - 1];
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
		//基数排序，从低位到高位逐位进行计数排序
		//低位计数排序
		memset (c, 0, sizeof(c));
		for (int i = 1; i <= n; i++) c[a[i].second]++;
		for (int i = 1; i <= n; i++) c[i] += c[i - 1];
		for (int i = n; i >= 1; i--) b[c[a[i].second]--] = a[i];
		//高位计数排序
		memset (c, 0, sizeof(c));
		for (int i = 1; i <= n; i++) c[b[i].first]++;
		for (int i = 1; i <= n; i++) c[i] += c[i - 1];
		for (int i = n; i >= 1; i--) a[c[b[i].first]--] = b[i];
		//
		tot = 0;
		for (int i = 1; i <= n; i++){
			if (a[i].first == a[i - 1].first && a[i].second == a[i - 1].second) rk[a[i].id] = tot;
			else rk[a[i].id] = ++tot;
		}
		if (tot >= n) break;
	}
	for (int i = 1; i <= n; i++) sa[rk[i]] = i;
}
int height1[maxn];
int height2[maxn];
void getHeight(int *height, int *s, int *rk, int *sa){
	int k = 0;
	for (int i = 1; i <= n; i++){
		if (k != 0) k--;
		while(s[sa[rk[i] - 1] + k] == s[i + k]) k++;
		height[rk[i]] = k;
	}
} 
int d1[maxn][20];
int d2[maxn][20]; 
int log_[maxn];
void initST(int d[maxn][20], int *height){
	for (int i = 2; i < maxn; i++) log_[i] = log_[i >> 1] + 1;
	for (int i = 1; i <= n; i++) d[i][0] = height[i];
	for (int k = 1; (1 << k) <= n; k++){
		for (int i = 1; i <= n - (1 << k) + 1; i++){
			d[i][k] = min(d[i][k - 1], d[i + (1 << (k - 1))][k - 1]);
		}
	}
}
int query(int d[maxn][20], int L, int R){
	int k = log_[R - L + 1];
	return min(d[L][k], d[R - (1 << k) + 1][k]);
}
int lcp(int d[maxn][20], int L, int R, int *rk){
	int x = rk[L], y = rk[R];
	if (x > y) swap(x, y);
	return query(d, x + 1, y);  
}
int f[maxn], g[maxn];
void init(){
    memset(ss, 0, sizeof(ss));
    memset(s1, 0, sizeof(s1));
    memset(s2, 0, sizeof(s2));
    memset(sa1, 0, sizeof(sa1));
    memset(sa2, 0, sizeof(sa2));
    memset(rk1, 0, sizeof(rk1));
    memset(rk2, 0, sizeof(rk2));
    memset(height1, 0, sizeof(height1));
    memset(height2, 0, sizeof(height2));
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
}
int main(){
	int T;
	cin >> T;
	while (T--){
        init();
		cin >> ss + 1;
		n = strlen(ss + 1);
		for (int i = 1; i <= n; i++) s1[i] = ss[i];
		for (int i = 1; i <= n; i++) s2[n - i + 1] = s1[i];
		getSA(s1, sa1, rk1);
		getSA(s2, sa2, rk2);
		getHeight(height1, s1, rk1, sa1);
		getHeight(height2, s2, rk2, sa2);
		initST(d1, height1);
		initST(d2, height2);
		for (int len = 1; len <= n / 2; len++){
			for (int i = len; i <= n; i += len){
                int x = i, y = i + len;
                if (y > n) break;
				int lcp_ = min(lcp(d1, x, y, rk1), len);
				int lcs_ = min(lcp(d2, n - y + 2, n - x + 2, rk2), len - 1);
				int tmp = lcp_ + lcs_ - len + 1;
                if (lcp_ + lcs_ >= len){
                    // if (y + lcp_ - tmp == 4) cout << "----" << x << ' ' << y << ' ' << lcp_ << ' ' << lcs_ << ' ' << tmp << ' ' << len << endl; 
                    f[y + lcp_ - tmp] += 1; f[y + lcp_] -= 1;
                    g[x - lcs_] += 1; g[x - lcs_ + tmp] -= 1;
                }
			}
		}
		// for (int i = 1; i <= n; i++) cout << f[i] << ' ';
		// cout << endl; 
		// for (int i = 1; i <= n; i++) cout << g[i] << ' ';
		// cout << endl; 
		for (int i = 1; i <= n; i++){
			f[i] += f[i - 1];
			g[i] += g[i - 1];
		}
		// for (int i = 1; i <= n; i++) cout << f[i] << ' ';
		// cout << endl; 
		// for (int i = 1; i <= n; i++) cout << g[i] << ' ';
		// cout << endl; 
		long long ans = 0;
		for (int i = 1; i < n; i++){
			ans += f[i] * g[i + 1];
		}
		cout << ans << endl;
	}
	return 0;
}