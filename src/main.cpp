#include <iostream>
#include <event.hxx>

#include <ctime>

int main()
{
    Event moo("Party", 1477717458, 1477789458,  "My birthday");
    moo.propagateEvent(1262304000, 1920070400, "y");
    moo.printEvents();
    
    return 0;
}
