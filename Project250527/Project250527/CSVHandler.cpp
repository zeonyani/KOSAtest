#include "CSVHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>

/*
 * writeCSV:
 * data를 CSV 형식으로 파일에 저장합니다.
 */
void CSVHandler::writeCSV(const std::string& filename, const std::vector<std::vector<std::string>>& data) {
    std::ofstream file(filename);  // 파일 열기
    if (!file.is_open()) {
        std::cerr << "파일 열기 실패: " << filename << std::endl;
        return;
    }

    // 각 행(row)을 파일에 작성
    for (const auto& row : data) {
        // 각 셀(cell)을 쉼표로 구분하여 기록
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i != row.size() - 1) {
                file << ",";
            }
        }
        file << "\n";  // 한 줄 끝나면 줄 바꿈
    }

    file.close();  // 파일 닫기
}

/*
 * readCSV:
 * CSV 파일을 읽어서 2차원 벡터로 반환합니다.
 */
std::vector<std::vector<std::string>> CSVHandler::readCSV(const std::string& filename) {
    std::ifstream file(filename);  // 파일 열기
    std::vector<std::vector<std::string>> data;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "파일 열기 실패: " << filename << std::endl;
        return data;  // 빈 벡터 반환
    }

    // 파일에서 한 줄씩 읽기
    while (getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);

        std::string cell;
        // 쉼표 단위로 나눠서 각 셀을 벡터에 저장
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        data.push_back(row);  // 한 행(row) 추가
    }

    file.close();  // 파일 닫기
    return data;   // 읽은 데이터 반환
}
