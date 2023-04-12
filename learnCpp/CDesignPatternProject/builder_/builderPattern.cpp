#include <iostream>
using namespace std;


// 0

class item {
public:
    item() {
        cout << "item..." << endl;
    }
};

// Builder

class Builder {
public:
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual void BuildPartC() = 0;
    virtual item* GetProduct() = 0;
    virtual ~Builder() { }
};

class impBuilder :public Builder {
public:
    void BuildPartA() {
        cout << "BuildPartA..." << endl;
    }

    void BuildPartB() {
        cout << "BuildPartB..." << endl;
    }

    void BuildPartC() {
        cout << "BuildPartC..." << endl;
    }

    item* GetProduct() {
        return new item();
    }
};

// Director

class Director {
public:
    Director(Builder* pBuilder) {
        _builer = pBuilder;
    }

    void Construct() {
        _builer->BuildPartA();
        _builer->BuildPartB();
        _builer->BuildPartC();
    }

private:
    Builder* _builer;
};


int main() {
    auto builder = new impBuilder();
    auto director = new Director(builder);

    director->Construct();
    item* product = builder->GetProduct();

    delete product;
    delete builder;
    delete director;

    return 0;
}
