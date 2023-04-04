#include <bits/stdc++.h>
using namespace std;
int maxn = 1005, maxm = 2005;
bitset <1008> bst[2005]; 
int main(){
	int n, K;
	cin >> n >> K;
	for (int i = 1; i <= K; i++){
		string s;
		cin >> s;
		for (int j = 0; j < n; j++){
			bst[i][j] = s[j] - '0';
		}
		cin >> s;
		bst[i][n] = s[0] - '0';
	}
	int ans = 1;
	for (int i = 1; i <= n; i++){
		ans = max(ans, i);
		int r = i;
		if (bst[r][i - 1] == 0){	
			for (int j = i + 1; j <= K; j++){
				if (bst[j][i - 1] == 1){
					swap(bst[r], bst[j]);
					ans = max(ans, j);
					break;
				}
			}
            if (bst[r][i - 1] == 0){
                cout << "Cannot Determine";
                return 0;
            }
		}
		for (int j = 1; j <= K; j++){
			if (i == j) continue;
			if (bst[j][i - 1] == 1) bst[j] ^= bst[i];
		}
	}
	cout << ans << endl;
    for (int i = 1; i <= n; i++){
        if (bst[i][n] == 0) cout << "Earth" << endl;
        else cout << "?y7M#" << endl;
    }
	return 0;
}