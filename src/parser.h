#ifndef parser
  #define parser

  void load_next_token(
    size_t **dims,
    char **source
  );

  void AST_generate(
      char *source);

#endif
