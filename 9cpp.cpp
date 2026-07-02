#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

struct Token {
  int val=0;
  std::string str="";
};

std::vector<Token> tokenize(std::string str);

int main(int argc, char **argv) {
    if (argc != 2) {
    fprintf(stderr, "引数の個数が正しくありません\n");
    return 1;
  }

  std::vector<Token> token = tokenize(argv[1]);

  std::cout << ".intel_syntax noprefix\n";
  std::cout << ".globl main\n";
  std::cout << "main:\n";

  int n=0;
  std::cout << "    mov rax, " << token[n].val << "\n";

  n++;

  while(n<token.size()){
    if(token[n].str == "+"){
        n++;
        std::cout << "    add rax, " << token[n].val << "\n";
        n++;
        continue;
    }

    if(token[n].str == "-"){
        n++;
        std::cout << "    sub rax, " << token[n].val << "\n";
        n++;
        continue;
    }

    std::cerr << "予期しない文字です: " << token[n].str << "\n";
    return 1;

  }

  std::cout << "ret\n";
  return 0;
}

std::vector<Token> tokenize(std::string p) {
  std::vector<Token> token;
  int n=0;
  size_t len=0;
  while(n<p.size()) {
    Token t;
    if(isspace(p[n])) {
      n++;
      continue;
    }

    if(isdigit(p[n])) {
      t.val=std::stoi(p.substr(n), &len);
      n+=len;
      token.push_back(t);
      continue;
    }

    t.str=p[n];
    n++;
    token.push_back(t);
  }

  return token;
}