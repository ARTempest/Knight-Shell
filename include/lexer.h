#include <iostream>
#include <string>
#include <vector>

enum class TokenType {
    WORD,

    PIPE,               // |
    BACKGROUND,         // &
    SEMI_COLON,         // ;   


    REDICT_IN,          // <
    REDICT_OUT,         // >
    REDICT_APPEND,      // >>

    L_PARENTHESIS,      // (
    R_PARENTHESIS,      // ) 

    NONE             // error
};

struct Token {
  std::string value;
  TokenType type;
  int line;
};




void TokenizeInput(std::string);
bool SeparateTokens(TokenType*,char);
Token CreateToken(std::string, TokenType);

void PrintTokens(std::vector<Token>);
