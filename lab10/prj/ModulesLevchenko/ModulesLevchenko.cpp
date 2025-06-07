#include "ModulesLevchenko.h"
#include <fstream>
#include <iostream>
#include <ctime>

// ===== ������ 10.1 =====
void task101(const std::string& inputFile, const std::string& outputFile) {
    // ³�������� inputFile �� �������
    std::ifstream fin(inputFile.c_str());
    if (!fin) {
        std::cout << "�������: �� ������� ������� ������� ����: " << inputFile << std::endl;
        return;
    }

    // ³�������� outputFile �� ����� (������������)
    std::ofstream fout(outputFile.c_str());
    if (!fout) {
        std::cout << "�������: �� ������� �������� �������� ����: " << outputFile << std::endl;
        fin.close();
        return;
    }

    // 1) ��������� ���������� (������� ��� ���)
    fout << "�����: �������� ��������\n";
    fout << "��������: ���� - ���������� ���������� ������������ �������� ����������\n";
    fout << "̳���: �������������\n";
    fout << "�����: ������\n";
    fout << "г� ��������: 2025\n";
    fout << "----------------------------------------\n";

    // 2) ��� ������� ����� � inputFile
    std::string line;
    while (std::getline(fin, line)) {
        // ϳ�������� ������� ������� ':'
        int countColon = 0;
        for (char ch : line) {
            if (ch == ':') {
                ++countColon;
            }
        }
        fout << "ʳ������ ':' � �����: " << countColon << "\n";

        // ��������: �� � ������ (���.)
        bool hasVowel = false;
        const std::string vowels = "�ŪȲ�����຺賿����";
        for (char ch : line) {
            if (vowels.find(ch) != std::string::npos) {
                hasVowel = true;
                break;
            }
        }
        // ���� ������� ���� � �������� ��� �����
        if (!hasVowel && !line.empty()) {
            fout << "������� ��� ��������: " << line << "\n";
        }
        fout << "\n"; // ������ ����� �� ���������
    }

    fin.close();
    fout.close();
}

