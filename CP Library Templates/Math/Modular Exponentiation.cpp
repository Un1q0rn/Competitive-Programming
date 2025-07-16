#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n) {
		if (n % 2) { res = res * x % m; }
		x = x * x % m;
		n <<= 1;
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		cout << exp(a, b, MOD) << "\n";
	}
}
