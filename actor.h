#include <string>
#include <vector>
#include <functional>
#include <memory>
#include "./spdlog/spdlog.h"

/**
 * Eine Aktion ist steuert einen Aktor
 * z.B. turnOn, turnOff, reset oder getInfo
 */ 
class Action {
public:
    virtual std::string getName();
    virtual std::string getDescription();

    bool operator==(TAction const& rhs) { return this->_name == rhs._name; }
    bool operator!=(TAction const& rhs) { return this->_name != rhs._name; }

protected:
    std::string _name;
    std::string _description;

private:
    Action() {}
};


/**
 * Eine Aktion ist steuert einen Aktor
 * z.B. turnOn, turnOff, reset oder getInfo
 * 
 * template T: Typ der Variable, welche verschickt werden soll 
 * z.B. Integer, String, Binary
 */
template<class T> class TAction : public Action {
public:
    TAction(std::string name, std::string desc, T sendData);

    /**
     * Lampda-Funktion zum verschicken der einer Aktion
     * so kann ein Aktor mehrere Typen der Ansteuerung haben
     * z.B. über das Wlan, einer RestApi oder über eine Funkanbindung
     */ 
    std::function<void (T)> send;
    // [x](int n) {return n < x;}
    // function<int (int)> func = [](int i) {return i + 4};

protected:
    T _sendData;

private:
    TAction();


};

template<class T> class TIpAction : public TAction<T> {
public:
    TIPAction(std::string name, std::string desc, T sendData, std::string ipAddress, int port);
    std::string getIpAddress();
    int getPort();

protected:
    std::string _ipAddress;
    int _port;

private:
    TIpAction();
}
 

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

    Action std::string getName();
    getAction(std::string);
    void setAction(Action);
    void send(Action);
    void send(std::string);

protected:
    std::string _name;
    std::vector<Action> _actions;
    std::shared_ptr<spdlog::logger> _logger;

};
