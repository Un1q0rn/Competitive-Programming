#include <bits/stdc++.h>

char a[1000][1000];
int len[1000];
char c[1000][1000];
int main()
{
    int n,m;scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;
            scanf(" %c",&x);
            a[i][j] = tolower(x);
        }
    }
    int k;scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf(" %s",c[i]);
        len[i] = strlen(c[i]);
        for(int j=0;j<len[i];j++){
            c[i][j] = tolower(c[i][j]);
        }
    }
    for(int p=0;p<k;p++){
        int found = 0,x=-1,y=-1,cnt;
        for(int i=0;i<n && !found;i++){
            for(int j=0;j<m && !found;j++){
                if(a[i][j] == c[p][0]){
                    if(j+len[p] <= m){
                        cnt = 0;
                        int r=0;
                        for(int l=j;l<j+len[p];l++){
                            if(a[i][l] != c[p][r]){
                                break;
                            }
                            else cnt++;
                            r++;
                        }
                        if(cnt == len[p]){
                            found = 1;
                            x = i;
                            y = j;
                        }
                    }
                    if(j-len[p]+1 >= 0){
                        cnt = 0;
                        int r = 0;
                        for(int l=j;l>j-len[p];l--){
                            if(a[i][l] != c[p][r]){
                                break;
                            }
                            else cnt++;
                            r++;
                        }
                        if(cnt == len[p]){
                            found = 1;
                            x = i;
                            y = j;
                        }
                    }
                    if(i+len[p] <= n){
                        cnt = 0;
                        int r = 0;
                        for(int l=i;l<i+len[p];l++){
                            if(a[l][j] != c[p][r]){
                                break;
                            }
                            else cnt++;
                            r++;
                        }
                        if(cnt == len[p]){
                            found = 1;
                            x = i;
                            y = j;
                        }
                    }
                    if(i-len[p]+1 >= 0){
                        cnt = 0;
                        int r = 0;
                        for(int l=i;l>i-len[p];l--){
                            if(a[l][j] != c[p][r]){
                                break;
                            }
                            else cnt++;
                            r++;
                        }
                        if(cnt == len[p]){
                            found = 1;
                            x = i;
                            y = j;
                        }
                    }
                    if(i+len[p]<=n && j+len[p] <= m){
                        cnt = 0;
                        int r=0,l1 = i,l2 = j;
                        while(l1 < n && l2 < m){
                            if(a[l1][l2] != c[p][r]){
                                break;
                            }
                            else cnt++;
                            l1++;
                            l2++;
                            r++;
                        }
                        if(cnt == len[p]){
                            found = 1;
                            x = i;
                            y = j;
                        }
                    }
                    if(i-len[p]+1>=0 && j+len[p] <= m){
                        cnt = 0;
                        int r=0,l1 = i,l2 = j;
                        while(l1 >= 0 && l2 < m){
                            if(a[l1][l2] != c[p][r]){
                                break;
                            }
                            else cnt++;
                            l1--;
                            l2++;
                            r++;
                        }
                        if(cnt == len[p]){
                            found = 1;
                            x = i;
                            y = j;
                        }
                    }
                    if(i-len[p]+1>=0 && j-len[p]+1>=0){
                        cnt = 0;
                        int r=0,l1=i,l2=j;
                        while(l1 >= 0 && l2 >= 0){
                            if(a[l1][l2] != c[p][r]){
                                break;
                            }
                            else cnt++;
                            l1--;
                            l2--;
                            r++;
                        }
                        if(cnt == len[p]){
                            found = 1;
                            x = i;
                            y = j;
                        }
                    }
                    if(i+len[p]<=n && j-len[p]+1>=0){
                        cnt = 0;
                        int r=0,l1=i,l2=j;
                        while(l1 < n && l2 >= 0){
                            if(a[l1][l2] != c[p][r]){
                                break;
                            }
                            else cnt++;
                            l1++;
                            l2--;
                            r++;
                        }
                        if(cnt == len[p]){
                            found = 1;
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}
