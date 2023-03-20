// 12S20017 - Lile Asima Manalu
// 12S20031 - Daniel Andres Simangunsong

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Mengubah grade menjadi nilai huruf
char *grade_to_text(enum grade_t _grade){
  char *text = malloc(8);
  text[0] = '\0';

  switch (_grade)
  {
  case GRADE_A:
    strcpy(text, "A");
    break;
  case GRADE_AB:
    strcpy(text, "AB");
    break;
  case GRADE_B:
    strcpy(text, "B");
    break;
  case GRADE_BC:
    strcpy(text, "BC");
    break;
  case GRADE_C:
    strcpy(text, "C");
    break;
  case GRADE_D:
    strcpy(text, "D");
    break;
  case GRADE_E:
    strcpy(text, "E");
    break;
  case GRADE_T:
    strcpy(text, "T");
    break;
  default:
    strcpy(text, "None");
  }

  return text;
}

//Menghitung nilai performa
float calculate_performance(enum grade_t _grade, unsigned short _credit){
  float performance;
  switch (_grade)
  {
  case GRADE_A:
    performance = 4.00 * _credit;
    break;
  case GRADE_AB:
    performance = 3.50 * _credit;
    break;
  case GRADE_B:
    performance = 3.00 * _credit;
    break;
  case GRADE_BC:
    performance = 2.50 * _credit;
    break;
  case GRADE_C:
    performance = 2.00 * _credit;
    break;
  case GRADE_D:
    performance = 1.00 * _credit;
    break;
  case GRADE_E:
    performance = 0.00 * _credit;
    break;
  case GRADE_T:
    performance = 0.00 * _credit;
    break;
  default:
    performance = 0.00;
  }
  return performance;
}

//Menampilkan informasi course
void print_course(struct course_t _course){
  char *text = grade_to_text(_course.passing_grade);
  printf("%s|%s|%d|%s\n", _course.code, _course.name, _course.credit, text);
}

//Menampilkan informasi courses
void print_courses(struct course_t *_courses, unsigned short int _course_size){ 
  int i;
  for (i = 0; i < _course_size; i++){
    char *text = grade_to_text(_courses[i].passing_grade);
    printf("%s|%s|%d|%s\n", _courses[i].code, _courses[i].name, _courses[i].credit, text);
  }
}

//Menampilkan informasi student
void print_student(struct student_t _student){
  printf("%s|%s|%s|%s|%.2f\n", _student.id, _student.name, _student.year, _student.study_program, _student.gpa);
}

//Menampilkan informasi students
void print_students(struct student_t *_students,
                    unsigned short int _student_size) {
  int i;
  for (i = 0; i < _student_size; i++){
    printf("%s|%s|%s|%s|%.2f\n", _students[i].id, _students[i].name, _students[i].year, _students[i].study_program, _students[i].gpa);
  }
}

//Menampilkan informasi enrollment
void print_enrollment(struct enrollment_t _enrollment){
  char *text = grade_to_text(_enrollment.grade);
  float performance = calculate_performance(_enrollment.grade, _enrollment.course.credit);
  printf("%s|%s|%s|%.2f\n", _enrollment.course.code, _enrollment.student.id, text, performance);
}

//Menampilkan informasi enrollments(array)
void print_enrollments(struct enrollment_t *_enrollments,
                       unsigned short int _enrollment_size){
  int i;
  for (i = 0; i < _enrollment_size; i++)
  {
    char *text = grade_to_text(_enrollments[i].grade);
    float performance = calculate_performance(_enrollments[i].grade, _enrollments[i].course.credit);
    printf("%s|%s|%s|%.2f\n", _enrollments[i].course.code, _enrollments[i].student.id, text, performance);
  }
}

//Membuat factory course
struct course_t create_course(char *_code, char *_name, unsigned short _credit,
                              enum grade_t _passing_grade){
  struct course_t crs;

  strcpy(crs.code, _code);
  strcpy(crs.name, _name);
  crs.credit = _credit;
  crs.passing_grade = _passing_grade;

  return crs;
}

//Membuat factory student
struct student_t create_student(char *_id, char *_name, char *_year,
                                char *_study_program){
  struct student_t std;

  strcpy(std.id, _id);
  strcpy(std.name, _name);
  strcpy(std.year, _year);
  strcpy(std.study_program, _study_program);
  std.gpa = GRADE_NONE;

  return std;
}

//Membuat factory enrollment
struct enrollment_t create_enrollment(struct course_t _course,
                                      struct student_t _student, char *_year,
                                      enum semester_t _semester){
  struct enrollment_t emt;

  emt.course = _course;
  emt.student = _student;
  strcpy(emt.year, _year);
  emt.semester = _semester;
  emt.grade = GRADE_NONE;

  return emt;
}

//Menghitung gpa dari student, dihitung dari total performance dibagi dengan total kredit
void calculate_gpa(struct student_t *_student,
                   struct enrollment_t *_enrollments,
                   unsigned short int _enrollment_size){
  int i;
  float total_performance = 0.00;
  int total_credit = 0;
  for (i = 0; i < _enrollment_size; i++)
  {
    total_performance += calculate_performance(_enrollments[i].grade, _enrollments[i].course.credit);
    total_credit += _enrollments[i].course.credit;
  }
  _student->gpa = total_performance / total_credit;
}

//Meng-update grade dari enrollment
void set_enrollment_grade(struct course_t _course, struct student_t _student,
                          struct enrollment_t *_enrollments,
                          unsigned short int _enrollment_size,
                          enum grade_t _grade){

  for (int i = 0; i < _enrollment_size; i++)
  {
    if (_enrollments[i].grade != 0)
    {
      continue;
    }
    else
    {
      _enrollments[i].grade = _grade;
      break;
    }
  }
}

struct student_t find_student_by_id(struct student_t *_students,
                                    unsigned short int _student_size,
                                    char *_id) {
  int i
  struct student_t std;
  for(int i = 0; i < _student_size; i++){
    if(strcmp(_students[i].id, _id) == 0){
    printf("%s|%s|%s|%s|%.2f\n", _students[i].id, _students[i].name, _students[i].year, _students[i].study_program, _students[i].gpa);
  return std;
    }
  }
}
struct course_t find_course_by_code(struct course_t *_courses,
                                    unsigned short int _course_size,
                                    char *_code) {
  int i
  struct course_t crs;
  for(int i = 0; i < _course_size; i++){
    if(strcmp(_courses[i].code, _code) == 0){
    char *text = grade_to_text(_courses[i].passing_grade);
    printf("%s|%s|%d|%s\n", _courses[i].code, _courses[i].name, _courses[i].credit, text);
    return crs;
      }
  }
}