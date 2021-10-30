//
//  token.h
//  yellow_course_poject
//
//  Created by research on 09.03.2021.
//

#ifndef token_h
#define token_h
#pragma once

#include <sstream>
#include <vector>
using namespace std;

enum class TokenType {
  DATE,
  EVENT,
  COLUMN,
  LOGICAL_OP,
  COMPARE_OP,
  PAREN_LEFT,
  PAREN_RIGHT,
};

struct Token {
  const string value;
  const TokenType type;
};

vector<Token> Tokenize(istream& cl);

#endif /* token_h */
