#include <iostream>
#include <string>

#include <stringStuff.hxx>

void splitString(std::string *splitInTo, std::string toSplit, char splitOn)
{
    int counter = 0;
    std::string currentString = "";
    
    for(int i = 0; i < toSplit.length(); ++i)
        if(toSplit[i] == splitOn)
        {
            if(i+1 < toSplit.length() && toSplit[i+1] == splitOn) //skip over char if it's repeated multiple times
                continue;
            
            splitInTo[counter] = currentString;
            counter++;
            currentString = "";
        } else if(toSplit[i] != '\n')
            currentString += toSplit[i];
    
    splitInTo[counter] = currentString;
}

int findInArray(std::string *array, std::string toFind, int arrayLength)
{
    for(int i = 0; i < arrayLength; ++i)
        if(array[i] == toFind)
            return i;
    return -1;
}
