class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int M = 1000000007;
        unordered_map<int, long long unsigned int> mp;
        long long unsigned sum = 0;

        sort(arr.begin(), arr.end());
        
        for(auto i=0; i<arr.size(); ++i){
            mp[arr[i]]=1;
            for(auto j=0; j<i; ++j){
                if(arr[i]%arr[j]==0){
                    if(mp.count(arr[i]/arr[j])>0)
                        mp[arr[i]]+= mp[arr[j]]*mp[arr[i]/arr[j]];
                }
            }
            sum+=mp[arr[i]];
        }
        
        return sum%M;
        
    }
};