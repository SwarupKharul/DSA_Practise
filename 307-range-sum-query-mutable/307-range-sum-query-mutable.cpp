class NumArray {
public:
    vector<int> seg, arr;
    NumArray(vector<int>& nums) {
        seg.resize(4*nums.size()+1); 
        arr = nums;
        build(0, 0, nums.size()-1);
    }
    
    void build(int ind, int low, int high){
        if(low==high){
           seg[ind] = arr[low];
            return;
        }
        int mid = low - (low - high)/2;
        build(2*ind+1, low, mid);
        build(2*ind+2, mid+1, high);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    
    void myUpdate(int ind, int changeInd, int val, int low, int high){
        if(low==high){
            seg[ind] = val;
            return;
        }
        int mid = low - (low-high)/2;
        if(changeInd<=mid) myUpdate(2*ind+1, changeInd, val, low, mid);
        else myUpdate(2*ind+2, changeInd, val, mid+1, high);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    
    void update(int index, int val) {
          myUpdate(0, index, val, 0, arr.size()-1);
    }
    
    int query(int ind, int l, int r, int low, int high){
        if(r<low || high<l) return 0;   //no overlap
        if (low>=l && r>=high) return seg[ind];     //complete overlap
        int mid = low - (low-high)/2;
        int left = query(2*ind+1, l, r, low, mid);
        int right = query(2*ind+2, l, r, mid + 1, high);
        return left+right;
    }
    
    int sumRange(int left, int right) {
        return query(0, left, right, 0, arr.size()-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */