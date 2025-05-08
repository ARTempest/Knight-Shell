#include "../include/shell.h"
#include "../include/lexer.h"

const std::string shell_prompt = "knight$ ";

void StartShell() {

  while (true) {
    ReadInput();
  }

}

void ReadInput() {
  std::cout << shell_prompt; // print the shell's prompt

  std::string input;
  std::getline(std::cin, input);
  input.push_back(' '); // added a space at the end to recognize the last word at the loop
  
  TokenizeInput(input);

}




