#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 1e6;
int tot = 0, rt = 0;
int ch[maxn][26];
bool flag[maxn];
char s[maxn];
int smallest[maxn], biggest[maxn];
bool Cap_flag[maxn];
int getId(char c){
    if ('A' <= c && c <= 'Z')
        c += 32;
    if ('a' <= c && c <= 'z')
        return c - 'a';
    return 0;
}
void insert(char s[], int x){
    int len = strlen(s);
    int p = rt;
    for(int i = 0; i < len; i++){
        int id = getId(s[i]);
        if(!ch[p][id]) ch[p][id] = ++tot;
        p = ch[p][id];
        if (!smallest[p]) smallest[p] = x;
        biggest[p] = x;
        if ('A' <= s[i] && s[i] <= 'Z') Cap_flag[p] = true;
        else Cap_flag[p] = false;
    }
    flag[p] = 1;
}
void query(int x, int y){
    int p = rt;
    for(int len = 1; len <= 15; len++){
        for (int i = 25; i >= 0; i--){
        	if (ch[p][i]){
        		if (biggest[ch[p][i]] >= x && smallest[ch[p][i]] <= y){
	        		p = ch[p][i];
                    char c = i + 'a';
                    if (Cap_flag[p]) c -= 32;
                    printf("%c", c);
                    break;
				}
			}
		}
        if(flag[p]) break;
    }
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
    	cin >> s;
    	insert(s, i);
	}
	int x, y;
	while(m--){
		scanf("%d %d", &x, &y);
		query(x, y);
		printf("\n");
	}
    return 0;
}