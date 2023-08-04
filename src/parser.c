#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

void load_next_token(size_t **dims, char **source) {
    size_t curr_dim = 0;
    size_t old_beg = (*dims)[0];

    // Skip leading whitespaces and newlines
    while (**source == ' ' || **source == '\n') {
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

void AST_generate(char *source)
{
  size_t *token = calloc(2, sizeof(size_t));
  if (token == NULL)
    return; 

  while (*source != '\0')
  {
    load_next_token(&token, &source);
    printf("%d, %d\n", token[0], token[1]);
    
    token[0] = token[1];
  
    if (*source == '\n')
      token[0] --;
  }

  free(token);
}
