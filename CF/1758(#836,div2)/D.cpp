#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int T;
    cin >> T;
    int n;
    while(T--){
        cin >> n;
        if (n % 2 == 1){
            for (int i = 0; i < n; i++) cout << n * (n - 1)  * (n - 1) - (n - 1) / 2 * n + i * n << ' ';
        }
        else{
            for (int i = n - n / 2; i < n; i++) cout << i << ' ';
            for (int i = n + 1; i <= n + n / 2; i++) cout << i << ' ';
        }
        cout << endl;
    }
    // system("pause");
    return 0;
    /*
    for (double i = 0.5; i < 1; i += 0.001){
        double x = i + 1;
        cout << i << "     " << pow(x,3) - pow(i, 3) << endl;
    }
    for (int fenmu = 1; fenmu <= 100000; fenmu++){
        for (int fenzi = 1; fenzi <= fenmu; fenzi++){
            long double x = 1.0 * fenzi / fenmu;
            long double y = x + 1;
            // cout << x << "     " << pow(y,3) - pow(x, 3) << endl;
            if (abs(pow(y, 3) - pow(x, 3) - 4) <= 0.00000001) {
                // cout << fenzi << '/' << fenmu << "     " << pow(y, 3) - pow(x, 3);
                printf("%d/%d     %.10Lf        %.10Lf\n", fenzi, fenmu, pow(y, 3) - pow(x, 3), pow(y, 13) - pow(x, 13));
            }
        }
    }
    */
    system("pause");
}