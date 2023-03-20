// DO NOT EDIT
#ifndef ACADEMIC_H
#define ACADEMIC_H

enum grade_t {
  GRADE_NONE,
  GRADE_T,
  GRADE_E,
  GRADE_D,
  GRADE_C,
  GRADE_BC,
  GRADE_B,
  GRADE_AB,
  GRADE_A
};

enum semester_t { SEMESTER_ODD, SEMESTER_EVEN, SEMESTER_SHORT };

struct course_t {
  char code[12];
  char name[40];
  unsigned short int credit;
  enum grade_t passing_grade;
};

struct student_t {
  char id[12];
  char name[40];
  char year[5];
  char study_program[40];
  float gpa;
};

struct enrollment_t {
  struct course_t course;
  struct student_t student;
  char year[12];
  enum semester_t semester;
  enum grade_t grade;
};

char *grade_to_text(enum grade_t _grade);
float calculate_performance(enum grade_t _grade, unsigned short _credit);
void print_course(struct course_t _course);
void print_courses(struct course_t *_courses, unsigned short int _course_size);
void print_student(struct student_t _student);
void print_students(struct student_t *_students,
                    unsigned short int _student_size);
void print_enrollment(struct enrollment_t _enrollment);
void print_enrollments(struct enrollment_t *_enrollments,
                       unsigned short int _enrollment_size);
struct course_t create_course(char *_code, char *_name, unsigned short _credit,
                              enum grade_t _passing_grade);
struct student_t create_student(char *_id, char *_name, char *_year,
                                char *_study_program);
struct enrollment_t create_enrollment(struct course_t _course,
                                      struct student_t _student, char *_year,
                                      enum semester_t _semester);
void set_enrollment_grade(struct course_t _course, struct student_t _student,
                          struct enrollment_t *_enrollments,
                          unsigned short int _enrollment_size,
                          enum grade_t _grade);
void calculate_gpa(struct student_t *_student,
                   struct enrollment_t *_enrollments,
                   unsigned short int _enrollment_size);
struct student_t find_student_by_id(struct student_t *_students,
                                    unsigned short int _student_size,
                                    char *_id);
struct course_t find_course_by_code(struct course_t *_courses,
                                    unsigned short int _course_size,
                                    char *_code);

#endif
// DO NOT EDIT
