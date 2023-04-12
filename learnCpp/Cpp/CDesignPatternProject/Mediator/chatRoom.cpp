#include "chatRoom.h"

 void chattingRoom::showMessage(userPerson* user, std::string message) {
    time_t timep;
    time(&timep);

    std::cout << asctime(gmtime(&timep));
    std::cout << "[" << user->getName() << "]" << " speak: " << message << std::endl;
}
