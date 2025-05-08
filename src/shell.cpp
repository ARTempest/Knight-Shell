#include "../include/shell.h"
#include <iostream>
#include <string>
#include <vector>

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
  
  LexecizeInput(input);

}

void LexecizeInput(std::string input) {
  std::vector<std::string> lexed_input;
  std::string token;

  for (int i=0; i < input.size(); i++) {
    if (input[i] != ' ') {
      token.push_back(input[i]);
    } else {
      lexed_input.push_back(token);
      token.clear();
    }
  }

  for (int i=0; i < lexed_input.size(); i++) {
    std::cout << "word " << i << " is: " << lexed_input[i] << '\n';
  }
}



