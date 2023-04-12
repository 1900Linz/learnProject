#include "userPerson.h"
#include "chatRoom.h"

 userPerson::userPerson(chattingRoom* _Room, std::string _name) {
    mName = _name;
    mRoom = _Room;
}

 std::string userPerson::getName() {
    return mName;
}

 void userPerson::setName(std::string _name) {
    mName = _name;
}

 void userPerson::sendMessage(std::string message) {
    mRoom->showMessage(this, message);
}
