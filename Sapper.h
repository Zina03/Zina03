// Sapper.h
#pragma once

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <ios>

template<typename T>
auto Create_array(size_t size, T** arr);

template<typename T>
auto Delete_array(size_t size, T** arr);

void EpilepsyTime(const char* text);  // Веселая загрузка игры 

void Wrong();  // Когда пользователь допустил ошибку при наборе текста

void Create_GameField(size_t size, char** GameField, char** MinaBoard, bool** HiddenField); // Создание игрового поля. Заполнение определенными символами

void SetMina(int mina, size_t size, char** MinaBoard, bool** HiddenField, short vertical_coordinat, short horizontal_coordinat); // Рандомизируем мины вокруг поля

bool Check_coordinats(size_t size, char& vertical_coordinat, short horizontal_coordinat); // Проверка координатов

void Display_GameField(size_t size, char** Field); // Отображение игрового поля
void Display_Mines(size_t size, bool** Mines); // Отображение игрового поля с минами

void MakeSpace(short vertical_coordinat, short horizontal_coordinat, size_t size, char** GameField, char** MinaBoard);
bool Impact(short vertical_coordinat, short horizontal_coordinat, size_t size, char** GameField, char** MinaBoard);

void Deleting_GameOptions(size_t size, char** GameField, char** MinaBoard, bool** HiddenField);


// Sapper.cpp

#include "Header.h"

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

void Wrong()
{
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
		{
			system("color 40"); Sleep(150);
		}
		else
		{
			system("color 0F"); Sleep(150);
		}
	}
}

void Create_GameField(size_t size, char** GameField, char** MinaBoard, bool** HiddenField) // Создание игрового поля. Заполнение определенными символами
{
	Create_array(size, GameField);
	Create_array(size, MinaBoard);
	Create_array(size, HiddenField);

	char symbol = 2;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			GameField[i][j] = symbol;
			MinaBoard[i][j] = '0';
			HiddenField[i][j] = 0;
		}
	}
}

void SetMina(int mina, size_t size, char** MinaBoard, bool** HiddenField, short vertical_coordinat, short horizontal_coordinat) // Рандомизируем мины вокруг поля
{
	HiddenField[vertical_coordinat][horizontal_coordinat] = 1;
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

	HiddenField[vertical_coordinat][horizontal_coordinat] = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (HiddenField[i][j] == 1)
			{
				MinaBoard[i][j] = '*';
			}
		}
	}

	short vertical = 0;
	short horizontal = 0;
	int count = 0;
	bool flag = true;
	// 
	{
		do
		{
			count = 0;
			if (!HiddenField[vertical][horizontal])
			{
				if (vertical == 0)
				{
					if (horizontal == 0)
					{
						count = HiddenField[vertical + 1][horizontal] + HiddenField[vertical][horizontal + 1] + HiddenField[vertical + 1][horizontal + 1];
					}
					else if (horizontal > 0 && horizontal < size - 1)
					{
						count = HiddenField[vertical][horizontal - 1] + HiddenField[vertical + 1][horizontal - 1] + HiddenField[vertical + 1][horizontal] + HiddenField[vertical][horizontal + 1] + HiddenField[vertical + 1][horizontal + 1];
					}
					else
					{
						count = HiddenField[vertical][horizontal - 1] + HiddenField[vertical + 1][horizontal - 1] + HiddenField[vertical + 1][horizontal];
					}
				}
				else if (vertical > 0 && vertical < size - 1)
				{
					if (horizontal == 0)
					{
						count = HiddenField[vertical - 1][horizontal] + HiddenField[vertical + 1][horizontal] + HiddenField[vertical - 1][horizontal + 1] + HiddenField[vertical][horizontal + 1] + HiddenField[vertical + 1][horizontal + 1];

					}
					else if (horizontal > 0 && horizontal < size - 1)

					{
						count = HiddenField[vertical - 1][horizontal - 1] + HiddenField[vertical - 1][horizontal] + HiddenField[vertical - 1][horizontal + 1] + HiddenField[vertical][horizontal - 1] + HiddenField[vertical][horizontal + 1] + HiddenField[vertical + 1][horizontal - 1] + HiddenField[vertical + 1][horizontal] + HiddenField[vertical + 1][horizontal + 1];
					}
					else
					{
						count = HiddenField[vertical - 1][horizontal - 1] + HiddenField[vertical - 1][horizontal] + HiddenField[vertical][horizontal - 1] + HiddenField[vertical + 1][horizontal - 1] + HiddenField[vertical + 1][horizontal];
					}
				}
				else
				{
					if (horizontal == 0)
					{
						count = HiddenField[vertical - 1][horizontal] + HiddenField[vertical - 1][horizontal + 1] + HiddenField[vertical][horizontal + 1];
					}
					else if (horizontal > 0 && horizontal < size - 1)
					{
						count = HiddenField[vertical - 1][horizontal - 1] + HiddenField[vertical - 1][horizontal] + HiddenField[vertical - 1][horizontal + 1] + HiddenField[vertical][horizontal - 1] + HiddenField[vertical][horizontal + 1];
					}
					else
					{
						count = HiddenField[vertical - 1][horizontal - 1] + HiddenField[vertical][horizontal - 1] + HiddenField[vertical - 1][horizontal];
					}
				}

				MinaBoard[vertical][horizontal] = char(count + 48);
			}

			horizontal++;

			if (horizontal == size && vertical + 1 == size)
			{
				flag = false;
			}

			if (horizontal == size)
			{
				horizontal = 0;
				vertical++;
			}
		} while (flag);
	}
}

