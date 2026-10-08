#include <stdio.h>

int main(int argc, char **argv) {
    if (argc!=2)
  {
    fprintf(stderr, "Usage: %s <value>\n", argv[0]);
    return 1;
  }
    


    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");
    printf("  mov eax, %s\n", argv[1]);
    printf("  ret\n");
    return 0;
}