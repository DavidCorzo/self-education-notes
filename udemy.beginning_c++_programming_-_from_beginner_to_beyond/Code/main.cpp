#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Mystring {
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-(const Mystring &obj);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
private:
    char *str;
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    ~Mystring();

    // copy assignment (overloaded).
    Mystring &operator=(const Mystring &rhs);
    // move assignment (overloaded).
    Mystring & operator=(Mystring &&rhs);

    void display() const;
    int get_length() const;
    const char *get_str() const;
};
// no args constructor.
Mystring::Mystring() : str(nullptr) {
    // Make an empty string
    str = new char[1];
    *str = '\0';
}
// overloaded constructor.
Mystring::Mystring(const char *s) : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}
// copy constructor
Mystring::Mystring(const Mystring &source) 
       : str{nullptr} {
    str = new char[strlen(source.str)+ 1];
    strcpy(str, source.str);
    std::cout << "Copy constructor used" << std::endl;
}
// destructor.
Mystring::~Mystring() {
    delete[] str;
}

// print the string.
void Mystring::display() const {
    std::cout << str << ": " << get_length() << std::endl;
}

// string length.
int Mystring::get_length() const { return std::strlen(str); }

// string getter.
const char *Mystring::get_str() const { return str; }
// copy assignment operator overloading.
Mystring &Mystring::operator=(const Mystring &rhs) {
    // std::cout << "Copy assignment" << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete[] this->str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(this->str, rhs.str);
    return *this;
}
// move assignment operator.
Mystring &Mystring::operator=(Mystring &&rhs) {
    if (this == &rhs) { // self assignment.
        return *this;   // return current object.
    }
    delete[] str; // deallocate current storage.
    str = rhs.str; // steal the pointer
    rhs.str = nullptr; // null out the rhs object.
    return *this; 
}
// Equality non-member function
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}
// Make lowercase non-member function
Mystring operator-(const Mystring &obj) {
    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (size_t i {0}; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete[] buff;
    return temp;
}
// Concatenation non-member function
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete[] buff;
    return buff;
}

int main() {
    cout << std::boolalpha << endl;
    Mystring larry{"Larry"};
    larry.display();

    larry = -larry;
    larry.display();

    Mystring moe{"Moe"};
    
    Mystring stooge = larry;

    std::cout << (larry == moe) << std::endl;
    std::cout << (larry == stooge) << std::endl;

    Mystring stooges = "Larry" + moe;
    stooges.display();

    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();

    return 0;
}

/* OUTPUT:
Larry: 5
larry: 5
Copy constructor used
false
true
*/
