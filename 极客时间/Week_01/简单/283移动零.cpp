/*
 * @Author: your name
 * @Date: 2021-01-31 23:02:18
 * @LastEditTime: 2021-01-31 23:07:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \简单\283移动零.cpp
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//解法一:双指针法(在原数组中循环遍历)
//思路:1.定义变量j用来记录非零元素的位置2.循环遍历数组元素,如果遇到非零元素,则将其移动到j所在位置;如果遇到0,则继续向下遍历
//时间复杂度:O(n),其中n为序列长度
//空间复杂度:O(1),只需要常数的空间存放若干变量

class Test {
   public:
    void Move_Zero(vector<int> &array) {
        //双指针方法1(一次遍历)
        /* int j = 0;
        for (int i = 0; i < array.size(); ++i) {
            if (0 != array[i]) {
                array[j] = array[i];
                if (i != j) {
                    array[i] = 0;
                }
                ++j;
            }
        } */

        //双指针方法2
        /* int left = 0, right = 0;
        while (right < array.size()) {
            if (array[right]) {
                swap(array[left], array[right]);
                ++left;
            }
            ++right;
        } */

        //双指针方法3(两次遍历)
        int slowIndex = 0;
        for (int i = 0; i < array.size(); ++i) {
            if (array[i]) {
                array[slowIndex++] = array[i];
            }
        }
        for (int j = slowIndex; j < array.size(); ++j) {
            array[j] = 0;
        }

        //打印结束时数组的数据
        cout << "[";
        if (0 == array.size()) {
            cout << "]";
        } else {
            for (int i = 0; i < array.size(); ++i) {
                if (i != array.size() - 1) {
                    cout << array[i] << ",";
                } else {
                    cout << array[i] << "]";
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Test test;
    int value;
    vector<int> Array;
    while (cin >> value, !cin.eof()) {
        Array.push_back(value);
    }
    //打印初始时数组的数据
    cout << "[";
    if (0 == Array.size()) {
        cout << "]";
    } else {
        for (int i = 0; i < Array.size(); ++i) {
            if (i != Array.size() - 1) {
                cout << Array[i] << ",";
            } else {
                cout << Array[i] << "]";
            }
        }
    }
    cout << endl;

    test.Move_Zero(Array);

    return 0;
}