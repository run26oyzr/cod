#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 235;
const double eps = 1e-6;
struct AC
{
    int c[26], fail, sum; double punish;
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
        st[a].punish += st[st[a].fail].punish;
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
    double m[maxn][maxn];
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
    void mulrow(int i, double mul)
    {
        for (int j = 0; j < n; j++)
        {
            m[i][j] = m[i][j] * mul;
        }
    }
    void oprow(int src, double mul, int dst)
    {
        for (int j = 0; j < n; j++)
        {
            m[dst][j] += m[src][j] * mul;
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
            int maxi = i;
            for (int j = i + 1; j < n; j++)
            {
                if (fabs(m[j][i]) > fabs(m[maxi][i]))
                    maxi = j;
            }
            swprow(i, maxi);
            b.swprow(i, maxi);
            if (fabs(m[i][i]) < eps)
            {
                continue;
            }
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    double k = -m[j][i] / m[i][i];
                    oprow(i, k, j);
                    b.oprow(i, k, j);
                }
            }
            double k = 1 / m[i][i];
            mulrow(i, k);
            b.mulrow(i, k);
        }
        for (int i = 0; i < n; i++)
        {
            if (fabs(m[i][i]) < eps)
            {
                for (int j = 0; j < n; j++)
                {
                    if (fabs(b.m[i][j]) > eps)
                        throw "-1";
                }
            }
        }
    }
};
signed main()
{
    freopen("jail0.in", "r", stdin);
    freopen("jail.out", "w", stdout);
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
    double inv26 = (double)1 / 26;
    Matrix A = 0, b = 0;
    for (int j = 0; j < 26; j++)
        for (int i = 0; i < n; i++)
            if (!st[i].end)
                A.m[st[i].c[j]][i] = A.m[st[i].c[j]][i] + inv26;
    
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
            A.m[i][j] = (i == j) - A.m[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<A.m[i][j]<<" ";
        }
        cout<<endl;
    }
    A.eliminate(b);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << b.m[i][0] << " ";
    // }
    // cout << endl;
    double ans = 0;
    for(int i=0;i<n;i++) ans += st[i].punish * b.m[i][0];
    cout<<ans<<endl;
    return 0;
}