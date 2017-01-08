#include <iostream>
#include <vector>
#include <string>
#include <timeObject.hxx>
#include <repeatTime.hxx>

propagateObject::propagateObject(timeObject *startTime, std::vector<timeObject*> *eventVector) :
    eventVector(eventVector),
    eventStartTime(startTime)
{
    //std::cout << "Object propagation complete\n";
}

void getTimeObject(timeObject &iterateTime, std::string repeatType, bool direction)
{
    if(repeatType == "y")
    {
        if(direction == 0)
            iterateTime.year++;
        else
            iterateTime.year--;
    }
    else if(repeatType == "m")
    {
        if(direction == 0)
            iterateTime.addMonth(1);
        else
            iterateTime.addMonth(-1);
    }
    else if(repeatType == "d")
    {
        if(direction == 0)
            iterateTime.addDay(1);
        else
            iterateTime.addDay(-1);
    }
}

bool propagateObject::addRule(int startTime, int endTime, std::string propagateRule)
{
    std::cout << propagateRule << std::endl;
    
    for(int i = 0; i < eventVector->size(); ++i)
        delete eventVector->at(i);
    
    eventVector->clear();
    
    timeObject iterateTime(eventStartTime->getUnixTimestamp());
    
    myRules.push_back(new propagateObjectRules(propagateRule));
    
    int testingTime;
    int tempCounter = 0;
    
    for(int i = 0; i < myRules.size(); ++i)
    {
        testingTime = iterateTime.getUnixTimestamp();
        
        //count up
        while(testingTime < endTime)
        {
            testingTime = iterateTime.getUnixTimestamp();
            eventVector->push_back(new timeObject(testingTime));
            getTimeObject(iterateTime, myRules.at(i)->repeatType, 0);
        }
        
        //remove first date
        if(eventVector->size() > 0)
        {
            delete eventVector->at(0);
            eventVector->erase(eventVector->begin());
        }
        
        //remove extra date at end
        if(eventVector->size() > 0)
        {
            delete eventVector->at(eventVector->size()-1);
            eventVector->pop_back();
        }
        
        tempCounter = eventVector->size();
        iterateTime.setObject(eventStartTime);
        
        //count down
        while(testingTime > startTime)
        {
            testingTime = iterateTime.getUnixTimestamp();
            eventVector->push_back(new timeObject(testingTime));
            getTimeObject(iterateTime, myRules.at(i)->repeatType, 1);
        }
        
        //remove extra date at beginning
        if(eventVector->size() > tempCounter)
        {
            delete eventVector->at(eventVector->size()-1);
            eventVector->pop_back();
        }
    }
    
    //eventVector->push_back(new timeObject());
    //eventVector->at(eventVector->size()-1) = iterateTime;
    
    //eventVector->push_back(new timeObject(2140000001));
    return true;
}
