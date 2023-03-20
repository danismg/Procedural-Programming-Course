#include "academic.h"
#include <stdio.h>

int main(int _argc, char **_argv) {

  struct student_t std_wiro =
      create_student("12S20999", "Wiro Sableng", "2020", "Information Systems");

  struct student_t std_jaka =
      create_student("12S20998", "Jaka Sembung", "2020", "Information Systems");

  struct course_t crs_vp =
      create_course("12S1102", "Visual Programming", 2, GRADE_D);

  struct course_t crs_pp =
      create_course("10S1002", "Procedural Programming", 2, GRADE_C);

 print_student(std_wiro);
  print_student(std_wiro);
  print_student(std_jaka);
  print_course(crs_vp);
  print_course(crs_vp);
  print_course(crs_pp);
  print_student(std_wiro);
  print_student(std_jaka);
  print_student(std_jaka);
  print_course(crs_vp);
  print_course(crs_pp);
  print_student(std_wiro);
  return 0;
}