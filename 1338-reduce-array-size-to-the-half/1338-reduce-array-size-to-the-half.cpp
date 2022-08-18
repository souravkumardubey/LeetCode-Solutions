class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n = arr.size();
        
        map < int , int > mp;
        
        for ( auto i : arr ) {
            
            mp[i] += 1;
            
        }
        
        vector < pair < int , int > > vp;
        
        for ( auto i : mp ) {
            
            vp.push_back({i.second,i.first});
            
        }
        
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        
        int cnt = 0 , val = 0;
        
        for ( auto i : vp ) {
            
            cnt += 1;
            val += i.first;
            if ( val >= n / 2 ) {
                
                return cnt;
                
            }
            
        }
        
        return n;
        
    }
};