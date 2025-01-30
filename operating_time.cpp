/** 
 * @file OperatingTime.cpp
 * @brief Implementing a class OperatingTime
 * @author anzipex
 * @date July 9, 2018
 */

#include "operating_time.h"

OperatingTime::OperatingTime(const char *pathToFile) :
_operatingTime(0),
_lastTime(0),
_timePoint(0),
_clockDifference(0),
_fiveSecondsPoint(5) {
    _pathToFile = pathToFile;
    prepareOperating();
}

void OperatingTime::prepareOperating() {
    if (fileExist()) {
        resumeOperating();
    } else {
        createFile();
    }
}

bool OperatingTime::fileExist() {
    std::ifstream infile(_pathToFile);
    return infile.good();
}

void OperatingTime::createFile() {
    std::ofstream outfile(_pathToFile);
    outfile.close();
}

void OperatingTime::resumeOperating() {
    std::ifstream infile(_pathToFile);
    while (infile >> _lastTime) {
        _operatingTime = _lastTime;
    }
}

void OperatingTime::printOperatingTime() {
    printf("operating time: %u\n", _operatingTime);
}

void OperatingTime::clearScreen() {
    printf("\e[1;1H\e[2J");
}

void OperatingTime::countdownLoop() {
    for (;;) {
        operateTime();
        printOperatingTime();
        clearScreen();
        sleep(1);
    }
}

int OperatingTime::clockSecondsPassed() const {
    int clockSeconds = (_clockDifference / 1000);
    return clockSeconds;
}

void OperatingTime::checkTimePointToSave() {
    if (_timePoint >= _fiveSecondsPoint) {
        resetTimePoint();
        saveOperatingTime();
    }
}

void OperatingTime::operateTime() {
    static auto clockPrev = countMilliseconds();
    const auto clockCurrent = countMilliseconds();
    _clockDifference = clockCurrent - clockPrev;
    checkTimePointToSave();
    increaseTime();
    increaseTimePoint();
    clockPrev = clockCurrent;
}

uint64_t OperatingTime::countMilliseconds() {
    const auto timePoint = std::chrono::high_resolution_clock::now();
    const auto duration = timePoint.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

void OperatingTime::saveOperatingTime() {
    std::ofstream outfile;
    outfile.open(_pathToFile);
    outfile << _operatingTime;
    outfile.close();
}

void OperatingTime::resetTimePoint() {
    _timePoint = 0;
}

void OperatingTime::increaseTime() {
    _operatingTime += clockSecondsPassed();
}

void OperatingTime::increaseTimePoint() {
    _timePoint += clockSecondsPassed();
}
