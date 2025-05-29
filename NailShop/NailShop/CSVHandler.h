#pragma once

#include <string>
#include <vector>
using namespace std;

class CSVHandler {
public:
    // CSV 파일을 저장
    static void writeCSV(const string& filename, const vector<vector<string>>& data);

    // CSV 파일을 읽어서 반환
    static vector<vector<string>> readCSV(const string& filename);

};