#include "ModulesLevchenko.h"
#include <fstream>
#include <iostream>
#include <ctime>

// ===== Задача 10.1 =====
void task101(const std::string& inputFile, const std::string& outputFile) {
    // Відкриваємо inputFile на читання
    std::ifstream fin(inputFile.c_str());
    if (!fin) {
        std::cout << "Помилка: не вдалося відкрити вхідний файл: " << inputFile << std::endl;
        return;
    }

    // Відкриваємо outputFile на запис (перезаписуємо)
    std::ofstream fout(outputFile.c_str());
    if (!fout) {
        std::cout << "Помилка: не вдалося створити вихідний файл: " << outputFile << std::endl;
        fin.close();
        return;
    }

    // 1) Авторська інформація (впишіть свої дані)
    fout << "Автор: Левченко Олександ\n";
    fout << "Установа: ЦНТУ - Центрально український національний технічний університет\n";
    fout << "Місто: Кропивницький\n";
    fout << "Країна: Україна\n";
    fout << "Рік розробки: 2025\n";
    fout << "----------------------------------------\n";

    // 2) Для кожного рядка з inputFile
    std::string line;
    while (std::getline(fin, line)) {
        // Підрахунок кількості символів ':'
        int countColon = 0;
        for (char ch : line) {
            if (ch == ':') {
                ++countColon;
            }
        }
        fout << "Кількість ':' у рядку: " << countColon << "\n";

        // Перевірка: чи є голосні (укр.)
        bool hasVowel = false;
        const std::string vowels = "АЕЄИІЇОУЮЯаєєиіїоуюя";
        for (char ch : line) {
            if (vowels.find(ch) != std::string::npos) {
                hasVowel = true;
                break;
            }
        }
        // Якщо гласних немає — записуємо цей рядок
        if (!hasVowel && !line.empty()) {
            fout << "Речення без голосних: " << line << "\n";
        }
        fout << "\n"; // Пустий рядок як роздільник
    }

    fin.close();
    fout.close();
}

