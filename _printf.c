#include <stdio.h>
#include <stdarg.h>

void _printf(char *format, ...) {
  va_list args;
  va_start(args, format);

  char *s;
  int d;
  char c;

  while (*format != '\0') {
    if (*format == '%') {
      format++;
      if (*format == 's') {
        s = va_arg(args, char*);
        printf("%s", s);
      } else if (*format == 'd') {
        d = va_arg(args, int);
        printf("%d", d);  
      } else if (*format == 'c') {
        c = va_arg(args, int);
        printf("%c", c);
      }
    } else {
      printf("%c", *format);
    }
    format++;
  }
  
  va_end(args);
}

int main() {
  
  _printf("Hello %s %d", "world!", 123);
  
  return 0;
}