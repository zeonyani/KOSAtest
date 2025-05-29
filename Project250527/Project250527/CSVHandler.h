#pragma once
#include <string>
#include <vector>

/*
 * CSVHandler 클래스:
 * CSV 파일을 읽고 쓰는 역할만 하는 유틸리티 클래스입니다.
 * 모든 함수는 static이며, 객체를 생성하지 않고 사용합니다.
 */
class CSVHandler {
public:
    /*
     * CSV 파일로 데이터를 저장합니다.
     * filename: 저장할 파일명
     * data: 2차원 벡터, 각 내부 벡터는 한 줄(row), 각 문자열은 셀(cell)을 의미
     */
    static void writeCSV(const std::string& filename, const std::vector<std::vector<std::string>>& data);

    /*
     * CSV 파일에서 데이터를 읽어옵니다.
     * filename: 읽을 파일명
     * 반환값: 2차원 벡터, 각 내부 벡터는 한 줄(row), 각 문자열은 셀(cell)
     */
    static std::vector<std::vector<std::string>> readCSV(const std::string& filename);
};
