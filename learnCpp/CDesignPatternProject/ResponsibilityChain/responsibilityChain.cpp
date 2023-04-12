#include <iostream>

using namespace std;

#define CONSOLELOGSTRING " Console::Logger: "

enum loggerLevel
{
	infoLevel = 0,
	debugLevel,
	errorLevel,
	countLevel
};

string loggerLevelList[countLevel]
{
	"Info",
	"debug",
	"error"
};

class basicLogger {
public:
	void setNextLogger(basicLogger* l) { nextLogger = l; }
	void logMessage(int l, string message) {
		if (level <= l)
		{
			write(message);
			cout << endl;
			return;
		}
		if (nextLogger)
		{
			nextLogger->logMessage(l, message);
		}
	}

protected:
	int level = 0;

	basicLogger* nextLogger;

	virtual void write(string) = 0;
};

class infoLogger : public basicLogger
{
public :
	infoLogger(int l) {
		level = l;
	}

protected:
	void write(string s) {
		printf((loggerLevelList[level] + CONSOLELOGSTRING + s).c_str());
	}
};

class debugLogger : public basicLogger
{
public:
	debugLogger(int l) {
		level = l;
	}

protected:
	void write(string s) {
		printf((loggerLevelList[level] + CONSOLELOGSTRING + s).c_str());
	}
};

class errorLogger : public basicLogger
{
public:
	errorLogger(int l) {
		level = l;
	}

protected:
	void write(string s) {
		printf((loggerLevelList[level] + CONSOLELOGSTRING + s).c_str());
	}
};


basicLogger* logDemo() {
	basicLogger* infoLog = new infoLogger(loggerLevel::infoLevel);
	basicLogger* debugLog = new debugLogger(loggerLevel::debugLevel);
	basicLogger* errorLog = new errorLogger(loggerLevel::errorLevel);

	errorLog->setNextLogger(debugLog);
	debugLog->setNextLogger(infoLog);

	return errorLog;
}


int main(){
	basicLogger* loggerChain = logDemo();

	loggerChain->logMessage(infoLevel, "This is an information.");

	loggerChain->logMessage(debugLevel,
		"This is a debug level information.");

	loggerChain->logMessage(errorLevel,
		"This is an error information.");
}