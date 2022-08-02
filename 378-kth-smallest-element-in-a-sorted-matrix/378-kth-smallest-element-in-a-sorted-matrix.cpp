class Solution {
public:
     int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        priority_queue<int> max_heap;

        for(auto row : matrix)
        {
            for(auto col : row)
            {
                max_heap.push(col);
                if(max_heap.size()>k)
                    max_heap.pop();
            }
        }

        return max_heap.top();
    }
};