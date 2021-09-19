// Sapper.h
#pragma once

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <ios>

template<typename T>
auto Create_array(size_t size, T** arr); // 

template<typename T>
auto Delete_array(size_t size, T** arr);

void EpilepsyTime(const char* text);  // Веселая загрузка игры 

void Create_GameField(size_t size, char** GameField, bool** HiddenField); // Создание игрового поля. Заполнение определенными символами

void SetMina(int mina, size_t size, char** GameField, bool** HiddenField); // Рандомизируем мины вокруг поля


void Display_GameField(size_t size, char** Field); // Отображение игрового поля
void Display_Mines (size_t size, bool** Mines); // Отображение игрового поля с минами

bool Impact(short vertical_coordinat, short horizontal_coordinat, char** GameField, bool** HiddenField);

void Delete_Game(size_t size, char** GameField, bool** HiddenField);



// Sapper.cpp

#include "Sapper.h"

template<typename T>
auto Create_array(size_t size, T** arr)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = new T[size];
	}
}

template<typename T>
auto Delete_array(size_t size, T** arr)
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;
}

void EpilepsyTime(const char* text) // Веселая загрузка игры 
{
	std::cout << std::setw(100) << std::setfill(' ') << text;
	
	Sleep(500);

	int disco_time = 0;
	for (int i = 0; i < 100; i++)
	{
		if (disco_time == 2)
		{
			system("color 10"); Sleep(50);
		}
		else if (disco_time == 4)
		{
			system("color 20"); Sleep(50);
		}
		else if (disco_time == 6)
		{
			system("color 30"); Sleep(50);
		}
		else if (disco_time == 8)
		{
			system("color 40"); Sleep(50);
		}
		else if (disco_time == 10)
		{
			system("color 50"); Sleep(50);
			std::cout << '.';
			disco_time = 0;
		}
		disco_time++;
	}

	std::cout << std::endl;
	system("color 0F");
}

void Create_GameField(size_t size, char** GameField, bool** HiddenField) // Создание игрового поля. Заполнение определенными символами
{
	Create_array(size, GameField);
	Create_array(size, HiddenField);

	char symbol = '*';

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			GameField[i][j] = symbol;
			HiddenField[i][j] = 0;
		}
	}
}

void SetMina(int mina, size_t size, char** GameField, bool** HiddenField) // Рандомизируем мины вокруг поля
{
	for (int i = 0; i < mina;)
	{
		int x = rand() % size; // случайные числа из диапазона 0 <-> size
		int y = rand() % size; // случайные числа из диапазона 0 <-> size

		if (!HiddenField[x][y])
		{
			HiddenField[x][y] = 1;
			i++;
		}
	}
}

void Display_GameField(size_t size, char** Field) // Отображение игрового поля
{
	char vertical_coordinates = 65; // Чтобы добавить горизонтальные координаты, например буква ('A', 'B'...)

	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

	std::cout << std::setw(75) << std::setfill(' ');
	for (int i = 0; i < size;) // Чтобы добавить горизонтальные координаты, например (1, 2, 3, 4...)
	{
		if (i > 8)
		{
			std::cout << i++ << "  "; 
		}
		else
		{
			std::cout << i++ << "   ";
		}
	}

	std::cout << '\n' << std::setw(212) << std::setfill('_') << " \n" << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << std::setw(70) << std::setfill(' ') << (char)(vertical_coordinates + i) << " |  ";
		for (int j = 0; j < size; j++)
		{
			std::cout << Field[i][j] << "   ";
		}
		std::cout << '\n';
	}
	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

}
void Display_Mines(size_t size, bool** Mines) // Отображение игрового поля с минами
{
	char vertical_coordinates = 65; // Чтобы добавить горизонтальные координаты, например буква ('A', 'B'...)

	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

	std::cout << std::setw(75) << std::setfill(' ');
	for (int i = 0; i < size;) // Чтобы добавить горизонтальные координаты, например (1, 2, 3, 4...)
	{
		if (i > 8)
		{
			std::cout << i++ << "  "; 
		}
		else
		{
			std::cout << i++ << "   ";
		}
	}

	std::cout << '\n' << std::setw(212) << std::setfill('_') << " \n" << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << std::setw(70) << std::setfill(' ') << (char)(vertical_coordinates + i) << " |  ";
		for (int j = 0; j < size; j++)
		{
			std::cout << Mines[i][j] << "   ";
		}
		std::cout << '\n';
	}
	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

}

bool Impact(short vertical_coordinat, short horizontal_coordinat, char** GameField, bool** HiddenField) // Воздействие на конкретную координату
{
	if (HiddenField[vertical_coordinat][horizontal_coordinat]) return false; // Вы задели мину
}

void Delete_Game(size_t size, char** GameField, bool** HiddenField)
{
	Delete_array(size, GameField);
	Delete_array(size, HiddenField);
}
