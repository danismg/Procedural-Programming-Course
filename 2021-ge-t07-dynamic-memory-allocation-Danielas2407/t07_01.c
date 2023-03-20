#include "academic.h"
#include <stdio.h>

int main(int _argc, char **_argv) {

  struct student_t std_wiro =
    create_student("12S20999", "Wiro Sableng", "2020", "Information Systems");

  struct student_t std_jaka =
    create_student("12S20998", "Jaka Sembung", "2020", "Information Systems");

  print_student(std_wiro);
  print_student(std_wiro);
  print_student(std_jaka); 
  return 0;
}