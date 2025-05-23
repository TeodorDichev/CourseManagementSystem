/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "../Utills/MyString.h"
#include <ctime>

class Message
{
private:
	int receiverId;
	MyString sentOn;
	MyString senderFirstName;
	MyString senderLastName;
	MyString content;

public:
	Message();
	Message(int receiverId, const MyString& senderFirstName, const MyString& senderLastName, const MyString& content);
	Message(int receiverId, const MyString& senderFirstName, const MyString& senderLastName, const MyString& sentOn, const MyString& content);
	Message(const Message& other) = default;

	int getReceiverId() const;
	const MyString& getSentOn() const;
	const MyString& getSenderFirstName() const;
	const MyString& getSenderLastName() const;
	const MyString& getContent() const;

	void printMessage() const;
};
