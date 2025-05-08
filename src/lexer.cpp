#include "../include/lexer.h"
#include <string>
#include <unordered_map>
#include <vector>

std::vector<Token> tokenized_input;

std::unordered_map<TokenType, std::string> strings = {
  {TokenType::BACKGROUND, "BACKGROUND"},
  {TokenType::L_PARENTHESIS, "L_PARENTHESIS"},
  {TokenType::R_PARENTHESIS, "R_PARENTHESIS"},
  {TokenType::NONE, "NONE"},
  {TokenType::PIPE, "PIPE"},
  {TokenType::REDICT_APPEND, "REDICT_APPEND"},
  {TokenType::REDICT_IN, "REDICT_IN"},
  {TokenType::WORD, "WORD"},
  {TokenType::REDICT_OUT, "REDICT_OUT"},
  {TokenType::SEMI_COLON, "SEMI_COLON"}
};


void TokenizeInput(std::string input) {

  std::string token_value;
  TokenType token_type;

  for (int c=0; c < input.size(); c++) {
    token_value.push_back(input[c]);

    if (SeparateTokens(&token_type, input[c]) == true) {
      Token new_token = CreateToken(token_value, token_type);
      tokenized_input.push_back(new_token);

      token_type = TokenType::NONE;
      token_value.clear();
    }

  }

  PrintTokens(tokenized_input);
  tokenized_input.clear();
}

bool SeparateTokens(TokenType* type, char c) {
  TokenType t; 

  switch (c) {
    case ' ':
      t = TokenType::NONE;
    break;

    case '|':
      t = TokenType::PIPE;
    break;

    case '&':
      t = TokenType::BACKGROUND;
    break;

    case ';':
      t = TokenType::SEMI_COLON;
    break;

    case '<':
      t = TokenType::REDICT_IN;
    break;

    case '>':
      if (*type == TokenType::REDICT_OUT){
        t = TokenType::REDICT_APPEND;
      } else {
        t = TokenType::REDICT_OUT;
      }
    break;
    
    case '(':
      t = TokenType::L_PARENTHESIS;
    break;

    case ')':
      t = TokenType::R_PARENTHESIS;
    break;

    default:
      t = TokenType::WORD;
    break;
  }
  

  if (t == TokenType::NONE) {
    return true;
  } 

  *type = t;

  if (t != TokenType::WORD && t != TokenType::REDICT_OUT) {
    return true;
  }

  return false;
}

Token CreateToken(std::string value, TokenType type) {
  Token new_token {.value = value, .type = type};
  return new_token;
}

void PrintTokens(std::vector<Token> tokens) {

  for (int i=0; i < tokens.size(); i++) {
    std::string type = strings[tokens[i].type];

    std::cout << "token #" << i << " " << tokens[i].value << "  " << type << '\n';
  }
}


