#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,x;cin >> n >> x;
  vector<pair<int,int>> a(n);
  for(int i=0;i<n;i++){
      cin >> a[i].first;
      a[i].second = i+1;
  }
  sort(all(a));
  for(int i=0;i<n;i++){
      int l = 0,r = n-1,k = x-a[i].first;
      while(l != r){
          if(l != i && r != i && a[r].first+a[l].first == k){
              cout << a[l].second << ' ' << a[r].second << ' ' << a[i].second;
              return 0;
          }
          if(a[r].first+a[l].first < k){
              l++;
          }
          else r--;
      }
  }
  cout << "IMPOSSIBLE";
  return 0;
}
