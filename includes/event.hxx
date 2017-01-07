#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>

#include <timeObject.hxx>
#include <repeatTime.hxx>

class Event {
    private:
    public:
        Event(std::string eventName, int _startTime, int _endTime, std::string eventDescription = "");
        
        std::string eventName;
        std::string eventDescription;
        int eventLength;
        int eventImportance;
        
        std::string eventCategory; //define event categories later
        std::string repeatRule;
        
        timeObject *startTime;
        propagateObject *propagateThis;
        
        std::vector<timeObject*> eventVector; //for repeating events
        
        bool propagateEvent(int startTime, int endTime, std::string repeatRule);
        
        void printEvents();
};


#endif
