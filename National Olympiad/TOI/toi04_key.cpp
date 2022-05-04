#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

map<int,int> m;
queue<int> q[11],r;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int l,k;cin >> l >> k;
    string s1,s2,s3;cin >> s1 >> s2 >> s3;
    for(int i=0;i<k;i++){
        for(int j=0;j<l;j++){
            if((s3[i] <= s1[j] && s3[i] >= s2[j]) || (s3[i] <= s2[j] && s3[i] >= s1[j])){
                continue;
            }
            if(s3[i] > s2[j] && s3[i] > s1[j]){
                if(s2[j] > s1[j]) s3[i] = s2[j];
                else s3[i] = s1[j];
            }
            else{
                if(s2[j] < s1[j]) s3[i] = s2[j];
                else s3[i] = s1[j];
            }
        }
    }
    cout << s3;
    return 0;
}
