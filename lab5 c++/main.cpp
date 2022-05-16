#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <fstream>
#include "struct.h"
using namespace std;
int main() {
    OurAgents.reserve(10000000);
    srand(time(NULL));
    int count_of_infected = 0;
    int count_of_recovered = 0;
    int count_of_hospital = 0;
    int amount_of_tests = 0;
    int genozid1 = 15;
    ofstream file ("/Users/andrejhudik/Documents/Xcode/TIIT lab5/TIIT lab5/virus.txt");
    unsigned int infected = (double)((5*pow(10,6) + rand()%(int)(10*pow(10,6)-5*pow(10,6)))/pow(10,6));
    double temp = (double)((0*pow(10,6) + rand()%(int)(1*pow(10,6)-0*pow(10,6)))/pow(10,6));
    double temp1 = 0;
    for(int i = 0; i < 10; i++) {
        temp1+=(double)((0*pow(10,6) + rand()%(int)(1*pow(10,6)-0*pow(10,6)))/pow(10,6));
    }
    int middleage = 25+5.5*pow(12/10, 1/2)*(temp1-(10/2));
    double tests = -1.0/3.5* log(1-temp);
        for (int i = 0; i < infected; i++) {
            OurAgents.push_back(agent());
            setData(OurAgents, agentAmount, middleage);
            agentAmount++;
        }
         cout << 0 << ": " << agentAmount << endl;
    ofstream file1 ("/Users/andrejhudik/Documents/Xcode/TIIT lab5/TIIT lab5/virus.txt", ios_base::app);
    if (file1) {
        file << 0 << endl;
        file <<  agentAmount << endl;
        file << count_of_death2 << endl;
        file << count_of_recovered << endl;
        file << count_of_infected << endl;
        file <<  count_of_death << endl;
        file << 0 << endl;
    }


        
//------------------------------------------------------------------
        for (int i = 1; i <= 6; i++) {
            cout << i << ": " << /*agentAmount <<*/ endl;
            count_of_recovered = redata(OurAgents, agentAmount);
//            int rnd = rand()%100;         //for genozid
            for (int j = 0; j < infected; ++j) {
                int for_test = 0;
                double for_hospital = 0;
                for_test = rand() % 100;
                for_hospital = (double)((0*pow(10,6) + rand()%(int)(1*pow(10,6)-0*pow(10,6)))/pow(10,6));
                if (for_hospital <= OurAgents[j].chance_of_emergency){
                    OurAgents[j].social_contact = 0;
                    count_of_hospital++;
                    OurAgents[j].status = "В больнице";
                }
                if (for_test <= tests){
                    amount_of_tests++;
                    OurAgents[j].social_contact /= OurAgents[j].otvet;
                    OurAgents[j].on_heal = 1;
                    OurAgents[j].effective = 20+3.5*pow(12/10, 1/2)*(temp1-(10/2));
                    OurAgents[j].status = "Болен и знает";
                }
            }
            count_of_infected = zaraz(OurAgents, agentAmount);
            for (int p = 0; p < count_of_infected; p++) {
                OurAgents.push_back(agent());
                setData(OurAgents, agentAmount, middleage);
                agentAmount++;
            }
            cout << "\t" << "test: " << amount_of_tests << endl;
            cout << "\t" << "recovered: " << count_of_recovered << endl;
            cout << "\t" << "in hospital: " << count_of_hospital << endl;
            OurAgents = dead(OurAgents, agentAmount);
            cout << "\t" << "Life: " << agentAmount << endl;
            ofstream file ("/Users/andrejhudik/Documents/Xcode/TIIT lab5/TIIT lab5/virus.txt", ios_base::app);
           
            if (file) {
                file << i << endl;
                file <<  agentAmount << endl;
                file << count_of_death2 << endl;
                file << count_of_recovered << endl;
                file << count_of_infected << endl;
                file <<  count_of_death << endl;
                file << 0 << endl;
                
            }
            
            file.close();
            count_of_infected = 0;
            count_of_death = 0;
        }
    return 0;
}















//            OurAgents = dead(OurAgents, agentAmount);



//            if (rnd <= genozid1) {
//                if (cou != 1) {
//                    OurAgents = genozid(OurAgents, agentAmount);
//                    cout << "ЭТО ГЕНОЦИД!!!!" << endl << "Выжило только два счастливчика" << endl;
//                    cou = 1;
//                    for (int i = 0; i < 2; i++) {
//                        OurAgents = AddStruct(OurAgents, agentAmount);
//                        setData(OurAgents, agentAmount, middleage, temp, temp1, effective);
//                        agentAmount++;
//                    }
//                }
//            }
//            cout << "\t" << "Life: " << agentAmount << endl;









//    virus first;
//    first.calc(middleage, temp, temp1, one.heal, effective, one.age);
//    one.calc(34, temp, temp1);
//    cout << agentAmount << endl;
//    int social_contact = 0;
//    int zaraznot = 0;
//    int age[80000];
//    unsigned int infected = 0;
//    int time = 0;
//    int time_infected = 0;
//    int middle;
//    double heal[80000];
//    double temp1 = 0;
//    int dead = 0;
//    for(int i = 0; i < 10; i++) {
//        temp1+=(double)((0*pow(10,6) + rand()%(int)(1*pow(10,6)-0*pow(10,6)))/pow(10,6));
//    }
//    int middleage = 25+5.5*pow(12/10, 1/2)*(temp1-(10/2));
//    int effective = 0;
//    infected = (double)((5*pow(10,6) + rand()%(int)(10*pow(10,6)-5*pow(10,6)))/pow(10,6));
//    for (int i = 1; i <= 30; i++) {
//        for (int o = 0; o < infected; ++o) {
//            heal[o] = 8+1.5*pow(12/10, 1/2)*(temp1-(10/2));
//            age[o] = middleage+10*pow(12/10, 1/2)*(temp1-(10/2));
//        }
//        middle = (double)((0*pow(10,6) + rand()%(int)(50*pow(10,6)-0*pow(10,6)))/pow(10,6));
//        for (int y = 0; y < infected; y++){
//
//            social_contact = (double)(((middle-3)*pow(10,6) + rand()%(int)((middle+3)*pow(10,6)-(middle-3)*pow(10,6)))/pow(10,6));
//            effective = 20+3.5*pow(12/10, 1/2)*(temp1-(10/2));
//            for (int e = 0; e < social_contact; e++) {
//                zaraznot = (double)((0*pow(10,6) + rand()%(int)(60*pow(10,6)-0*pow(10,6)))/pow(10,6));
//                time = (double)((0*pow(10,6) + rand()%(int)(100*pow(10,6)-0*pow(10,6)))/pow(10,6));
//                if(time <= zaraznot){
//                    time_infected++;
//                }
//            }
//        }
//        for (int j = 0; j < infected; ++j) {
//            int proccent;
//            dead = (age[j]*0.07+((15-1.0*heal[j]-0.8*effective)+(2-0.15*heal[j]-0.12*effective)*pow(12/10, 1/2)*(temp1-(10/2))))*(-1);
//            proccent = rand()%100;
//            if (proccent <= dead){
//                infected--;
//            }
//        }
//        infected += time_infected;
//        time_infected = 0;
//        temp1 = 0;
//        cout << i << ": " << infected << endl;
//    }


