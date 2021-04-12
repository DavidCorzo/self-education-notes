#include <iostream>
using namespace std;

class Player {
    private:
    std::string name;
    int health;
    int xp;
    public: 
    std::string get_name() {return name;}
    int get_health() {return health;}
    int get_xp() {return xp;}
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
    // Copy constructor:
    Player(const Player &source);
    // Destructor:
    ~Player() { cout << "Destrocutor called for: " << name << endl; }
};

Player::Player(std::string name_val, int health_val, int xp_val) : name{name_val}, health{health_val}, xp{xp_val} {
    cout << "Theree-args constructor for " + name << endl;
}

Player::Player(const Player &source) : name{source.name}, health{source.health}, xp{source.xp} {
    cout << "Copy constructor - made a copy of: " << source.name << endl;
}

void display_player(Player p) {
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "xp: " << p.get_xp() << endl;
}

int main() {
    Player empty;
    display_player(empty);
    Player copy_of_empty {empty};
    display_player(copy_of_empty);
    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 100, 55};
    return 0;
}
/* OUTPUT:
Theree-args constructor for None
Copy constructor - made a copy of: None
Name: None
Health: 0
xp: 0
Destrocutor called for: None
Copy constructor - made a copy of: None
Copy constructor - made a copy of: None
Name: None
Health: 0
xp: 0
Destrocutor called for: None
Theree-args constructor for Frank
Theree-args constructor for Hero
Theree-args constructor for Villain
Destrocutor called for: Villain
Destrocutor called for: Hero
Destrocutor called for: Frank
Destrocutor called for: None
Destrocutor called for: None
*/
