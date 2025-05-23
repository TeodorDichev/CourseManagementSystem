/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#pragma once
#include "../Utills/MyString.h"
#include "../Utills/SerializeFunctions.h"

#include "Login.h"
#include "Logout.h"
#include "AddStudent.h"
#include "AddToCourse.h"
#include "AddTutor.h"
#include "ChangePassword.h"
#include "ClearMailBox.h"
#include "CreateCourse.h"
#include "GetMailBox.h"
#include "MessageUser.h"
#include "MessageAll.h"
#include "MessageStudents.h"
#include "Enroll.h"
#include "AssignHomework.h"
#include "GradeAssignment.h"
#include "InvalidCommand.h"
#include "PrintStudentGrades.h"
#include "SubmitAssignment.h"
#include "ViewAssignmentSubmissions.h"

class CommandFactory
{
public:
	static CommandFactory* getInstance();
	static void freeInstance();

	Command* readCommand(const MyString& command) const;

private:
	static CommandFactory* instance;
	CommandFactory() = default;
};