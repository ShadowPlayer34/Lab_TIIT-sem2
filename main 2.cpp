#include <iostream>
#include <cmath>
#include "struct.h"
using namespace std;
int main() {
    srand(time(NULL));
    int count = 0;
    agent* OurAgents = 0;
    unsigned int agentAmount = 0;
    int infected = (double)((5*pow(10,6) + rand()%(int)(10*pow(10,6)-5*pow(10,6)))/pow(10,6));
    double temp = (double)((0*pow(10,6) + rand()%(int)(1*pow(10,6)-0*pow(10,6)))/pow(10,6));
    double temp1 = 0;
    for(int i = 0; i < 10; i++) {
        temp1+=(double)((0*pow(10,6) + rand()%(int)(1*pow(10,6)-0*pow(10,6)))/pow(10,6));
    }
    double effective = 20+3.5*pow(12/10, 1/2)*(temp1-(10/2));
    double middleage = 25+5.5*pow(12/10, 1/2)*(temp1-(10/2));
    double tests = -1.0/3.5* log(1-temp);
    for (int i = 0; i < infected; i++) {
        OurAgents = AddStruct(OurAgents, agentAmount);
        setData(OurAgents, agentAmount, middleage, temp, temp1);
        agentAmount++;
    }
    for (int i = 1; i <= 30; i++) {
        count = zaraz(OurAgents, agentAmount);
        for (int i = 0; i < count; i++) {
            OurAgents = AddStruct(OurAgents, agentAmount);
            setData(OurAgents, agentAmount, middleage, temp, temp1);
            agentAmount++;
            cout << agentAmount << endl;
            
        }
        cout << agentAmount << endl;
        cin >> count;
        count = 0;
    }
    virus first;
//    first.calc(middleage, temp, temp1, one.heal, effective, one.age);
//    one.calc(34, temp, temp1);
//    cout << agentAmount << endl;
    return 0;
}
