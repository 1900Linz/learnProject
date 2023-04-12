
#include <iostream>
#include "chatRoom.h"


int main()
{
    chattingRoom* thisRoom = new chattingRoom();

    userPerson* Y = new userPerson(thisRoom, "Mr.Y");
    userPerson* X = new userPerson(thisRoom, "Mr.X");

    Y->sendMessage("Hello, world");
    X->sendMessage("Bye");
}

