#ifndef TIMEOBJECT_H
#define TIMEOBJECT_H

#include <string>

static std::string dayNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
static std::string dayNamesShort[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

static std::string monthNames[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

static std::string monthNamesShort[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
static int monthDayLength[] = {31,28,31,30,31,30,31,31,30,31,30,31};

//minute, hour, day, week, year
//int measureToSeconds;

class timeObject {
    public:
        int day; //day number
        int dayIndex; //index of dayNamesShort
        int month;
        int year;
        
        int second;
        int minute;
        int hour;
        
        timeObject(int toParse = 0, timeObject *toCopy = NULL);
        bool setObject(timeObject *toCopy);
        int getUnixTimestamp();
        std::string getDate();
};

#endif
