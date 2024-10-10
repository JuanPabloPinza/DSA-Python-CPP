#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int k = 1;
    for (int i = 1; i < nums.size(); i++) {
        if(nums[i]!=nums[i-1]){
            nums[k]=nums[i];
            k++;
        }
    }
    return k;
}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = removeDuplicates(nums);
    cout<<"No of elem: "<<k<<endl;
    for(int n:nums){
        std::cout << n << " ";
    }


    return 0;
};