#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double a, b, c, d, e[10];
int k = 1;
float g(float x) {
	return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}
void check(float l, float r) {
	float m = (l + r) / 2;
	if (int(round(l * 100)) == int(round(r * 100)) || r - l <= 0.005) {
		if (g(l) * g(r) < 0) {
			e[k++] = round(l * 100) / 100;
		}
		return;
	}
	check(l, m);
	check(m, r);
	return;
}
int main() {
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	if (d == 0) e[3] = 0;
	check(-100, 100);
	sort(e + 1, e + 3 + 1);
	printf("%.2lf %.2lf %.2lf", e[1], e[2], e[3]);
	return 0;
}
