
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

//题解
//力扣中国原题地址：https://leetcode.cn/problems/roman-to-integer/
//小镇做题迦博客传送门：https://blog.csdn.net/wellwillw?type=blog
//本文链接：https://blog.csdn.net/wellwillw/article/details/130223674?spm=1001.2014.3001.5502

using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int value{};
#if 1
        for (size_t i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case 'I': 
                value += (s[i + 1] == 'V' || s[i + 1] == 'X') ? -1 : 1;
                break;
            case 'V':
                value += 5;
                break;
            case 'X':
                value += (s[i + 1] == 'L' || s[i + 1] == 'C') ? -10: 10;
                break;
            case 'L':
                value += 50;
                break;
            case 'C':
                value += (s[i + 1] == 'D' || s[i + 1] == 'M') ? -100 : 100;
                break;
            case 'D':
                value += 500;
                break;
            case 'M':
                value += 1000;
                break;
            default:  break;
            }
        }
#else
        map<string, int> romanChoices
        {
          {"I",1},
          {"V",5},
          {"X",10},
          {"L",50},
          {"C",100},
          {"D",500},
          {"M",1000},
          {"IV",4},
          {"IX",9},
          {"XL",40},
          {"XC",90},
          {"CD",400},
          {"CM",900}
        };
  
        for (size_t i = 0; i < s.size(); i++)
        {

        }
#endif
    
        return value;
    }
};


int main()
{
    Solution s;
    std::cout << s.romanToInt("LVIII");
}
