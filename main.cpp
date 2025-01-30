#include "operating_time.h"

int main() {
    const char *pathToFile = "optime.txt";
    OperatingTime operatingTime(pathToFile);
    operatingTime.countdownLoop();

    return 0;
}
