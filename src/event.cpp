#include <iostream>

#include <string>
#include <event.hxx>
#include <timeObject.hxx>
#include <repeatTime.hxx>

Event::Event(std::string eventName, int _startTime, int _endTime, std::string eventDescription):
    eventDescription(eventDescription)
{
    eventLength = _endTime - _startTime;
    startTime = new timeObject(_startTime);
    propagateThis = new propagateObject(startTime, &eventVector);
}

bool Event::propagateEvent(int startTime, int endTime, std::string repeatRule)
{
    propagateThis->addRule(startTime, endTime, repeatRule);
}

void Event::printEvents()
{
    for(int x = 0; x < eventVector.size(); ++x)
        std::cout << eventVector.at(x)->getDate() << std::endl;
}
