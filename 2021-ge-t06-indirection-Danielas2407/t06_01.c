// DO NOT EDIT
#include "academic.h"
#include <stdio.h>
#define MAX_ENROLLMENT 100

int main(int _argc, char **_argv) {
  struct course_t crs_vp =
      create_course("12S1102", "Visual Programming", 2, GRADE_D);
  struct course_t crs_pp =
      create_course("10S1002", "Procedural Programming", 2, GRADE_D);
  print_course(crs_vp);
  print_course(crs_pp);

  struct student_t std_wiro =
      create_student("12S20999", "Wiro Sableng", "2020", "Information Systems");

  // re-implement the print_student(...)
  print_student(std_wiro);

  return 0;
}
// DO NOT EDIT
