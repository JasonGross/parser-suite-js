#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int8_t needs_b = 0;
    while (1) {
      switch (fgetc(stdin) - needs_b) {
      case 'a': needs_b = !needs_b; break;
      case EOF: case '\n': return needs_b;
      default: return 1;
      }
    }
    return 0;
}
