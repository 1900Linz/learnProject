#include <iostream>

using namespace std;

//水质--是否导致生物生病
//生物--是否能净化水
//生物A----不能净化水，喝了脏水会生病
//生物B----能净化水，喝了脏水不会生病


class water {
public:
	virtual void trans() = 0;
	void effect() {
		if (isClean)
			printf("状态：健康 \n");
		else
			printf("状态：生病 \n");
	}

protected:
	bool isClean;
}; 

class feature {
public:
	explicit feature() : food(nullptr) {}

	void drink(water* w) {
		printf("%s 正在喝水", typeid(this).name());
		food = w;
		makeclean(food);
	}
	virtual void makeclean(water* w) = 0;
protected:
	water* food;
};

class cleanWater : public water {
public:
	explicit cleanWater() { isClean = 1; };

	void trans() {};
};

class dirtyWater : public water {
public:
	explicit dirtyWater() { isClean = 0; };

	void trans() { isClean = 1; };
};

class person : public feature{
public:
	void makeclean(water* w) {
		food->effect();
	}
};

class featureX : public feature {
public:
	void makeclean(water* w) { 
		w->trans(); 
		food->effect();
	}
};

int main()
{
	person* p = new person;
	featureX* x = new featureX;

	cleanWater* clean = new cleanWater();
	dirtyWater* poison = new dirtyWater();

	p->drink(clean);
	x->drink(clean);

	p->drink(poison);
	x->drink(poison);
}