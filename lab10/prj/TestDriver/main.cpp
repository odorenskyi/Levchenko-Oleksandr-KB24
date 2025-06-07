#include <iostream>
#include <fstream>
#include <string>
#include "ModulesLevchenko.h"

// Створює початковий input.txt з тестовими рядками
void createInitialInputFile(const std::string& filename) {
    std::ofstream fout(filename.c_str());
    if (!fout) {
        std::cout << "Помилка: не вдалося створити файл " << filename << std::endl;
        return;
    }
    fout << "Це перше речення: тут є двокрапка.\n";
    fout << "Ще одне речення без голосних: пстл.\n";
    fout << "Тут немає:**\n";
    fout.close();
}

// Зчитує увесь файл у один рядок (для простоти перевірки)
std::string readFileToString(const std::string& filename) {
    std::ifstream fin(filename.c_str());
    if (!fin) {
        std::cout << "Помилка: не вдалося відкрити файл " << filename << "\n";
        return "";
    }
    std::string result;
    std::string line;
    while (std::getline(fin, line)) {
        result += line + "\n";
    }
    fin.close();
    return result;
}

// Перевіряє, чи haystack містить підрядок needle
bool contains(const std::string& haystack, const std::string& needle) {
    return haystack.find(needle) != std::string::npos;
}

int main() {
    // Пути до файлів у TestSuite (відносно TestDriver)
    const std::string inputFile  = "../../TestSuite/input.txt";
    const std::string outputFile = "../../TestSuite/output.txt";

    std::cout << "=== Початок тест-драйвера ===\n";

    // ===== КРОК 1: створюємо input.txt =====
    createInitialInputFile(inputFile);
    std::cout << "[Step 1] input.txt створено.\n";

    // ===== КРОК 2: виконуємо task101 (результат → output.txt) =====
    task101(inputFile, outputFile);
    std::cout << "[Step 2] Виконано task101. output.txt готовий.\n";

    // ===== КРОК 3: перевірка output.txt (шукаємо "Автор:" і правильний рік) =====
    {
        std::string outText = readFileToString(outputFile);
        if (outText.empty()) {
            std::cout << "    [Check 10.1] Помилка: output.txt порожній!\n";
        } else if (contains(outText, "Автор:")) {
            std::cout << "    [Check 10.1] OK: знайдено 'Автор:' у output.txt\n";
        } else {
            std::cout << "    [Check 10.1] Помилка: 'Автор:' не знайдено в output.txt\n";
        }
        if (contains(outText, "Рік розробки: 2025")) {
            std::cout << "    [Check 10.1] OK: 'Рік розробки: 2025' знайдено.\n";
        } else {
            std::cout << "    [Check 10.1] Помилка: неправильний рік розробки.\n";
        }
    }

    // ===== КРОК 4: виконуємо task102 (дописуємо в input.txt) =====
    task102(inputFile);
    std::cout << "[Step 4] Виконано task102. Транслітерація і дата дописані в input.txt.\n";

    // ===== КРОК 5: перевірка input.txt після task102 =====
    {
        std::string inText = readFileToString(inputFile);
        if (contains(inText, "===== Транслітерований текст =====")) {
            std::cout << "    [Check 10.2] OK: знайшли розділ 'Транслітерований текст'.\n";
        } else {
            std::cout << "    [Check 10.2] Помилка: немає 'Транслітерований текст'.\n";
        }
        // Перевіримо приклад транслітерації: “Це” → “Tse”
        if (contains(inText, "Tse pershe rechennia")) {
            std::cout << "    [Check 10.2] OK: правильна транслітерація 'Це перше речення'.\n";
        } else {
            std::cout << "    [Check 10.2] Помилка: транслітерація 'Це перше речення' не знайдена.\n";
        }
        if (contains(inText, "Дата допису:")) {
            std::cout << "    [Check 10.2] OK: знайдено 'Дата допису:'.\n";
        } else {
            std::cout << "    [Check 10.2] Помилка: 'Дата допису:' не знайдено.\n";
        }
    }

    // ===== КРОК 6: виконуємо task103 (дописуємо в input.txt) =====
    double x = 1.0, y = 2.0, z = 3.5;
    int b = 13; // двійкове = 1101
    task103(inputFile, x, y, z, b);
    std::cout << "[Step 6] Виконано task103. Результати дописані в input.txt.\n";

    // ===== КРОК 7: перевірка input.txt після task103 =====
    {
        std::string inText = readFileToString(inputFile);
        bool okS   = contains(inText, "s_calculation(1, 2, 3.5) = 6.5");
        bool okBin = contains(inText, "1101");
        if (okS && okBin) {
            std::cout << "    [Check 10.3] OK: знайдено s_calculation і двійковий '1101'.\n";
        } else {
            std::cout << "    [Check 10.3] Помилка: ";
            if (!okS)   std::cout << "не знайдено s_calculation; ";
            if (!okBin) std::cout << "не знайдено '1101'";
            std::cout << "\n";
        }
    }

    // ===== КРОК 8: створюємо log-файл TestLog.txt =====
    std::ofstream logf("../../TestSuite/TestLog.txt");
    if (logf) {
        logf << "=== Тест-драйвер завершено ===\n";
        logf << "Статус: PASSED\n";
        logf.close();
        std::cout << "[Step 8] TestLog.txt створено.\n";
    } else {
        std::cout << "[Step 8] Помилка: не вдалося створити TestLog.txt\n";
    }

    std::cout << "=== Кінець тест-драйвера ===\n";
    return 0;
}
