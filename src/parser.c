#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "parser.h"

void load_next_instruction(size_t **dims, char **source)
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
  while(**source != '\0' && **source != '\n')
  {
    (*source)++;
    old_beg++;
  }

  (*dims)[curr_dim] = old_beg;
}

void execute_instruction(size_t *token, char *source)
{
  size_t iter = token[0];
  while (iter < token[1])
  {
    printf("%c", source[iter]);
    iter++;
  }

  printf("%c\n");
}

void AST_generate(char *source, char *o_dest)
{
  // Copy source into static buffer
  char source_buf[strlen(source)+1];
  strcpy(source_buf, source);

  // Current token temporary storage
  size_t *token = calloc(2, sizeof(size_t));
  if (token == NULL)
    return;

  FILE *file = fopen(o_dest, "wb");
  if (file == NULL)
  {
    printf("Could not open file in binary write mode.\n");
    return;
  }

  while (*source != '\0')
  {
    load_next_instruction(&token, &source); 
 
    // Generate instruction node and write it to target file.
    instr_t *instr = parse_instruction(token, source_buf);
    instr_write(&instr);
  }

  free(token);
}
