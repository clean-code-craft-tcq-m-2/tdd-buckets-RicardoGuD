#include "test_TDDCurrentRanges.h"
#include <iostream>
#include <assert.h>


void test_outputString(){
    std::cout <<"[test_outputString]---TEST STARTED---\n";
    std::vector<int> readingVector_test = {4,5};

    std::string expectedOutput = "4-5, 2";
    std::string actualOutput = createOutputString(4,5,2);

    assert(expectedOutput == actualOutput);
    std::cout <<"[test_outputString]---TEST OK---\n";
}

void test_rangesDetection(){
    std::cout <<"[test_rangesDetection]---TEST STARTED---\n";
    std::vector<int> vectortest = {7,4,8,4,6,1,6,8,9,3,1,1,13,12,11};
    std::sort(vectortest.begin(), vectortest.end());

    std::vector<std::pair<int,int>> expectedOutput = {{1,1},{3,4},{6,9},{11,13}};
    std::vector<std::pair<int,int>>  actualOutput = detectRanges(vectortest);

    assert(expectedOutput == actualOutput);
    std::cout <<"[test_rangesDetection]---TEST OK---\n";
}

void test_countMeasurenments(){
    std::cout <<"[test_countMeasurenments]---TEST STARTED---\n";
    std::vector<int> vectortest = {7,4,8,4,6,1,6,8,2,9,3,};
    std::sort(vectortest.begin(), vectortest.end());

    int expectedOutput = 5;
    int actualOutput = countMeasurenmentsInRange(std::make_pair(1,4), vectortest);

    assert(expectedOutput == actualOutput);
    std::cout <<"[test_countMeasurenments]---TEST OK---\n";
}
