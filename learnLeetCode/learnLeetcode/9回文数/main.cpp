#include <QtCore/QCoreApplication>
#include <QDebug>

#define BASIC 0  //基础题解
//力扣中国原题地址：https://leetcode.cn/problems/palindrome-number/
//小镇做题迦博客传送门：https://blog.csdn.net/wellwillw?type=blog

class Solution {
public:
    std::vector<int> X{};

    bool isPalindrome(int x) {
        bool compareResult{false}; //需要返回的结果，默认为0
        if (x < 0)
        {
        }
        else if (x >= 0 && x < 10)
        {
            compareResult = true;
        }
        else
        {
#if BASIC
            std::string strX = std::to_string(x);
            int strXlen = strX.length();
            int count = strXlen / 2;//需要对比的次数

            auto indexBegin = 0;
            auto indexEnd = strXlen - 1;

            while (count--)
            {
                if (strX[indexBegin] == strX[indexEnd])
                {
                    compareResult = true;
                }
                else
                {
                    compareResult = false;
                    break;
                }

                indexBegin++;
                indexEnd--;
            }
#else
            //进阶版
            int count = X.size();

            auto indexBegin = 0;
            auto indexEnd = count - 1;

            while (count--)
            {
                if (X[indexBegin] == X[indexEnd])
                {
                    compareResult = true;
                }
                else
                {
                    compareResult = false;
                    break;
                }

                indexBegin++;
                indexEnd--;
            }

#endif 

        }

        return compareResult;
    }

    void getIntegerNumLengthWithNone(const int value, const int hexadecimal = 10 /*进制，默认为十进制*/)
        //原地计算
    {
        X.clear();

        int num = value;
        
        while  (num != 0)  { 

            num /= hexadecimal;

            X.push_back(num % hexadecimal);
        } 

        return ; 
    } 
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Solution solution;
    qDebug() << solution.isPalindrome(13341);

    return a.exec();
}
