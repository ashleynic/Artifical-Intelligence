#ifndef Backward_h
#define Backward_h

#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using std::string;
using std::vector;

struct conclusion_entry //for the conclusion list entries
{
    int rule;
    string name;
    string value;
};
struct clause_pointer //for the conclusion stack
{
    int rule;
    int clause;
};
struct variable_entry //holds data for variables, used in multiple data strucutres
{
    string name;
    bool inst;
    string value;
};
struct rule //holds set of clauses for each rule
{
    vector<variable_entry> clauses;
};
class BackwardChaining
{
    private:
        vector<conclusion_entry> conclusion_list;
        stack<clause_pointer> conclusion_stack;
        vector<variable_entry> varList;
        rule rule_list[30];
        void collect_var(string var_name);
        void update_clause(string var_name);
        variable_entry clause_list[180];
        void fill_varList();
        void fill_conclusion();
        void generate_clause_list();
        string get_answer();
    public:
        BackwardChaining();
        string execute();
            


};

#endif