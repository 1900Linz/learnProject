#include <iostream>
#include <vector>

class Memento {

public:
    Memento(std::string state) {
        m_State = state;
    }

    std::string getState() {
        return m_State;
    }

private:
    std::string m_State;
};

class Originator {
public:
    void setState(std::string state) {
        m_State = state;
    }

    std::string getState() {
        return m_State;
    }

    Memento saveStateToMemento() {
        return  (Memento)m_State;
    }

    void getStateFromMemento(Memento Memento) {
        m_State = Memento.getState();
    }

private:
    std::string m_State;

};

class CareTaker {
public:
    void push(Memento state) {
        mementoList.push_back(state);
    }

    Memento pop() {
        Memento returnVal = *mementoList.rbegin();
        mementoList.pop_back();

        return returnVal;
    }

private:
    std::vector<Memento> mementoList;

};
int main()
{
    Originator originator;
    CareTaker careTaker;
    originator.setState("State #1");
    careTaker.push(originator.saveStateToMemento());

    originator.setState("State #2");
    careTaker.push(originator.saveStateToMemento());
    originator.setState("State #3");
    originator.setState("State #4");

    std::cout << "Current State: " + originator.getState() << std::endl;

    std::cout << "[roll back one step] "<< std::endl;
    originator.getStateFromMemento(careTaker.pop());
    std::cout << "Current State: " + originator.getState() << std::endl;

    std::cout << "[roll back one step] " << std::endl;
    originator.getStateFromMemento(careTaker.pop());
    std::cout << "Current State: " + originator.getState() << std::endl;

    return 0;
}
