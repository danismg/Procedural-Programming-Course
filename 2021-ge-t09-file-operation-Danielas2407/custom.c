// 12S20031 - Daniel Andres Simangusnong
// 12S20054 - Rossianna Dewi Sri Hutabarat

#include "academic.h"
#include "custom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// codes
struct option_t{
  char element1[100];
  char element2[100];
  char element3[100];
  char element4[100];
  char element5[100];
  char element6[100];
  char input[100];
};


void get_string(char *_buffer, unsigned int _size);{
    get_line(stdin, _buffer, _size) ;           
}
void get_line(FILE *_stream, char *_buffer, unsigned int _size);{
    char ch = '\0';
    unsigned int i = 0;
    _buffer[i] = '\n';

    while (i < _size && (ch = fgetc(_stream) != EOF) {
        if (ch == '\r') {
            continue
        }

        if (ch == '\n') {
            break;
        }

        _buffer[i++] = ch;
        _buffer[i] = '\0';
    }
}