//
// Created by qyxie on 18/9/2021.
//
#include<iostream>
#include<stack>
using namespace std;

//class Solution {
//public:
//    int reverse(int x) {
//        stack<int> s;
//        while(x){
//            s.push(x % 10);
//            x = x / 10;
//        }
//        long result = 0;
//        long i = 1;
//        while(!s.empty()){
//           long n = s.top();
//           result += i * n;
//           i *= 10;
//           s.pop();
//        }
//        return result;
//    }
//};

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
                return 0;
            }
            int digit = x % 10;
            x /= 10;
            rev = rev * 10 + digit;
        }
        return rev;
    }
};

int main(){
    int num = 123;

    Solution s = Solution();

    int result = s.reverse(num);

    cout << result << endl;

    return 0;
}