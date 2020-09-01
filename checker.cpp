#include <iostream>
#include <cassert>

using namespace std;

class Alert
{
    public:
    virtual void raiseAlert(const char* vitalName, const char* level) = 0;
};

class AlertWithSms: public Alert
{
    public:
    virtual void raiseAlert(const char* vitalName, const char* level){
        cout << "SMS: The " << vitalName << " is very " << level << endl;
    }
};

class AlertWithSound: public Alert
{
    public:
    virtual void raiseAlert(const char* vitalName, const char* level){
        cout << "Sound: The " << vitalName << " is very " << level << endl;
    }
};

class Vital{
    private:
    int lowLimit, highLimit;
    char* vitalName;
    Alert* alertSystem;
    public:
    Vital(){}
    Vital(int x, int y, char* z, Alert* alerter): lowLimit(x), highLimit(y), vitalName(z), alertSystem(alerter) {}
    void isInRange(int val){
        if(val < lowLimit){
            alertSystem->raiseAlert(vitalName, "Low");
        }
        if(val> highLimit){
            alertSystem->raiseAlert(vitalName, "High");
        }
    }
};



class VitalsChecker{
private:
    Alert* alertSystem;
    Vital vitals[3];
public:
    VitalsChecker(Alert* alerter):alertSystem(alerter)
    {
        vitals[0] = Vital(70, 150, "Pulse checker", alertSystem);
        vitals[1] = Vital(90, 100, "spo2", alertSystem);
        vitals[2] = Vital(30, 95, "respRate", alertSystem);
    }
    void checkVitals(float* vals){
        for (int i=0; i<3; i++){
            vitals[i].isInRange(vals[i]);
        }
    }
};

int main(){
    float vals[3] = {30,40,50};
    AlertWithSms alertSystem;
    VitalsChecker vitals(&alertSystem);

    vitals.checkVitals(vals);
    return 0;
}