using namespace std;
struct agent{
public:
    string status = "Болен, но не знает";
    int social_contact ;
    double otvet;
    double heal;
    int zaraznot;
    int age;
        void calc(double middleage, double temp, double temp1, int middle){
            social_contact = (double)(((middle-3)*pow(10,6) + rand()%(int)((middle+3)*pow(10,6)-(middle-3)*pow(10,6)))/pow(10,6));;
            otvet = -1.0/0.5* log(1-temp);
            heal = 8+1.5*pow(12/10, 1/2)*(temp1-(10/2));
            age = middleage+10*pow(12/10, 1/2)*(temp1-(10/2));
            zaraznot = (double)((0*pow(10,6) + rand()%(int)(60*pow(10,6)-0*pow(10,6)))/pow(10,6));
        }
    
};
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
agent* AddStruct(agent* Obj, const int amount)
{
    if (amount == 0)
    {
        Obj = new agent[amount + 1]; // выделение памяти для первой структуры
    }
    else
    {
        agent* tempObj = new agent[amount + 1];

        for (int i = 0; i < amount; i++)
        {
            tempObj[i] = Obj[i]; // копируем во временный объект
        }
        delete [] Obj;

        Obj = tempObj;
    }
    return Obj;
}
//------------------------------------------------------------------
void setData(agent* Obj, const int amount, double middleage, double temp, double temp1)
{
    int middle = (double)((0*pow(10,6) + rand()%(int)(50*pow(10,6)-0*pow(10,6)))/pow(10,6));
    double temp3 = (double)((0*pow(10,6) + rand()%(int)(1*pow(10,6)-0*pow(10,6)))/pow(10,6));
    double temp2 = 0;
    for(int i = 0; i < 10; i++) {
        temp2+=(double)((0*pow(10,6) + rand()%(int)(1*pow(10,6)-0*pow(10,6)))/pow(10,6));
    }
        Obj[amount].calc(middleage, temp3, temp2, middle);
    
}
//------------------------------------------------------------------
void showData(const agent* Obj, const int amount)
{
    for (int i = 0; i < amount; i++)
    {
        cout << Obj[i].zaraznot << endl;
    }
}
//------------------------------------------------------------------
double zaraz(const agent* Obj, const int amount){
    double infected = 0;
    int temp = 0;
    for (int i = 0; i < amount; i++) {
        for(int y = 0; y < Obj[i].social_contact; y++){
        temp = (double)((0*pow(10,6) + rand()%(int)(100*pow(10,6)-0*pow(10,6)))/pow(10,6));
        if(temp <= Obj[i].zaraznot){
            infected++;
        }
        }
        }
    return infected;
}
