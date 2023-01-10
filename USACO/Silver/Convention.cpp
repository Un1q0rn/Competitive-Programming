nvention");
    int n,m,c;cin >> n >> m >> c;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    sort(all(a));
    int l = 0,r = a[n-1]-a[0];
    while(l < r){
        int mid = (l+r)>>1;
        queue<int> bus;
        int p = 0,cnt = 1;
        while(p < n){
            if(sz(bus) < c && (sz(bus) == 0 || a[p]-bus.front() <= mid)){
                bus.push(a[p]);
            }
            else{
                while(sz(bus)) bus.pop();
                bus.push(a[p]);
                cnt++;
            }
            p++;
        }
        if(cnt <= m){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout << r;
    return 0; 
}
