#include <iostream>    
#include <iomanip>    
#include <ios>    
#include <math.h>               

struct rectangle
{
	int Lenght;
	int Width;
	int Cordinat_A_x;
	int Cordinat_A_y;
	int Cordinat_B_x;
	int Cordinat_B_y;
	int Cordinat_C_x;
	int Cordinat_C_y;
	int Cordinat_D_x;
	int Cordinat_D_y;
};

rectangle* create_Rectangle(int Lenght, int Width, int Cordinat_A_x, int Cordinat_A_y)
{
	rectangle* specification = new rectangle;
	// A     B
	//
	// C     D

	specification->Lenght = Lenght;
	specification->Width = Width;

	specification->Cordinat_A_x = Cordinat_A_x;
	specification->Cordinat_A_y = Cordinat_A_y;

	specification->Cordinat_B_x = Cordinat_A_x + Lenght;
	specification->Cordinat_B_y = Cordinat_A_y;

	specification->Cordinat_C_x = Cordinat_A_x;
	specification->Cordinat_C_y = Cordinat_A_y - Width;

	specification->Cordinat_D_x = Cordinat_A_x + Lenght;
	specification->Cordinat_D_y = Cordinat_A_y - Width;

	return specification;
}

void print_Rectangle(rectangle& specification)
{
	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;
	std::cout << std::setw(72) << std::setfill(' ') << ' ' << "Length of rectangle => " << specification.Lenght << '\n';
	std::cout << std::setw(72) << std::setfill(' ') << ' ' << "Width of rectangle => " << specification.Width << '\n';
	std::cout << std::setw(69) << std::setfill(' ') << ' ' << "Coordinat of A (x, y) => (" << specification.Cordinat_A_x << "," << specification.Cordinat_A_y << ")\n";
	std::cout << std::setw(69) << std::setfill(' ') << ' ' << "Coordinat of B (x, y) => (" << specification.Cordinat_B_x << "," << specification.Cordinat_B_y << ")\n";
	std::cout << std::setw(69) << std::setfill(' ') << ' ' << "Coordinat of C (x, y) => (" << specification.Cordinat_C_x << "," << specification.Cordinat_C_y << ")\n";
	std::cout << std::setw(69) << std::setfill(' ') << ' ' << "Coordinat of D (x, y) => (" << specification.Cordinat_D_x << "," << specification.Cordinat_D_y << ")\n";
	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

	for (int i = 0; i < specification.Width; i++)
	{
		std::cout << std::setw(75) << std::setfill(' ') << ' ' << "* ";

		for (int j = 0; j < specification.Lenght - 2; j++)
		{
			if (i == 0 || i == specification.Width - 1)
			{
				std::cout << "* ";
			}
			else
			{
				std::cout << "  ";
			}
		}
		std::cout << '*' << std::endl;

	}

	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;
}
void MoveRectangle(rectangle*& picture, int Lenght, int Width, int X, int Y)
{
	picture = create_Rectangle(Lenght, Width, X, Y);
}
void ChangeRectangle(rectangle*& picture, int Lenght, int Width, int X, int Y)
{
	picture = create_Rectangle(Lenght, Width, X, Y);
}

struct coordinat
{
	int Cordinat_A_x;
	int Cordinat_A_y;
	int Cordinat_B_x;
	int Cordinat_B_y;
};

coordinat* create_coordinat(int Cordinat_A_x, int Cordinat_A_y, int Cordinat_B_x, int Cordinat_B_y)
{
	coordinat* specification = new coordinat;
	// A     B

	specification->Cordinat_A_x = Cordinat_A_x;
	specification->Cordinat_A_y = Cordinat_A_y;

	specification->Cordinat_B_x = Cordinat_B_x;
	specification->Cordinat_B_y = Cordinat_B_y;

	return specification;
}

double Lenght_A_B(coordinat& specification)
{
	return sqrt(pow((specification.Cordinat_B_x - specification.Cordinat_A_x), 2) + pow((specification.Cordinat_B_y - specification.Cordinat_A_y), 2));
}

void print_coordinat(coordinat& specification)
{
	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;
	std::cout << std::setw(68) << std::setfill(' ') << ' ' << "Coordinat of A (x, y) => (" << specification.Cordinat_A_x << "," << specification.Cordinat_A_y << ")\n";
	std::cout << std::setw(68) << std::setfill(' ') << ' ' << "Coordinat of B (x, y) => (" << specification.Cordinat_B_x << "," << specification.Cordinat_B_y << ")\n";
	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;
	std::cout << std::setw(76) << std::setfill(' ') << ' ' << "A *" << std::setw(Lenght_A_B(specification)) << std::setfill(' ') << ' ' << "* B \n";
	std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

}



