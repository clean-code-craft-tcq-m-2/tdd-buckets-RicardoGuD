#include "test_tddBuckects.h"
#include <iostream>
#include <assert.h>

void test_output(){
    std::cout <<"[test_output]---TEST STARTED---\n";
    std::vector<int> readingVector_test = {4,5};
    std::string expectedOutput = "4-5, 2";
    std::string actualOutput = createOutputString(4,5,2);

    if(expectedOutput != actualOutput){std::cout << "expected output = " << expectedOutput << std::endl 
                                                 << "actual ouput = "    << actualOutput << std::endl;}
    assert(expectedOutput == actualOutput);
    std::cout <<"[test_output]---TEST OK---\n";
}

int main(){
    test_output();
    return 0;
}