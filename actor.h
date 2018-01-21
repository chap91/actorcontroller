#include <string>
#include <vector>
#include <functional>
#include <shared_ptr>
#include "./spdlog/spdlog.h"


// [x](int n) {return n < x;}
// function<int (int)> func = [](int i) {return i + 4};

/**
 * Eine Aktion ist steuert einen Aktor
 * z.B. turnOn, turnOff, reset oder getInfo
 * 
 * template T: Typ der Variable, welche verschickt werden soll 
 * z.B. Integer, String, Binary
 */
template<class T> class Action {
public:
    /**
     * Lampda-Funktion zum verschicken der einer Aktion
     * so kann ein Aktor mehrere Typen der Ansteuerung haben
     * z.B. über das Wlan, einer RestApi oder über eine Funkanbindung
     */ 
    std::function<void (T)> send;

private:
    std::string _name;
    std::T _sendData;
    spdlog::basic_logger_mt("basic_logger", "logs/log.txt") _logger;
};


/**
 * Ein Aktor ist eine Steuereinheit
 * z.B. eine Funk- oder Wlan-Steckdose 
 * 
 * Ein Aktor verfügt über mehrere Aktionen welche den Aktor steuern
 */
class Actor {
public:
    Actor();
    ~Actor();

    std::string getName();
    Action getAction(std::string);
    void setAction(Action);
    void send(Action);

private:
    std::string _name;
    std::vector<Action*> _actions;
    std::shared_ptr<logger> _logger;
};
