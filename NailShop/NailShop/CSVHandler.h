#pragma once

#include <string>
#include <vector>
using namespace std;

class CSVHandler {
public:
    // CSV ������ ����
    static void writeCSV(const string& filename, const vector<vector<string>>& data);

    // CSV ������ �о ��ȯ
    static vector<vector<string>> readCSV(const string& filename);

};