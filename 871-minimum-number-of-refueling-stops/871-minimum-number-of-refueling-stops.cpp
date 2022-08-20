class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        sort(stations.begin(),stations.end());
        
        int n = stations.size();
        
        priority_queue < int > pq;
        
        int curr = startFuel , i = 0 , minStops = 0;
        
        while ( curr < target ) {

            while ( i < n and stations[i][0] <= curr ) {
                
                pq.push(stations[i][1]);
                i += 1;
                
            }
            
            if ( pq.empty() ) return -1;
            else curr += pq.top();
            
            pq.pop();     
            
            minStops += 1;
            
        }
        
        return minStops;
        
    }
};