#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car
{
protected:
    double price;
    int year;
public:
    Car(){}
    Car(double price, int year)
        :price{price}, year{year}
    {}

    string toString(){}

    virtual double calculateSalePrice(){};
};

class SportCar: public Car
{
public:
    double calculateSalePrice(){}
};

class ClassicCar: public Car
{
    double calculateSalePrice(){}
};

class CarExhibition
{
private:
    vector <Car> car_list;
public:
    void addCar(){}
    void addSportCar(){}
    int getTotalPrice(){}
};

int main(){
    Car c1(500, 1970);
    Car c2(300, 2001);
	return 0;
}
