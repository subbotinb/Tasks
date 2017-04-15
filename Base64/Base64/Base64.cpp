// Base64.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include "Base64Lib.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	uchar key;
	string str;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	while (true) {
		system("cls");
		cout << "— Нажмите букву \"E\", чтобы закодировать текст" << endl << "— Нажмите букву \"D\", чтобы декодировать текст" << endl << "— Нажмите букву \"Q\", чтобы выйти из программы" << endl;
		key = _getch();
		if (key == 'E' || key == 'e') {
			cout << "Введите строку для кодирования: " << endl;
			getline(cin, str);
			cout << "Исходная строка: " << str << " | Закодированная строка: " << Base64::encode(str) << endl;
		} else if (key == 'D' || key == 'd') {
			cout << "Введите строку для декодирования: " << endl;
			getline(cin, str);
			cout << "Исходная строка: " << str << " | Раскодированная строка: " << Base64::decode(str) << endl;
		} else if (key == 'Q' || key == 'q') {
			return 0;
		}
		cout << "Нажмите любую клавишу для продолжить..." << endl;
		_getch();
	}

	return 0;
}