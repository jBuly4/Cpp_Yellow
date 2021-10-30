//
//  date.cpp
//  yellow_course_poject
//
//  Created by research on 09.03.2021.
//

#include <stdio.h>
#include "date.h"

Date::Date(const int& new_year, const int& new_month, const int& new_day) : day(new_day), month(new_month), year(new_year) {}

int Date::GetDay() const
{
    return day;
}

int Date::GetMonth() const
{
    return month;
}

int Date::GetYear() const
{
    return year;
}

Date ParseDate(istream& input_stream)
{
    int year, month, day;
    bool day_bool = true;
    // Гарантируется, что поле date в команде Add имеет формат «Год-Месяц-День», где Год — это целое число от 0 до 9999, Месяц — это номер месяца от 1 до 12 включительно, День — это номер дня от 1 до 31 включительно. После даты обязательно следует пробел, отделяющий её от события. Примеры корректных дат: 2017-11-07, 0-2-31.
    
    input_stream >> year;
    input_stream.ignore(1);
    input_stream >> month;
    input_stream.ignore(1);
    input_stream >> day;
//    if (input_stream.peek() == '-')
//    {
//        input_stream.ignore(1);
//        input_stream >> month;
//        if (input_stream.peek() == '-')
//        {
//            input_stream.ignore(1);
//            day_bool = day_bool && input_stream >> day;
//            if (!day_bool)
//            {
//                throw logic_error("Wrong date format: " + to_string(day)); // think how to output stream at this moment
//            }
//            if (!input_stream.eof())
//            {
//                throw logic_error("Wrong date format: " + to_string(day));
//            }
//        } else {
//            throw logic_error("Wrong date format: " + to_string(month));
//        }
//    } else {
//        throw logic_error("Wrong date format: " + to_string(year));
//    }
    return Date(year, month, day);
}

bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() != rhs.GetYear())
    {
        return lhs.GetYear() < rhs.GetYear();
    } else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    } else {
        return lhs.GetDay() < rhs.GetDay();
    }
}

bool operator<=(const Date& lhs, const Date& rhs)
{
    return  (lhs.GetYear() <= rhs.GetYear() && lhs.GetMonth() <= rhs.GetMonth() && lhs.GetDay() <= rhs.GetDay());
}

bool operator>(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() != rhs.GetYear())
    {
        return lhs.GetYear() > rhs.GetYear();
    } else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() > rhs.GetMonth();
    } else {
        return lhs.GetDay() > rhs.GetDay();
    }
}

bool operator>=(const Date& lhs, const Date& rhs)
{
    return  (lhs.GetYear() >= rhs.GetYear() && lhs.GetMonth() >= rhs.GetMonth() && lhs.GetDay() >= rhs.GetDay());
}

bool operator==(const Date& lhs, const Date& rhs)
{
    return  (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay());
}

bool operator!=(const Date& lhs, const Date& rhs)
{
    return  !(lhs == rhs); //(lhs.GetYear() != rhs.GetYear() && lhs.GetMonth() != rhs.GetMonth() && lhs.GetDay() != rhs.GetDay());
}

ostream& operator<<(ostream& stream, const Date& date)
{
    stream << setw(4) << setfill('0') << date.GetYear() << "-" << setw(2) << setfill('0') << date.GetMonth() << "-" << setw(2) << setfill('0') << date.GetDay();
    return stream;
}



