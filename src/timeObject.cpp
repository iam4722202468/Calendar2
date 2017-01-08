#include <iostream> //for debugging
#include <ctime>
#include <string>

#include <timeObject.hxx>
#include <stringStuff.hxx>
/*
    int day;
    int month;
    int year;
    int second;
    int minute;
    int hour;
*/

bool timeObject::setObject(timeObject *toCopy)
{
    day = toCopy->day;
    dayIndex = toCopy->dayIndex;
    month = toCopy->month;
    year = toCopy->year;
    
    second = toCopy->second;
    minute = toCopy->minute;
    hour = toCopy->hour;
    return true;
}

timeObject::timeObject(int toParse)
{
    time_t timeStampTime = toParse;
    std::string timeString = ctime(&timeStampTime);
        
    std::string sections[5];
    std::string sections2[3];
    
    splitString(sections, timeString, ' ');
    splitString(sections2, sections[3], ':');
    
    day = stoi(sections[2]);
    dayIndex = findInArray(dayNamesShort, sections[0], 7);
    month = findInArray(monthNamesShort, sections[1], 12);
    year = stoi(sections[4]);
    
    second = stoi(sections2[2]);
    minute = stoi(sections2[1]);
    hour = stoi(sections2[0]);
}

int timeObject::getUnixTimestamp()
{
    //build timestamp
    std::string tempTimestamp = std::to_string(month+1) + "/" + std::to_string(day) + "/" + std::to_string(year);
    tempTimestamp += " " + std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
    
    struct tm tm = {0};;
    strptime(tempTimestamp.c_str(), "%m/%d/%Y %H:%M:%S", &tm);
    time_t t = mktime(&tm);  // t is now your desired time_t
    
    return t;
}

std::string timeObject::getDate()
{
    return dayNames[dayIndex] + " " + std::to_string(day) + " " + monthNames[month] + " " + std::to_string(year);
}

void timeObject::addMonth(int toAdd)
{
    month += toAdd;
    
    if(month < 0)
        year--;
    
    year += month / 12;
    month = month % 12;
}

void timeObject::addDay(int toAdd)
{
    day += toAdd;
    
    while(day <= 0)
    {
        addMonth(-1);
        day += monthDayLength[month];
    }
    
    while(day > monthDayLength[month])
    {
        day -= monthDayLength[month];
        addMonth(1);
    }
}
