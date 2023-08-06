#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
//算法主体
int maxLcsplength(string str) {
    //空字符串直接返回0
    if (str.length() == 0) {
        return 0;
    }
    //记录下manacher字符串的长度，方便后面使用
    int len = (int)(str.length() * 2 + 1);
    //开辟动态数组chaArr记录manacher化的字符串
    //开辟动态数组pArr记录每个位置的回文半径
    char *chaArr = new char[len];
    int* pArr = new int[len];
    int index = 0;
    for (int i = 0; i < len;i++) {
        chaArr[i] = (i & 1) == 0 ? '#' : str[index++];
    }
    //到此完成对原字符串的manacher化
    //R是最右回文边界，C是R对应的最左回文中心，maxn是记录的最大回文半径
    int R = -1;
    int C = -1;
    int maxn = 0;
    //开始从左到右遍历
    for (int i = 0; i < len; i++) {
        //第一步直接取得可能的最短的回文半径，当i>R时，最短的回文半径是1，反之，最短的回文半径可能是i对应的i'的回文半径或者i到R的距离
        pArr[i] = R > i ? min(R - i, pArr[2 * C - i]) : 1;
        //取最小值后开始从边界暴力匹配，匹配失败就直接退出
        while (i + pArr[i]<len && i - pArr[i]>-1) {
            if (chaArr[i + pArr[i]] == chaArr[i - pArr[i]]) {
                pArr[i]++;
            }
            else {
                break;
            }
        }
        //观察此时R和C是否能够更新
        if (i + pArr[i] > R) {
            R = i + pArr[i];
            C = i;
        }
        //更新最大回文半径的值
        maxn = max(maxn, pArr[i]);
    }
    //记得清空动态数组哦
    delete[] chaArr;
    delete[] pArr;
    //这里解释一下为什么返回值是maxn-1，因为manacherstring的长度和原字符串不同，所以这里得到的最大回文半径其实是原字符串的最大回文子串长度加1，有兴趣的可以自己验证试试
    return maxn - 1;
}
int main()
{
    string s;
    cin>> s;
    cout << maxLcsplength(s) << endl;
    return 0;
}
