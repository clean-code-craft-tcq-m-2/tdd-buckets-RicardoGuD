#include "TDD_CurrentRanges.h"
bool isNewRangeStart(int firstValue, int NextValue)
{
    return (NextValue != firstValue &&
            NextValue != firstValue+1);
}

bool isLastMeasurenment(std::vector<int> measurenmentVector, uint8_t currentIndex)
{
    uint8_t finalMeasurenment = measurenmentVector.size()-1;
    return finalMeasurenment == currentIndex;
}

bool isRangeEnd(int firstValue, int NextValue, uint8_t measurenmentIndex, std::vector<int> vector)
{
    return (isNewRangeStart(firstValue, NextValue) || isLastMeasurenment(vector, measurenmentIndex));
}

void saveRangeLimits(std::pair<int,int>& rangeLimits, std::vector<std::pair<int,int>>& rangesVector, 
                     int latestValue, int nextValue)
{
    if(isNewRangeStart(latestValue, nextValue))
    {
        rangeLimits.second = latestValue;
        rangesVector.push_back(rangeLimits);
        rangeLimits.first  = nextValue;
    }
    else // is the last number in the array
    {
        rangeLimits.second = nextValue; 
        rangesVector.push_back(rangeLimits);
    }
}

std::vector<std::pair<int,int>> detectRanges(std::vector<int> orderedMeasurenments)
{
    std::pair<int,int> rangeLimits;
    std::vector<std::pair<int,int>> rangeLimitsVector;

    rangeLimits.first = orderedMeasurenments.at(0);
    uint8_t lastMeasurenment = orderedMeasurenments.size()-1;

    for(uint8_t measurenmentIndex=0; measurenmentIndex<lastMeasurenment; measurenmentIndex++)
    {
        int nextMeasurenmentIndex = measurenmentIndex + 1;
        int latestMeasurenment = orderedMeasurenments.at(measurenmentIndex);
        int nextMeasurenment   = orderedMeasurenments.at(nextMeasurenmentIndex);

        if(isRangeEnd(latestMeasurenment, nextMeasurenment, nextMeasurenmentIndex, orderedMeasurenments))
        {
            saveRangeLimits(rangeLimits, rangeLimitsVector, latestMeasurenment, nextMeasurenment);
        }
    } 
    return rangeLimitsVector;
}

int countMeasurenmentsInRange(std::pair<int,int> rangeLimits, std::vector<int> orderedMeasurenments)
{
    int measurenmentCount = 0;

    int rangeStart = rangeLimits.first;
    int rangeEnd = rangeLimits.second;

    for(int measurenment: orderedMeasurenments)
    {
        if(measurenment >= rangeStart && measurenment<=rangeEnd)
        {
            measurenmentCount++;
        }
    }
    return measurenmentCount;
}

std::string createOutputString(int rangeStart, int rangeEnd, int readingsFound)
{
    std::string  output_str = std::to_string(rangeStart) + "-" + std::to_string(rangeEnd) + ", " + std::to_string(readingsFound);
    return output_str;
}

void captureCurrentMeasurenmentsRanges(std::vector<int> measurenments)
{
    std::sort(measurenments.begin(), measurenments.end());
    std::vector<std::pair<int,int>> rangesDetected = detectRanges(measurenments);
    
    for(uint8_t i=0; i<rangesDetected.size(); i++)
    {
        int rangeStart = rangesDetected.at(i).first;
        int rangeEnd = rangesDetected.at(i).second;
        int measurenmentCounted = countMeasurenmentsInRange(rangesDetected.at(i), measurenments);
        std::cout << createOutputString(rangeStart, rangeEnd, measurenmentCounted) <<std::endl;
    }
}
