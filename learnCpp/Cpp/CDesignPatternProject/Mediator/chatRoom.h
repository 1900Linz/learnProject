#pragma once
#include "userPerson.h"
#include <time.h>

class chattingRoom {
public :
    static void showMessage(userPerson* user, std::string message);
};