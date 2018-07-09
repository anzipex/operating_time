/** 
 * @file OperatingTime.h
 * @brief Description of class OperatingTime
 * @author anzipex
 * @date July 9, 2018
 */

#ifndef OPERATINGTIME_H
#define OPERATINGTIME_H

#include <cstring>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <chrono>

class OperatingTime {
public:
    /**
     * @brief Accepts path to file and prepares operating
     * @param pathToFile, path to save text file with operating time
     */
    OperatingTime(const char *pathToFile);

    /**
     * @brief Countdown operating time
     */
    void countdownLoop();

private:
    /**
     * @brief Preparation of the file
     */
    void prepareOperating();

    /**
     * @brief Checking the existence of the operating time file
     * @return The file exists or the file doesn't exist
     */
    bool fileExist();

    /**
     * @brief Creating a file
     */
    void createFile();

    /**
     * @brief Continue to count operating time if the file exists
     */
    void resumeOperating();

    /**
     * @brief Run-time counter, output the result and update the value
     */
    void operateTime();

    /**
     * @brief Counting the time in milliseconds
     * @return Time from the origin to the current moment
     */
    uint64_t countMilliseconds();

    /**
     * @brief Save operating time to file
     */
    void saveOperatingTime();

    /**
     * @brief Clear 5 seconds for saving to file
     */
    void resetTimePoint();

    /**
     * @brief Increase in operating time
     */
    void increaseTime();

    /**
     * @brief Increase the count value of 5 seconds to save to a file
     */
    void increaseTimePoint();

    /**
     * @brief Print operating time value
     */
    void printOperatingTime();

    /**
     * @brief Clear screen
     */
    static void clearScreen();

    /**
     * @brief Counting time in seconds
     * @return How many seconds have passed since the countdown
     */
    int clockSecondsPassed() const;

    /**
     * @brief Checking the countdown time for saving the file
     */
    void checkTimePointToSave();

    const char *_pathToFile; //!< path to the file with time
    uint32_t _operatingTime; //!< operating time
    uint32_t _lastTime; //!< time of the last operating time from a file
    int _timePoint; //!< countdown time 5 seconds to save file
    double _clockDifference; //!< time difference
    int _fiveSecondsPoint; //!< 5 seconds border in time of counting
};

#endif /* OPERATINGTIME_H */