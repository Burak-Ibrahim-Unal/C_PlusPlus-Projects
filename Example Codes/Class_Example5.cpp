#include <iostream>

using namespace std;

class Covid
{

public:
     int getYear(void);
     Covid(int year);         // simple constructor
     Covid(const Covid &obj); // copy constructor
     ~Covid();                // destructor

private:
     int *p;
};

// Member functions definitions including constructor
Covid::Covid(int year)
{
     cout << "Normal constructor allocating p" << endl;

     // allocate memory for the pointer;
     p = new int;
     *p = year;
}

Covid::Covid(const Covid &obj)
{
     cout << "Copy constructor allocating p." << endl;
     p = new int;
     *p = *obj.p; // copy the value
}

Covid::~Covid(void)
{
     cout << "Freeing memory!" << endl;
     delete p;
}

int Covid::getYear(void)
{
     return *p;
}

void display(Covid obj)
{
     cout << "year of Covid : " << obj.getYear() << endl;
}

// Main function for the program
int main()
{
     Covid covid(2020);
     Covid covid2 = covid;

     display(covid);
     display(covid2); //copy constructor

     return 0;
}
