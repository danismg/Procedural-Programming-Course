// 12S20031 - Daniel Andres Simangusnong
// 12S20054 - Rossianna Dewi Sri Hutabarat

#include "repository.h"
#include "academic.h"
#include "custom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


short int load_students_from_repository(struct student_t **_students) {
  FILE *repository = fopen(DEFAULT_STUDENT_REPOSITORY, "r");
if(repository == EOF){
  printf("failed to open a stream.\n");
  return -1;
}
///////////////////////////////////////////////////////////
int i;
char action[100] = "";
  for (i = 0; i < 100; i++){
    char action[100] = "";
    short int ii = 0;
    action[0] = '\0';
    while (1){
      char d = '\0';
      d = getchar();
      if (d != '\r' && d != '\n'){
        action[ii] = d;
        action[++ii] = '\0';
      } else{
        if (d == '\r'){
          continue;
        }
        if (d == '\n'){
          break;
        };
      }
      if (strcmp(action, "---") == 0){
        i = 100;
      }
    }    
    
    strcpy(opt[i].input, action);
    token = strtok(opt[i].input, "#");
    int j = 0;
    while (token != NULL){
      if (j == 0){
        strcpy(opt[i].element1, token);
        token = strtok(NULL, "#");
        j += 1;
      } else if (j == 1){
        strcpy(opt[i].element2, token);
        token = strtok(NULL, "#");
        j += 1;
      } else if (j == 2){
        strcpy(opt[i].element3, token);
        token = strtok(NULL, "#");
        j += 1;
      } else if (j == 3)
      {
        strcpy(opt[i].element4, token);
        token = strtok(NULL, "#");
        j += 1;
      } else if (j == 4){
        strcpy(opt[i].element5, token);
        token = strtok(NULL, "#");
        j += 1;
      } else if (j == 5){
        strcpy(opt[i].element6, token);
        token = strtok(NULL, "#");
        j += 1;
      }
    }
  }

  for (i = 0; i < 100; i++){
    if (strcmp(opt[i].element1, "create-student") == 0){
      int j,k =0;
      for (j = 0; j < next_student_index; j++){
        if (strcmp(opt[i].element2, students[j].id) == 0){
          k+= 1;
          break;
        }
      }
      if (k == 0){
        if (students == NULL){
          a+= 1;
          students = malloc(sizeof(struct student_t) * a);
          students[next_student_index++] =
              create_student(opt[i].element2, opt[i].element3, opt[i].element4, opt[i].element5);
        } else if (students != NULL){
          a+= 1;
          students = realloc(students, sizeof(struct student_t) * a);
          students[next_student_index++] =
              create_student(opt[i].element2, opt[i].element3, opt[i].element4, opt[i].element5);
        } else if (k != 0){
          break;
        }
      }
//////////////////////////////////////////////////////
  short int closing_code = fclose(repository);
  if(closing_code != 0){
    printf("failed to close the stream.\n");
    return -2;
  
  return 0;
}
short int load_courses_from_repository(struct course_t **_courses) { return 0; }
short int load_enrollments_from_repository(struct enrollment_t **_enrollments,
                                           struct course_t *_courses,
                                           unsigned short int _course_size,
                                           struct student_t *_students,
                                           unsigned short int _student_size) {
  return student_size;
}
void save_courses_to_repository(struct course_t *_courses,
                                unsigned short int _course_size) {}
void save_students_to_repository(struct student_t *_students,
                                 unsigned short int _student_size) {}
void save_enrollments_to_repository(struct enrollment_t *_enrollments,
                                    unsigned short int _enrollment_size) {} 