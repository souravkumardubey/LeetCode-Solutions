class Solution {
    
    static bool cmp(pair< int, int >p1, pair < int, int > p2) {
        
        return ( p1.first > p2.first ) || ( p1.first == p2.first and p1.second < p2.second );
        
    }
    
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {

        vector < pair < int , int > > vp;
        
        for ( auto i : properties ) {
            
            vp.push_back({i[0],i[1]});
            
        }
        
        sort(vp.begin(),vp.end(),cmp);
                
        int cnt = 0, prev = 0; 
        
        for (auto& x : vp) {
            
            if (x.second < prev) cnt += 1; 
            else prev = max(prev, x.second);
            
        }
        
        return cnt; 
    }
};