#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "forwardchaining.h"
using namespace std;

forwardchaining::forwardchaining(string s)
{
    
    fill_varList();
    generate_clause_list();
    for(int i= 0; i< 25; i++){
            if(varlist[i].name.compare(s) == 0)
                varlist[i].value = "YES";
        }
    for(int i = 0; i <25; i++){
        if(clause_list[i].name.compare(s)==0) {
            clause_list[i].value = "YES";
        }
 

    }
}

string forwardchaining::execute()
{
    string result = "We are unable to identify the issue. Please contact a mechanic.";
    for(int i = 0; i< 25; i++ )
    {
        while(!conclusion_queue.empty())
            conclusion_queue.pop();

        for(int k = rule_list[i].clauses.size()-1;k>=0;k--)
            conclusion_queue.push({i,i});
        int rule_num;
        int clause_num;
        bool pass = true;
        int cnt = 0; //keeps track of which clause to check
        while(!conclusion_queue.empty())
        {
            if(pass == false)
                break;
            rule_num = conclusion_queue.front().rule;
            clause_num = conclusion_queue.front().clause;
            if((clause_list[clause_num].name.compare(rule_list[rule_num].clauses[0 + cnt ].name) == 0))
                if((clause_list[clause_num].value.compare(rule_list[rule_num].clauses[0 + cnt ].value) != 0))
                        pass = false; //checks if the rule and the variables line up
            conclusion_queue.pop();
            cnt++; //increments the clause in each rule
           

        }
        if(pass == true){
            if(i == 0)
                result = "We recommend that you replace the battery.";
            if(i== 1)
                result = "We recommend that you replace the starter.";
            if(i == 2)
                result = "We recommend that you replace the brake pads.";
            if(i== 3)
                result = "We recommend that you bleed the brake lines.";
            if(i== 4)
                result = "We recommend that you replace the master cylinder.";
            if(i == 5)
                result = "We recommend that you replace your tire(s).";
            if(i == 6)
                result = "We recommend that you get your tires balanced.";
            if(i == 7)
                result = "We recommend that you pull over and let the car cool immediately.";
            if (i == 8)
                result = "We recommend that you check your oil.";
            if (i==9)
                result = "We recommend that you get an oil change.";
            if(i ==10)
                result = "We recommend that you replace your car's battery.";
            if (i == 11)
                result = "We recommend that you get jumper cables and charge the battery";
            if (i== 12)
                result = "We recommend that you replace your car's wiping mechanism.";
            if (i == 13)
                result = "We recommend that you replace your car's wiper fluid.";
            if (i == 14)
                result = "We recommend that you replace your car's wiper blade.";
            if (i == 15)
                result = "We recommend that you replace your car's wiper blades.";
            if (i==16)
                result = "We recommend that you replace your car's speaker system.";
            if (i == 17)
                result = "We recommend that you have a mechanic replace your car's transmission.";
            if(i == 18)
                result = "We recommend that you replace your car's muffler.";
            if(i==19)
                result = "We recommend that you replace your car's fuel filter.";
            if(i == 20)
                result = "We recommend that you replace your car's fuel filter.";
            if(i == 21)
                result = "We recommend that you replace your car's suspension.";
            if(i== 21)
                result = "We recommend that you contact a mechanic to replace your car's A/C system.";
            if(i == 22)
                result = "We recommend that you replace your car's steering fluid.";
            if(i == 23)
                result = "We recommend refueling your car.";
            if(i == 24)
                result = "We recommend refueling your car.";
            if(i == 25)
                result = "We recommend to replace your car's gas tank.";
        }
        if(result.compare("We are unable to identify the issue. Please contact a mechanic.") != 0) //breaks if a problem is found
            break;
    } return result;

}

void forwardchaining::fill_varList()
{
    varlist.push_back({"DeadBattery", false , ""});
    varlist.push_back({"Starter",false,""});
    varlist.push_back({"BrakePads",false,""});
    varlist.push_back({"BrakeLines", false,""});
    varlist.push_back({"MasterCylinder", false , ""});
    varlist.push_back({"FlatTire",false,""});
    varlist.push_back({"OutOfBalance",false,""});
    varlist.push_back({"CarOverheating", false,""});
    varlist.push_back({"Overheating", false , ""});
    varlist.push_back({"MotorOil",false,""});
    varlist.push_back({"Oil",false,""});
    varlist.push_back({"BatteryIssue", false,""});
    varlist.push_back({"LowBattery", false , ""});
    varlist.push_back({"WiperSystem",false,""});
    varlist.push_back({"BadWiperBlade",false,""});
    varlist.push_back({"WiperBlade", false,""});
    varlist.push_back({"Speakers", false , ""});
    varlist.push_back({"Transmission",false,""});
    varlist.push_back({"Muffler",false,""});
    varlist.push_back({"Filter", false,""});
    varlist.push_back({"FuelFilter", false , ""});
    varlist.push_back({"Suspension",false,""});
    varlist.push_back({"A/C",false,""});
    varlist.push_back({"SteeringFluid", false,""});
    varlist.push_back({"NoFuel",false,""});


}

void forwardchaining::generate_clause_list()
{
    rule_list[0].clauses.push_back({"DeadBattery", true, "YES"});
    rule_list[1].clauses.push_back({"Starter",true, "YES"});
    rule_list[2].clauses.push_back({"BrakePads", true, "YES"});
    rule_list[3].clauses.push_back({"BrakeLines", true, "YES"});
    rule_list[4].clauses.push_back({"MasterCylinder",true,"YES"});
    rule_list[5].clauses.push_back({"FlatTire",true,"YES"});
    rule_list[6].clauses.push_back({"OutOfBalance", true,"YES"});
    rule_list[7].clauses.push_back({"CarOverheating",true,"YES"});
    rule_list[8].clauses.push_back({"Overheating",true,"YES"});
    rule_list[9].clauses.push_back({"MotorOil",true,"YES"});
    rule_list[10].clauses.push_back({"Oil",true,"YES"});
    rule_list[11].clauses.push_back({"BatteryIssue", true,"YES"});
    rule_list[12].clauses.push_back({"LowBattery", true , "YES"});
    rule_list[13].clauses.push_back({"WiperSystem",true,"YES"});
    rule_list[14].clauses.push_back({"BadWiperBlade",true,"YES"});
    rule_list[15].clauses.push_back({"WiperBlade", true,"YES"});
    rule_list[16].clauses.push_back({"Speakers", true , "YES"});
    rule_list[17].clauses.push_back({"Transmission",true,"YES"});
    rule_list[18].clauses.push_back({"Muffler",true,"YES"});
    rule_list[19].clauses.push_back({"Filter", true,"YES"});
    rule_list[20].clauses.push_back({"FuelFilter", true , "YES"});
    rule_list[21].clauses.push_back({"Suspension",true,"YES"});
    rule_list[22].clauses.push_back({"A/C",true,"YES"});
    rule_list[23].clauses.push_back({"SteeringFluid", true,"YES"});
    rule_list[24].clauses.push_back({"NoFuel",true,"YES"});
    rule_list[25].clauses.push_back({"TankLeak",true,"YES"});

    for(int i = 0; i < 25; i++)
    {
        int counter = 0;
        for(int k = 0; k < rule_list[i].clauses.size(); k++)
        {
            clause_list[i].name = rule_list[i].clauses[k].name;
            counter++;
        }
    }
}
