#include <iostream>
#include <string>
using namespace std;
class Vehicle {
protected:
  string brand;
  string model;
  int year;

public:
  // Constructor to initialize base class members
  Vehicle(const string& brand, const string& model, int year)
      : brand(brand), model(model), year(year) {}

  // Function to display base class details
  virtual void displayDetails() {
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
  }
};

class Car : public Vehicle {
private:
  int numDoors;
  double engineCapacity; // In liters

public:
  // Constructor to initialize car specific members and call base class constructor
  Car(const string& brand, const string& model, int year, int numDoors, double engineCapacity)
      : Vehicle(brand, model, year), numDoors(numDoors), engineCapacity(engineCapacity) {}

  // Override displayDetails to include car specific information
  void displayDetails() override {
    Vehicle::displayDetails(); // Call base class displayDetails
    cout << "Number of Doors: " << numDoors << endl;
    cout << "Engine Capacity: " << engineCapacity << " liters" << endl;
  }
};

int main() {
  // Create a Car object
  Car myCar("Toyota", "Camry", 2023, 4, 2.5);

  // Display car details
  myCar.displayDetails();

  return 0;
}
