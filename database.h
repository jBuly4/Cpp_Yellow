//
//  database.h
//  yellow_course_poject
//
//  Created by research on 09.03.2021.
//

#ifndef database_h
#define database_h

#pragma once

#include "date.h"

#include <map>
#include <set>
#include <vector>
#include <algorithm>

class Database {
private:
    map<Date, set<string>> storage_for_data;
    map<Date, vector<string>> tracker_for_data;
    
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& output) const;
    string Last(const Date& ParsedDate) const;
    
    // declaration and definition must be in .h
    template <typename Input_predicate>
    int RemoveIf(const Input_predicate& predicate)
    {
        map<Date, set<string>> storage_after_del;
        map<Date, vector<string>> tracker_after_del;
        
        int removed_items = 0;
        
        for (auto& pair_items : tracker_for_data)
        {
            auto border = stable_partition(begin(pair_items.second), end(pair_items.second),
                                           [pair_items, predicate](auto& vec_items)
            {
                return predicate(pair_items.first, vec_items);
            });
            
            if (border == end(pair_items.second))
            {
                removed_items += pair_items.second.size();
            } else {
                storage_after_del[pair_items.first] = set<string>(border, end(pair_items.second));
                tracker_after_del[pair_items.first] = vector<string>(border, end(pair_items.second));
                
                removed_items += static_cast<int>(pair_items.second.size() - tracker_after_del.at(pair_items.first).size()); // only assignment doesnt work. need to use +=
                
            }
        }
        
        tracker_for_data = tracker_after_del;
        storage_for_data = storage_after_del;
        
        return removed_items;
        
    }

    template <typename Input_predicate>
    vector<pair<Date,string>> FindIf(const Input_predicate& predicate) const
    {
        vector<pair<Date,string>> output_res;
        
        for (const auto& pair_items : tracker_for_data)
        {
            for (const auto& event : pair_items.second)
            {
                if (predicate(pair_items.first, event))
                {
                    output_res.push_back(make_pair(pair_items.first, event));
                }
            }
        }
        return output_res;
    }
};

ostream& operator<<(ostream& output, const pair<Date,string>& pair);
ostream& operator<<(ostream& output, const vector<pair<Date,string>>& pair_vec);

bool operator<(const pair<Date,string>& lhs, const pair<Date,string>& rhs);
bool operator==(const pair<Date,string>& lhs, const pair<Date,string>& rhs);


#endif /* database_h */
