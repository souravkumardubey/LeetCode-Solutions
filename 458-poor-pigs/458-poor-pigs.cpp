class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        int val = minutesToTest / minutesToDie + 1;
        // int val2 = log(buckets);
        int val3 = log(val);
        
        return ceil(log(buckets)/log(val));
        
    }
};