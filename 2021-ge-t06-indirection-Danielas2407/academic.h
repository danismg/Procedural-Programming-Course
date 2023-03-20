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
void print_student(struct student_t _student);
void print_enrollment(struct enrollment_t _enrollment);
/**
 * The print_enrollments behaves similar to the print_enrollment. The main
 * difference is it accepts an array of enrollment and prints all of them.
 *
 */
void print_enrollments(struct enrollment_t *_enrollments,
                       unsigned short int _enrollment_size);
struct course_t create_course(char *_code, char *_name, unsigned short _credit,
                              enum grade_t _passing_grade);
struct student_t create_student(char *_id, char *_name, char *_year,
                                char *_study_program);
struct enrollment_t create_enrollment(struct course_t _course,
                                      struct student_t _student, char *_year,
                                      enum semester_t _semester);
/**
 * The set_enrollment_grade will update the grade of an enrollment.
 * The targeted enrollment is the one that match with the supplied student and
 * course. The search is conducted in a reverse order.
 */
void set_enrollment_grade(struct course_t _course, struct student_t _student,
                          struct enrollment_t *_enrollments,
                          unsigned short int _enrollment_size,
                          enum grade_t _grade);
/**
 * The calculate_gpa update a student's GPA by first calculating his/her
 * performance. To achieve this, the enrollments are supplied.
 */
void calculate_gpa(struct student_t *_student,
                   struct enrollment_t *_enrollments,
                   unsigned short int _enrollment_size);

#endif
// DO NOT EDIT
