#include "../../Headers/Entities/Message.h"

namespace {
    static void appendIntAsStr(MyString& str, int num) {
        char buf[12];
        int len = 0;

        if (num == 0) {
            buf[len++] = '0';
        }
        else {
            char temp[12];
            while (num > 0) {
                temp[len++] = '0' + (num % 10);
                num /= 10;
            }
            for (int i = 0; i < len; ++i)
                buf[i] = temp[len - i - 1];
        }

        buf[len] = '\0';
        str += buf;
    }
}

Message::Message() : Message(-1,"","","")
{ }

Message::Message(int receiverId, const MyString& senderFirstName, const MyString& senderLastName, const MyString& content)
	: receiverId(receiverId), senderFirstName(senderFirstName), senderLastName(senderLastName), content(content)
{ 
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    sentOn += (localTime->tm_hour < 10 ? "0" : "");
    appendIntAsStr(sentOn, localTime->tm_hour);

    sentOn += ":";
    sentOn += (localTime->tm_min < 10 ? "0" : "");
    appendIntAsStr(sentOn, localTime->tm_min);

    sentOn += " ";
    sentOn += (localTime->tm_mday < 10 ? "0" : "");
    appendIntAsStr(sentOn, localTime->tm_mday);

    sentOn += ".";
    sentOn += (localTime->tm_mon + 1 < 10 ? "0" : "");
    appendIntAsStr(sentOn, localTime->tm_mon + 1);

    sentOn += ".";
    appendIntAsStr(sentOn, localTime->tm_year + 1900);
}

Message::Message(int receiverId, const MyString& senderFirstName, const MyString& senderLastName, const MyString& sentOn, const MyString& content)
    : receiverId(receiverId), senderFirstName(senderFirstName), senderLastName(senderLastName), sentOn(sentOn), content(content)
{ }

int Message::getReceiverId() const
{
    return receiverId;
}

const MyString& Message::getSentOn() const
{
    return sentOn;
}

const MyString& Message::getSenderFirstName() const
{
    return senderFirstName;
}

const MyString& Message::getSenderLastName() const
{
    return senderLastName;
}

const MyString& Message::getContent() const
{
    return content;
}

void Message::printMessage() const
{
    std::cout << sentOn << ", sent by " << senderFirstName << " " << senderLastName << ":" << content << std::endl;
}
