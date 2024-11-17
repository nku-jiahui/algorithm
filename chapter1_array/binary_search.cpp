//orderly array without duplicate elements


//extention:locate the insert location of the non-existent element,return left
//because finally,there are only one or two elements in the array,by enumeration,we can find that if the element is not found,the lest is the right insert location of it  
#include<iostream>
#include<vector>//必须使用命名空间std
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        //time complexity logn   space complexity O1  constant
        int n=nums.size();
        //the left and right sides are closed intervals
        int left=0,right=n-1;
        
        while(left<=right){
            int middle =(right+left)/2;
            //std::cout<<"middle = "<<middle<<" nums[middle]= ="<<nums[middle]<<" target = "<<target<<std::endl;
            if(nums[middle]>target){
                right=middle-1;
                //std::cout<<"bigger"<<std::endl;
            }else if(nums[middle]<target){
                left=middle+1;
                //std::cout<<"lesser"<<std::endl;
            }else{
                //std::cout<<"find target"<<std::endl;
                return middle;
            }
        }
        return left;
    }
    int removeElement(std::vector<int>& nums, int val) {

        //time complexity n^2   space O1
        // int n=nums.size();
        // int num=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==val){
        //         for(int j=i+1;j<n;j++){
        //             nums[j-1]=nums[j];
        //         }
        //         i--;
        //         n--;
        //     }
        // }
        // return n;
        int slowpointer=0;
        for(int fastpointer=0;fastpointer<nums.size();fastpointer++){
            if(val!=nums[fastpointer]){
                nums[slowpointer++]=nums[fastpointer];
            }
        }
        return slowpointer;
    }
};
int main(){
    Solution solution;
    std::vector<int> vec{1,2,3,4,5,6,7,8,9};
    std::cout<<solution.search(vec,2)+1<<std::endl;;
    return 0;
}