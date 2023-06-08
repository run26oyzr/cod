#include <bits/stdc++.h>
#include <random>
using namespace std;
typedef long long ll;
mt19937 rng(time(0));
int main()
{
    for (int T = 0; T < 20; T++)
    {
        string fn = "jail" + to_string(T);
        FILE *input = freopen((fn + ".in").c_str(), "w", stdout);
        uniform_int_distribution<ll> lenR(185, 199);
        uniform_int_distribution<ll> n0R(3, 9);
        uniform_int_distribution<ll> n1R(3, 39);
        uniform_int_distribution<int> cR(0, 25);
        uniform_int_distribution<int> shortR(0, 255);
        int n;
        if(T < 10) n = n0R(rng);
        else n = n1R(rng);
        int l = lenR(rng);
        cout << n << endl;
        char s[205];
        bool split[205];
        uniform_int_distribution<int> spR(0, l - 1);
        for (int i = 0; i < l; i++)
            s[i] = 'a' + cR(rng);
        split[0] = 1;
        split[l] = 1;
        for (int i = 0; i < n; i++)
        {
            int r = spR(rng);
            while (split[r])
                r = spR(rng);
            split[r] = 1;
        }
        split[0] = 0;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if(shortR(rng) < 80) cout<<-1<<" ";
            else cout<<shortR(rng)<<" ";
            for (; !split[p]; p++)
            {
                cout << s[p];
            }
            split[p] = 0;
            cout << endl;
        }
        fclose(input);
        system(("./std < " + fn + ".in > " + fn + ".ans").c_str());
    }
    return 0;
}