#include <bits/stdc++.h>
using namespace std;

struct bee{
    int work,sol;
    int ans(){
        return work+sol+1;
    }
};
bee dp[25];
int mark[25],mx=1;
int main()
{
    dp[0].work = 1;
    while(1){
        int k;cin >> k;
        if(k == -1) break;
        if(!mark[k]){
            for(int i=mx;i<=k;i++){
                dp[i].work = dp[i-1].work+1;
                dp[i].work += dp[i-1].sol;
                dp[i].sol+=dp[i-1].work;
                mark[i] = 1;
            }
            mx = k+1;
        }
        cout << dp[k].work << " " << dp[k].ans() << "\n";
    }
	return 0;
}
