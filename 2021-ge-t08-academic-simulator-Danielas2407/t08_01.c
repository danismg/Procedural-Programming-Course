// 12S20016 - Via Uni Rosa Sianipar
// 12S20038 - Arni Febryarti Sitorus

#include "academic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STUDENT 2

struct selection_t {
  char order1[100];
  char order2[100];
  char order3[100];
  char order4[100];
  char order5[100];
  char in[100];
};

struct to_t{
  struct selection_t selec;
};

int main(int _argc, char **_argv) {

int j;
struct selection_t select[150];
struct selection_t create_selection {
  struct selection_t select[150];
  for(j = 0; j < 100; j++) {
    select[j] = create_selection;
    strcpy(select[j].order1, "");
    strcpy(select[j].order2, "");
    strcpy(select[j].order3, "");
    strcpy(select[j].order4, "");
    strcpy(select[j].order5, "");
    strcpy(select[j].in, "");
  }
};

  char *separator;
  char none[5] = "---";
  struct student_t *students = NULL;
  struct course_t *courses = NULL;
  struct enrollment_t *enrollments = NULL;
  int student = 0;
  int course = 0;
  int enrollment = 0;
  students = malloc(sizeof(struct student_t) * student);
  courses = malloc(sizeof(struct course_t) * course);
  enrollments = malloc(sizeof(struct enrollment_t) * enrollment);
  short int next_student_index = 0;
  short int next_course_index = 0;

  short int next_enrollment_index = 0;
  for (j = 0; j < 100; j++) {
   char action[100] = "";
    short int ii = 0;
    action[0] = '\0';
      while(1) {
        char R = '\0';
         R = getchar();
         if (R != '\r' && R != '\n') {
        action[ii] = R;
        action[++ii] = '\0';
         }  
          else {
          if (R == '\r') {
          continue;
          }

          if (R == '\n') {
          break;
        };
        } 
      if(strcmp(action, "---") == 0) {
        j = 150;
        }
   }
  strcpy(select[j].in, action);
  separator = strtok(select[j].in, "#");
  int a = 0;
    while(separator != NULL) {
      if(a == 0) {
        strcpy(select[j].order1, separator);
        separator = strtok(NULL, "#");
        a = a + 1;
      }
      else if(a == 1) {
        strcpy(select[j].order2, separator);
        separator = strtok(NULL, "#");
        a = a + 1;
      }
      else if(a == 2) {
        strcpy(select[j].order3, separator);
        separator = strtok(NULL, "#");
        a = a + 1;
      }
      else if(a == 3) {
        strcpy(select[j].order4, separator);
        separator = strtok(NULL, "#");
        a = a + 1;
      }
      else if(a == 4) {
        strcpy(select[j].order5, separator);
        separator = strtok(NULL, "#");
        a = a + 1;
    }
  }
  }
  
  char forstudent[20] = "create-student";
  char forstudents[20] = "print-students";
  char forcourse[20] = "create-course";
  char forcourses[20] = "print-courses";
  char findstudent[20] = "find-student-by-id";
  char findcourse[20] = "find-course-by-code";
  char forenrollment[20] = "create-enrollment";
  char forenrollments[20] = "print-enrollments";
  char forslash[20] = "---";
  char foryear[20] = "2020";
  for (j = 0; j < 100; j++) {
  if(strcmp(select[j].order1, "create-student") == 0){
    if (students == NULL) {
      student = student + 1;
      students = malloc(sizeof(struct student_t) * student);
      students[next_student_index++] = 
      create_student(select[j].order2, select[j].order3, select[j].order4, select[j].order5);
    } 
    else {
      student = student + 1;
      students = realloc(students, sizeof(struct student_t) * student);
      students[next_student_index++] = 
      create_student(select[j].order2, select[j].order3, select[j].order4, select[j].order5);
    }
  }
  else if(strcmp(select[j].order1, "print-students") == 0 ) {
    print_students(students, next_student_index);
  }
  else if(strcmp(select[j].order1, "---") == 0) {
    j = 100;
  }
  else if(strcmp(select[j].order1, "create-course") == 0) {
    char forgradeA[] = "A";
    char forgradeAB[] = "AB";
    char forgradeB[] = "B";
    char forgradeBC[] = "BC";
    char forgradeC[] = "C";
    char forgradeD[] = "D";
    char forgradeE[] = "E";
    enum grade_t _order = GRADE_NONE;
    if(strcmp(select[j].order5,  "A") == 0) {
        _order = GRADE_A;
    }
      else if(strcmp(select[j].order5, "AB") == 0) {
        _order = GRADE_AB; 
    }
      else if(strcmp(select[j].order5, "B") == 0) {
       _order = GRADE_B; 
    }
      else if(strcmp(select[j].order5, "BC") == 0) {
       _order = GRADE_BC; 
    }
      else if(strcmp(select[j].order5, "C") == 0) {
       _order = GRADE_C; 
    }
      else if(strcmp(select[j].order5, "D") == 0) {
       _order = GRADE_D; 
    }
      else {
       _order = GRADE_E; 
    }
    if (courses == NULL) {
      course = course + 1;
      courses = malloc(sizeof(struct course_t) * course);
      courses[next_course_index++] = 
      create_course(select[j].order2, select[j].order3, atoi(select[j].order4), _order);
    } 
    else {
      course = course + 1;
      courses = realloc(courses, sizeof(struct course_t) * course);
      courses[next_course_index++] = 
      create_course(select[j].order2, select[j].order3, atoi(select[j].order4), _order);
    }
  }
  else if(strcmp(select[j]. order1, "print-courses") == 0) {
    print_courses(courses, next_course_index);
  }
 else if(strcmp(select[j].order1, "find-student-by-id") == 0) {
    find_student_by_id(students, next_student_index, select[j].order2);
  }
  else if (strcmp(select[j].order1, "print-enrollments") == 0) {
  print_enrollments(enrollments, next_enrollment_index);
  } 
  else if(strcmp(select[j].order1, "find-course-by-code") == 0){
    find_course_by_code(courses, next_course_index, select[j].order2);
  }
  else if(strcmp(select[j].order1, "create-enrollment") == 0) {
    char theodd[] = "odd";
    char theeven[] = "even";
    enum grade_t _orders;
        if(strcmp(select[j].order5, "odd") == 0 ) {
          _orders = SEMESTER_ODD;
        }
        if(strcmp(select[j].order5, "even") == 0) {
          _orders = SEMESTER_EVEN;
        }
        else{
          _orders = SEMESTER_ODD;
        }
          if(enrollments == NULL) {
            int a = 0;
            int aa = 0;
            do {
               if(strcmp(select[j].order2, courses[a].code) == 0 && strcmp(select[j].order3, students[aa].id) == 0) {
                enrollment = enrollment + 1;
                enrollments = malloc(sizeof(struct enrollment_t) * enrollment);
                enrollments[next_enrollment_index++] = 
                create_enrollment(courses[a], students[aa], select[j].order4, _orders);
                aa = 100;
              }
              else if(strcmp(select[j].order2, courses[a].code) != 0) {
                a = a + 1;
              }
              else if(strcmp(select[j].order3, students[aa].id) != 0){
                aa = aa + 1;
              }
            }
            while(aa != 100);
          }
             
          else if (enrollments != NULL) {
            int a = 0;
            int aa = 0;
              do {
              if(strcmp(select[j].order2, courses[a].code) == 0 && strcmp(select[j].order3, students[aa].id) == 0) {
                enrollment = enrollment + 1;
                enrollments = malloc(sizeof(struct enrollment_t) * enrollment);
                enrollments[next_enrollment_index++] = 
                create_enrollment(courses[a], students[aa], select[j].order4, _orders);
                aa = 100;
              }
              else if(strcmp(select[j].order2, courses[a].code) != 0) {
                a = a + 1;
              }
              else if(strcmp(select[j].order3, students[aa].id) != 0){
                aa = aa + 1;
              }
            }
            while(aa != 100);
          }
  
  }
              
else if (strcmp(select[j].order1, "print-enrollments") == 0) {
  print_enrollments(enrollments, next_enrollment_index);
}
  }
  

  return 0;
}