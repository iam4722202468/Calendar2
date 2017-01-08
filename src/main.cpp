#include <iostream>
#include <event.hxx>

#include <ctime>

int main()
{
    Event moo("Party", 1477717458, 1477789458,  "My birthday");
    moo.propagateEvent(1475125457, 1479225600, "d");
    moo.printEvents();
    
    return 0;
}
