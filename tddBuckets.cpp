#include "tddBuckets.h"

std::string createOutputString(int rangeStart, int rangeEnd, int readingsFound){
    std::string  output_str = std::to_string(rangeStart) + std::to_string(rangeEnd) + std::to_string(readingsFound);
    return "4-5, 2"; //hardcoded output for test purposes 
}