#include <QtCore/QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#pragma pack(1)
    typedef struct student
    {
        char           a;  //Ĭ��4���ֽڶ��룬char           ��1���ֽڣ���4�ֽڶ��룬��4���ֽڴ���
        short          b;  //Ĭ��4���ֽڶ��룬short          ��2���ֽڣ���4�ֽڶ��룬��4���ֽڴ���
        int            c;  //Ĭ��4���ֽڶ��룬int            ��4���ֽڣ���4�ֽڶ��룬��4���ֽڴ���
        float          d;  //Ĭ��4���ֽڶ��룬float          ��4���ֽڣ���4�ֽڶ��룬��4���ֽڴ���
        double         e;  //Ĭ��4���ֽڶ��룬double         ��8���ֽڣ���4�ֽڶ��룬��8���ֽڴ���
        long           f;  //Ĭ��4���ֽڶ��룬long           ��4���ֽڣ���4�ֽڶ��룬��4���ֽڴ���
        unsigned char  g;  //Ĭ��4���ֽڶ��룬unsigned char  ��1���ֽڣ���4�ֽڶ��룬��4���ֽڴ���
        unsigned short h;  //Ĭ��4���ֽڶ��룬unsigned short ��2���ֽڣ���4�ֽڶ��룬��4���ֽڴ���
        unsigned int   i;  //Ĭ��4���ֽڶ��룬unsigned int   ��4���ֽڣ���4�ֽڶ��룬��4���ֽڴ���
    }student;

#pragma pop(pack)

    qDebug() << sizeof(student);
    
    return a.exec();
}
