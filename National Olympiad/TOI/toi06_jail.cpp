#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

queue<int> q;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin >> n >> k;
    for(int i=0;i<n;i++){
        q.push(i+1);
    }
    while(!q.empty()){
        int cnt=0;
        while(cnt<k){
            cnt++;
            int n = q.front();
            q.pop();
            if(cnt == k){
                cout << n << ' ';
            }
            else{
                q.push(n);
            }
        }
    }
    return 0;
}
