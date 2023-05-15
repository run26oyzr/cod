#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 1e6;
int tot = 0, rt = 0;
int ch[maxn][62];
bool flag[maxn];
char s[maxn];
int cnt[maxn];
int getId(char c){
    if ('a' <= c && c <= 'z')
        return c - 'a';
    if ('A' <= c && c <= 'Z')
        return 26 + c - 'A';
    if ('0' <= c && c <= '9')
        return 52 + c - '0';
    return 0;
}
void insert(char s[]){
    int len = strlen(s);
    int p = rt;
    for(int i = 0; i < len; i++){
        int id = getId(s[i]);
        if(!ch[p][id]) ch[p][id] = ++tot;
        p = ch[p][id];
        cnt[p]++;
    }
}
int query(char s[]){
    int len = strlen(s);
    int p = rt;
    for(int i = 0; i < len; i++){
        int id = getId(s[i]);
        if(!ch[p][id]){
            return 0;
        }
        p = ch[p][id];
    }
    return cnt[p];
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        tot = 0, rt = 0;
        int n, m;
        scanf("%d %d", &n, &m);
        while(n--){
            scanf("%s", &s);
            insert(s);
        }
        while(m--){  
            scanf("%s", &s);
            printf("%d\n", query(s));
        }
        for (int i = 0; i <= tot; i++){
            cnt[i] = 0;
            for (int j = 0; j < 62; j++){
                ch[i][j] = 0;
            }
        }
    }
    return 0;
}