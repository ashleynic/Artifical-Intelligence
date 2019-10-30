#include "BackwardChaining.h"
#include "forwardchaining.h"
#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    BackwardChaining bc;
    string result = bc.execute(); //calls backwards chaining to execute, returns the fault for the forward chaining to address
    forwardchaining fc(result);
    cout << fc.execute() << endl;

}
