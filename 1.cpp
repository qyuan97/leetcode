#include<vector>
#include<map>
#include<iostream>
#include <unordered_map>

using namespace std;

/*
 * baseline o(n^2)
 */
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> result;
//        for(int i = 0; i < nums.size(); ++i){
//            for(int j = i + 1; j < nums.size(); ++j){
//                if(nums[i] + nums[j] == target){
//                    result.push_back(i);
//                    result.push_back(j);
//                }
//            }
//        }
//        return result;
//    }
//};

/*
 * 使用哈希表来加速查找：
 * std::unordered_map底层实现为哈希表，std:map和std::multimap底层实现为红黑树
 * 同时unordered_map的key无序，std::map和std::multimap的key是有序的
 * 不需要key有序，unordered_map的效率更高
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()) {
                // iter->first map:key
                // iter->second map:value
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

int main(){
    Solution s = Solution();
    int nums[4] = {2,7,11,15};
    vector<int> vNums;
    for(int i = 0; i < 4; ++i){
        vNums.push_back(nums[i]);
    }
    int target = 9;
    vector<int>result = s.twoSum(vNums, target);
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
}