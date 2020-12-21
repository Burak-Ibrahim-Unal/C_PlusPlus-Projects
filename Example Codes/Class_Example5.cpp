#include <iostream>

using namespace std;
class Covid
{
public:
     void setBirthYear(int y);
     int getBirthYear(void);

     Covid(); // This is the constructor
     ~Covid();

private:
     int birthYear;
};

// Member functions definitions including constructor

Covid::Covid()
{
     cout << "Object created" << endl;
}

Covid::~Covid()
{
     cout << "Object deleted" << endl;
}

void Covid::setBirthYear(int y)
{
     birthYear = y;
}
int Covid::getBirthYear(void)
{
     return birthYear;
}

// Main function for the program
int main()
{
     Covid Covid;
     // set Covid birthYear again
     Covid.setBirthYear(2020);
     cout << "birthYear of Covid : " << Covid.getBirthYear() << endl;

     return 0;
}