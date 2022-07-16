#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[15];
void b(int a[], int c, int d){
	for (int i = 0; i <= 2; i++){
		int x = c / int(pow(10, i)) % 10;
		a[d + i] = x;
	}
}
bool check(int a[]){
	sort(a + 1, a + 9 + 1);
	for (int i = 1; i <= 9; i++){
		if (a[i] != i) return false;
	}
	return true;
}
int main()
{
	for (int i = 1; i <= 333; i++){
		b(a, i, 1);
		b(a, i * 2, 4);
		b(a, i * 3, 7);
		if (check(a)) printf("%d %d %d\n", i, i * 2, i * 3);
	}
	return 0;
}
