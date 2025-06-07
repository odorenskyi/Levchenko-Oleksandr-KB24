#ifndef MODULES_LEVCHENKO_H
#define MODULES_LEVCHENKO_H

#include <string>

// ===== Задача 10.1 =====
// Читає inputFile, створює outputFile і записує туди:
//   1) авторську інформацію (ім’я, прізвище, установа, місто, країна, рік розробки),
//   2) кількість ':' у кожному рядку з inputFile,
//   3) ті рядки, у яких відсутні всі голосні літери (укр.).
void task101(const std::string& inputFile, const std::string& outputFile);

// ===== Задача 10.2 =====
// Дописує в той же inputFile:
//   1) увесь текст, транслітерований згідно Постанови № 55,
//   2) поточну дату у форматі "ДД/ММ/РР".
void task102(const std::string& inputFile);

// ===== Задача 10.3 =====
// Дописує в той же inputFile:
//   1) результат виклику s_calculation(x, y, z),
//   2) натуральне число b у двійковому (строковому) вигляді.
void task103(const std::string& inputFile, double x, double y, double z, int b);

// ===== Допоміжні функції =====
// Просто повертає x + y + z .
double s_calculation(double x, double y, double z);

// Перетворює натуральне число b у рядок з двійковим поданням.
std::string toBinary(int b);

#endif // MODULES_LEVCHENKO_H
