#include "./console.h"
using namespace std;

class Car
{
private:
    string name = "Lamborghini";
    string model = "911";

public:
    string getCarName()
    {
        return name;
    }
};

int main()
{
    string newCarArr[2] = {"Toyota", "Cross"};

    Car newCarObj;

    console.output(newCarObj.getCarName(), true);
    console.output(newCarArr[0], true);
    return 0;
}