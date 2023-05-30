/*
 * @Author: your name
 * @Date: 2021-01-31 23:04:59
 * @LastEditTime: 2021-01-31 23:07:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \简单\1两数之和01.cpp
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//解法一:双指针法(暴力枚举法)
//思路:1.枚举数组中所有的不同的两个下标的组合2.逐个检查它们所对应的数的和是否等于目标值
//时间复杂度:O(n^2),双层嵌套for循环遍历出所有情况
//空间复杂度:如果开辟额外数组保存结果就是O(n)或如果用两个整型临时变量保存结果就是O(1)

class Test {
   public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int sum = 0;
        vector<int> result;
        for (int i = 0; i < nums.size() - 1;
             ++i) {  //此处 i 的边界值也可以为 i < nums.size()
            for (int j = i + 1; j < nums.size();
                 ++j) {  //此处 j 的边界值只能为 j < nums.size()
                sum = nums[i] + nums[j];
                if (target == sum) {
                    result.push_back(i);
                    result.push_back(j);
                    cout << "[" << i << "," << j << "]" << endl;
                    return result;
                }
            }
        }
        return result;
    }
};

int main() {
    Test test;
    int value;
    int tagget;
    vector<int> Array;
    cin >> tagget;
    while (cin >> value, !cin.eof()) {
        Array.push_back(value);
    }
    test.twoSum(Array, tagget);
    return 0;
}