#include <stdio.h>
#include <stdint.h>

int main(void)
{
    char mybuf[4096];
    setvbuf(stdin, mybuf, _IOFBF, 4096);

    int8_t needs_b = 0;
    while (1) {
      switch (fgetc(stdin)) {
      case 'a':
	if (needs_b) {
	  exit(1);
	} else {
	  needs_b = 1;
	}
	break;
      case 'b':
	if (needs_b) {
	  needs_b = 0;
	} else {
	  exit(1);
	}
	break;
      case EOF: case '\n': return 0;
      default: return 1;
      }
    }
    return 0;
}
