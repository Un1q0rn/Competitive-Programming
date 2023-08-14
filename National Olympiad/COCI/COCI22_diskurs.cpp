#include <bits/stdc++.h> 
using namespace std; 

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n,m;cin >> n >> m;
    vector<int> a(n),dist(1<<m,1e9);
    queue<int> q;
    for(auto &e:a){
        cin >> e;
        dist[e] = 0;
        q.push(e);
    }
    int num = (1<<m)-1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int shift = 1;
        while(shift < (1<<m)){
            if(dist[u^shift] > dist[u]+1){
                dist[u^shift] = dist[u]+1;
                q.push(u^shift);
            }
            shift <<= 1;
        }
    }
    for(auto e:a){
        cout << m-dist[e^num] << ' ';
    }
    return 0;
} 
