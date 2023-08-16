#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e3 + 5;
int ss[maxn], s[maxn];
struct Node{
	int first, second, id;
}a[maxn], b[maxn];
int idx[maxn], c[maxn];
int sa[maxn], rk[maxn << 1];
int n;
void getSA(){
	memset(c, 0, sizeof(c));
    memset(idx, 0, sizeof(idx));
	for (int i = 1; i <= n; i++) c[s[i]]++;
	for (int i = 1; i <= 176; i++) c[i] += c[i - 1];
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
bool check(int x){
    int maxnum = sa[1], minnum = sa[1];
    for (int i = 2; i <= n; i++){
        if (height[i] >= x){
            maxnum = max(maxnum, sa[i]);
            minnum = min(minnum, sa[i]);
            if (maxnum - minnum > x) return true;
        }else{
            maxnum = sa[i];
            minnum = sa[i];
        }
    }
    return false; 
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ss[i];
    n--;
    for (int i = 1; i <= n; i++)
        s[i] = ss[i + 1] - ss[i] + 88;
    getSA();
    getHeight();
    int l = 0, r = n;
    while (l < r){
        int mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else 
            r = mid - 1;
    }
    int ans = l + 1;
    if (ans <= 4)
        cout << 0;
    else cout << ans;
	return 0;
}