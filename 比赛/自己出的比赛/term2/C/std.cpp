#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 209;
const int p = 998244353;
int qpow(int a, int b)
{
    int res = 1, mul = a % p;
    while (b)
    {
        if (b & 1)
            res = (res * mul) % p;
        mul = (mul * mul) % p;
        b >>= 1;
    }
    return res;
}
struct AC
{
    int c[26], fail, punish, sum;
    bool end;
} st[maxn];
int pos = 1;
int n;
int insert(string s)
{
    int a = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int c = s[i] - 'a';
        if (st[a].c[c] == 0)
            st[a].c[c] = pos++;
        a = st[a].c[c];
    }
    return a;
}
queue<int> q;
void build()
{
    for (int i = 0; i < 26; i++)
        if (st[0].c[i])
            q.push(st[0].c[i]);
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        st[a].punish += st[st[a].fail].punish; st[a].punish %= p;
        st[a].end |= st[st[a].fail].end;
        for (int i = 0; i < 26; i++)
        {
            if (st[a].c[i])
            {
                st[st[a].c[i]].fail = st[st[a].fail].c[i];
                q.push(st[a].c[i]);
            }
            else
            {
                st[a].c[i] = st[st[a].fail].c[i];
            }
        }
    }
}
struct Matrix
{
    int m[maxn][maxn];
    Matrix(int s = 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                m[i][j] = s & (i == j);
            }
        }
    }
    void mulrow(int i, int mul)
    {
        for (int j = 0; j < n; j++)
        {
            m[i][j] = m[i][j] * mul % p;
        }
    }
    void oprow(int src, int mul, int dst)
    {
        for (int j = 0; j < n; j++)
        {
            m[dst][j] = (m[src][j] * mul % p + m[dst][j]) % p;
        }
    }
    void swprow(int x, int y)
    {
        for (int j = 0; j < n; j++)
        {
            swap(m[x][j], m[y][j]);
        }
    }
    void eliminate(Matrix &b)
    {
        for (int i = 0; i < n; i++)
        {
            int maxi = 0;
            for (int j = i; j < n; j++)
            {
                if (m[j][i] != 0)
                {
                    maxi = j;
                    break;
                }
            }
            swprow(i, maxi);
            b.swprow(i, maxi);
            if (m[i][i] == 0)
            {
                cerr << "No Solution" << endl;
                throw "No";
            }
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    int k = ((p - m[j][i]) % p) * qpow(m[i][i], p - 2) % p;
                    oprow(i, k, j);
                    b.oprow(i, k, j);
                }
            }
            int k = qpow(m[i][i], p - 2);
            mulrow(i, k);
            b.mulrow(i, k);
        }
    }
};
signed main()
{
    // freopen("jail0.in", "r", stdin);
    // freopen("jail.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int c;
        string s;
        cin >> c >> s;
        int id = insert(s);
        if (c == -1)
            st[id].end = 1;
        else
            st[id].punish = c;
    }
    build();
    n = pos;
    int inv26 = qpow(26, p - 2);
    Matrix A = 0, b = 0;
    for (int j = 0; j < 26; j++)
        for (int i = 0; i < n; i++)
            if (!st[i].end)
                A.m[st[i].c[j]][i] = (A.m[st[i].c[j]][i] + inv26) % p;
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<A.m[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    b.m[0][0] = 1;
    // s = b + Ab + AAb + AAAb + ...   As + b = s b = (1 - A)s
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A.m[i][j] = ((p + (i == j) - A.m[i][j]) % p + p) % p;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<A.m[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    A.eliminate(b);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << b.m[i][0] << " ";
    // }
    // cout << endl;
    int ans = 0;
    for(int i=0;i<n;i++) ans = (ans + st[i].punish * b.m[i][0] % p) % p;
    cout<<ans<<endl;
    return 0;
}