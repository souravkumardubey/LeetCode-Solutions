class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        map < int, int > mp;
        int sum = 0;
        
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            
            if ( nums[i] % 2 == 0 ) {
                
                mp[i] += 1;
                sum += nums[i];
                
            }
            
        }
        
        vector < int > ans;
        
        for ( auto i : queries ) {
            
            if ( mp.find(i[1]) != mp.end() ) {
                
                int temp = nums[i[1]];
                nums[i[1]] += i[0];
                
                if ( nums[i[1]] % 2 ) {
                    
                    sum -= temp;
                    mp.erase(i[1]);
                    
                }
                else sum += i[0];
                
            }
            else {
                
                nums[i[1]] += i[0];
                int temp = nums[i[1]];
                if ( temp % 2 == 0 ) {
                    
                    sum += temp;
                    mp[i[1]] += 1;
                    
                }
                
            }
            
            ans.push_back(sum);
            
        }
        
        return ans;
        
    }
};