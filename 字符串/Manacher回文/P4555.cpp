#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int n;
char s[maxn], s2[maxn];
int RL[maxn];
int l[maxn], r[maxn];
void manacher(){
	int maxR = 0, pos = 0;
	RL[0] = 1;
	for(int i = 1; i <= 2 * n + 1; i++){
		if(i < maxR) RL[i] = min(RL[pos * 2 - i], maxR - i);
		else RL[i] = 1;
		while(s2[i + RL[i]] == s2[i - RL[i]] && RL[i] < i) RL[i]++;
		if(maxR < i + RL[i]){maxR = i + RL[i]; pos = i;}
	}
}
int main(){
	cin >> s + 1;
	n = strlen(s + 1);
	for(int i = 1; i <= 2 * n + 1; i++){
		if(i % 2 == 0) s2[i] = s[i / 2];
		else s2[i] = '#';
	}
//	for(int i = 1; i <= 2 * n + 1; i++) cout << s2[i];
//	cout << endl;
	manacher();
    for(int i = 1; i <= 2 * n + 1; i++){
		l[i - RL[i] + 1] = max(l[i - RL[i] + 1], RL[i] - 1);
        r[i + RL[i] - 1] = max(r[i + RL[i] - 1], RL[i] - 1);
    }
	// for(int i = 1; i <= 2 * n + 1; i++) cout << l[i] << ' ';
    // cout << endl;
	// for(int i = 1; i <= 2 * n + 1; i++) cout << r[i] << ' ';
    // cout << endl;
	for(int i = 1; i <= 2 * n + 1; i += 2) l[i] = max(l[i], l[i - 2] - 2);
    for(int i = 2 * n + 1; i >= 1; i -= 2) r[i] = max(r[i], r[i + 2] - 2);
	// for(int i = 1; i <= 2 * n + 1; i++) cout << l[i] << ' ';
    // cout << endl;
	// for(int i = 1; i <= 2 * n + 1; i++) cout << r[i] << ' ';
    for(int i = 1; i <= 2 * n + 1; i += 2){
        if(l[i] == 0) l[i] = -1e9;
        if(r[i] == 0) r[i] = -1e9;
    }
    int ans = 0;
    for(int i = 1; i <= 2 * n + 1; i += 2) ans = max(ans, l[i] + r[i]);
    cout << ans;
    return 0;
}