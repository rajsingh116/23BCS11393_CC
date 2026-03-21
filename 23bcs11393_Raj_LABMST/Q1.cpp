class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while (low<high){
            int mid=(low+high)/2;
            int ops=0;
            for(int i=0;i<nums.size();i++){
                ops+=(nums[i]-1)/mid;
                if(ops>maxOperations)
                break;
            }
            if(ops<=maxOperations){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return high;
    }
};