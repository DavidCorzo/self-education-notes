#include <iostream>
#include <vector>
#include <string.h>

#ifndef MYSTRING_H
    #define MYSTRING_H

class Mystring {
private:
    char *str;
public:
    Mystring(); // no args constructor.
    Mystring(const char *s); // overloaded constructor.
    Mystring(const Mystring &source); // copy constructor
    ~Mystring(); // destructor
    Mystring(Mystring &&source); // move constructor

    Mystring &operator=(const Mystring &rhs); // copy assignment.
    Mystring &operator=(Mystring &&rhs); // Move assignment.

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

// copy constructor.
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

// destructor.
Mystring::~Mystring() {
    delete[] str;
}

// move constructor
Mystring::Mystring(Mystring &&source) : str{source.str} {
    source.str = nullptr;
    std::cout << "Move contructor used" << std::endl;
}

// move assignment.
Mystring &Mystring::operator=(Mystring &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// print the string.
void Mystring::display() const {
    std::cout << str << ": " << get_length() << std::endl;
}

// string length.
int Mystring::get_length() const { return strlen(str); }

// string getter.
const char *Mystring::get_str() const { return str; }

// copy assignment operator overloading.
Mystring &Mystring::operator=(const Mystring &rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}



#endif
