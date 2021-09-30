#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <ios>

#include <cstdio>
#include <string>

#define FILENAME "Gamers.txt"
typedef FILE* stream;

struct user
{
	char* name;
	uint32_t points;
};

char* serialize_user(user& p);
user* create_user(const char* name, uint32_t age);
void print_user(user& p);
void delete_user(user* p);
bool write_person(user& p);
bool search_person(char* );
void append(user**& arr, size_t& len, user* value);
char* normalize_string(char* s);
user** read_persons(bool* success, size_t& len);

enum SelectLanguage
{
	Russian = 0,
	English,
};

enum SelectMode
{
	Easy = 1,
	Medium,
	Hard,
};

enum SelectSize
{
	Ten = 1,
	Fifteen,
	Twenty,
};

template<typename T>
auto Create_array(size_t, T**);

template<typename T>
auto Delete_array(size_t, T**);

void EpilepsyTime(const char*);  // Веселая загрузка игры 

void Wrong();  // Когда пользователь допустил ошибку при наборе текста

void Create_GameField(size_t, char**, char**, bool**); // Создание игрового поля. Заполнение определенными символами

void SetMina(int mina, size_t, char**, bool**, short, short); // Рандомизируем мины вокруг поля

bool Check_coordinats(size_t, char&, short); // Проверка координатов

void Display_GameField(size_t, char**); // Отображение игрового поля или же поля с минами для админа

void MakeVerticalSpace(short, short, size_t size, char**, char**);
void MakeHorizontalSpace(short, short, size_t size, char**, char**);
void MakeDiaqonalSpace(short, short, size_t size, char**, char**);

void MakeSpace(short, short, size_t size, char**, char**);
bool IsWinner(size_t, char**, char**);
bool Impact(short, short, size_t, char**, char**);

void Deleting_GameOptions(size_t, char**, char**, bool**);




