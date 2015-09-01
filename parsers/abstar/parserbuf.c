#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define CHUNK 4096

int main(int argc, char **argv)
{
  char mybuf[CHUNK];
  setvbuf(stdin, mybuf, _IOFBF, CHUNK);

  int8_t needs_b = 0;
  if (argc < 2) {
    while (1) {
      switch (fgetc(stdin) - needs_b) {
      case 'a': needs_b = !needs_b; break;
      case EOF: case '\n': return needs_b;
      default: return 1;
      }
    }
    return 0;
  } else if (argc == 2) {
    FILE *f = fopen(argv[1], "r");
    if (!f) {
      perror(argv[0]);
      return 1;
    }

    size_t r;
    while ((r = fread(mybuf, sizeof(char), CHUNK, f)) > 0) {
      for (size_t i = 0; i < r; i++) {
	switch (mybuf[i] - needs_b) {
	case 'a':
	  needs_b = !needs_b;
	  break;
	case EOF: case '\n':
	  fclose(f);
	  return needs_b;
	default:
	  fclose(f);
	  return 1;
	}
      }
    }
    fclose(f);
    return 0;
  } else {
    return argc;
  }
}
