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

void load_next_token(size_t **dims, char **source) {
    size_t curr_dim = 0;
    size_t old_beg = (*dims)[0];

    while (**source == ' ') {
        (*source)++;
        old_beg++;
    }

    // Store the beginning position of the token
    (*dims)[curr_dim] = old_beg;
    curr_dim ++;

    while(**source != '\0' && **source != ' ')
    {
      (*source)++;
      old_beg++;
    }

    (*dims)[curr_dim] = old_beg;
}

void parse(char *source)
{
  size_t *tokens = calloc(2, sizeof(size_t));
  if (tokens == NULL)
    return;

  tokens[0] = 0;
  tokens[1] = 0;

  while (*source != '\0')
  {
    load_next_token(&tokens, &source);
    printf("%d, %d\n", tokens[0], tokens[1]);
    tokens[0] = tokens[1];
  }

  free(tokens);
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
