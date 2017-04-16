// Base64.cpp: ���������� ����� ����� ��� ����������� ����������.


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
		cout << "� ������� ����� \"E\", ����� ������������ �����" << endl << "� ������� ����� \"D\", ����� ������������ �����" << endl << "� ������� ����� \"Q\", ����� ����� �� ���������" << endl;
		key = _getch();
		if (key == 'E' || key == 'e') {
			cout << "������� ������ ��� �����������: " << endl;
			getline(cin, str);
			cout << "�������� ������: " << str << " | �������������� ������: " << Base64::encode(str) << endl;
		} else if (key == 'D' || key == 'd') {
			cout << "������� ������ ��� �������������: " << endl;
			getline(cin, str);
			cout << "�������� ������: " << str << " | ��������������� ������: " << Base64::decode(str) << endl;
		} else if (key == 'Q' || key == 'q') {
			return 0;
		}
		cout << "������� ����� ������� ��� ����������..." << endl;
		_getch();
	}

	return 0;
}