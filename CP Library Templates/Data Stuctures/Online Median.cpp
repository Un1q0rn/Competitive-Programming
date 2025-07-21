struct MED{
    multiset<int> low,up;
    void ins(int val){
        if(!sz(low)){
            low.insert(val);
            return ;
        }
        ll a = *low.rbegin();
        if(a < val){
            up.insert(val);
            if(sz(up) > (sz(up) + sz(low)) / 2){
                low.insert(*up.begin());
                up.erase(up.begin());
            }
        }
        else{
            low.insert(val);
            if(sz(low) > (sz(up) + sz(low) + 1) / 2){
                up.insert(*low.rbegin());
                low.erase(--low.end());
            }
        }
    }

    void er(int val){
        if(val <= *low.rbegin()){
            low.erase(low.find(val));
        }
        else{
            up.erase(up.find(val));
        }

        if(sz(low) < sz(up)){
            low.insert(*up.begin());
            up.erase(up.begin());
        }
        else if(sz(low) > sz(up) + 1){
            up.insert(*low.rbegin());
            low.erase(--low.end());
        }
    }

    int qry(){
        return *low.rbegin();
    }
}
