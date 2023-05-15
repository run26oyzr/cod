#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5, maxlen = 55;
int tot = 0, rt = 0;
int ch[maxn * maxlen][26];
int flag[maxn * maxlen];
char s[maxlen];
void insert(char s[]){
    int len = strlen(s);
    int p = rt;
    for(int i = 0; i < len; i++){
        if(!ch[p][s[i] - 'a']) ch[p][s[i] - 'a'] = ++tot;
        p = ch[p][s[i] - 'a'];
    }
    flag[p] = 1;
}
void query(char s[]){
    int len = strlen(s);
    int p = rt;
    for(int i = 0; i < len; i++){
        if(!ch[p][s[i] - 'a']){
            printf("WRONG\n");
            return;
        }
        p = ch[p][s[i] - 'a'];
    }
    if (flag[p] == 0){
        printf("WRONG\n");
    }else if (flag[p] == 1){
        printf("OK\n");
        flag[p] = 2;
    }else{
        printf("REPEAT\n");
    }
}
int main(){
    int n, m;
    cin >> n;
    while(n--){
        scanf("%s", &s);
        insert(s);
    }
    cin >> m;
    while(m--){  
        scanf("%s", &s);
        query(s);
    }
    return 0;
}