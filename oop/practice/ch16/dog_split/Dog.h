#include<string>
using namespace std;

class Dog{
    public:
        Dog(string);
        void bark();
        void introduce();
        void setdogname(string);
        string getdogname();
    private:
        string name;
};