#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=0;
        int num_biscuit=s.size()-1;
        int num_child=g.size()-1;
        for(int i=num_child;i>=0;i--){
            if(num_biscuit>=0&&s[num_biscuit]>=g[i]){//can satisfy
                ++n;
                --num_biscuit;
            }
        }
        return n;
        //time complexity:nlogn  space complexity:constant
    }

    int wiggleMaxLength(std::vector<int>& nums) {
        int prediff=0;
        int curdiff=0;
        int length=nums.size();
        if(length<=1)return 1;
        int peak=1;
        for(int i=0;i<length-1;i++){
            curdiff=nums[i+1]-nums[i];
            if((prediff>=0&&curdiff<0)||(prediff<=0&&curdiff>0)){
                ++peak;
                prediff=curdiff;//Monotonous slopes have flat slopes
                //std::cout<<nums[i]<<"is a peak"<<std::endl;
            }
            
        }
        return peak;
        //time complexity:n  space:constant
    }

    int dp[1005][2];
    int wiggleMaxLength2(std::vector<int>& nums){
        for(int i=0;i<1005;i++){
            for(int j=0;j<2;j++){
                dp[i][j]=0;
            }
        }
        int length=nums.size();
        dp[0][0]=1;
        dp[0][1]=1;
        for(int i=1;i<length;i++){
            dp[i][0]=1;
            dp[i][1]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){//peak
                    dp[i][0]=std::max(dp[i][0],dp[j][1]+1);
                } 
            }
            for(int j=0;j<i;j++){
                if(nums[i]<nums[j]){
                    dp[i][1]=std::max(dp[i][1],dp[j][0]+1);
                }
            }
        }
        for(int i=0;i<length;i++){
            std::cout<<"dp[]"<< i <<"[0] = "<<dp[i][0]<<"\t"<<std::endl;
            std::cout<<"dp[]"<< i <<"[1] = "<<dp[i][1]<<"\t"<<std::endl;
        }
        // std::cout<<dp[nums[length-1]][1]<<std::endl;
        // std::cout<<dp[nums[length-1]][0]<<std::endl;
        return std::max(dp[length-1][1],dp[length-1][0]);

    }
    int maxSubArray(std::vector<int>& nums) {
        
        int maxsum=nums[0],sum=nums[0],length=nums.size();
        for(int i=1;i<length;i++){
            if(sum<0)sum=0;
            sum+=nums[i];
            
            maxsum=std::max(maxsum,sum);
        }
        return maxsum;
    }
};
int main(){
    Solution so;
    std::vector<int>arr={5,4,-1,7,8};
    std::cout<<so.maxSubArray(arr)<<std::endl;
    return 0;
}