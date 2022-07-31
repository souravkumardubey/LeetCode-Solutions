class NumArray {
        
    vector < int > vec;
    int sum; 
    
public:

    NumArray(vector<int>& nums) {
        
        vec = nums;
        
        sum = accumulate(nums.begin(),nums.end(),0);
        
    }
    
    void update(int index, int val) {
        
        sum -= vec[index];
        
        vec[index] = val;
        
        sum += val;
        
    }
    
    int sumRange(int left, int right) {
        
        int newSum = sum; 
        
        for ( int i = 0 ; i < left ; i++ )  newSum -= vec[i];
        
        for ( int i = right + 1 ; i < vec.size() ; i++ )  newSum -= vec[i];
        
        return newSum;
        
    }
    
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */