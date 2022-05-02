#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> a(n+1);
    vector<int> b(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b[i] = a[i];
        a[i]+=a[i-1];
    }
    int mxsum=INT_MIN;
    pair<int,int> pos;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(mxsum < a[j]-a[i-1]){
                mxsum = a[j]-a[i-1];
                pos.f = i;
                pos.s = j;
            }
        }
    }
    if(mxsum <= 0){
        cout << "Empty sequence";
        return 0;
    }
    for(int i=pos.f;i<=pos.s;i++){
        cout << b[i] << " ";
    }
    cout << "\n";
    cout << mxsum;
    return 0;
}
