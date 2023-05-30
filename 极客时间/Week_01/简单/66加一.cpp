/*
 * @Author: your name
 * @Date: 2021-01-31 22:59:00
 * @LastEditTime: 2021-01-31 23:07:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \简单\20210126_66_01.cpp
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//解法一:常规解法
//思路:共分为三种情况:(1)末位无进位,比如998(2)末位有进位,中间有无进位的数,比如989(3)全都有进位,比如999
//时间复杂度:O(n)
//空间复杂度:O(1)

class Test {
   public:
    vector<int> plusOne(vector<int> &digits) {
        //方式1:重点在最后利用 push_back() 函数
        /* for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1; */

        //方式二:重点在中间通过取余运算来区分是否产生进位
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            ++digits[i];
            digits[i] = digits[i] % 10;
            if (0 != digits[i]) return digits;
        }
        digits.insert(digits.begin(), 1);

        //打印改变后的数组
        cout << "[";
        if (0 == digits.size()) {
            cout << "]";
        } else {
            for (int i = 0; i < digits.size(); ++i) {
                if (i == digits.size() - 1) {
                    cout << digits[i];
                } else {
                    cout << digits[i] << ",";
                }
            }
            cout << "]" << endl;
        }
        return digits;
    }
};

int main() {
    Test test;
    int value;
    vector<int> Array;
    while (cin >> value, !cin.eof()) {
        Array.push_back(value);
    }
    //打印数组的数据
    /* cout << "[";
    if (0 == Array.size()) {
        cout << "]";
    } else {
        for (int i = 0; i < Array.size(); ++i) {
            if (i == Array.size() - 1) {
                cout << Array[i];
            } else {
                cout << Array[i] << ",";
            }
        }
        cout << "]" << endl;
    } */
    test.plusOne(Array);
    return 0;
}