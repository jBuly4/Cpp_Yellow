//
//  node.h
//  yellow_course_poject
//
//  Created by research on 09.03.2021.
//

#ifndef node_h
#define node_h

#pragma once

#include "date.h"

#include <string>
#include <memory>

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,    
};

enum class LogicalOperation {
    Or,
    And,
};

class Node {
public:
    virtual bool Evaluate(const Date&  date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(const Date&  date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison& comp, const Date& date) : comp_(comp), date_(date) {}
    bool Evaluate(const Date&  date, const string& event) const override;
    
private:
    const Comparison comp_;
    const Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison& comp, const string& event) : comp_(comp), event_(event) {}
    bool Evaluate(const Date&  date, const string& event) const override;
    
private:
    const Comparison comp_;
    const string event_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation& logic_operation, const shared_ptr<Node>& left, const shared_ptr<Node>& right) : logic_op_(logic_operation), left_(left), right_(right) {}
    bool Evaluate(const Date&  date, const string& event) const override;
    
private:
    const LogicalOperation logic_op_;
    const shared_ptr<Node> left_;
    const shared_ptr<Node> right_;
};



// классы Node, EmptyNode, DateComparisonNode, EventComparisonNode и LogicalOperationNode — сформировать их иерархию и публичный интерфейс вам поможет анализ функций main и ParseCondition;



#endif /* node_h */
