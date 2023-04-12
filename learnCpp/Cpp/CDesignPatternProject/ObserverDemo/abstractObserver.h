#pragma once

class subject;
class abstractObserver {
public:
	virtual void update() = 0;

protected:
	subject* mSubject;
};

class aObserver : public abstractObserver {
public:
	explicit aObserver(subject*);
	void update();
	
};

class bObserver : public abstractObserver {
public:
	explicit bObserver(subject*);

	void update();
};


class cObserver : public abstractObserver {
public:
	explicit cObserver(subject*);

	void update();
};