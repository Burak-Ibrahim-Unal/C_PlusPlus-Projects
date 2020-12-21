#include <iostream>
 
using namespace std;
 
class Car {
   public:
      void setYear( int y );
      int getYear( void );
      Car();  // This is the constructor
   private:
      int year;
};
 
// Member functions definitions including constructor
Car::Car(void) {
   cout << "Car object is being created" << endl;
}
void Car::setYear( int y ) {
   year = y;
}
int Car::getYear( void ) {
   return year;
}

// Main function for the program
int main() {
   Car Car;
 
   // set Car year
   Car.setYear(2020); 
   cout << "year of Car : " << Car.getYear() <<endl;
 
   return 0;
}