#include <iostream>
#include <cassert>
#include <vector>

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
    vector<Vital> vitals;
public:
    VitalsChecker(Alert* alerter):alertSystem(alerter)
    {
        vitals.push_back(Vital(70, 150, "Pulse checker", alertSystem));
        vitals.push_back(Vital(90, 100, "spo2", alertSystem));
        vitals.push_back(Vital(30, 95, "respRate", alertSystem));
    }
    void checkVitals(vector<float> vals){
        for (int i=0; i<vals.size(); i++){
            vitals[i].isInRange(vals[i]);
        }
    }
};

int main(){
    vector<float> v{30,40,50};
    Alert* alertSystem = new AlertWithSms;
    VitalsChecker vitals(alertSystem);

    vitals.checkVitals(v);
    return 0;
}