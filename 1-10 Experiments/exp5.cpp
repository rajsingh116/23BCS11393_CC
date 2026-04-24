class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long totalPower = 0;
        
        for (int b : batteries)
            totalPower += b;
        
        long long low = 0;
        long long high = totalPower / n;
        long long ans = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            long long total = 0;
            for (int b : batteries)
                total += min((long long)b, mid);
            
            if (total >= n * mid) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        
        return ans;
    }
};