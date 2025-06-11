#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    int mx = -2e9;
    int mn = 2e9;
    
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x > mx) mx = x;
        if(x < mn) mn = x;
    }

    printf("%d \n%d",mn,mx);
    return 0;
}
