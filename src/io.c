#include <stdio.h>
#include <stdlib.h>

char *read_file(const char *path)
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
