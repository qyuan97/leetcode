//
// Created by qyxie on 17/9/2021.
//
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

// exceed time
//int exist(deque<char> &max_substring, char c){
//    int flag = 0;
//    for(auto i = max_substring.begin(); i < max_substring.end(); ++i){
//        if(c == *i){
//            flag = 1;
//            break;
//        }
//    }
//    return flag;
//}
//
//void show_deque(deque<char> &max_substring){
//    for(auto i = max_substring.begin(); i < max_substring.end(); ++i){
//        cout << *i << " ";
//    }
//    cout << endl;
//}
//
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        if(s == ""){
//            return 0;
//        }
//
//        if(s == " "){
//            return 1;
//        }
//
//        deque<char> max_substring;
//        int record = 0;
//
//        for(int i = 0; i < s.length(); ++i){
//            if(max_substring.empty()){
//                max_substring.push_back(s[i]);
//                continue;
//            }
//            if(exist(max_substring, s[i])){
//                int d_size = max_substring.size();
//                if(d_size > record){
//                    record = d_size;
//                }
//                while(!max_substring.empty()){
//                    if(max_substring.front() == s[i]){
//                        max_substring.pop_front();
//                        break;
//                    }
//                    max_substring.pop_front();
//                }
//                max_substring.push_back(s[i]);
//            }else{
//                max_substring.push_back(s[i]);
//            }
//            show_deque(max_substring);
//        }
//
//        if(!max_substring.empty()){
//            int d_size = max_substring.size();
//            if(d_size > record){
//                record = d_size;
//            }
//        }
//        return record;
//    }
//};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> char_set;
        int left = 0, right = 0, res = 0;
        for(;left<s.size(); ++left){
            while(right<s.size() && char_set.count(s[right]) == 0){
                char_set.insert(s[right]);
                res = max(res, right-left+1);
                ++right;
            }
            char_set.erase(s[left]);
        }
        return res;
    }
};

int main(){
    Solution s = Solution();
    string str = "abcabcbb";
    string str_2 = "dvdf";
    int result = s.lengthOfLongestSubstring(str);
    int result_2 = s.lengthOfLongestSubstring(str_2);
    cout << result << endl;
    cout << result_2 << endl;
}