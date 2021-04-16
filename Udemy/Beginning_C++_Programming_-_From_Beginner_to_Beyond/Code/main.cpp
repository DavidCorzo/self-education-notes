class Player {
    private:
     ...
    public: 
     ...
     std::string get_name() const;
};
const Player villain {"Villain", 100, 55}; 
villain.set_name("Nice guy"); // Not allowed.
std::cout << villain.get_name() << std::endl; // OK
