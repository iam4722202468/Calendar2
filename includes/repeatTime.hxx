#ifndef REPEATTIME_H
#define REPEATTIME_H

#include <vector>
#include <timeObject.hxx>
#include <stringStuff.hxx>

class propagateObjectRules
{
    public:
        std::string repeatType;
        std::vector<std::string> secondary;
        
        propagateObjectRules(std::string toParse)
        {
            bool foundBeginning = false;
            std::string tempString = "";
            
            for(int x = 0; x < toParse.length(); x++)
                if(toParse[x] == ',')
                {
                    if(foundBeginning)
                        secondary.push_back(tempString);
                    else
                    {
                        repeatType = tempString;
                        foundBeginning = true;
                    }
                    tempString = "";
                }
                else
                    tempString += toParse[x];
                
            if(!foundBeginning)
                repeatType = tempString;
            else
                secondary.push_back(tempString);
        }
};

class propagateObject
{
    private:
        timeObject *eventStartTime;
        std::vector<timeObject*> *eventVector;
        std::vector<propagateObjectRules*> myRules;
    public:
        propagateObject(timeObject *startTime, std::vector<timeObject*> *eventVector);
        bool addRule(int startTime, int endTime, std::string propagateRule);
        int getUnixTimestamp() {return eventStartTime->getUnixTimestamp();};
};

#endif
