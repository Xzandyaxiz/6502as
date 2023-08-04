#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "parser.h"
#include "io.h"

// Shift argv position to read next argument
static char *shift(int *argc, char ***argv)
{
  assert(*argc > 0);

  char *arg = **argv;
  *argc -= 1;
  *argv += 1;

  return arg;
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("Insufficient arguments!\n");
    return 1;
  }

  // Shift the program name (not needed)
  shift(&argc, &argv);

  // Catch the program path 
  const char *path = shift(&argc, &argv);
  
  char *source = read_file(path);

  printf("%s\n\n", source);
  AST_generate(source);

  free(source);

  return 0;
}
