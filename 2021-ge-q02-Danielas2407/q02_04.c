// 12S20017 - Lile Asima Manalu
// 12S20031 - Daniel Andres Simangunsong

#include "academic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STUDENT 2

struct option_t{
  char element1[100];
  char element2[100];
  char element3[100];
  char element4[100];
  char element5[100];
  char element6[100];
  char input[100];
};

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
    } else if (strcmp(opt[i].element1, "print-students") == 0){
      print_students(students, next_student_index);
    } else if (strcmp(opt[i].element1, "---") == 0){
      i = 100;
    } else if (strcmp(opt[i].element1, "find-student-by-id") == 0){
      find_student_by_id(students, next_student_index, opt[i].element2);
    } else if (strcmp(opt[i].element1, "create-course") == 0){
      enum grade_t _element = GRADE_NONE;
      if (strcmp(opt[i].element5, "A") == 0){
        _element = GRADE_A;
      } else if (strcmp(opt[i].element5, "AB") == 0){
        _element = GRADE_AB;
      } else if (strcmp(opt[i].element5, "B") == 0){
        _element = GRADE_B;
      } else if (strcmp(opt[i].element5, "BC") == 0){
        _element = GRADE_BC;
      } else if (strcmp(opt[i].element5, "C") == 0){
        _element = GRADE_C;
      } else if (strcmp(opt[i].element5, "D") == 0){
        _element = GRADE_D;
      } else{
        _element = GRADE_E;
      }
      int j,k=0;
      for (j = 0; j < next_course_index; j++){
        if (strcmp(opt[i].element2, courses[j].code) == 0){
          k+= 1;
          break;
        }
      }
      if (k == 0){
        if (courses == NULL){
          b+= 1;
          courses = malloc(sizeof(struct course_t) * b);
          courses[next_course_index++] =
              create_course(opt[i].element2, opt[i].element3, atoi(opt[i].element4), _element);
        } else{
          b+= 1;
          courses = realloc(courses, sizeof(struct course_t) * b);
          courses[next_course_index++] =
              create_course(opt[i].element2, opt[i].element3, atoi(opt[i].element4), _element);
        }
      }
    } else if (strcmp(opt[i].element1, "print-courses") == 0){
      print_courses(courses, next_course_index);
    } else if (strcmp(opt[i].element1, "find-course-by-code") == 0){
      find_course_by_code(courses, next_course_index, opt[i].element2);
    } else if (strcmp(opt[i].element1, "create-enrollment") == 0){

      enum grade_t _element_grade;
      if (strcmp(opt[i].element5, "even") == 0){
        _element_grade = SEMESTER_EVEN;
      } else{
        _element_grade = SEMESTER_ODD;
      }
      int d,e=0;
      for (d = 0; d < next_enrollment_index; d++){
        if (strcmp(opt[i].element3, enrollments[d].student.id) == 0 && strcmp(opt[i].element2, enrollments[d].course.code) == 0 && _element_grade == enrollments[d].semester){
          e+= 1;
          break;
        }
      }
      if (e == 0){
        int x,y,z=0;
        for (x = 0; x < next_course_index; x++){
          if (strcmp(opt[i].element2, courses[x].code) != 0){
            y += 1;
          }
        }
        for (x = 0; x < next_student_index; x++){
          if (strcmp(opt[i].element3, students[x].id) != 0){
            z += 1;
          }
        }
        if (y == 0 && z == 0){
          if (enrollments == NULL){
            int j,k=0;
            do{
              if (strcmp(opt[i].element2, courses[j].code) == 0 && strcmp(opt[i].element3, students[k].id) == 0){
                c+= 1;
                enrollments = malloc(sizeof(struct enrollment_t) * c);
                enrollments[next_enrollment_index++] =
                    create_enrollment(courses[j], students[k], opt[i].element4, _element_grade);
                k = 100;
              } else if (strcmp(opt[i].element2, courses[j].code) != 0){
                j+= 1;
              } else if (strcmp(opt[i].element3, students[k].id) != 0){
                k+= 1;
              }
            } while (k != 100);
          } else if (enrollments != NULL){
            int j,k = 0;
            do{
              if (strcmp(opt[i].element2, courses[j].code) == 0 && strcmp(opt[i].element3, students[k].id) == 0){
                c+=1;
                enrollments = realloc(enrollments, sizeof(struct enrollment_t) * c);
                enrollments[next_enrollment_index++] =
                    create_enrollment(courses[j], students[k], opt[i].element4, _element_grade);
                k = 100;
              } else if (strcmp(opt[i].element2, courses[j].code) != 0){
                j+= 1;
              } else if (strcmp(opt[i].element3, students[k].id) != 0){
                k+= 1;
              }
            } while (k != 100);
          }
        }
      }
    } else if (strcmp(opt[i].element1, "print-enrollments") == 0){
      print_enrollments(enrollments, next_enrollment_index);
    } else if (strcmp(opt[i].element1, "set-enrollment-grade") == 0){
      enum grade_t _element = GRADE_NONE;
      if (strcmp(opt[i].element6, "A") == 0){
        _element = GRADE_A;
      } else if (strcmp(opt[i].element6, "AB") == 0){
        _element = GRADE_AB;
      } else if (strcmp(opt[i].element6, "B") == 0){
        _element = GRADE_B;
      } else if (strcmp(opt[i].element6, "BC") == 0){
        _element = GRADE_BC;
      } else if (strcmp(opt[i].element6, "C") == 0){
        _element = GRADE_C;
      } else if (strcmp(opt[i].element6, "D") == 0){
        _element = GRADE_D;
      } else{
        _element = GRADE_E;
      }
      int j, k = 0;
      do{
        if (strcmp(opt[i].element2, courses[j].code) == 0 && strcmp(opt[i].element3, students[k].id) == 0){
          set_enrollment_grade(courses[j], students[k], enrollments, next_enrollment_index, _element);
          k = 100;
        } else if (strcmp(opt[i].element2, courses[j].code) != 0){
          j+= 1;
        } else if (strcmp(opt[i].element3, students[k].id) != 0){
          k+= 1;
        }
      } while ( k != 100);
    }
  }

  return 0;
}