#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "BackwardChaining.h"
using namespace std;

BackwardChaining::BackwardChaining() //calls neccessary lists to be filled
{ 
    fill_varList();
    fill_conclusion();
    generate_clause_list();
}

string BackwardChaining::execute()
{       
        string result = "None";
        for(int i = 0; i < 30; i++)
        {
                while(!conclusion_stack.empty()) //clears stack at start
                        conclusion_stack.pop();
                for(int k = rule_list[i].clauses.size()-1; k >= 0; k--)
                {
                        conclusion_stack.push({i,(i*6)+k}); //adds rule and clauses to stack
                }
                int rule_num;
                int clause_num;
                bool pass = true;
                int cnt = 0; //keeps track of which clause to check
                while(!conclusion_stack.empty())
                {
                        if(pass == false)
                                break;
                        if(clause_list[conclusion_stack.top().clause].inst == false)
                                collect_var(clause_list[conclusion_stack.top().clause].name); //instantiates variable if not avaliable
                        rule_num = conclusion_stack.top().rule;
                        clause_num = conclusion_stack.top().clause;
                        if((clause_list[clause_num].name.compare(rule_list[rule_num].clauses[0 + cnt ].name) == 0))
                                if((clause_list[clause_num].value.compare(rule_list[rule_num].clauses[0 + cnt ].value) != 0))
                                        if((clause_list[clause_num].inst == rule_list[rule_num].clauses[0 +  cnt ].inst))
                                                pass = false; //checks if the rule and the variables line up
        
                        conclusion_stack.pop(); 
                        cnt++; //increments the clause in each rule
                        
                }
                if(pass == true) //if a problem is found
                {
                        if(i == 0)
                                conclusion_list[i].value = "DeadBattery";
                        if(i == 1)
                                conclusion_list[i].value = "Starter";
                        if(i == 2)
                                conclusion_list[i].value = "YES";
                        if(i == 3)
                                conclusion_list[i].value = "BrakePads";
                        if(i == 4)
                                conclusion_list[i].value = "BrakeLines";
                        if(i == 5)
                                conclusion_list[i].value = "MasterCylinder";
                        if(i == 6)
                                conclusion_list[i].value = "FlatTire";
                        if(i == 7)
                                conclusion_list[i].value = "TireOutOfBalance";
                        if(i == 8)
                                conclusion_list[i].value = "CarOverheating";
                        if(i == 9)
                                conclusion_list[i].value = "Overheating";
                        if(i == 10)
                                conclusion_list[i].value = "MotorOil";
                        if(i == 11)
                                conclusion_list[i].value = "Oil";
                        if(i == 12)
                                conclusion_list[i].value = "BatteryIssue";
                        if(i == 13)
                                conclusion_list[i].value = "LowBattery";
                        if(i == 14)
                                conclusion_list[i].value = "WiperSystem";
                        if(i == 15)
                                conclusion_list[i].value = "WiperFluid";
                        if(i == 16)
                                conclusion_list[i].value = "BadWiperBlade";
                        if(i == 17)
                                conclusion_list[i].value = "WiperBlade";
                        if(i == 18)
                                conclusion_list[i].value = "Speakers";
                        if(i == 19)
                                conclusion_list[i].value = "Transmission";
                        if(i == 20)
                                conclusion_list[i].value = "Transmission";
                        if(i == 21)
                                conclusion_list[i].value = "Muffler";
                        if(i == 22)
                                conclusion_list[i].value = "Filter";
                        if(i == 23)
                                conclusion_list[i].value = "FuelFilter";
                        if(i == 24)
                                conclusion_list[i].value = "Suspension";
                        if(i == 25)
                                conclusion_list[i].value = "AC";
                        if(i == 26)
                                conclusion_list[i].value = "SteeringFluid";
                        if(i == 27)
                                conclusion_list[i].value = "NoFuel";
                        if(i == 28)
                                conclusion_list[i].value = "NoFuel";
                        if(i == 29)
                                conclusion_list[i].value = "NoFuel";
                        if(conclusion_list[i].name.compare("Problem") == 0)
                                result = conclusion_list[i].value; //filters out the SYSTEM variable, since it is not our goal
                }
                if(result.compare("None") != 0) //breaks if a problem is found
                        break;                
        }
        return result;
}

