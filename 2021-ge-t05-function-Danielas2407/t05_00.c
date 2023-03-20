// DO NOT EDIT
#include "academic.h"
#include <stdio.h>

int main(int _argc, char **_argv) {
  struct course_t crs_pp =
      create_course("10S1002", "Procedural Programming", 2, GRADE_D);
  print_course(crs_pp);

  return 0;
}
// DO NOT EDIT
