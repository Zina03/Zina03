// Sapper.h
#pragma once

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <ios>

void EpilepsyTime(int language);

template<typename T>
auto Create_array(size_t size, T** arr);

template<typename T>
auto Delete_array(size_t size, T** arr);

void Create_GameField(size_t size, char** GameField, bool** HiddenField);

void SetMina(int mina, size_t size, char** GameField, bool** HiddenField);

void Show_GameField(size_t size, bool** GameField);

void Delete_Game(size_t size, char** GameField, bool** HiddenField);


// Sapper.cpp

#include "Sapper.h"

void EpilepsyTime(int language) // Веселая загрузка игры 
{
	if (language)
	{
		std::cout << std::setw(86) << std::setfill(' ') << ' ' << "Loading.";
	}
	else
	{
		std::cout << std::setw(84) << std::setfill(' ') << ' ' << "Загрузка.";
	}
	Sleep(500);

	int disco_time = 0;
	for (int i = 0; i < 100; i++)
	{
		if (disco_time == 2)
		{
			system("color 10"); Sleep(10);
		}
		else if (disco_time == 4)
		{
			system("color 20"); Sleep(10);
		}
		else if (disco_time == 6)
		{
			system("color 30"); Sleep(10);
		}
		else if (disco_time == 8)
		{
			system("color 40"); Sleep(10);
		}
		else if (disco_time == 10)
		{
			system("color 50"); Sleep(10);
			std::cout << '.';
			disco_time = 0;
		}
		disco_time++;
	}

	std::cout << std::endl;
	system("color 0F");
}

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

void Create_GameField(size_t size, char** GameField, bool** HiddenField) // Создание Игрового поля. Заполнения определенными символами
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

void SetMina(int mina, size_t size, char** GameField, bool** HiddenField) // Раставление мин в рандомном порядке
{
	for (int i = 0; i < mina; i++)
	{
		int x = rand() % size; // random numbers from diaposon 0 <-> size
		int y = rand() % size; // random numbers from diaposon 0 <-> size
		if (!HiddenField[x][y])
		{
			HiddenField[x][y] = 1;
		}
	}
}

void Show_GameField(size_t size, bool** Field) // Выводим на экран Игровое поле
{
	char vertical_coordinates = 65;

	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

	std::cout << std::setw(70) << std::setfill(' ') << ' ';
	for (int i = 0; i < size;)
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
		std::cout << std::setw(65) << std::setfill(' ') << ' ' << (char)(vertical_coordinates + i) << " |  ";
		for (int j = 0; j < size; j++)
		{
			std::cout << Field[i][j] << "   ";
		}
		std::cout << '\n';
	}
	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

}

void Delete_Game(size_t size, char** GameField, bool** HiddenField)
{
	Delete_array(size, GameField);
	Delete_array(size, HiddenField);
}
