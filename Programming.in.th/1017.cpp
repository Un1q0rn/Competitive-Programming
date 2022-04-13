#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int a[N][N],n;
bool ch = true;
int vertical(){
    int ans = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            if(!i) ans += a[j][i];
            sum+=a[j][i];
        }
        if(ans != sum) ch = false;
    }
    return ans;
}
int horizontal(){
    int ans = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            if(!i) ans += a[i][j];
            sum+=a[i][j];
        }
        if(ans != sum) ch = false;
    }
    return ans;
}
int Diagonal(){
    int sum1 = 0,sum2 = 0;
    for(int i=0;i<n;i++){
        int r=n-i-1;
        sum1+=a[i][i];
        sum2+=a[i][r];
    }
    if(sum1 != sum2) ch = false;
    return sum1;
}
void check(){
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
         for(int k=0;k<n;k++)
         {
            for(int l=0;l<n;l++)
            {
               if(i!=k && j!=l)
               {
                  if(a[i][j] == a[k][l])
                  {
                      ch = false;
                  }
               }
            }
         }
      }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    check();
    if(vertical() == horizontal() && horizontal() == Diagonal() && ch){
        cout << "Yes";
    }
    else cout << "No";
	return 0;
}
