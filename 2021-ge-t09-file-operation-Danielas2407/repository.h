// DO NOT EDIT
#include "academic.h"
#include "custom.h"

#ifndef REPOSITORY_H
#define REPOSITORY_H

#define DEFAULT_COURSE_REPOSITORY "./storage/course-repository.txt"
#define DEFAULT_STUDENT_REPOSITORY "./storage/student-repository.txt"
#define DEFAULT_ENROLLMENT_REPOSITORY "./storage/enrollment-repository.txt"

short int load_courses_from_repository(struct course_t **_courses);
short int load_students_from_repository(struct student_t **_students);
short int load_enrollments_from_repository(struct enrollment_t **_enrollments,
                                           struct course_t *_courses,
                                           unsigned short int _course_size,
                                           struct student_t *_students,
                                           unsigned short int _student_size);
void save_courses_to_repository(struct course_t *_courses,
                                unsigned short int _course_size);
void save_students_to_repository(struct student_t *_students,
                                 unsigned short int _student_size);
void save_enrollments_to_repository(struct enrollment_t *_enrollments,
                                    unsigned short int _enrollment_size);

#endif
// DO NOT EDIT
