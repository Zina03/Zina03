#include "sapper.h"

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

	Sleep(1500);

	int disco_time = 0;
	for (int i = 0; i < 50; i++)
	{
		if (disco_time == 2)
		{
			system("color 10"); Sleep(100);
		}
		else if (disco_time == 4)
		{
			system("color 20"); Sleep(100);
		}
		else if (disco_time == 6)
		{
			system("color 30"); Sleep(100);
		}
		else if (disco_time == 8)
		{
			system("color 40"); Sleep(100);
		}
		else if (disco_time == 10)
		{
			system("color 50"); Sleep(100);
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

void Create_GameField(size_t size, char** Field, char** MinaBoard, bool** HiddenField) // Создание игрового поля. Заполнение определенными символами
{
	Create_array(size, Field);
	Create_array(size, MinaBoard);
	Create_array(size, HiddenField);

	char symbol = 2;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Field[i][j] = symbol;
			MinaBoard[i][j] = ' ';
			HiddenField[i][j] = 0;
		}
	}
}

void SetMina(int mina, size_t size, char** MinaBoard, bool** HiddenField, short vertical, short horizontal) // Рандомизируем мины вокруг поля
{
	HiddenField[vertical][horizontal] = 1;
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

	HiddenField[vertical][horizontal] = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (HiddenField[i][j] == 1)
			{
				MinaBoard[i][j] = 2;
			}
		}
	}

	vertical = 0;
	horizontal = 0;
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

bool Check_coordinats(size_t size, char& vertical, short horizontal) // Проверка координатов
{
	if (char(vertical - 32) >= 65 && char(vertical - 32) < (65 + size))
	{
		vertical -= 32;
	}

	if (!(vertical >= 65 && vertical < (65 + size)))
	{
		return false;
	}

	if (!(horizontal >= 0 && horizontal < size))
	{
		return false;
	}
	return true;
}

void Display_GameField(size_t size, char** Field) // Отображение игрового поля
{
	char vertical_coordinates = 65; // Чтобы добавить вертикальные координаты, например буква ('A', 'B'...)

	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

	std::cout << std::setw(69) << std::setfill(' ');
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
		std::cout << std::setw(62) << std::setfill(' ') << (char)(vertical_coordinates + i) << " |  ";
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

	std::cout << std::setw(69) << std::setfill(' ');
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
		std::cout << std::setw(62) << std::setfill(' ') << (char)(vertical_coordinates + i) << " |  ";
		for (int j = 0; j < size; j++)
		{
			std::cout << Mines[i][j] << "   ";
		}
		std::cout << '\n';
	}
	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

}

void MakeHorizontalSpace(short , short , size_t , char** , char** );

