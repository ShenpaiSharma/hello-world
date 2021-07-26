class Solution {
public:
    
    vector<vector<pair<int, int>>> dp;
    
    pair<int, int> fun(int start, int end, vector<int> &arr)
    {
        if(start > end) return {INT_MIN, INT_MAX};
        if(start == end) return {arr[start], 0};
        if(dp[start][end].first != -1 && dp[start][end].second != -1) return dp[start][end];
        
        int minSum = INT_MAX;
        int maxLeaf = INT_MIN;
        for(int i=start;i<end;i++)
        {
            auto left = fun(start, i, arr);
            auto right = fun(i+1, end, arr);
            
            maxLeaf = max(left.first, right.first);
            minSum = min(minSum, left.second + right.second + left.first*right.first);
        }
        return dp[start][end] = {maxLeaf, minSum};
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        dp.resize(n+1, vector<pair<int, int>>(n+1, {-1, -1}));
        return fun(0, n-1, arr).second;
    }
};
