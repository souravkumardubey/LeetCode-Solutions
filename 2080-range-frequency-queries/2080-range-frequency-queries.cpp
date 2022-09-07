class RangeFreqQuery {
    
    vector < int > vec;
    
    map < int , vector < int > > mp;
    
public:
    RangeFreqQuery(vector<int>& arr) {
        
        vec = arr;
        
        for ( int i = 0 ; i < vec.size() ; i++ ) {
            
            mp[vec[i]].push_back(i);
            
        }
        
    }
    
    int query(int left, int right, int value) {
        
        int idx1 = lower_bound(mp[value].begin(),mp[value].end(),left) - mp[value].begin();
        int idx2 = upper_bound(mp[value].begin(),mp[value].end(),right) - mp[value].begin();
        
        return (idx2) - (idx1);
        
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */