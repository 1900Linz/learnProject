#include <iostream>

using namespace std;

class target {
public:
	virtual void request() {
		cout << "request ing ,,,";

	}

	virtual ~target() {}
};

class adapatee {
public:
	void specificRequest() {
        cout << "Adaptee::SpecificRequest..." << endl;
    }
};

class Adapter :public target, private adapatee {
public:
    Adapter(adapatee* ade) {
        _ade = ade;
    }
    void Request() {
        _ade->specificRequest();
    }
private:
    adapatee* _ade;
};

#define Ptr_Delete_SetNull(A) delete A; A = nullptr;

int main() {
    adapatee* _adaptee = new adapatee();
    target* adapter = new Adapter(_adaptee);

    adapter->request();

    Ptr_Delete_SetNull(adapter);
    Ptr_Delete_SetNull(_adaptee);

    return 0;
}