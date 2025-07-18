#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()

const int MAXN = 1e7 + 5;
vector<bool> is_prime(MAXN, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAXN; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAXN; i += p){
                is_prime[p] = false;
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    sieve();
    int n;cin >> n;
    cout << is_prime[n];
    return 0;
}
