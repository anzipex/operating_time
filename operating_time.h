#pragma once

#include <fstream>
#include <iostream>
#include <chrono>
#include <unistd.h>

class OperatingTime {
public:
    explicit OperatingTime(const char *path);
    void countdownLoop();

private:
    void loadTime();
    void saveTime();
    void updateTime();
    void printTime() const;
    static uint64_t currentMillis();

    const char *filePath_;
    uint32_t time_{0};
    uint64_t lastUpdate_{0};
};
