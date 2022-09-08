#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;cin >> n;
  vector<int> a(n);
  for(auto &e:a) cin >> e;
  stack<pair<int,int>> st;
  vector<int> ans(n);
  st.push({a[0],1});
  a[0] = 0;
  for(int i=1;i<n;i++){
      while(sz(st) && a[i] <= st.top().first) st.pop();
      if(!sz(st)) ans[i] = 0;
      else ans[i] = st.top().second;
      st.push({a[i],i+1});
  }
  for(auto e:ans) cout << e << ' ';
  return 0;
}
