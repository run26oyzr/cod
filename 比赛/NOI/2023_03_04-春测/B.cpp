#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int used[1005], tot;
long long countn(long long n, int x){
    if(x >= 60) return 1;
    if(x == 2){
		long long res = sqrt(n);
		for (int i = res - 5; i <= res + 5; i++)
			if (i * i > n) return i - 1;
	}
    else if(x == 3){
        long long l = 1, r = sqrt(n);
        while(l < r){
			//cout << l << ' ' << r << endl;
            int mid = (l + r) >> 1;
            long double tmp1 = mid * mid * 1.0;
            long double tmp2 = n / mid * 1.0;
            if (tmp1 == tmp2) return mid;
            if (tmp1 < tmp2) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
    else if(x == 4){
		long long res = sqrt(sqrt(n));
		for (int i = res - 5; i <= res + 5; i++)
			if (i * i * i * i > n) return i - 1;
	}
    else{
        for (int i = 1; i <= n; i++){
            long double tmp = pow(i, x);
            if (tmp > n){
                return i - 1;
            }
        }
    }
    return 1;
}
long long countnum(long long n, int x){
	return countn(n, x) - 1;
}
signed main(){
	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout);
    long long n;
    int K;
    scanf("%lld %lld", &n, &K);
    if (K == 1){
        printf("%lld", n);
        return 0;
    }
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
