#include "mat.h"

#include "ast/Function.h"

#include <algorithm>
#include <iostream>
#include <sstream>

enum token_type { IDENT = 0, NUMBER, PUNCT, WHITE, EOL };

struct token {
  token_type t;
  std::string src;
  int line, col;
};

std::vector<token> lex(const std::string &v) {
  int line = 1;
  int col = 1;
  std::vector<token> tokens;
  for (const char &c : v) {
    auto line_update = [&]() {
      if (c == '\n') {
        line++;
        col = 0;
      }
      col++;
    };
    auto new_token = [&]() {
      if (c == 0) {
        return;
      }
      if (c == '\n') {
        tokens.push_back({EOL, "\n", line, col});
      } else if (std::isspace(c)) {
        tokens.push_back({WHITE, std::string(1, c), line, col});
      } else if (c >= '0' && c <= '9') {
        tokens.push_back({NUMBER, std::string(1, c), line, col});
      } else if (std::isalnum(c) || c == '_') {
        tokens.push_back({IDENT, std::string(1, c), line, col});
      } else {
        tokens.push_back({PUNCT, std::string(1, c), line, col});
      }
      line_update();
    };
    if (tokens.size() == 0) {
      new_token();
    } else {
      if (tokens.back().t == IDENT) {
        if (std::isalnum(c) || c == '_') {
          tokens.back().src += c;
          line_update();
        } else {
          new_token();
        }
      } else if (tokens.back().t == NUMBER) {
        if ((c >= '0' && c <= '9') || c == 'e' || c == 'E' || c == '.') {
          tokens.back().src += c;
          line_update();
        } else {
          new_token();
        }
      } else if (tokens.back().t == PUNCT) {
        if (((c >= '0' && c <= '9') || c == '.') &&
            (tokens.back().src == "-" || tokens.back().src == ".")) {
          tokens.back().t = NUMBER;
          tokens.back().src += c;
          line_update();
        } else if (tokens.back().src.back() == '.' || c == '=') {
          tokens.back().src += c;
          line_update();
        } else {
          new_token();
        }
      } else if (tokens.back().t == WHITE) {
        if (std::isspace(c) && c != '\n') {
          tokens.back().src += c;
          line_update();
        } else {
          new_token();
        }
      } else if (tokens.back().t == EOL) {
        new_token();
      }
    }
  }
  return tokens;
}

int test(std::vector<token> &tokens, int index, std::vector<std::string> valid,
         std::stringstream &err, int &advance, bool eol_valid = false) {
  for (int k = 0; k < valid.size(); k++) {
    std::string &s = valid[k];
    
  }
  return -1;
}



mat_module compile_source(const std::string &v) {
  auto l = lex(v);
  mat_module m;
  std::stringstream s;
  int adv;
  int x = test(l, 0, {}, s, adv);
  std::cout << x << ":" << s.str() << ":" << adv << std::endl;
  return m;
}
