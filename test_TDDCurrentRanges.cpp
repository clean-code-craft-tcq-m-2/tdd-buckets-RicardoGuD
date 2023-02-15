#include "test_TDDCurrentRanges.h"
#include <iostream>
#include <assert.h>


void test_outputString(){
    std::cout <<"[test_outputString]--------------TEST STARTED--------------\n";

    std::string expectedOutput = "4-5, 2";
    std::string actualOutput = createOutputString(4,5,2);
    assert(expectedOutput == actualOutput);
    
    std::cout <<"[test_outputString]--------------TEST OK--------------\n";
}

void test_rangesDetection(){
    std::cout <<"[test_rangesDetection]--------------TEST STARTED--------------\n";

    std::cout <<"[test_rangesDetection]-----Random Measurenments\n";
    std::vector<int> testVector1 = {7,4,8,4,6,1,6,8,9,3,1,1,13,12,11};
    std::sort(testVector1.begin(), testVector1.end());
    std::vector<std::pair<int,int>> expectedOutput = {{1,1},{3,4},{6,9},{11,13}};
    std::vector<std::pair<int,int>>  actualOutput = detectRanges(testVector1);
    assert(expectedOutput == actualOutput);

    std::cout <<"[test_rangesDetection]-----Only one number range in the middle\n";
    std::vector<int> testVector2 = {9,8,7,5,3,2,1,1,1,1};
    std::sort(testVector2.begin(), testVector2.end());
    expectedOutput = {{1,3},{5,5},{7,9}};
    actualOutput   = detectRanges(testVector2);
    assert(expectedOutput == actualOutput);

    std::cout <<"[test_rangesDetection]-----All measurenments are the same\n";
    std::vector<int> testVector3 = {8,8,8,8,8,8,8};
    std::sort(testVector3.begin(), testVector3.end());
    expectedOutput = {{8,8}};
    actualOutput   = detectRanges(testVector3);
    assert(expectedOutput == actualOutput);

    std::cout <<"[test_rangesDetection]-----All measurenments are different and consecutive\n";
    std::vector<int> testVector4 = {1,2,3,4,5,6,7};
    std::sort(testVector4.begin(), testVector4.end());
    expectedOutput = {{1,7}};
    actualOutput   = detectRanges(testVector4);
    assert(expectedOutput == actualOutput);

    std::cout <<"[test_rangesDetection]-----All measurenments are different and not consecutive\n";
    std::vector<int> testVector5 = {1,3,5,7,9};
    std::sort(testVector5.begin(), testVector5.end());
    expectedOutput = {{1,1}, {3,3}, {5,5}, {7,7}, {9,9}};
    actualOutput   = detectRanges(testVector5);
    assert(expectedOutput == actualOutput);

    std::cout <<"[test_rangesDetection]--------------TEST OK--------------\n";
}

void test_countMeasurenments(){
    std::cout <<"[test_countMeasurenments]--------------TEST STARTED--------------\n";

    std::cout <<"[test_countMeasurenments]-----one number range count\n";
    std::vector<int> testVector1 = {7};
    std::sort(testVector1.begin(), testVector1.end());
    int expectedOutput = 1;
    int actualOutput = countMeasurenmentsInRange(std::make_pair(7,7), testVector1);
    assert(expectedOutput == actualOutput);

    std::cout <<"[test_countMeasurenments]-----All measurenment are the same\n";
    std::vector<int> testVector2 = {1,1,1,1,1,1,1};
    std::sort(testVector2.begin(), testVector2.end());
    expectedOutput = 7;
    actualOutput = countMeasurenmentsInRange(std::make_pair(1,4), testVector2);
    assert(expectedOutput == actualOutput);

    std::cout <<"[test_countMeasurenments]-----All measurenment are different\n";
    std::vector<int> testVector3 = {1,2,3,4,5,6,7};
    std::sort(testVector3.begin(), testVector3.end());
    expectedOutput = 4;
    actualOutput = countMeasurenmentsInRange(std::make_pair(1,4), testVector3);
    assert(expectedOutput == actualOutput);

    std::cout <<"[test_countMeasurenments]-----Current measurenment 0\n";
    std::vector<int> testVector4 = {1,2,3,0,4,5,6,7};
    std::sort(testVector4.begin(), testVector4.end());
    expectedOutput = 4;
    actualOutput = countMeasurenmentsInRange(std::make_pair(1,4), testVector4);
    assert(expectedOutput == actualOutput);

    std::cout <<"[test_countMeasurenments]--------------TEST OK--------------\n";
}
