#ifndef parser
  #define parser

  // Token types
  typedef enum
  {
    DIRECTIVE,
    LABEL,
    OPCODE,
    OPERAND
  } token_type_T;

  // Opcode types
  typedef enum
  {
    ADC,
    AND,
    ASL,
    BCC,
    BCS,
    BEQ,
    BIT,
    BMI,
    BNE,
    BPL,
    BRK,
    BVC,
    BVS,
    CLC,
    CLD,
    CLI,
    CLV,
    CMP,
    CPX,
    CPY,
    DEC,
    DEY,
    EOR,
    INC,
    INY,
    JMP,
    JSR,
    LDA,
    LDX,
    LDY,
    LSR,
    NOP,
    ORA,
    PHA,
    PHP,
    PLA,
    PLP,
    ROL,
    ROR,
    RTI,
    RTS,
    SBC,
    SEC,
    SED,
    SEI,
    STA,
    STX,
    STY,
    TAX,
    TAY,
    TSX,
    TXA,
    TXS,
    TYA
  } opcode_type_T;
  
  typedef struct
  {
    opcode_type_T opcode;
    char *operand;
  } instr_t;

  void load_next_token(
    size_t **dims,
    char **source
  );

  void AST_generate(
    char *source);

#endif
