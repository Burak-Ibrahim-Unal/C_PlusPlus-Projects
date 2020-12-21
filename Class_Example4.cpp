#include <iostream>
 
using namespace std;
class Covid {
   public:
      void setBirthYear( int y );
      int getBirthYear( void );

      Covid(int y);  // This is the constructor
      Covid();       // This is the constructor

   private:
      int birthYear;
};
 
// Member functions definitions including constructor



Covid::Covid( int y) {
   cout << "Covid is borth, birthYear = " << y << endl;
   birthYear = y;
}

void Covid::setBirthYear( int y ) {
   birthYear = y;
}
int Covid::getBirthYear( void ) {
   return birthYear;
}

// Main function for the program
int main() {
   Covid Covid(2019);

   // get initially set birthYear.
   cout << "birthYear of Covid : " << Covid.getBirthYear() <<endl;
   
   // set Covid birthYear again
   Covid.setBirthYear(2020); 
   cout << "birthYear of Covid : " << Covid.getBirthYear() <<endl;

   return 0;
}