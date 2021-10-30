//
//  main.cpp
//  yellow_course_poject
//
//  Created by research on 09.03.2021.
//

#include "date.h"
#include "database.h"
#include "node.h"
#include "condition_parser.h"
//#include "test_runner.h"
//#include "test_db.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string ParseEvent(istream& is)
{
    // Реализуйте эту функцию
    // Вся остальная часть строки в команде Add задаёт событие. Оно может содержать пробелы, поэтому для его считывания удобно воспользоваться функцией getline. При этом гарантируется, что название события не может содержать символ кавычки ("). Таким образом, этот символ может встретиться лишь в условии в командах Find и Del, являясь ограничителем названия события.
    string event;
    while (is.peek() == ' ')
    {
        is.ignore(1);
    }
    getline(is, event, '\n');
    
    return event;
}

//void TestAll();

int main() {
//    TestAll();

    Database db;

    for (string line; getline(cin, line); )
        {
            istringstream is(line);

            string command;
            is >> command;
            if (command == "Add")
            {
                const auto date = ParseDate(is);
                const auto event = ParseEvent(is);
                db.Add(date, event);
            } else if (command == "Print") {
                db.Print(cout);
            } else if (command == "Del") {
                auto condition = ParseCondition(is);
                auto predicate = [condition](const Date& date, const string& event)
                {
                    return condition->Evaluate(date, event);
                };
                int count = db.RemoveIf(predicate);
                cout << "Removed " << count << " entries" << endl;
            } else if (command == "Find") {
                auto condition = ParseCondition(is);
                auto predicate = [condition](const Date& date, const string& event)
                {
                    return condition->Evaluate(date, event);
                };

                const auto entries = db.FindIf(predicate);
                for (const auto& entry : entries) {
                    cout << entry << endl;
                }
                cout << "Found " << entries.size() << " entries" << endl;
            } else if (command == "Last") {
                try
                {
                    cout << db.Last(ParseDate(is)) << endl;
                } catch (invalid_argument&) {
                    cout << "No entries" << endl;
                }
            } else if (command.empty()) {
                continue;
            } else {
                throw logic_error("Unknown command: " + command);
            }
        }

    return 0;
}
//
//void TestParseEvent() {
//  {
//    istringstream is("event");
//    AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
//  }
//  {
//    istringstream is("   sport event ");
//    AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
//  }
//  {
//    istringstream is("  first event  \n  second event");
//    vector<string> events;
//    events.push_back(ParseEvent(is));
//    events.push_back(ParseEvent(is));
//    AssertEqual(events, vector<string>{"first event  ", "second event"}, "Parse multiple events");
//  }
//}
//
//
//void TestAll() {
//  TestRunner tr;
//    tr.RunTest(TestParseEvent, "TestParseEvent");
//    tr.RunTest(TestParseCondition, "TestParseCondition");
//    tr.RunTest(TestEventComparisonNode, "TestEventComparisonNode");
//    tr.RunTest(TestEmptyNode, "Тест 2 из Coursera");
//    tr.RunTest(TestDbAdd, "TestDbAdd Тест 3(1) из Coursera");
//    tr.RunTest(TestDbFind, "TestDbFind Тест 3(2) из Coursera");
//    tr.RunTest(TestDbLast, "TestDbLast Тест 3(3) из Coursera");
//    tr.RunTest(TestDbRemoveIf, "TestDbRemoveIf Тест 3(4) из Coursera");
//    tr.RunTest(TestInsertionOrder, " TestInsertionOrder Тест на порядок вывода");
//    tr.RunTest(TestsMyCustom, "TestsMyCustom Мои тесты");
//    tr.RunTest(TestDatabase, "TestDatabase Тест базы данных с GitHub");
//
//}

