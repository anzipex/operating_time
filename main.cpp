#include "operating_time.h"

int main() {
    OperatingTime operatingTime("optime.txt");
    operatingTime.countdownLoop();
    return 0;
}
