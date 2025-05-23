#pragma once
#include "../Entities/Course.h"

class CourseRepository
{
private:	
	CourseRepository();

	static CourseRepository* instance;

	MyVector<Course> courses;

public:
	static CourseRepository* getInstance();
	static void freeInstance();

	void printGrades(int studentId) const;

	Course* find(const MyString& courseName);

	void addCourse(const Course& course);

	friend class SerializeFunctions;
};
