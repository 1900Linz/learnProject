#include <iostream>

using namespace std;

//ˮ��--�Ƿ�����������
//����--�Ƿ��ܾ���ˮ
//����A----���ܾ���ˮ��������ˮ������
//����B----�ܾ���ˮ��������ˮ��������


class water {
public:
	virtual void trans() = 0;
	void effect() {
		if (isClean)
			printf("״̬������ \n");
		else
			printf("״̬������ \n");
	}

protected:
	bool isClean;
}; 

class feature {
public:
	explicit feature() : food(nullptr) {}

	void drink(water* w) {
		printf("%s ���ں�ˮ", typeid(this).name());
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