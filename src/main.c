#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Read source file from specified path
static char *read_file(const char *path)
{
  FILE *file = fopen(path, "r");
  if (file == NULL)
    return NULL;

  fseek(file, 0, SEEK_END);
  int f_size = ftell(file);  
  fseek(file, 0, SEEK_SET);
  
  char *contents = calloc(f_size, 1);
  int iter = 0;
  while(iter < f_size)
  {
    contents[iter] = fgetc(file);
    iter++;
  }

  fclose(file);
  contents[iter] = '\0';

  return contents;
}

// Shift argv position to read next argument
static char *shift(int *argc, char ***argv)
{
  assert(*argc > 0);

  char *arg = **argv;
  *argc -= 1;
  *argv += 1;

  return arg;
}

void load_next_token(char **source)
{
  while(1) 
  {
    
  }
}

void parse(char *source)
{
  
  while (1)
  {
  }
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("Insufficient arguments!\n");
    return 1;
  }

  shift(&argc, &argv);

  const char *path = shift(&argc, &argv);
  
  char *source = read_file(path);

  printf("%s\n\n", source);
  parse(source);

  free(source);

  return 0;
}