bool Check_coordinats(size_t size, char& vertical_coordinat, short horizontal_coordinat) // Проверка координатов
{
	if (char(vertical_coordinat - 32) >= 65 && char(vertical_coordinat - 32) < (65 + size))
	{
		vertical_coordinat -= 32;
	}

	if (!(vertical_coordinat >= 65 && vertical_coordinat < (65 + size)))
	{
		return false;
	}

	if (!(horizontal_coordinat >= 0 && horizontal_coordinat < size))
	{
		return false;
	}
	return true;
}

void Display_GameField(size_t size, char** Field) // Отображение игрового поля
{
	char vertical_coordinates = 65; // Чтобы добавить вертикальные координаты, например буква ('A', 'B'...)

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

void MakeSpace(short vertical_coordinat, short horizontal_coordinat, size_t size, char** GameField, char** MinaBoard)
{
	if (vertical_coordinat == 0)
	{
		if (!horizontal_coordinat)
		{
			for (int i = vertical_coordinat; i > 0 && i < size; i++)
			{
				for (int j = horizontal_coordinat; j > 0 && j < size; j++)
				{
					if (MinaBoard[i][j] == '0')
					{
						GameField[i][j] = ' ';
					}
				}
			}
		}
		else
		{
			for (int i = vertical_coordinat; i > 0 && i < size; i++)
			{
				for (int j = horizontal_coordinat - 1; j > 0 && j < size; j++)
				{
					if (MinaBoard[i][j] == '0')
					{
						GameField[i][j] = ' ';
					}
				}
			}
		}
	}

	else
	{
		if (horizontal_coordinat == 0)
		{



			for (int i = vertical_coordinat - 1; i > 0 && i < size; i++)
			{
				for (int j = horizontal_coordinat; j > 0 && j < size; j++)
				{
					if (MinaBoard[i][j] == '0')
					{
						GameField[i][j] = ' ';
					}
				}
			}
		}
		else
		{
			for (int i = vertical_coordinat - 1; i > 0 && i < size; i++)
			{
				for (int j = horizontal_coordinat - 1; j > 0 && j < size; j++)
				{
					if (MinaBoard[i][j] == '0')
					{
						GameField[i][j] = ' ';
					}
				}
			}
		}

	}
}

bool Impact(short vertical_coordinat, short horizontal_coordinat, size_t size, char** GameField, char** MinaBoard) // Воздействие на конкретную координату
{
	if (MinaBoard[vertical_coordinat][horizontal_coordinat] == '*') return false; // Вы задели мину

	else if (MinaBoard[vertical_coordinat][horizontal_coordinat] == '0')
	{
		MakeSpace(vertical_coordinat, horizontal_coordinat, size, GameField, MinaBoard);
	}

	else
	{
		GameField[vertical_coordinat][horizontal_coordinat] = MinaBoard[vertical_coordinat][horizontal_coordinat];
	}

	return true;
}

void Deleting_GameOptions(size_t size, char** GameField, char** MinaBoard, bool** HiddenField)
{
	Delete_array(size, GameField);
	Delete_array(size, MinaBoard);
	Delete_array(size, HiddenField);
}
