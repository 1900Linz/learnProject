#include <QtCore/QCoreApplication>
#include <QDebug>

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    void string_replace(std::string& strBig, const std::string& strsrc, const std::string& strdst) {
        std::string::size_type pos = 0;
        std::string::size_type srclen = strsrc.size();
        std::string::size_type dstlen = strdst.size();

        while ((pos = strBig.find(strsrc, pos)) != std::string::npos)
        {
            strBig.replace(pos, srclen, strdst);
            pos += dstlen;
        }
    }

#if 0
    int romanToInt(std::string s) {

    }

    char romanNumbers[7]{ 'I','V','X','L','C','D','M' };

#else

    int romanToInt(std::string s) {
        char space{' '};
        int value{};

        for (auto i = s.begin() ; i != s.end() ; i++)
        {
            s[i] = space;
            s[i+1] = space;
        }

        

        return value;
    }

    char romanNumbers[7]{ 'I','V','X','L','C','D','M' };
    std::string romanLeftPair[6]{ "IV","IX","XL","XC","CD","CM"};


#endif


};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Solution s;
    qDebug() << (s.romanToInt("III"));

    return a.exec();
}
