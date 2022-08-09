class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int M = 1000000007;
        unordered_map<int, long long unsigned int> mp;
        long long unsigned sum = 0;
        for(auto it: arr)
            mp[it] = 1;
        
        sort(arr.begin(), arr.end());
        
        for(auto i=0; i<arr.size(); ++i)
            for(auto j=0; j<i; ++j){
                if(arr[i]%arr[j]==0){
                    if(mp.count(arr[i]/arr[j])>0)
                        mp[arr[i]]+= mp[arr[j]]*mp[arr[i]/arr[j]];
                }
            }
        
        for(auto &it: mp){
            sum+=it.second;
            cout<<it.first<<" "<<it.second<<endl;
        }
        return sum%M;
        
    }
};