#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int main() {
    double high[3];
    double middle[15];
    double low[5];
    double noob[2];
    double count = 0;
    int day = 0;
    double disp = 0;
    double midday = 0;
    srand(time(NULL));
    //for (int o = 0; o < 100; o++) {
        for (int i = 0;; i++) {
            if (count >= 100) {
                cout << "Всего выполнено: " << count << "%" << endl;
                day = i;
                break;
            }
            for (int y = 0; y < 3; y++){
                high[y] = (double)((0.2*pow(10,6) + rand()%(int)(0.5*pow(10,6)-0.2*pow(10,6)))/pow(10,6));
                disp = (double)((5.4*pow(10,6) + rand()%(int)(6.6*pow(10,6)-5.4*pow(10,6)))/pow(10,6));
                count += high[y]*disp;
            }
            for (int y = 0; y < 15; y++){
                middle[y] = (double)((0.1*pow(10,6) + rand()%(int)(0.3*pow(10,6)-0.1*pow(10,6)))/pow(10,6));
                disp = (double)((5.5*pow(10,6) + rand()%(int)(6.5*pow(10,6)-5.5*pow(10,6)))/pow(10,6));
                count += middle[y]*disp;
            }
            for (int y = 0; y < 5; y++){
                low[y] = (double)((0.05*pow(10,6) + rand()%(int)(0.2*pow(10,6)-0.05*pow(10,6)))/pow(10,6));
                disp = (double)((3.6*pow(10,6) + rand()%(int)(4.4*pow(10,6)-3.6*pow(10,6)))/pow(10,6));
                count += low[y]*disp;
                
            }
            for (int y = 0; y < 2; y++){
                noob[y] = (double)((0.01*pow(10,6) + rand()%(int)(0.02*pow(10,6)-0.01*pow(10,6)))/pow(10,6));
                disp = (double)((1.8*pow(10,6) + rand()%(int)(2.2*pow(10,6)-1.8*pow(10,6)))/pow(10,6));
                count += noob[y]*disp;
            }
            
            
        }
        cout << "Среднее значение: " << count/day << "%" << endl;
        cout << "За сколько дней выполнено: " << day << endl;
        if (day == 5) {
            cout << "УВОЛИТЬ!!!!!\n";
        }
        midday += day;
        count = 0;
        day = 0;
    //}
    midday /= 100; cout << "Среднее количество дней: " << midday << endl;
}

