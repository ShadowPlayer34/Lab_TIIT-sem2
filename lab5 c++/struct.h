using namespace std;
int agentAmount = 0;
int count_of_death = 0;
int countofdetg = 0;
int count_of_death2 = 0;
struct agent{
public:
    string status = "Болен, но не знает";
    int social_contact;
    int daysofheal;
    bool on_heal = 0;
    double effective = 0;
    double otvet;
    double heal;
    int zaraznot;
    int age;
    int dead;
    double chance_of_emergency;
    int day = 0;
    int middle;
    void calc(int middleage, double temp, double temp1){
        middle = (double)((0*pow(10,6) + rand()%(int)(50*pow(10,6)-0*pow(10,6)))/pow(10,6));
        if (middle >= 3){
            social_contact = (double)(((middle-3)*pow(10,6) + rand()%(int)((middle+3)*pow(10,6)-(middle-3)*pow(10,6)))/pow(10,6));
        }else social_contact = (double)(((0)*pow(10,6) + rand()%(int)((middle+3)*pow(10,6)-(0)*pow(10,6)))/pow(10,6));
        otvet = -1.0/0.5* log(1-temp);
        daysofheal = 1+(double)((((20-1.5*heal-0.5*effective)-(5-0.25*heal-0.1*effective))*pow(10,6) + rand()%(int)(((20-1.5*heal-0.5*effective)+(5-0.25*heal-0.1*effective))*pow(10,6)-((20-1.5*heal-0.5*effective)-(5-0.25*heal-0.1*effective))*pow(10,6)))/pow(10,6));
        heal = 8+1.5*pow(12/10, 1/2)*(temp1-(10/2));
        if (heal < 2){
            chance_of_emergency = 0.1;
        }else chance_of_emergency = 0.01;
        age = middleage+10*pow(12/10, 1/2)*(temp1-(10/2));
        //zaraznot = (double)((0*pow(10,6) + rand()%(int)(60*pow(10,6)-0*pow(10,6)))/pow(10,6));
        dead = (age*0.07+((15-1.0*heal-0.8*effective)+(2-0.15*heal-0.12*effective)*pow(12/10, 1/2)*(temp1-(10/2))));
    }
    void resocial(){
        social_contact = (double)(((middle-3)*pow(10,6) + rand()%(int)((middle+3)*pow(10,6)-(middle-3)*pow(10,6)))/pow(10,6));
        day++;
    }
};
vector<agent> OurAgents;
//------------------------------------------------------------------
struct virus{
    int daysofheal;
    int dead;
    double zaraznot = (double)((0*pow(10,6) + rand()%(int)(60*pow(10,6)-0*pow(10,6)))/pow(10,6));
    void calc(double middleage, double temp, double temp1, double heal,double effective, int age){
        daysofheal =1+ (double)((((20-1.5*heal-0.5*effective)-(5-0.25*heal-0.1*effective))*pow(10,6) + rand()%(int)(((20-1.5*heal-0.5*effective)+(5-0.25*heal-0.1*effective))*pow(10,6)-((20-1.5*heal-0.5*effective)-(5-0.25*heal-0.1*effective))*pow(10,6)))/pow(10,6));
        dead = age*0.07+((15-1.0*heal-0.8*effective)+(2-0.15*heal-0.12*effective)*pow(12/10, 1/2)*(temp1-(10/2)));
    }
};
//------------------------------------------------------------------
void clear(int i){
    OurAgents.erase(OurAgents.begin() + i);
    ::agentAmount--;
};
//------------------------------------------------------------------
void setData(vector<agent> Obj, const int amount, int middleage)
{
    double temp3 = (double)((0*pow(10,6) + rand()%(int)(1*pow(10,6)-0*pow(10,6)))/pow(10,6));
    double temp2 = 0;
    for(int i = 0; i < 10; i++) {
        temp2+=(double)((0*pow(10,6) + rand()%(int)(1*pow(10,6)-0*pow(10,6)))/pow(10,6));
    }
    OurAgents[amount].calc(middleage, temp3, temp2);
    int kju;
}
//------------------------------------------------------------------
void showData(vector<agent> Obj, const int amount)
{
    for (int i = 0; i < amount; i++)
    {
        cout << OurAgents[i].zaraznot << endl;
    }
}
//------------------------------------------------------------------
double zaraz(vector<agent> Obj, const int amount){
    double infected = 0;
    int temp = 0;
    int zaraznot = 0;
    for (int i = 0; i < amount; i++) {
        for(int y = 0; y < OurAgents[i].social_contact; y++){
            zaraznot = (int)((0*pow(10,6) + rand()%(int)(20*pow(10,6)-0*pow(10,6)))/pow(10,6));
            temp = rand()%100;
            if(temp <= zaraznot){
                infected++;
            }
        }
    }
    temp = 0;
    cout << "\t" << "new infected: " << infected << endl;
    return infected;
}
//------------------------------------------------------------------
vector<agent> dead(vector<agent> Obj, const int amount){
    double temp = 0;
    for (int i = 0; i < amount; ++i) {
        temp = (double)((0*pow(10,6) + rand()%(int)(100*pow(10,6)-0*pow(10,6)))/pow(10,6));
        if (temp <= OurAgents[i].dead){
            OurAgents.erase(OurAgents.begin() + i);
            ::agentAmount--;
            count_of_death++;
        }
    }
    cout << "\t" << "dead: " << count_of_death << endl;
    count_of_death2 += count_of_death;
    temp = 0;
    return Obj;
}
//------------------------------------------------------------------
//agent* genozid(agent* Obj, const int amount){
//    delete [] Obj;
//    ::agentAmount = 0;
//}
//------------------------------------------------------------------
int redata(vector<agent> Obj, const int amount){
    int count = 0;
    for (int i = 0; i < amount; i++) {
        OurAgents[i].resocial();
        if (OurAgents[i].day == OurAgents[i].daysofheal) {
            OurAgents.erase(OurAgents.begin() + i);
            ::agentAmount--;
            count++;
        }
    }
    return count;
}










