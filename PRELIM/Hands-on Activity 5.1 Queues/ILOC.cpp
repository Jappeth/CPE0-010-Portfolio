#include <iostream>
#include "iloc.h"
#include <string>


int main() {
    //4. Finally, simulate a scenario where multiple people are adding jobs to the printer, and the printer is processing them one by one.
    Printer printer1;
    
    Job print1(1, "Resume", 1);
    Job print2(2, "Research", 15);
    Job print3(3, "Report Cards", 5);

    printer1.addJob(print1);
    printer1.addJob(print2);
    printer1.addJob(print3);

    printer1.StartPrinting();

    Job print4(4, "Assignment", 2);
    printer1.addJob(print4);
    printer1.StartPrinting();

    return 0;
}