#ifndef parser
  #define parser

  typedef enum
  {
    DIRECTIVE,
    LABEL,
    OPCODE,
    OPERAND
  } token_type_T;

  typedef enum
  {
    LDA, LDX, LDY
  } opcode_type_T;

  void load_next_token(
    size_t **dims,
    char **source
  );

  void AST_generate(
    char *source);

#endif
