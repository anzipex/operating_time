/** 
 * @file main.cpp
 * @brief operating_time (https://github.com/anzipex/operating_time)
 * @author anzipex
 * @date July 9, 2018
 */

#include "OperatingTime.h"

int main() {
    const char *pathToFile = "OperatingTime.txt";
    OperatingTime operatingTime(pathToFile);
    operatingTime.countdownLoop();

    return 0;
}