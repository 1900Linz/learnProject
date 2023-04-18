#include <QtCore/QCoreApplication>
#include <QtSql>

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    QStringList drivers = QSqlDatabase::drivers();    //��ȡQT����֧�ֵ����ݿ���������

    foreach(QString driver, drivers)
    {
        qDebug() << driver;
    }
    //"QSQLITE"
    //    "QODBC"
    //    "QODBC3"
    //    "QPSQL"
    //    "QPSQL7"

    return a.exec();
}
