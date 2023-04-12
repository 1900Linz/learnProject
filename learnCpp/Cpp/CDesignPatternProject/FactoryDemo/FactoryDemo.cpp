#include <iostream>

class project {
public:
    virtual ~project() {};
    virtual void say() = 0;
};

class factory {
public:
    virtual ~factory() {};
    virtual project* createProj() = 0;
};

class EntityProj :public project {
public:
    EntityProj() {
        std::cout << "This is an entity..." << std::endl;
    }

    ~EntityProj() {
        std::cout << " entity deleted..." << std::endl;
    }

    void say() {
        std::cout << "An Entity Project Say..." << std::endl;
    }
};

class entityFactory : public factory{
public:
    entityFactory() {
        std::cout << "This is an factory..." << std::endl;
    }

    ~entityFactory() { }

    project* createProj() {
        return new EntityProj();
    }

};

#define deleteandrelesePtr(p) \
delete p;\
p = nullptr;
int main()
{
    factory* mDemoFactory = new entityFactory;
    project* mDemoProject = new EntityProj;
    mDemoProject->say();

    deleteandrelesePtr(mDemoFactory);
    deleteandrelesePtr(mDemoProject);
}

