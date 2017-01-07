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

bool propagateObject::addRule(int startTime, int endTime, std::string propagateRule)
{
    std::cout << propagateRule << std::endl;
    
    eventVector->clear();
    timeObject iterateTime(0, eventStartTime);
    
    myRules.push_back(new propagateObjectRules(propagateRule));
    
    int testingTime;
    
    for(int i = 0; i < myRules.size(); ++i)
    {
        if(myRules.at(i)->repeatType == "y")
        {
            testingTime = iterateTime.getUnixTimestamp();
            
            while(testingTime < endTime)
            {
                eventVector->push_back(new timeObject(0, &iterateTime));
                testingTime = iterateTime.getUnixTimestamp();
                
                iterateTime.year++;
            }
            
            if(eventVector->size() > 0)
                eventVector->pop_back();
            
            iterateTime.setObject(eventStartTime);
            
            while(testingTime > startTime)
            {
                testingTime = iterateTime.getUnixTimestamp();
                iterateTime.year--;
                eventVector->push_back(new timeObject(0, &iterateTime)); //need to remove two, not sure how yet
            }
        }
    }
    
    //eventVector->push_back(new timeObject());
    //eventVector->at(eventVector->size()-1) = iterateTime;
    
    //eventVector->push_back(new timeObject(2140000001));
    return true;
}
