#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv)
{
  FILE *f;
  int8_t needs_b = 0;
  if (argc < 2) {
    f = stdin;
  } else if (argc == 2) {
    f = fopen(argv[1], "r");
    if (!f) {
      perror(argv[0]);
      return 1;
    }
  } else {
    return argc;
  }

  while (1) {
    switch (fgetc(f) - needs_b) {
    case 'a':
      needs_b = !needs_b;
      break;
    case EOF: case '\n':
      if (argc == 2) fclose(f);
      return needs_b;
    default:
      if (argc == 2) fclose(f);
      return 1;
    }
  }
  if (argc == 2) fclose(f);
  return 0;
}
