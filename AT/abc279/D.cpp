#include <bits/stdc++.h>
#define int long long
using namespace std;
    int A, B;
long double solve (long double x){
    long double a = A * 1.0;
    long double sqrt_ = sqrtl(x + 1);
    long double b = B * 1.0;
    return x * b + a / sqrt_;
}
signed main() {
    cin >> A >> B;
    int l = 0, r = A, mid;
    while(r - l > 1){
        mid = (l + r) / 2;
        if (solve(mid - 1) > solve(mid)) l = mid;
        else r = mid;
    }
    printf("%.10Lf", solve(l));
    // system("pause");
    return 0;
}