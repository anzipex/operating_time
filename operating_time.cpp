#include "operating_time.h"

OperatingTime::OperatingTime(const char *path) :
filePath_(path) {
    loadTime();
    lastUpdate_ = currentMillis();
}

void OperatingTime::loadTime() {
    std::ifstream infile(filePath_);
    if (infile >> time_)
        infile.close();
}

void OperatingTime::saveTime() {
    std::ofstream outfile(filePath_);
    outfile << time_;
}

void OperatingTime::updateTime() {
    uint64_t now = currentMillis();
    time_ += (now - lastUpdate_) / 1000;
    lastUpdate_ = now;
}

void OperatingTime::printTime() const {
    printf("Operating time: %u sec\n", time_);
}

uint64_t OperatingTime::currentMillis() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
}

void OperatingTime::countdownLoop() {
    while (true) {
        updateTime();
        printTime();
        saveTime();
        sleep(1);
    }
}
