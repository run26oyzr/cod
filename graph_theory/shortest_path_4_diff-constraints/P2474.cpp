#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int maxdis[maxn][maxn], mindis[maxn][maxn];
int main(){
    int n, A, B;
    cin >> n >> A >> B;
    char c;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> c;
            if (c == '=') mindis[i][j] = maxdis[i][j] = 0;
            if (c == '-') mindis[i][j] = -2, maxdis[i][j] = -1;
            if (c == '+') mindis[i][j] = 1, maxdis[i][j] = 2;
            if (c == '?') mindis[i][j] = -2, maxdis[i][j] = 2;
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                mindis[i][j] = max(mindis[i][j], mindis[i][k] + mindis[k][j]);
                maxdis[i][j] = min(maxdis[i][j], maxdis[i][k] + maxdis[k][j]);
            }
        }
    }
    int c1 = 0, c2 = 0, c3 = 0;
    for (int C = 1; C <= n; C++){
        for (int D = C + 1; D <= n; D++){
            if (C == A || C == B || D == A || D == B) continue;
            if (mindis[A][C] > maxdis[D][B] || mindis[B][C] > maxdis[D][A]) c1++;
            if (mindis[A][C] == mindis[D][B] && maxdis[A][C] == maxdis[D][B] && mindis[A][C] == maxdis[D][B] || mindis[B][C] == mindis[D][A] && maxdis[B][C] == maxdis[D][A] && mindis[B][C] == maxdis[D][A]) c2++;
            if (maxdis[A][C] < mindis[D][B] || maxdis[B][C] < mindis[D][A]) c3++;
        }
    }
    cout << c1 << ' ' << c2 << ' ' << c3;
    system("pause");
    return 0;
}