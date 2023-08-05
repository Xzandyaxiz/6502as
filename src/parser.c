#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

void load_next_token(size_t **dims, char **source)
{
  (*dims)[0] = (*dims)[1];

  size_t curr_dim = 0;
  size_t old_beg = (*dims)[0];

  // Skip leading whitespaces and newlines
  while (**source == ' ' || **source == '\n' || **source == '\0') {
    (*source)++;
    old_beg++;
  }

  // Store the beginning
  (*dims)[curr_dim] = old_beg;
  curr_dim ++;

  // Skip trailing characters until we reach a delimiter
  while(**source != '\0' && **source != ' ' && **source != '\n')
  {
    (*source)++;
    old_beg++;
  }

  // Store the end
  (*dims)[curr_dim] = old_beg;
}

token_type_T get_type(size_t *token, char *source)
{
  // Store token in a temporary char buf
  char token_buf[(token[1] - token[0]) + 1];
  size_t buf_iter = 0;

  for (size_t iter = token[0]; iter < token[1]; iter++)
  {
    token_buf[buf_iter] = source[iter];
    buf_iter ++;
  }
  token_buf[buf_iter] = '\0';

  // (For debugging purposes)
  printf("%s\n", token_buf); 
}

void print_token(size_t *token, char *source)
{
  size_t iter = token[0];
  while (iter < token[1])
  {
    printf("%c", source[iter]);
    iter++;
  }
  printf("\n");
}

void AST_generate(char *source)
{
  // Copy source into static buffer
  char source_buf[strlen(source)+1];
  strcpy(source_buf, source);

  // Current token temporary storage
  size_t *token = calloc(2, sizeof(size_t));
  if (token == NULL)
    return;

  while (*source != '\0')
  {
    load_next_token(&token, &source); 
 
    get_type(token, source_buf);
  }

  free(token);
}