void BackwardChaining::fill_varList() //creates all variables, sets value to nothing
{
    varList.push_back({"CarTurnOn", false,""});
    varList.push_back({"CarClickingNoise", false,""});
    varList.push_back({"ServiceLightOn", false,""});
    varList.push_back({"LowOilLight", false,""});
    varList.push_back({"LowGasLight", false,""});
    varList.push_back({"LowBatteryLight", false,""});
    varList.push_back({"TempLight", false,""});
    varList.push_back({"CarNoise", false,""});
    varList.push_back({"CarSmell", false,""});
    varList.push_back({"BrakeSystem", false,""});
    varList.push_back({"AirWarm", false,""});
    varList.push_back({"WheelShaking", false,""});
    varList.push_back({"System", false,""});
    varList.push_back({"LightsTurnOn", false,""});
    varList.push_back({"CarTurnOff", false,""});
    varList.push_back({"NoiseWhenBraking", false,""});
    varList.push_back({"WiperFluid", false,""});
    varList.push_back({"LowTireLight", false,""});
    varList.push_back({"StepOnBrake", false,""});
    varList.push_back({"Tires", false,""});
    varList.push_back({"EngineSystem", false,""});
    varList.push_back({"MotorOil", false,""});
    varList.push_back({"Wipers", false,""});
    varList.push_back({"Wiping", false,""});
    varList.push_back({"Transmission", false,""});
    varList.push_back({"Filter", false,""});
    varList.push_back({"Accelerate", false,""});
    varList.push_back({"HardTurn", false,""});
    varList.push_back({"BatteryIssue", false,""});
    varList.push_back({"SinkToFloor", false,""});
    varList.push_back({"StarterIssues", false,""});
    varList.push_back({"BrokenBrakes", false,""});
    varList.push_back({"CarOverheating", false,""});
    varList.push_back({"BadWiperBlade", false,""});
    varList.push_back({"Sound", false,""});
}

void BackwardChaining::fill_conclusion() //fills the conclusion list without results
{
    for(int i = 0; i < 30; i++)
    {
        conclusion_list.push_back({i*10, "Problem", ""});
    }
    conclusion_list[2] = {30, "System", ""};
}

void BackwardChaining::collect_var(string var_name) //prompts user and formats response to be processed
{
    string answer;
    if(var_name.compare("CarTurnOn") == 0)
    {
            cout << "Does your car turn on?" << endl;
            string s = get_answer();
            varList[0].value = s;
            varList[0].inst = true;
            update_clause(var_name);
            varList[12].value = s;
            varList[12].inst = true;
            update_clause("System");


    }
    if(var_name.compare("CarClickingNoise") == 0)
    {
            cout << "Is your car making a clicking noise?" << endl;
            varList[1].value = get_answer();
            varList[1].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("ServiceLightOn") == 0)
    {
            cout << "Is your service light on?" << endl;
            varList[2].value = get_answer();
            varList[2].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("LowOilLight") == 0)
    {
            cout << "Is your low oil light on?" << endl;
            varList[3].value = get_answer();
            varList[3].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("LowGasLight") == 0)
    {
            cout << "Is your low gas light on?" << endl;
            varList[4].value = get_answer();
            varList[4].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("LowBatteryLight") == 0)
    {
            cout << "Is your battery light on?" << endl;
            varList[5].value = get_answer();
            varList[5].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("TempLight") == 0)
    {
            cout << "Is your over-heating light on?" << endl;
            varList[6].value = get_answer();
            varList[6].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("CarNoise") == 0)
    {
            cout << "Is your car making any unusual noises?" << endl;
            varList[7].value = get_answer();
            varList[7].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("CarSmell") == 0)
    {
            cout << "Is your car emitting any unusual smells?" << endl;
            varList[8].value = get_answer();
            varList[8].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("BrakeSystem") == 0)
    {
            cout << "Are your brakes not operating as intended?" << endl;
            varList[9].value = get_answer();
            varList[9].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("AirWarm") == 0)
    {
            cout << "Does your A/C only produce warm air?" << endl;
            varList[10].value = get_answer();
            varList[10].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("WheelShaking") == 0)
    {
            cout << "Does your wheel shake when driving?" << endl;
            varList[11].value = get_answer();
            varList[11].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("LightsTurnOn") == 0)
    {
            cout << "Do your lights turn on?" << endl;
            varList[13].value = get_answer();
            varList[13].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("CarTurnOff") == 0)
    {
            cout << "Did your car abruptly turn off?" << endl;
            varList[14].value = get_answer();
            varList[14].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("NoiseWhenBraking") == 0)
    {
            cout << "Does your car make an unusual noise when braking?" << endl;
            varList[15].value = get_answer();
            varList[15].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("WiperFluid") == 0)
    {
            cout << "Does your car produce wiper fluid?" << endl;
            varList[16].value = get_answer();
            varList[16].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("LowTireLight") == 0)
    {
            cout << "Is your low light pressure light on?" << endl;
            varList[17].value = get_answer();
            varList[17].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("StepOnBrake") == 0)
    {
            cout << "Does the peddle sink to the floor when stepping on the brake?" << endl;
            varList[18].value = get_answer();
            varList[18].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("Tires") == 0)
    {
            cout << "Are your having tire problems?" << endl;
            varList[19].value = get_answer();
            varList[19].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("EngineSystem") == 0)
    {
            cout << "Do you believe you are having engine problems?" << endl;
            varList[20].value = get_answer();
            varList[20].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("MotorOil") == 0)
    {
            cout << "Was the last time you replaced your oil more than 6 months ago?" << endl;
            varList[21].value = get_answer();
            varList[21].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("Wipers") == 0)
    {
            cout << "Are your wipers not operating correctly?" << endl;
            varList[22].value = get_answer();
            varList[22].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("Wiping") == 0)
    {
            cout << "Are your wipers able to move?" << endl;
            varList[23].value = get_answer();
            varList[23].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("Transmission") == 0)
    {
            cout << "Do you believe you have transmission problems?" << endl;
            varList[24].value = get_answer();
            varList[24].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("Filter") == 0)
    {
            cout << "Was the last time you replaced your fuel filter more than two years ago?" << endl;
            varList[25].value = get_answer();
            varList[25].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("Accelerate") == 0)
    {
            cout << "Does the wheel shake when accelerating?" << endl;
            varList[26].value = get_answer();
            varList[26].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("HardTurn") == 0)
    {
            cout << "Is it difficult to turn?" << endl;
            varList[27].value = get_answer();
            varList[27].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("BatteryIssue") == 0)
    {
            cout << "Has your battery had issues recently?" << endl;
            varList[28].value = get_answer();
            varList[28].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("SinkToFloor") == 0)
    {
            cout << "Does the peddle sink to the floor when braking?" << endl;
            varList[28].value = get_answer();
            varList[28].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("StarterIssues") == 0)
    {
            cout << "Do you have trouble starting your car?" << endl;
            varList[29].value = get_answer();
            varList[29].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("BrokenBrakes") == 0)
    {
            cout << "Are your brakes not operating as intended?" << endl;
            varList[30].value = get_answer();
            varList[30].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("CarOverheating") == 0)
    {
            cout << "Has your car been overheating?" << endl;
            varList[31].value = get_answer();
            varList[31].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("Sound") == 0)
    {
            cout << "Does your car produce sound from the speakers?" << endl;
            varList[33].value = get_answer();
            varList[33].inst = true;
            update_clause(var_name);

    }
    if(var_name.compare("BadWiperBlade") == 0)
    {
            cout << "Are your wiper blades damaged in any way?" << endl;
            varList[32].value = get_answer();
            varList[32].inst = true;
            update_clause(var_name);

    }
}

