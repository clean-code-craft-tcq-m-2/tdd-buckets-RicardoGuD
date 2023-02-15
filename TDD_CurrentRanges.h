#pragma once
#include <vector>
#include <string>
#include <bits/stdc++.h>

bool isNewRangeStart(int firstValue, int NextValue);
bool isLastMeasurenment(std::vector<int> measurenmentVector);
bool isRangeEnd(int firstValue, int NextValue, std::vector<int> vector);
void saveRangeLimits(std::pair<int,int>& rangeLimits, std::vector<std::pair<int,int>>& rangesVector,
                     int firstValue, int NextValue);

std::vector<std::pair<int,int>> detectRanges(std::vector<int> orderedMeasurenments);
int countMeasurenmentsInRange(std::pair<int,int> rangeLimits, std::vector<int> orderedMeasurenments);
std::string createOutputString(int rangeStart, int rangeEnd, int readingsFound);

void captureCurrentMeasurenmentsRanges(std::vector<int> measurenments);