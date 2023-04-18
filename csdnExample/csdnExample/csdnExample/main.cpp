#include <QtCore/QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#pragma pack(1)
    typedef struct student
    {
        char           a;  //默认4个字节对齐，char           是1个字节，以4字节对齐，按4个字节处理
        short          b;  //默认4个字节对齐，short          是2个字节，以4字节对齐，按4个字节处理
        int            c;  //默认4个字节对齐，int            是4个字节，以4字节对齐，按4个字节处理
        float          d;  //默认4个字节对齐，float          是4个字节，以4字节对齐，按4个字节处理
        double         e;  //默认4个字节对齐，double         是8个字节，以4字节对齐，按8个字节处理
        long           f;  //默认4个字节对齐，long           是4个字节，以4字节对齐，按4个字节处理
        unsigned char  g;  //默认4个字节对齐，unsigned char  是1个字节，以4字节对齐，按4个字节处理
        unsigned short h;  //默认4个字节对齐，unsigned short 是2个字节，以4字节对齐，按4个字节处理
        unsigned int   i;  //默认4个字节对齐，unsigned int   是4个字节，以4字节对齐，按4个字节处理
    }student;

#pragma pop(pack)

    qDebug() << sizeof(student);
    
    return a.exec();
}
