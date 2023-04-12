#include <iostream>
#include <list>

using namespace std;

//interface

class order {
public:
	~order() {}
	virtual void execute() = 0;
};

// request entity

class stock {
public:
	stock() {
		name = "ABC";
		quantity = 10;
	}

	void buy() {
		cout << "Stock [ Name: ";
		cout << name;
		cout << ",  Quantity: ";
		cout << quantity;
		cout << " ] bought";
		cout << endl;
	}

	void sell() {
		cout << "Stock [ Name: ";
		cout << name;
		cout << ",  Quantity: ";
		cout << quantity;
		cout << " ] sold";
		cout << endl;
	}

private:
	string name;
	int quantity;
};

//interface imple

class buyStock : public order {
public:
	buyStock(stock p) {
		thisStock = p;
	}

	void execute() {
		thisStock.buy();
	}

private:
	stock thisStock;
};

class sellStock : public order {
public:
	sellStock(stock p) {
		thisStock = p;
	}

	void execute() {
		thisStock.buy();
	}

private:
	stock thisStock;
};

// request caller
class requestPerson {
public:
	void takeOrder(order* p) {
		orderLst.push_back(p);
	}

	void placeOrders() {
		if (orderLst.empty())
		{
			return;
		}

		auto begin = orderLst.begin();
		auto end = orderLst.end();

		while (begin != end)
		{
			(*begin)->execute();
			begin++;
		}

		orderLst.clear();
	}

private:
	list<order*> orderLst;
};

int main() {
	stock demoStock;

	buyStock* buyStockOrder = new buyStock(demoStock);
	sellStock* sellStockOrder = new sellStock(demoStock);

	requestPerson mainPerson;
	mainPerson.takeOrder(buyStockOrder);
	mainPerson.takeOrder(sellStockOrder);

	mainPerson.placeOrders();

}