int main()
{
	bool flag = true;
	do
	{
		int op;
		std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;
		std::cout << std::setw(88) << std::setfill(' ') << " Select Task:" << std::endl;
		std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

		std::cout << std::setw(73) << std::setfill(' ') << ' ' << " 1. Rectangle" << std::endl; // Rectangle 
		std::cout << std::setw(73) << std::setfill(' ') << ' ' << " 2. Coordinat" << std::endl; // Coordinat
		std::cout << std::setw(73) << std::setfill(' ') << ' ' << " 3. Fractions " << std::endl; // fractions  
		std::cout << std::setw(82) << std::setfill(' ') << " => "; std::cin >> op;
		std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;


		enum SelectTask
		{
			Exit = 0,
			Rectangle,
			Coordinat,
			fractions,
		};

		switch (op)
		{
		case Rectangle:
		{
			std::cout << std::setw(210) << std::setfill('#') << '#' << std::endl;
			std::cout << std::setw(210) << std::setfill('#') << '#' << std::endl << std::endl;
			std::cout << std::setw(78) << std::setfill(' ') << ' ' << "Rectangle" << std::endl << std::endl;
			std::cout << std::setw(210) << std::setfill('#') << '#' << std::endl;
			std::cout << std::setw(210) << std::setfill('#') << '#' << std::endl;
			std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;
			int Length;
			int Width;
			int X;
			int Y;

			int move_x = 0;
			int move_y = 0;
			std::cout << std::setw(72) << std::setfill(' ') << ' ' << "Length of rectangle => "; std::cin >> Length;
			std::cout << std::setw(72) << std::setfill(' ') << ' ' << "Width of rectangle => "; std::cin >> Width;
			std::cout << std::setw(72) << std::setfill(' ') << ' ' << "Coordinat of A (x) => "; std::cin >> X;
			std::cout << std::setw(72) << std::setfill(' ') << ' ' << "Coordinat of A (y) => "; std::cin >> Y;

			rectangle* picture = create_Rectangle(Length, Width, X, Y);

			enum SelectTask
			{
				Exit = 0,
				Move,
				Change,
			};

			do
			{
				print_Rectangle(*picture);

				int op;
				std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;
				std::cout << std::setw(88) << std::setfill(' ') << " Select Task:" << std::endl;
				std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

				std::cout << std::setw(76) << std::setfill(' ') << ' ' << " 1. Move" << std::endl; // Move 
				std::cout << std::setw(76) << std::setfill(' ') << ' ' << " 2. Change size" << std::endl; // Change
				std::cout << std::setw(76) << std::setfill(' ') << ' ' << " 0. Exit" << std::endl; // Exit

				std::cout << std::setw(82) << std::setfill(' ') << " => "; std::cin >> op;
				std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;


				switch (op)
				{
				case Move:
				{

					std::cout << std::setw(76) << std::setfill(' ') << ' ' << " Move X => "; std::cin >> move_x;
					std::cout << std::setw(76) << std::setfill(' ') << ' ' << " Move Y => "; std::cin >> move_y;
					MoveRectangle(picture, Length, Width, X + move_x, Y + move_y);
					break;
				}
				case Change:
				{
					std::cout << std::setw(72) << std::setfill(' ') << ' ' << " Change Length => "; std::cin >> Length;
					std::cout << std::setw(72) << std::setfill(' ') << ' ' << " Change Width => "; std::cin >> Width;
					ChangeRectangle(picture, Length, Width, X + move_x, Y + move_y);
					break;
				}
				case Exit:
				{
					flag = false;
					break;
				}
				default:
					std::cout << std::setw(88) << std::setfill(' ') << " Try again!" << std::endl;
				}
			} while (flag);
			flag = true;
			break;
		}
		case Coordinat:
		{
			std::cout << std::setw(210) << std::setfill('#') << '#' << std::endl;
			std::cout << std::setw(210) << std::setfill('#') << '#' << std::endl << std::endl;
			std::cout << std::setw(78) << std::setfill(' ') << ' ' << "Coordinat" << std::endl << std::endl;
			std::cout << std::setw(210) << std::setfill('#') << '#' << std::endl;
			std::cout << std::setw(210) << std::setfill('#') << '#' << std::endl;
			std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;

			int A_x;
			int A_y;
			int B_x;
			int B_y;

			int move_x = 0;
			int move_y = 0;
			std::cout << std::setw(72) << std::setfill(' ') << ' ' << "Coordinat of x1 => "; std::cin >> A_x;
			std::cout << std::setw(72) << std::setfill(' ') << ' ' << "Coordinat of y1 => "; std::cin >> A_y;
			std::cout << std::setw(72) << std::setfill(' ') << ' ' << "Coordinat of x2 => "; std::cin >> B_x;
			std::cout << std::setw(72) << std::setfill(' ') << ' ' << "Coordinat of y2 => "; std::cin >> B_y;
			if (A_x > B_x)
			{
				int help = A_x;
				A_x = B_x;
				B_x = help;
				help = A_y;
				A_y = B_y;
				B_y = help;
			}
			coordinat* picture = create_coordinat(A_x, A_y, B_x, B_y);
			print_coordinat(*picture);
			double distance = Lenght_A_B(*picture);
			std::cout << std::setw(76) << std::setfill(' ') << ' ' << "Distance => " << distance << "\n";

			break;
		}
		case fractions:
		{
			std::cout << std::setw(210) << std::setfill('#') << '#' << std::endl;
			std::cout << std::setw(210) << std::setfill('#') << '#' << std::endl << std::endl;
			std::cout << std::setw(78) << std::setfill(' ') << ' ' << "Fractions" << std::endl << std::endl;
			std::cout << std::setw(210) << std::setfill('#') << '#' << std::endl;
			std::cout << std::setw(210) << std::setfill('#') << '#' << std::endl;
			std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;
			break;
		}

		case Exit:
		{
			std::cout << std::setw(75) << std::setfill(' ') << ' ' << "Goodbye!" << std::endl;
			std::cout << std::setw(212) << std::setfill('_') << " \n" << std::endl;
			flag = false;
			break;
		}
		default:
			std::cout << std::setw(75) << std::setfill(' ') << ' ' << " Try again!" << std::endl;
		}
	} while (flag);
}