/*
 * Author: Teodor Dichev
 * Faculty number: 7MI0600424
 */

#include "../../Headers/Repositories/CourseRepository.h"

CourseRepository::CourseRepository() 
{ }

CourseRepository* CourseRepository::instance = nullptr;

CourseRepository* CourseRepository::getInstance()
{
    if (!instance)
    {
        instance = new CourseRepository();
    }

    return instance;
}

void CourseRepository::freeInstance()
{
    delete instance;
    instance = nullptr;
}
void CourseRepository::printGrades(int studentId) const
{
    for (size_t i = 0; i < courses.size(); i++)
    {
        if (courses[i].hasUser(studentId))
        {
            courses[i].printGradedAssignments(studentId);
        }
    }
}

Course* CourseRepository::find(const MyString& courseName)
{
    for (size_t i = 0; i < courses.size(); i++)
    {
        if (courses[i].getCourseName() == courseName)
        {
            return &courses[i];
        }
    }

    return nullptr;
}

void CourseRepository::addCourse(const Course& course)
{
    courses.push_back(course);
}