// ===== ������ 10.2 =====
void task102(const std::string& inputFile) {
    // 1) ������� ���� ����� �� inputFile
    std::ifstream fin(inputFile.c_str());
    if (!fin) {
        std::cout << "�������: �� ������� ������� ���� ��� �������: " << inputFile << std::endl;
        return;
    }
    std::string allText;
    std::string line;
    while (std::getline(fin, line)) {
        allText += line + "\n";
    }
    fin.close();

    // 2) ������������ ����� ����� ����� ��������� � 55
    std::string translitText;
    translitText.reserve(allText.size() * 2); // ��������� ����� ����� ����

    for (size_t i = 0; i < allText.size(); ++i) {
        unsigned char c = static_cast<unsigned char>(allText[i]);
        switch (c) {
            // ����ʲ ��������ʲ
            case '�': translitText += "A";  break;
            case '�': translitText += "B";  break;
            case '�': translitText += "V";  break;
            case '�': translitText += "H";  break;
            case '�': translitText += "G";  break;
            case '�': translitText += "D";  break;
            case '�': translitText += "E";  break;
            case '�': translitText += "YE"; break;
            case '�': translitText += "ZH"; break;
            case '�': translitText += "Z";  break;
            case '�': translitText += "Y";  break;
            case '�': translitText += "I";  break;
            case '�': translitText += "YI"; break;
            case '�': translitText += "Y";  break;
            case '�': translitText += "K";  break;
            case '�': translitText += "L";  break;
            case '�': translitText += "M";  break;
            case '�': translitText += "N";  break;
            case '�': translitText += "O";  break;
            case '�': translitText += "P";  break;
            case '�': translitText += "R";  break;
            case '�': translitText += "S";  break;
            case '�': translitText += "T";  break;
            case '�': translitText += "U";  break;
            case '�': translitText += "F";  break;
            case '�': translitText += "KH"; break;
            case '�': translitText += "TS"; break;
            case '�': translitText += "CH"; break;
            case '�': translitText += "SH"; break;
            case '�': translitText += "SHCH"; break;
            case '�': translitText += "YU"; break;
            case '�': translitText += "YA"; break;

            // ��˲ ��������ʲ
            case '�': translitText += "a";  break;
            case '�': translitText += "b";  break;
            case '�': translitText += "v";  break;
            case '�': translitText += "h";  break;
            case '�': translitText += "g";  break;
            case '�': translitText += "d";  break;
            case '�': translitText += "e";  break;
            case '�': translitText += "ye"; break;
            case '�': translitText += "zh"; break;
            case '�': translitText += "z";  break;
            case '�': translitText += "y";  break;
            case '�': translitText += "i";  break;
            case '�': translitText += "yi"; break;
            case '�': translitText += "y";  break;
            case '�': translitText += "k";  break;
            case '�': translitText += "l";  break;
            case '�': translitText += "m";  break;
            case '�': translitText += "n";  break;
            case '�': translitText += "o";  break;
            case '�': translitText += "p";  break;
            case '�': translitText += "r";  break;
            case '�': translitText += "s";  break;
            case '�': translitText += "t";  break;
            case '�': translitText += "u";  break;
            case '�': translitText += "f";  break;
            case '�': translitText += "kh"; break;
            case '�': translitText += "ts"; break;
            case '�': translitText += "ch"; break;
            case '�': translitText += "sh"; break;
            case '�': translitText += "shch"; break;
            case '�': translitText += "yu"; break;
            case '�': translitText += "ya"; break;

            default:
                // ���� ������� (������, ����������, �����, ��������) �������� ��� ���
                translitText += allText[i];
                break;
        }
    }

    // 3) �������� � ����� inputFile ��������������� ����� � ����
    std::ofstream fout(inputFile.c_str(), std::ios::app);
    if (!fout) {
        std::cout << "�������: �� ������� ������� ���� ��� ������: " << inputFile << std::endl;
        return;
    }
    fout << "\n===== ��������������� ����� =====\n";
    fout << translitText;
    fout << "\n���� ������: ";

    // �������� ���������� ���� � ������ "��/��/��"
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int day   = now->tm_mday;
    int month = now->tm_mon + 1;       // ����� ����� �� 0 �� 11
    int year  = (now->tm_year % 100);  // �� ������ ����� ����

    if (day < 10)   fout << '0';
    fout << day << '/';
    if (month < 10) fout << '0';
    fout << month << '/';
    if (year < 10)  fout << '0';
    fout << year << "\n";

    fout.close();
}

// ===== ������ 10.3 =====
void task103(const std::string& inputFile, double x, double y, double z, int b) {
    // 1) ���������� s = x + y + z
    double s = s_calculation(x, y, z);
    // 2) ������������ b � �������� �����
    std::string bin = toBinary(b);

    // 3) �������� ���������� � ����� inputFile
    std::ofstream fout(inputFile.c_str(), std::ios::app);
    if (!fout) {
        std::cout << "�������: �� ������� ������� ���� ��� ������: " << inputFile << std::endl;
        return;
    }
    fout << "\n===== ���������� ������ 10.3 =====\n";
    fout << "s_calculation(" << x << ", " << y << ", " << z << ") = " << s << "\n";
    fout << "����� b = " << b << " � ���������: " << bin << "\n";
    fout.close();
}

// ===== �������� ������� s_calculation =====
double s_calculation(double x, double y, double z) {
    return x + y + z;
}

// ===== ������������ ������������ b � �������� ����� =====
std::string toBinary(int b) {
    if (b == 0) return "0";
    std::string result;
    int n = b;
    while (n > 0) {
        int digit = n % 2;
        result = char('0' + digit) + result;
        n /= 2;
    }
    return result;
}
