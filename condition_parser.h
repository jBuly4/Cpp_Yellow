//
//  condition_parser.h
//  yellow_course_poject
//
//  Created by research on 09.03.2021.
//

#ifndef condition_parser_h
#define condition_parser_h
#pragma once

#include "node.h"

#include <memory>
#include <iostream>

using namespace std;

shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();

#endif /* condition_parser_h */
