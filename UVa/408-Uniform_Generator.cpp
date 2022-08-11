#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s,m,tmp=0;
    while(cin >> s >> m){
        vector<int> mark(m);
        int ok = 0;
        for(int i=0;i<m;i++){
            int gen = (tmp+s)%m;
            if(mark[gen]){
                ok = 1;
                break;
            }
            mark[gen] = 1;
            tmp = gen;
        }
        cout << setw(10) << s << setw(10) << m << "    ";
        cout << (ok ? "Bad Choice\n":"Good Choice\n") << '\n';
    }
    return 0;
}
