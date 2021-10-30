//
//  date.h
//  yellow_course_poject
//
//  Created by research on 09.03.2021.
//

#ifndef date_h
#define date_h

#pragma once

#include <string>
#include <istream>
#include <ostream>
#include <iomanip>

using namespace std;

class Date {
public:
//    Date();
    Date(const int& new_year, const int& new_month, const int& new_day);
    
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
    
    Date(const Date& newDate)
    {
        year = newDate.GetYear();
        month  = newDate.GetMonth();
        day = newDate.GetDay();
    }
    
private:
    int year;
    int month;
    int day;
};

Date ParseDate(istream& input_stream);

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& stream, const Date& date);


#endif /* date_h */
