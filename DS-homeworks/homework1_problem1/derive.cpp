#include"head.h"

int main() {
	int m, n, s;
	cin >> n >> s >> m;
	Linkagain(n, s, m);

	//system("pause");

	return 0;
	
}
void Linkagain(int n, int s, int m) {
	int a[N] = { 0 };
	int i;
	for (i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	int k = 1, j = s - 1;
	for (i = 1; i <= n;i++) {
		k = 1;
		for (; k <= m; j++) {
			if (j == n) j = 0;
			if (a[j] != 0) k++;
		}

		if (i < n) {
			printf("%d ", a[j - 1]);
		}
		else {
			printf("%d", a[j - 1]);
		}
		
		a[j - 1] = 0;
		
	}
}