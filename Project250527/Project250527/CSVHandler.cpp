#include "CSVHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>

/*
 * writeCSV:
 * data�� CSV �������� ���Ͽ� �����մϴ�.
 */
void CSVHandler::writeCSV(const std::string& filename, const std::vector<std::vector<std::string>>& data) {
    std::ofstream file(filename);  // ���� ����
    if (!file.is_open()) {
        std::cerr << "���� ���� ����: " << filename << std::endl;
        return;
    }

    // �� ��(row)�� ���Ͽ� �ۼ�
    for (const auto& row : data) {
        // �� ��(cell)�� ��ǥ�� �����Ͽ� ���
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i != row.size() - 1) {
                file << ",";
            }
        }
        file << "\n";  // �� �� ������ �� �ٲ�
    }

    file.close();  // ���� �ݱ�
}

/*
 * readCSV:
 * CSV ������ �о 2���� ���ͷ� ��ȯ�մϴ�.
 */
std::vector<std::vector<std::string>> CSVHandler::readCSV(const std::string& filename) {
    std::ifstream file(filename);  // ���� ����
    std::vector<std::vector<std::string>> data;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "���� ���� ����: " << filename << std::endl;
        return data;  // �� ���� ��ȯ
    }

    // ���Ͽ��� �� �پ� �б�
    while (getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);

        std::string cell;
        // ��ǥ ������ ������ �� ���� ���Ϳ� ����
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        data.push_back(row);  // �� ��(row) �߰�
    }

    file.close();  // ���� �ݱ�
    return data;   // ���� ������ ��ȯ
}
