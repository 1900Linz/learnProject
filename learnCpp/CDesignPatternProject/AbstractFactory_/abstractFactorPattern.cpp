#include <iostream>

using namespace std;

class item {
public:
	virtual ~item() {}
	virtual void operation() = 0;
};

class product_A :public item
{
public:
	void operation() {
		cout << "product_A operation" << endl;
	}
};

class product_B :public item
{
public:
	void operation() {
		cout << "product_B operation" << endl;
	}
};

//

class Factory {
public:

	virtual ~Factory(){}
	virtual item* createProductA() = 0;
	virtual item* createProductB() = 0;
};

class runFactory : public Factory{
public:

	item* createProductA() {
		return new product_A();
	}

	item* createProductB() {
		return new product_B();
	}
};

#define Ptr_Delete_SetNull(A) delete A; A = nullptr;

int main() {
	Factory* factory = new runFactory();

	item* productA = factory->createProductA();
	item* productB = factory->createProductB();

	productA->operation();
	productB->operation();

	Ptr_Delete_SetNull(factory);
	Ptr_Delete_SetNull(productA);
	Ptr_Delete_SetNull(productB);

	return 0;
}