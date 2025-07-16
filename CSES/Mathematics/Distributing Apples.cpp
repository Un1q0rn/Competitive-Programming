#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e6;
const ll MOD = 1e9 + 7;

ll fac[MAXN + 10];
ll inv[MAXN + 10];

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n) {
		if (n % 2) { res = res * x % m; }
		x = x * x % m;
		n >>= 1;
	}
	return res;
}

void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

void inverses() {
	inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

ll choose(ll n, ll r) { return fac[n] * inv[r] % MOD * inv[n - r] % MOD; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
	factorial();
	inverses();
	ll n,m;
	cin >> n >> m;
    ll res = choose(n + m - 1,n - 1);
    cout << res;
}
