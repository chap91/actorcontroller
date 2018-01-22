#include "actor.h"


std::string Action::getName(){
    return _name;
}

std::string Action::getDescription(){
    return _description;
}

Actor::Actor() {    
    _logger = spdlog::basic_logger_st("ActorLogging", "./log/actor.log");

    #ifdef NDEBUG
        spdlog::set_level(spd::level::info); //Set global log level to info
    #else
        spdlog::set_level(spd::level::debug); //Set global log level to debug
    #endif
}

Actor::~Actor() {
    for(auto element : _actions) {
        delete element;
    }
    delete _logger;
}

Action Actor::getAction(std::string name) {
    Action result = null;
    if(std::find(_actions.begin(), _actions.end(), name) != _actions.end()) {
        result = 
    } 
    
    return null;
}

void Actor::setAction(Action action) {
    _actions.put(action);
}

std::string Actor::getName() {
    return this->_name;
}

void Actor::send(Action action) {
       
    try {
        
        if (action.send != nullptr){
            action.send(action._sendData);
            _logger->info("action complete");
        
        } else {
            throw std::exception(this->_name + "the action:\"" + action._name + "\"action got no sendFunction");
        }

    } catch (std::exception& e) {
        _logger->error(e.what());
    }
}