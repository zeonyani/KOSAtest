#pragma once
#include <string>
#include <vector>

/*
 * CSVHandler Ŭ����:
 * CSV ������ �а� ���� ���Ҹ� �ϴ� ��ƿ��Ƽ Ŭ�����Դϴ�.
 * ��� �Լ��� static�̸�, ��ü�� �������� �ʰ� ����մϴ�.
 */
class CSVHandler {
public:
    /*
     * CSV ���Ϸ� �����͸� �����մϴ�.
     * filename: ������ ���ϸ�
     * data: 2���� ����, �� ���� ���ʹ� �� ��(row), �� ���ڿ��� ��(cell)�� �ǹ�
     */
    static void writeCSV(const std::string& filename, const std::vector<std::vector<std::string>>& data);

    /*
     * CSV ���Ͽ��� �����͸� �о�ɴϴ�.
     * filename: ���� ���ϸ�
     * ��ȯ��: 2���� ����, �� ���� ���ʹ� �� ��(row), �� ���ڿ��� ��(cell)
     */
    static std::vector<std::vector<std::string>> readCSV(const std::string& filename);
};
