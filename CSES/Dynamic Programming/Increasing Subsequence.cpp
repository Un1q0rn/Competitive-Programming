#include <bits/stdc++.h>
using namespace std;
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;cin >> n;
  vector<int> a(n);
  for(auto &e:a) cin >> e;
  vector<int> lis;
  for(auto e:a){
      int pos = lower_bound(lis.begin(),lis.end(),e)-lis.begin();
      if(pos == lis.size()){
          lis.push_back(e);
      }
      else{
          lis[pos] = e;
      }
  }
  cout << lis.size();
  return 0;
}