string BackwardChaining::get_answer()
{
    string answer;
    cout << "(Input yes or no.)" << endl;
    getline(cin, answer);
    transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
    if(answer.compare("Y") == 0 || answer.compare("YES") == 0 || answer.compare("YES.") == 0)
    {
        return "YES";
    }
    else if (answer.compare("N") == 0 || answer.compare("NO") == 0 || answer.compare("NO.") == 0)
    {
        return "NO";
    }
    else
    {
        cout << "Invalid input, try again." << endl;
        return get_answer();
    }
    
}

void BackwardChaining::generate_clause_list() //creates all the rules and fills them with their appropriate clauses
{
    rule_list[0].clauses.push_back({"CarTurnOn", true, "NO"});
    rule_list[0].clauses.push_back({"CarClickingNoise", true, "YES"});
    
    rule_list[1].clauses.push_back({"CarTurnOn", true, "NO"});
    rule_list[1].clauses.push_back({"CarClickingNoise", true, "YES"});
    rule_list[1].clauses.push_back({"LightsTurnOn", true, "YES"});

    rule_list[2].clauses.push_back({"CarTurnOn", true, "YES"});
    
    rule_list[3].clauses.push_back({"CarTurnOn", true, "YES"});
    rule_list[3].clauses.push_back({"BrakeSystem", true, "YES"});
    rule_list[3].clauses.push_back({"NoiseWhenBraking", true, "YES"});

    rule_list[4].clauses.push_back({"BrakeSystem", true, "YES"});
    rule_list[4].clauses.push_back({"NoiseWhenBraking", true, "NO"});
    rule_list[4].clauses.push_back({"SinkToFloor", true, "YES"});

    rule_list[5].clauses.push_back({"BrakeSystem", true, "YES"});
    rule_list[5].clauses.push_back({"NoiseWhenBraking", true, "NO"});
    rule_list[5].clauses.push_back({"SinkToFloor", true, "YES"});

    rule_list[6].clauses.push_back({"Tires", true, "YES"});
    rule_list[6].clauses.push_back({"LowTireLight", true, "YES"});

    rule_list[7].clauses.push_back({"Tires", true, "YES"});
    rule_list[7].clauses.push_back({"LowTireLight", true, "NO"});
    rule_list[7].clauses.push_back({"WheelShaking", true, "YES"});

    rule_list[8].clauses.push_back({"EngineSystem", true, "YES"});
    rule_list[8].clauses.push_back({"ServiceLight", true, "YES"});

    rule_list[9].clauses.push_back({"CarOverheating", true, "YES"});
    rule_list[9].clauses.push_back({"TempLight", true, "YES"});

    rule_list[10].clauses.push_back({"CarOverheating", true, "YES"});
    rule_list[10].clauses.push_back({"TempLight", true, "NO"});

    rule_list[11].clauses.push_back({"MotorOil", true, "YES"});
    rule_list[11].clauses.push_back({"LowOilLight", true, "YES"});

    rule_list[12].clauses.push_back({"MotorOil", true, "YES"});
    rule_list[12].clauses.push_back({"LowOilLight", true, "NO"});

    rule_list[13].clauses.push_back({"BatteryIssue", true, "YES"});
    rule_list[13].clauses.push_back({"LowBatteryLight", true, "YES"});

    rule_list[14].clauses.push_back({"System", true, "YES"});
    rule_list[14].clauses.push_back({"Wipers", true, "NO"});

    rule_list[15].clauses.push_back({"Wipers", true, "YES"});
    rule_list[15].clauses.push_back({"WiperFluid", true, "NO"});

    rule_list[16].clauses.push_back({"Wipers", true, "NO"});
    rule_list[16].clauses.push_back({"WiperFluid", true, "YES"});

    rule_list[17].clauses.push_back({"BadWiperBlade", true, "YES"});
    rule_list[17].clauses.push_back({"Wipers", true, "YES"});

    rule_list[18].clauses.push_back({"System", true, "YES"});
    rule_list[18].clauses.push_back({"Sound", true, "NO"});

    rule_list[19].clauses.push_back({"CarNoise", true, "YES"});

    rule_list[20].clauses.push_back({"Transmission", true, "YES"});
    rule_list[20].clauses.push_back({"CarSmell", true, "YES"});

    rule_list[21].clauses.push_back({"Transmission", true, "YES"});
    rule_list[21].clauses.push_back({"CarSmell", true, "NO"});

    rule_list[22].clauses.push_back({"CarNoise", true, "NO"});
    rule_list[22].clauses.push_back({"WheelShaking", true, "YES"});

    rule_list[23].clauses.push_back({"Filter", true, "YES"});
    rule_list[23].clauses.push_back({"Accelerate", true, "YES"});

    rule_list[24].clauses.push_back({"Filter", true, "YES"});
    rule_list[24].clauses.push_back({"Accelerate", true, "NO"});

    rule_list[25].clauses.push_back({"CarNoise", true, "NO"});
    rule_list[25].clauses.push_back({"WheelShaking", true, "NO"});
    rule_list[25].clauses.push_back({"AirWarm", true, "YES"});

    rule_list[26].clauses.push_back({"CarNoise", true, "YES"});
    rule_list[26].clauses.push_back({"WheelShaking", true, "YES"});
    rule_list[26].clauses.push_back({"AirWarm", true, "NO"});
    rule_list[26].clauses.push_back({"HardTurn", true, "YES"});

    rule_list[27].clauses.push_back({"CarNoise", true, "NO"});
    rule_list[27].clauses.push_back({"WheelShaking", true, "NO"});
    rule_list[27].clauses.push_back({"AirWarm", true, "NO"});
    rule_list[27].clauses.push_back({"HardTurn", true, "NO"});
    rule_list[27].clauses.push_back({"CarTurnOff", true, "YES"});

    rule_list[28].clauses.push_back({"LowGasLight", true, "YES"});

    rule_list[29].clauses.push_back({"CarTurnOff", true, "YES"});
    rule_list[29].clauses.push_back({"LowGasLight", true, "NO"});

    for(int i = 0; i < 30; i++)
    {
        int counter = 0;
        for(int k = 0; k < rule_list[i].clauses.size(); k++)
       {
           clause_list[(i * 6) + counter].name = rule_list[i].clauses[k].name;
           counter++;
       }
    }
}

void BackwardChaining::update_clause(string var_name) //this updates the clause list after the variable list is also updated
{
        string val;
        for(int k = 0; k < varList.size(); k++)
        {
                if(varList[k].name.compare(var_name) == 0)
                        val = varList[k].value;
        }
        for(int i = 0; i < 180; i++)
        {
                if(clause_list[i].name.compare(var_name) == 0)
                {
                        clause_list[i].inst = true;
                        clause_list[i].value = val;
                }
        }
}




