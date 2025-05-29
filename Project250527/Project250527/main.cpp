#include <iostream>
#include "CSVHandler.h"
#include <vector>
#include <string>

/*
 * main 함수에서는 간단하게 CSVHandler가 제대로 동작하는지 테스트합니다.
 * 고객 데이터를 임의로 만들어 CSV로 저장한 후,
 * 다시 읽어서 콘솔에 출력하는 흐름입니다.
 */
int main() {
    // 1. CSV로 저장할 데이터 준비 (고객 정보 예시)
    std::vector<std::vector<std::string>> customers = {
        {"id", "name", "phone"},   // CSV 파일의 헤더 (열 이름)
        {"1", "김민지", "010-1234-5678"},
        {"2", "이수빈", "010-2345-6789"}
    };

    // 2. customers.csv 파일에 데이터 저장
    CSVHandler::writeCSV("customers.csv", customers);
    std::cout << "customers.csv 파일 저장 완료" << std::endl;

    // 3. 저장된 파일을 다시 읽기
    auto loadedData = CSVHandler::readCSV("customers.csv");

    // 4. 읽은 데이터 콘솔 출력 (정상 저장/읽기 확인용)
    std::cout << "CSV 파일에서 읽은 데이터:" << std::endl;
    for (const auto& row : loadedData) {
        for (const auto& cell : row) {
            std::cout << cell << "\t";
        }
        std::cout << std::endl;
    }

    // 5. 엑셀에서 customers.csv 파일을 열어보면 같은 내용이 보일 것입니다.

    return 0;
}
