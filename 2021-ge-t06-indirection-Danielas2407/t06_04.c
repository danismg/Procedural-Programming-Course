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
  print_student(std_wiro);

  // enrollments are stored in a fixed-size array.
  // unfortunately, it is not guaranteed the enrollments will be fully filled.
  struct enrollment_t enrollments[MAX_ENROLLMENT];
  // this variable tracks which element is the "to be" filled next.
  // it also represents the actual filled elements.
  short int next_enrollment_index = 0;

  // the next_enrollment_index must be increased by one each time a new
  // enrollment is registed into the array.
  enrollments[next_enrollment_index++] =
      create_enrollment(crs_vp, std_wiro, "2020/2021", SEMESTER_ODD);
  enrollments[next_enrollment_index++] =
      create_enrollment(crs_pp, std_wiro, "2020/2021", SEMESTER_EVEN);

  print_enrollments(enrollments, next_enrollment_index);

  set_enrollment_grade(crs_vp, std_wiro, enrollments, next_enrollment_index,
                       GRADE_A);
  set_enrollment_grade(crs_pp, std_wiro, enrollments, next_enrollment_index,
                       GRADE_AB);

  print_enrollments(enrollments, next_enrollment_index);

  // implement the calculate_grade(...)
  calculate_gpa(&std_wiro, enrollments, next_enrollment_index);

  print_student(std_wiro);

  return 0;
}
// DO NOT EDIT
