//
// Created by Ashley Sanchez on 10/6/19.
//

#ifndef CLIONPROJECTS_AIPROJECT_FORWARDCHAINING_H
#define CLIONPROJECTS_AIPROJECT_FORWARDCHAINING_H


#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using std::string;
using std::vector;


struct variables
{
    string name;
    bool inst;
    string value;

};

struct clause_pointer_fc

{
    int rule;
    int clause;
};

struct rule_fc //holds set of clauses for each rule
{
    vector<variables> clauses;
};

class forwardchaining
{


private:
    vector<variables> varlist;
    queue<clause_pointer_fc>conclusion_queue;
    variables clause_list[26];
    rule_fc rule_list[26];
    void fill_varList();
    void generate_clause_list();
public:
    forwardchaining(string s);
    string execute();




};

#endif //CLIONPROJECTS_AIPROJECT_FORWARDCHAINING_H
