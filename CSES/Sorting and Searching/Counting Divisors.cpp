#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

int factor(int n){
    int cnt = 0;
    for(int i=1;i*i < n;i++){
        if(n%i == 0){
            cnt++;
        }
    }
    int ret = (cnt*2)+((int)sqrt(n)*(int)sqrt(n) == n);
    return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;cin >> t;
  while(t--){
      int n;cin >> n;
      cout << factor(n) << '\n';
  }
  return 0;
}
