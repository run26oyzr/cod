#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3 * 1e5 + 5, maxk = 128;
char ss[maxn];
int s[maxn];
struct Node{
	int first, second, id;
}a[maxn], b[maxn];
int idx[maxn];
int sa[maxn], rk[maxn << 1], c[maxn];
int n;
void getSA(){
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++) c[s[i]]++;
	for (int i = 1; i < 128; i++) c[i] += c[i - 1];
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
int height[maxn];
void getHeight(){
	int k = 0;
	for (int i = 1; i <= n; i++){
		if (rk[i] == 1) continue;
		if (k != 0) k--;
		while(s[sa[rk[i] - 1] + k] == s[i + k]) k++;
		height[rk[i]] = k;
	}
} 
struct node{
    int height, id;
    bool operator < (const node T) const{
        return height > T.height;
    }
}t[maxn];
int val[maxn];
int ans1[maxn], ans2[maxn];
int Max[maxn], Min[maxn];
int size[maxn];
int fa[maxn];
int getfather(int x){
    if (fa[x] == x) return x;
    return fa[x] = getfather(fa[x]);
}
void merge(int x, int y, int h){
    int fx = getfather(x);
    int fy = getfather(y);
    if (fx == fy) return;
    ans1[h] += size[fx] * size[fy];
    size[fx] += size[fy];
    ans2[h] = max(ans2[h], max(Max[fx] * Max[fy], Min[fx] * Min[fy]));
    Max[fx] = max(Max[fx], Max[fy]);
    Min[fx] = min(Min[fx], Min[fy]);
    fa[fy] = fx;
}
signed main(){
    cin >> n;
	cin >> ss + 1;
	for (int i = 1; i <= n; i++) s[i] = ss[i];
    for (int i = 1; i <= n; i++) cin >> val[i];
	getSA();
    getHeight();
    for (int i = 2; i <= n; i++){
        t[i].height = height[i];
        t[i].id = i;
    }
    sort(t + 2, t + n + 1);
    for (int i = 1; i <= n; i++){
        fa[i] = i;
        size[i] = 1;
        Max[i] = Min[i] = val[i];
    }
    memset(ans2, -0x3f, sizeof(ans2));
    for (int i = 2; i <= n; i++){
        // cout << t[i].id << endl;
        // cout << sa[t[i].id - 1] <<  ' ' << sa[t[i].id] << ' ' << t[i].height << endl;
        merge(sa[t[i].id - 1], sa[t[i].id], t[i].height);
    }
    for (int i = n - 1; i >= 0; i--){
        ans1[i] += ans1[i + 1];
        ans2[i] = max(ans2[i], ans2[i + 1]);
    }
    for (int i = 1; i <= n; i++){
        if (ans1[i] == 0) ans2[i] = 0;
    }
    for (int i = 0; i < n; i++){
        cout << ans1[i] << ' ' << ans2[i] << endl;
    }
	return 0;
}