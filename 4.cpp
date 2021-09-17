//
// Created by qyxie on 17/9/2021.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void show_vector(vector<int>& nums){
    for(int i = 0; i < nums.size(); ++i){
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for(int i = 0; i < nums1.size(); ++i){
            nums.push_back(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); ++i){
            nums.push_back(nums2[i]);
        }
        show_vector(nums);
        sort(nums.begin(), nums.end());
        show_vector(nums);
        int flag = nums.size() % 2;
        int ind = 0;
        double result = 0.0;
        if(flag){
            ind = (nums.size()/2);
            result = nums[ind];
        }else{
            int ind_1 = nums.size()/2 - 1;
            int ind_2 = nums.size()/2;
            double sum = nums[ind_1] + nums[ind_2];
            result = sum / 2;
        }
        cout << result << endl;
        return result;
    }
};

int main(){
    int nums1[2] = {1,2};
    int nums2[2] = {3,4};

    vector<int> vNums_1;
    vector<int> vNums_2;
    for(int i = 0; i < 2; ++i){
        vNums_1.push_back(nums1[i]);
    }
    for(int i = 0; i < 2; ++i){
        vNums_2.push_back(nums2[i]);
    }

    Solution s = Solution();
    s.findMedianSortedArrays(vNums_1, vNums_2);

    return 0;
}

