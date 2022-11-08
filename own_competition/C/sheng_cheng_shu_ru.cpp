#include<bits/stdc++.h>
#include<windows.h>
#define int long long
using namespace std;
long long random(long long x, long long y){
	long long rand_ = rand() * rand() + rand();
	rand_ *= rand();
	rand_ += rand();
	return rand_ % (x - y + 1) + x;
}
signed main(){
	srand(time(0));
    for (int id = 1; id <= 10; id++){
        freopen(("./own_competition/C/yang_li/interval" + std::to_string(id) + ".in").c_str(), "w", stdout);
		long long n;
        if (id <= 2) n = 200;
        else if (id <= 4) n = 1000;
        else n = 100000;
		cout << n << ' ';
		long long k = random(1, 1e12);
		cout << k << endl;
		for (int i = 1; i <= n; i++){
			long long l = random(-1e12, 1e12);
			long long a = random(0, 1e12 - l - k);
			long long r = l + k + a;
			cout << l << ' ' << r << endl;
		}
    }
}