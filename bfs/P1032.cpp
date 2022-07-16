#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
struct node{
	string x, y;
};
node t[15];
int main()
{
	int i = 1;
	scanf("%s %s", a, b);
	while (true){
//		scanf("");
		scanf("\n%s %s", c, d);
		if (d[0] != '\0'){
			t[i++].x = c;
			t[i].x = d;
 		}
 		else break;
	}
	return 0;
}
