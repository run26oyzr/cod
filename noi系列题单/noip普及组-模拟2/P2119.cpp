#include <bits/stdc++.h>
using namespace std;
const int maxn = 15005, maxm = 40005;
int value[maxm], cnt[maxn];
int acnt[maxm], bcnt[maxm], ccnt[maxm], dcnt[maxm];
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		scanf("%d\n", &value[i]);
		cnt[value[i]] ++;
	}
	int A, B, C, D;
	for (int L = 1; L * 9 < n; L++){
        int tot = 0;
		for (D = 9 * L + 2; D <= n; D++){
			C = D - L;
			A = D - 9 * L - 1;
			B = A + 2 * L;
            tot += cnt[A] * cnt[B];
            ccnt[C] += tot * cnt[D];
            dcnt[D] += tot * cnt[D];
		}
        tot = 0;
        for (A = n - 9 * L - 1; A >= 1; A--){
            B = A + 2 * L;
            D = A + 9 * L + 1;
            C = D - L;
            tot += cnt[C] * cnt[D];
            acnt[A] += tot * cnt[A];
            bcnt[B] += tot * cnt[A];
        }
	}
    for (int i = 1; i <= m; i++){
        int x = value[i];
        printf("%d %d %d %d\n", acnt[x], bcnt[x], ccnt[x], dcnt[x]);
    }
    system("pause");
	return 0;
}