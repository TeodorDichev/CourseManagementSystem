#include "../../Headers/Commands/CommandFactory.h"

CommandFactory* CommandFactory::instance = nullptr;

CommandFactory* CommandFactory::getInstance()
{
	if (!instance)
	{
		instance = new CommandFactory();
	}

	return instance;
}

void CommandFactory::freeInstance()
{
	delete instance;
}

Command* CommandFactory::readCommand(const MyString& command) const
{
	if (command == "login")
	{
		return new Login();
	}
	else if (command == "logout")
	{
		return new Logout();
	}
	else if (command == "change_password")
	{
		return new ChangePassword();
	}
	else if (command == "mailbox")
	{
		return new GetMailBox();
	}
	else if (command == "clear_mailbox")
	{
		return new ClearMailBox();
	}
	else if (command == "create_course")
	{
		return new CreateCourse();
	}
	else if (command == "add_to_course")
	{
		return new AddToCourse();
	}
	else if (command == "add_teacher")
	{
		return new AddTutor();
	}
	else if (command == "add_student")
	{
		return new AddStudent();
	}
	else if (command == "message")
	{
		return new MessageUser();
	}
	else if (command == "message_all")
	{
		return new MessageAll();
	}
	else if (command == "message_students")
	{
		return new MessageStudents();
	}
	else if (command == "enroll")
	{
		return new Enroll();
	}
	else if (command == "assign_homework")
	{
		return new AssignHomework();
	}
	else if (command == "submit_assignment")
	{
		return new SubmitAssignment();
	}
	else if (command == "grades")
	{
		return new PrintStudentGrades();
	}
	else if (command == "view_assignment_submissions")
	{
		return new ViewAssignmentSubmissions();
	}
	else if (command == "grade_assignment")
	{
		return new GradeAssignment();
	}
	else
	{
		return new InvalidCommand();
	}
}