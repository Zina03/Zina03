// Sapper.h

#pragma once

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <ios>

void EpilepsyTime(int language);

template<typename T>
auto Create_array(T** arr, size_t lenght);

void Create_GameField(char** GameField, bool** HiddenField, size_t size);

void SetMina(int mina, char** GameField, bool** HiddenField, size_t size);

void Show_GameField(char** GameField, size_t size);


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
auto Create_array(T** arr, size_t lenght)
{
	for (size_t i = 0; i < lenght; i++)
	{
		arr[i] = new T[lenght];
	}
}

void Create_GameField(char** GameField, bool** HiddenField, size_t size) // Создание Игрового поля. Заполнения определенными символами
{
	Create_array(GameField, size);
	Create_array(HiddenField, size);

	char symbol = '*';

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			GameField[i][j] = symbol;
			HiddenField[i][j] = false;
		}
	}
}

void SetMina(int mina, char** GameField, bool** HiddenField, size_t size) // Раставление мин в рандомном порядке
{
	for (int i = 0; i < mina; i++)
	{
		int x = rand() % size; // random numbers from diaposon 0 - size
		int y = rand() % size; // random numbers from diaposon 0 - size
		if (!HiddenField[x][y])
		{
			HiddenField[x][y] = 1;
		}
	}
}

void Show_GameField(char** GameField, size_t size) // Выводим на экран Игровое поле
{
	int horizontal_coordinates = 0;
	char vertical_coordinates = 65;

	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

	std::cout << std::setw(70) << std::setfill(' ') << ' ';
	for (int i = 0; i < size; i++)
	{
		if (i > 8)
		{
			std::cout << horizontal_coordinates++ << "  ";
		}
		else
		{
			std::cout << horizontal_coordinates++ << "   ";
		}
	}

	std::cout << '\n' << std::setw(212) << std::setfill('_') << " \n" << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << std::setw(65) << std::setfill(' ') << ' ' << vertical_coordinates++ << " |  ";
		for (int j = 0; j < size; j++)
		{
			std::cout << GameField[i][j] << "   ";
		}
		std::cout << '\n';
	}
	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

}
