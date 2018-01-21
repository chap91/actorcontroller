#include <string.h>
#include <iostream>
#include <vector>
#include <functional>

template<class T>
class Action {
public:
    std::function<std::bool (T)> send;
    
private:
    std::string _name;
    std::T _sendData;
};

// [x](int n) {return n < x;}
// function<int (int)> func = [](int i) {return i + 4};

class Actor {
public:
    Action getAction(std::string);
    void setAction(Action);

private:
    std::string _name;
    std::vector<Action> _actions;
};

