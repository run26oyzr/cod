#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n;
char s[maxn], s2[maxn];
int RL[maxn];
void manacher(){
	int maxR = 0, pos = 0;
	RL[0] = 1;
	for (int i = 1; i <= n; i++){
		if (i < maxR) RL[i] = min(RL[pos * 2 - i], maxR - i);
		else RL[i] = 1;
		while (s[i + RL[i]] == s[i - RL[i]] && RL[i] < i) RL[i]++;
		if (maxR < i + RL[i]){maxR = i + RL[i]; pos = i;}
	}
}
bool flag[maxn];
int main(){
    int T;
    cin >> T;
    while (T--){
        memset(flag, 0, sizeof(flag));
        cin >> s + 1;
        n = strlen(s + 1);
        manacher();
        for (int i = n; i >= 1; i--){
            if (i + RL[i] - 1 == n) flag[i] = true;
            if (flag[i + RL[i] - 1] && i + RL[i] - 1 == 2 * i - 1) flag[i] = true;
        }
        for (int i = 1; i <= n; i++){
            if (flag[i])
                cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}