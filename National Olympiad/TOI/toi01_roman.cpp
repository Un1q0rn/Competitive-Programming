#include <bits/stdc++.h>
using namespace std;

string one[] = {"I","II","III","IV","V","VI","VII","VIII","IX"};
string ten[] = {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
string hun[] = {"C","CC","CCC"};
map<char,int> ans;

int main()
{
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        string s = to_string(i);
        int len = s.length();
        for(int j=len-1;j>=0;j--){
            int k = s[j]-'0'-1;
            if(k < 0) continue;
            if(len-j-1 == 2){
                int len2 = hun[k].length();
                for(int l=0;l<len2;l++){
                    ans[hun[k][l]]++;
                }
            }
            if(len-j-1 == 1){
                int len2 = ten[k].length();
                for(int l=0;l<len2;l++){
                    ans[ten[k][l]]++;
                }
            }
            if(len-j-1 == 0){
                int len2 = one[k].length();
                for(int l=0;l<len2;l++){
                    ans[one[k][l]]++;
                }
            }
        }
    }
    cout << ans['I'] << " " << ans['V'] << " " << ans['X'] << " " << ans['L'] << " " << ans['C'];
	return 0;
}
