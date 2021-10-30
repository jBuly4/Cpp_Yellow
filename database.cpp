//
//  database.cpp
//  yellow_course_poject
//
//  Created by research on 09.03.2021.
//

#include "date.h"
#include "database.h"

#include <stdio.h>
#include <ostream>
#include <sstream>

void Database::Add(const Date &date, const string &event)
{
    if (storage_for_data.count(date) == 0 || storage_for_data.at(date).count(event) == 0)
    {
        storage_for_data[date].insert(event);
        tracker_for_data[date].insert(end(tracker_for_data[date]), event); //.push_back(event);
    }
}

void Database::Print(ostream& output) const
{
    // good idea https://ravesli.com/urok-198-iteratory-stl/#toc-4
    // Встретив команду Print, ваша программа должна вывести все пары (дата, событие), которые в данный момент содержатся в базе данных. Пары надо выводить по одной в строке. Они должны быть отсортированы по дате по возрастанию. События в рамках одной даты необходимо выводить в порядке добавления (за исключением уже удалённых и попыток добавления повторов).
    
    auto it = begin(tracker_for_data);
    
    while (it != end(tracker_for_data))
    {
        for (auto it_vec = begin(it->second); it_vec != end(it->second); ++it_vec)
        {
            output << it->first << " " << *it_vec << endl;
        }
        ++it;
    }
}

string Database::Last(const Date &ParsedDate) const
{
    ostringstream output;
    
    auto it = begin(tracker_for_data);
//    auto border = upper_bound(it, end(tracker_for_data), ParsedDate); // first after date
    auto border = tracker_for_data.upper_bound(ParsedDate);
    
    if (border == it)//(ParsedDate < it->first)
    {
        throw invalid_argument("");
//        output << "No entries" << endl;
        //return output;
    }
    
    --border;// saved date less or equal to input date?
    output << border->first << " " << border->second.back(); // last element from vector for input date
        //return output;
    
    return output.str();
}

ostream& operator<<(ostream& output, const pair<Date,string>& pair)
{
    output << pair.first << " " << pair.second;
    return output;
}

ostream& operator<<(ostream& output, const vector<pair<Date,string>>& pair_vec)
{
    for (const auto& pair : pair_vec)
    {
        output << pair;
    }
    return output;
}

bool operator<(const pair<Date,string>& lhs, const pair<Date,string>& rhs)
{
    return lhs.first < rhs.first;
}

bool operator==(const pair<Date,string>& lhs, const pair<Date,string>& rhs)
{
    return lhs.first == rhs.first && lhs.second == rhs.second;
}


