#include <QtCore/QCoreApplication>
#include <QDebug>

#define BASIC 0  //�������
//�����й�ԭ���ַ��https://leetcode.cn/problems/palindrome-number/
//С�������Ȳ��ʹ����ţ�https://blog.csdn.net/wellwillw?type=blog

class Solution {
public:
    std::vector<int> X{};

    bool isPalindrome(int x) {
        bool compareResult{false}; //��Ҫ���صĽ����Ĭ��Ϊ0
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
            int count = strXlen / 2;//��Ҫ�ԱȵĴ���

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
            //���װ�
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

    void getIntegerNumLengthWithNone(const int value, const int hexadecimal = 10 /*���ƣ�Ĭ��Ϊʮ����*/)
        //ԭ�ؼ���
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
