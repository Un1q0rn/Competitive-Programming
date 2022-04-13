#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s1,s2;cin >> s1 >> s2;
    int l,r,mxans=0;
    for(int i=0;i<s1.length();i++){
        for(int j=0;j<s2.length();j++){
            if(s1[i] == s2[j]){
                int k = 0;
                while(s1[i+k] == s2[j+k] && i+k < s1.length() && j+k < s2.length()){
                    k++;
                }
                if(k > mxans){
                    mxans = k;
                    l = i;
                    r = i+k;
                }
            }
        }
    }
    for(int i=l;i<r;i++) cout << s1[i];
    return 0;
}