void MakeVerticalSpace(short vertical, short horizontal, size_t size, char** Field, char** MinaBoard)
{
	// Up

	for (int i = vertical; i >= 0; )
	{
		

		if (MinaBoard[i][horizontal] == '0')
		{
			Field[i][horizontal] = ' ';
			if (vertical - 1 >= 0)
			{
				if (MinaBoard[i][horizontal - 1] >= 49 && MinaBoard[i][horizontal - 1] <= 57)
				{
					Field[i][horizontal - 1] = MinaBoard[i][horizontal - 1];
				}
			}
			if (vertical + 1 < size)
			{
				if (MinaBoard[i][horizontal + 1] >= 49 && MinaBoard[i][horizontal + 1] <= 57)
				{
					Field[i][horizontal + 1] = MinaBoard[i][horizontal + 1];
				}
			}
			i--;
		}
		else if (MinaBoard[i][horizontal] >= 49 && MinaBoard[i][horizontal] <= 57)
		{
			Field[i][horizontal] = MinaBoard[i][horizontal];
			break;
		}
		
	}

	// Down

	for (int i = vertical; i < size; )
	{
		if (MinaBoard[i][horizontal] == '0')
		{
			Field[i][horizontal] = ' ';
			if (vertical - 1 >= 0)
			{
				if (MinaBoard[i][horizontal - 1] >= 49 && MinaBoard[i][horizontal - 1] <= 57)
				{
					Field[i][horizontal - 1] = MinaBoard[i][horizontal - 1];
				}

			}
			if (vertical + 1 < size)
			{
				if (MinaBoard[i][horizontal + 1] >= 49 && MinaBoard[i][horizontal + 1] <= 57)
				{
					Field[i][horizontal + 1] = MinaBoard[i][horizontal + 1];
				}

			}
			i++;
		}
		else if (MinaBoard[i][horizontal] >= 49 && MinaBoard[i][horizontal] <= 57)
		{
			Field[i][horizontal] = MinaBoard[i][horizontal];
			break;
		}

		
	}
}
void MakeHorizontalSpace(short vertical, short horizontal, size_t size, char** Field, char** MinaBoard)
{
	// Right

	for (int j = horizontal; j < size; )
	{
		
		if (MinaBoard[vertical][j] == '0')
		{
			Field[vertical][j] = ' ';

			if (vertical - 1 >= 0)
			{
				if (MinaBoard[vertical - 1][j] >= 49 && MinaBoard[vertical - 1][j] <= 57)
				{
					Field[vertical - 1][j] = MinaBoard[vertical - 1][j];
				}
			}
			if (vertical + 1 < size)
			{
				if (MinaBoard[vertical + 1][j] >= 49 && MinaBoard[vertical + 1][j] <= 57)
				{
					Field[vertical + 1][j] = MinaBoard[vertical + 1][j];
				}	
			}
			j++;
		}
		else if (MinaBoard[vertical][j] >= 49 && MinaBoard[vertical][j] <= 57)
		{
			Field[vertical][j] = MinaBoard[vertical][j];
			break;
		}

		
	}

	// Left

	for (int j = horizontal; j >= 0; )
	{
		
		if (MinaBoard[vertical][j] == '0')
		{
			Field[vertical][j] = ' ';
			if (vertical - 1 >= 0)
			{
				if (MinaBoard[vertical - 1][j] >= 49 && MinaBoard[vertical - 1][j] <= 57)
				{
					Field[vertical - 1][j] = MinaBoard[vertical - 1][j];
				}

			}
			if (vertical + 1 < size)
			{
				if (MinaBoard[vertical + 1][j] >= 49 && MinaBoard[vertical + 1][j] <= 57)
				{
					Field[vertical + 1][j] = MinaBoard[vertical + 1][j];
				}
			}

			j--;
		}
		else if (MinaBoard[vertical][j] >= 49 && MinaBoard[vertical][j] <= 57)
		{
			Field[vertical][j] = MinaBoard[vertical][j];
			break;
		}
		
	}
}
void MakeDiaqonalSpace(short vertical_coor, short horizontal_coor, size_t size, char** Field, char** MinaBoard)
{
	// Right diagonal

	for (int i = vertical_coor, j = horizontal_coor; i >= 0 && j < size;)
	{
		if (MinaBoard[i][j] == '0')
		{
			Field[i][j] = ' ';
			MakeVerticalSpace(i, j, size, Field, MinaBoard);
			MakeHorizontalSpace(i, j, size, Field, MinaBoard);
			i--;
			j++;
		}
		else if (MinaBoard[i][j] >= 49 && MinaBoard[i][j] <= 57)
		{
			Field[i][j] = MinaBoard[i][j];
			break;
		}
	}

	// Left diagonal

	for (int i = vertical_coor, j = horizontal_coor; i < size && j >= 0;)
	{
		if (MinaBoard[i][j] == '0')
		{
			Field[i][j] = ' ';
			MakeVerticalSpace(i, j, size, Field, MinaBoard);
			MakeHorizontalSpace(i, j, size, Field, MinaBoard);
			i++; j--;
		}
		else if (MinaBoard[i][j] >= 49 && MinaBoard[i][j] <= 57)
		{
			Field[i][j] = MinaBoard[i][j];
			break;
		}
	}

	for (int i = vertical_coor, j = horizontal_coor; i < size && j < size;)
	{
		if (MinaBoard[i][j] == '0')
		{
			Field[i][j] = ' ';
			MakeVerticalSpace(i, j, size, Field, MinaBoard);
			MakeHorizontalSpace(i, j, size, Field, MinaBoard);
			i++;
			j++;
		}
		else if (MinaBoard[i][j] >= 49 && MinaBoard[i][j] <= 57)
		{
			Field[i][j] = MinaBoard[i][j];
			break;
		}
	}

	for (int i = vertical_coor, j = horizontal_coor; i >= 0 && j >= 0;)
	{
		if (MinaBoard[i][j] == '0')
		{
			Field[i][j] = ' ';
			MakeVerticalSpace(i, j, size, Field, MinaBoard);
			MakeHorizontalSpace(i, j, size, Field, MinaBoard);
			i--;
			j--;
		}
		else if (MinaBoard[i][j] >= 49 && MinaBoard[i][j] <= 57)
		{
			Field[i][j] = MinaBoard[i][j];
			break;
		}
	}
}

void MakeSpace(short vertical, short horizontal, size_t size, char** Field, char** MinaBoard)
{
	MakeDiaqonalSpace(vertical, horizontal, size, Field, MinaBoard);
}

bool IsWinner(size_t size, char** Field, char** MinaBoard)
{
	bool win = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Field[i][j] == ' ')
			{
				Field[i][j] == '0';
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Field[i][j] != MinaBoard[i][j])
			{
				win = false;
				break;
			}
		}
	}


	return win;
}

bool Impact(short vertical, short horizontal, size_t size, char** Field, char** MinaBoard) // Воздействие на конкретную координату
{
	if (MinaBoard[vertical][horizontal] == 2) return false; // Вы задели мину

	else if (MinaBoard[vertical][horizontal] == '0')
	{
		MakeSpace(vertical, horizontal, size, Field, MinaBoard);
	}

	else
	{
		Field[vertical][horizontal] = MinaBoard[vertical][horizontal];
	}

	return true;
}

void Deleting_GameOptions(size_t size, char** Field, char** MinaBoard, bool** HiddenField)
{
	Delete_array(size, Field);
	Delete_array(size, MinaBoard);
	Delete_array(size, HiddenField);
}
