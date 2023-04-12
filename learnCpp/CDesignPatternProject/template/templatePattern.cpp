#include <iostream>
using namespace std;

class Class {
public:
    virtual void func() {
        OperationA();
        OperationB();
    }

    virtual ~Class() { }
protected:
    virtual void OperationA() = 0;
    virtual void OperationB() = 0;
};

class Class1 :public Class {
public:
    void OperationA() {
        cout << "1 OperationA" << endl;
    }

    void OperationB() {
        cout << "1 OperationB" << endl;
    }
};

class Class2 :public Class {
public:
    void OperationA() {
        cout << "2 OperationA" << endl;
    }

    void OperationB() {
        cout << "2 OperationB" << endl;
    }
};



int main() {
    Class* p1 = new Class1();
    Class* p2 = new Class2();
    p1->func();
    p2->func();

    delete p1;
    delete p2;

    return 0;
}