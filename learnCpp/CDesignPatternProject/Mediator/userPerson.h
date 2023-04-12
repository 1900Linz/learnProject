#pragma once
#include <iostream>

class chattingRoom;
class userPerson
{
public:
    userPerson(chattingRoom* _Room, std::string _name);

    std::string getName();

    void setName(std::string _name);

    void sendMessage(std::string message);

private:
    std::string mName;
    chattingRoom* mRoom;
};

