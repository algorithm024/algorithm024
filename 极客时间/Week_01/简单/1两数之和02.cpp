/*
 * @Author: your name
 * @Date: 2021-01-31 23:05:55
 * @LastEditTime: 2021-01-31 23:06:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \简单\1两数之和02.cpp
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//解法二:哈希表
//思路:1.遍历的同时,记录一些信息,以省去一层循环,采用"以空间换时间"的想法 2.需要记录已经遍历过的数值和它所对应的下标,可以借助查找表实现(查找表可以采用哈希表或平衡二叉搜索树去实现,因为不需要维护查找表的顺序,所以采用哈希表即可)
//时间复杂度:O(n),n为数组的长度,对于每一个元素 x,我们可以 O(1) 地寻找 target-x
//空间复杂度:O(n),主要为哈希表的开销,哈希表最多需要存n-1个键值对(因为当做差之后,如果去哈希表中查到了差值,则数组中当前下标的值就不需要往哈希表中存了,直接返回下标即可)

class Test {
   public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                cout << "[" << it->second << "," << i << "]" << endl;
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
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