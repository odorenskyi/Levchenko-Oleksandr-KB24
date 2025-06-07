#ifndef MODULES_LEVCHENKO_H
#define MODULES_LEVCHENKO_H

#include <string>

// ===== ������ 10.1 =====
// ���� inputFile, ������� outputFile � ������ ����:
//   1) ��������� ���������� (���, �������, ��������, ����, �����, �� ��������),
//   2) ������� ':' � ������� ����� � inputFile,
//   3) � �����, � ���� ������ �� ������ ����� (���.).
void task101(const std::string& inputFile, const std::string& outputFile);

// ===== ������ 10.2 =====
// ������ � ��� �� inputFile:
//   1) ����� �����, ��������������� ����� ��������� � 55,
//   2) ������� ���� � ������ "��/��/��".
void task102(const std::string& inputFile);

// ===== ������ 10.3 =====
// ������ � ��� �� inputFile:
//   1) ��������� ������� s_calculation(x, y, z),
//   2) ���������� ����� b � ��������� (����������) ������.
void task103(const std::string& inputFile, double x, double y, double z, int b);

// ===== ������� ������� =====
// ������ ������� x + y + z .
double s_calculation(double x, double y, double z);

// ���������� ���������� ����� b � ����� � �������� ��������.
std::string toBinary(int b);

#endif // MODULES_LEVCHENKO_H
