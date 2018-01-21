#include "actor.h"

Actor::Actor(){    
    _logger = spdlogger::basic_logger_st("ActorLogging", "./log/actor.log");
}

Actor::~Actor(){
    for(auto element : _actions) {
        delete element;
    }
    delete logger;
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

std::string Actor::getName(){
    return this->_name;
}

void Actor::send(Action action) const;{
       
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