// ===== Задача 10.2 =====
void task102(const std::string& inputFile) {
    // 1) Зчитуємо весь текст із inputFile
    std::ifstream fin(inputFile.c_str());
    if (!fin) {
        std::cout << "Помилка: не вдалося відкрити файл для читання: " << inputFile << std::endl;
        return;
    }
    std::string allText;
    std::string line;
    while (std::getline(fin, line)) {
        allText += line + "\n";
    }
    fin.close();

    // 2) Транслітеруємо увесь текст згідно Постанови № 55
    std::string translitText;
    translitText.reserve(allText.size() * 2); // резервуємо трохи більше місця

    for (size_t i = 0; i < allText.size(); ++i) {
        unsigned char c = static_cast<unsigned char>(allText[i]);
        switch (c) {
            // ВЕЛИКІ УКРАЇНСЬКІ
            case 'А': translitText += "A";  break;
            case 'Б': translitText += "B";  break;
            case 'В': translitText += "V";  break;
            case 'Г': translitText += "H";  break;
            case 'Ґ': translitText += "G";  break;
            case 'Д': translitText += "D";  break;
            case 'Е': translitText += "E";  break;
            case 'Є': translitText += "YE"; break;
            case 'Ж': translitText += "ZH"; break;
            case 'З': translitText += "Z";  break;
            case 'И': translitText += "Y";  break;
            case 'І': translitText += "I";  break;
            case 'Ї': translitText += "YI"; break;
            case 'Й': translitText += "Y";  break;
            case 'К': translitText += "K";  break;
            case 'Л': translitText += "L";  break;
            case 'М': translitText += "M";  break;
            case 'Н': translitText += "N";  break;
            case 'О': translitText += "O";  break;
            case 'П': translitText += "P";  break;
            case 'Р': translitText += "R";  break;
            case 'С': translitText += "S";  break;
            case 'Т': translitText += "T";  break;
            case 'У': translitText += "U";  break;
            case 'Ф': translitText += "F";  break;
            case 'Х': translitText += "KH"; break;
            case 'Ц': translitText += "TS"; break;
            case 'Ч': translitText += "CH"; break;
            case 'Ш': translitText += "SH"; break;
            case 'Щ': translitText += "SHCH"; break;
            case 'Ю': translitText += "YU"; break;
            case 'Я': translitText += "YA"; break;

            // МАЛІ УКРАЇНСЬКІ
            case 'а': translitText += "a";  break;
            case 'б': translitText += "b";  break;
            case 'в': translitText += "v";  break;
            case 'г': translitText += "h";  break;
            case 'ґ': translitText += "g";  break;
            case 'д': translitText += "d";  break;
            case 'е': translitText += "e";  break;
            case 'є': translitText += "ye"; break;
            case 'ж': translitText += "zh"; break;
            case 'з': translitText += "z";  break;
            case 'и': translitText += "y";  break;
            case 'і': translitText += "i";  break;
            case 'ї': translitText += "yi"; break;
            case 'й': translitText += "y";  break;
            case 'к': translitText += "k";  break;
            case 'л': translitText += "l";  break;
            case 'м': translitText += "m";  break;
            case 'н': translitText += "n";  break;
            case 'о': translitText += "o";  break;
            case 'п': translitText += "p";  break;
            case 'р': translitText += "r";  break;
            case 'с': translitText += "s";  break;
            case 'т': translitText += "t";  break;
            case 'у': translitText += "u";  break;
            case 'ф': translitText += "f";  break;
            case 'х': translitText += "kh"; break;
            case 'ц': translitText += "ts"; break;
            case 'ч': translitText += "ch"; break;
            case 'ш': translitText += "sh"; break;
            case 'щ': translitText += "shch"; break;
            case 'ю': translitText += "yu"; break;
            case 'я': translitText += "ya"; break;

            default:
                // Інші символи (пробіли, пунктуація, цифри, латиниця) залишаємо без змін
                translitText += allText[i];
                break;
        }
    }

    // 3) Дописуємо у кінець inputFile транслітерований текст і дату
    std::ofstream fout(inputFile.c_str(), std::ios::app);
    if (!fout) {
        std::cout << "Помилка: не вдалося відкрити файл для допису: " << inputFile << std::endl;
        return;
    }
    fout << "\n===== Транслітерований текст =====\n";
    fout << translitText;
    fout << "\nДата допису: ";

    // Отримуємо сьогоднішню дату у форматі "ДД/ММ/РР"
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int day   = now->tm_mday;
    int month = now->tm_mon + 1;       // місяці йдуть від 0 до 11
    int year  = (now->tm_year % 100);  // дві останні цифри року

    if (day < 10)   fout << '0';
    fout << day << '/';
    if (month < 10) fout << '0';
    fout << month << '/';
    if (year < 10)  fout << '0';
    fout << year << "\n";

    fout.close();
}

// ===== Задача 10.3 =====
void task103(const std::string& inputFile, double x, double y, double z, int b) {
    // 1) Обчислюємо s = x + y + z
    double s = s_calculation(x, y, z);
    // 2) Перетворюємо b у двійковий рядок
    std::string bin = toBinary(b);

    // 3) Дописуємо результати у кінець inputFile
    std::ofstream fout(inputFile.c_str(), std::ios::app);
    if (!fout) {
        std::cout << "Помилка: не вдалося відкрити файл для допису: " << inputFile << std::endl;
        return;
    }
    fout << "\n===== Результати Задачі 10.3 =====\n";
    fout << "s_calculation(" << x << ", " << y << ", " << z << ") = " << s << "\n";
    fout << "Число b = " << b << " у двійковому: " << bin << "\n";
    fout.close();
}

// ===== Допоміжна функція s_calculation =====
double s_calculation(double x, double y, double z) {
    return x + y + z;
}

// ===== Перетворення натурального b у двійковий рядок =====
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
