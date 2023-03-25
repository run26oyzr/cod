#include <bits/stdc++.h>
using namespace std;
#define int long long
const int try_range = 10;
int p[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int used[1005], tot;
long long countn(long long n, int x){
    long double ans = pow(n, (long double)1.0 / x);
    for (int i = ans - try_range; i <= ans + try_range; i++){
        if (i < 0) continue;
        if (pow(i, x) > n) return i - 1;
    }
}
long long countnum(long long n, int x){
	return countn(n, x) - 1;
}
signed main(){
    long long n;
    int K;
    scanf("%lld %lld", &n, &K);
    if (K == 1){
        printf("%lld", n);
        return 0;
    }
    if (K >= 3) return 0;
    long long ans = 1;
    for (int i = 0; i < 17; i++){
        if (p[i] >= K){
			long long tmp = countnum(n, p[i]);
			if(!tmp) break;
			//cout << n << ' ' << p[i] << endl;
			//cout << "--------tmp:" << tmp << endl;
            ans += tmp;
            used[++tot] = p[i];
        }
		else{
			for (int j = 2; j * p[i] <= 60 && j <= p[i]; j++){
				bool flag = false;
				for (int k = 1; k <= 17; k++){
					if (p[k] >= K && j % p[k] == 0){flag = true; break;}
				}
				if(flag) continue;
				long long tmp = countnum(n, p[i] * j);
				if(!tmp) break;
				//cout << n << ' ' << p[i] * j << endl;
				//cout << "--------tmp:" << tmp << endl;
				ans += tmp;
				used[++tot] = p[i] * j;
			}
		}
    }
    //cout << ans << endl;
    for (int i = 1; i <= tot; i++){
        for (int j = i + 1; j <= tot; j++){
            ans -= countnum(n, used[i] * used[j]);
            //cout << i << ' ' << j << ' ' << ans << endl;
        }
    }
    for (int i = 1; i <= tot; i++){
        for (int j = i + 1; j <= tot; j++){
            for (int k = j + 1; k <= tot; k++){
                ans += countnum(n, used[i] * used[j] * used[k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
