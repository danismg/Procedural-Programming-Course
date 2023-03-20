// 12S20031 - Daniel Andres Simangusnong
// 12S20054 - Rossianna Dewi Sri Hutabarat

#include "academic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STUDENT 2


struct option_t opt;


int main(int _argc, char **_argv){

  int i;
  struct option_t opt[100];
  struct option_t create_option();{
    struct option_t opt[100];
    for (i = 0; i < 100; i++){;
      strcpy(opt[i].element1, "");
      strcpy(opt[i].element2, "");
      strcpy(opt[i].element3, "");
      strcpy(opt[i].element4, "");
      strcpy(opt[i].element5, "");
      strcpy(opt[i].input, "");
    }
  };

  char *token;
  struct student_t *students = NULL;
  struct course_t *courses = NULL;
  struct enrollment_t *enrollments = NULL;
  int a,b ,c = 0;
  students = malloc(sizeof(struct student_t) * a);
  courses = malloc(sizeof(struct course_t) * b);
  enrollments = malloc(sizeof(struct enrollment_t) * c);
  short int next_student_index = 0;
  short int next_course_index = 0;
  short int next_enrollment_index = 0;

// load from ripo
next_student_index = load_students_from_repository(&students) ;


  while (1) {
    get_string(input, 100);
    strcpy (cinput, input);

    char *command = strtok (cinput, separator);
    if (strcmp ( "---", command) == 0 ){
      break;
    }

    if (strcmp("create-student", command) == 0){
      char *id = strtok(NULL, separator);
      char *name = strtok(NULL, separator);
      char *year = strtok(NULL, separator);
      char *study_program = strtok(NULL, separator);

      short int student_index =
      get_student_index_by_id (students, student_size, id);

      if(student_index > -1) {
        continue;
      }
      struct student_t new_student =
          create_student (id,name,year,study_program);

      //allocate the students as an array
      ++student_size;
      if (student_size == 1) {
        students = malloc (sizeof(struct student_t) * student_size);
      }else {
        students = realloc (students, sizeof(struct student_t) * student_size);
      }

      students [student_size -1 ] = new_student;
    }
    else if (strcmp ("create-course", command) == 0);
    
  }
  save_students_to_repository(students, next_student_index);
  return 0;
}