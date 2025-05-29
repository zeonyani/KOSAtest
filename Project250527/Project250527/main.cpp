#include <iostream>
#include "CSVHandler.h"
#include <vector>
#include <string>

/*
 * main �Լ������� �����ϰ� CSVHandler�� ����� �����ϴ��� �׽�Ʈ�մϴ�.
 * �� �����͸� ���Ƿ� ����� CSV�� ������ ��,
 * �ٽ� �о �ֿܼ� ����ϴ� �帧�Դϴ�.
 */
int main() {
    // 1. CSV�� ������ ������ �غ� (�� ���� ����)
    std::vector<std::vector<std::string>> customers = {
        {"id", "name", "phone"},   // CSV ������ ��� (�� �̸�)
        {"1", "�����", "010-1234-5678"},
        {"2", "�̼���", "010-2345-6789"}
    };

    // 2. customers.csv ���Ͽ� ������ ����
    CSVHandler::writeCSV("customers.csv", customers);
    std::cout << "customers.csv ���� ���� �Ϸ�" << std::endl;

    // 3. ����� ������ �ٽ� �б�
    auto loadedData = CSVHandler::readCSV("customers.csv");

    // 4. ���� ������ �ܼ� ��� (���� ����/�б� Ȯ�ο�)
    std::cout << "CSV ���Ͽ��� ���� ������:" << std::endl;
    for (const auto& row : loadedData) {
        for (const auto& cell : row) {
            std::cout << cell << "\t";
        }
        std::cout << std::endl;
    }

    // 5. �������� customers.csv ������ ����� ���� ������ ���� ���Դϴ�.

    return 0;
}
