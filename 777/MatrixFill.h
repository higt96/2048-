#pragma once
#include <ctime>
class MatrixFill
{
public:
	int field[4][4];
	int i,n,s;

	MatrixFill()
	{
	}

	~MatrixFill()
	{
	}
	void vpravo()     //	При назатті вправо
	{
		for (i = 0; i <4; i++) {			//перебираєм стовбці матриці
			for (n = 3; n > 0; n--)       //перебираєм рядки матриці
			{
				if (field[i][n] == field[i][n - 1])  //Переше обєднання одинакових
				{
					field[i][n] = field[i][n] * 2;
					field[i][n - 1] = 0;
				}

			}
			for (s = 0; s < 3; s++)			// 3 проходи
			{
				for (n = 0; n < 3; n++)     //зсув цифр на пусті клітинки
				{
					if (field[i][n] != 0)
					{
						if (field[i][n + 1] == 0) {
							field[i][n + 1] = field[i][n];
							field[i][n] = 0;
						}
					}
				}
			}
			for (s = 0; s < 2; s++)			// 2 проходи
			{
				for (n = 3; n > 0; n--)   //друге обєднання одинакових
				{
					if (field[i][n] == field[i][n - 1])
					{
						field[i][n] = field[i][n] * 2;
						field[i][n - 1] = 0;
					}

				}
			}
			
		}

	};


	void vlivo()
	{
		for (i = 0; i <4; i++) {   
			for (n = 0; n < 3; n++)
			{
				if (field[i][n] == field[i][n + 1])				//обєднання
				{
					field[i][n] = field[i][n] * 2;
					field[i][n + 1] = 0;
				}

			}
				for (s = 0; s < 3; s++)	
				{
					for (n = 3; n > 0; n--)			//зсув
					{
						if (field[i][n] != 0)
						{
							if (field[i][n - 1] == 0) {
								field[i][n - 1] = field[i][n];
								field[i][n] = 0;
							}
						}
					}
				}
				for (s = 0; s < 2; s++)			// 2 проходи
				{
					for (n = 0; n < 3; n++)
					{
						if (field[i][n] == field[i][n + 1])				//обєднання
						{
							field[i][n] = field[i][n] * 2;
							field[i][n + 1] = 0;
						}

					}
				}
		}

	};

	void vverh()
	{
		for (n = 0; n <4; n++) {    //перебираєм стовбці
			for (i = 0; i < 3; i++)    //рядки в стовбці
			{
				if (field[i][n] == field[i+1][n])
				{
					field[i][n] = field[i][n] * 2;
					field[i+1][n] = 0;
				}

			}
			for (s = 0; s < 3; s++)
			{
				for (i = 3; i > 0; i--)
				{
					if (field[i][n] != 0)
					{
						if (field[i-1][n] == 0) {
							field[i-1][n] = field[i][n];
							field[i][n] = 0;
						}
					}
				}
			}
			for (s = 0; s < 2; s++)			// 2 проходи
			{
				for (i = 0; i < 3; i++)
				{
					if (field[i][n] == field[i + 1][n])
					{
						field[i][n] = field[i][n] * 2;
						field[i + 1][n] = 0;
					}

				}
			}
		}

	};


	void vnyz()     
	{
		for (n = 0; n <4; n++) {			
			for (i = 3; i > 0; i--)       
			{
				if (field[i][n] == field[i-1][n])  {
					field[i][n] = field[i][n] * 2;
					field[i-1][n] = 0;
				}

			}
			for (s = 0; s < 3; s++)			// 3 проходи
			{
				for (i = 0; i < 3; i++)
				{
					if (field[i][n] != 0)
					{
						if (field[i + 1][n] == 0) {
							field[i + 1][n] = field[i][n];
							field[i][n] = 0;
						}
					}
				}
			}
			for (s = 0; s < 2; s++)			// 2 проходи
			{
				for (i = 3; i > 0; i--)
				{
					if (field[i][n] == field[i - 1][n])
					{
						field[i][n] = field[i][n] * 2;
						field[i - 1][n] = 0;
					}

				}
			}
		}

	};
	void clearm() {
		for (n = 0; n <4; n++) {  //заповнення матриці нулями
			for (i = 0; i < 4; i++) {
				field[i][n]=0;
			}

	}
	};

	void randomfill() {  
		int *r[16] = {};
		int o=0;
		
		for (n = 0; n <4; n++) {
			for (i = 0; i < 4; i++) {   //пошук пустих клітинок
				if (field[i][n] == 0) {
					r[o]=&field[i][n];   //заповнення масиву з ссилками на пусті клітинки
					o++;
				}
			}
		}
		srand(time(NULL));
		*r[rand() % o + 0]=2;  //присвоєння рандомному пустому елементу двойки
		

	};

	
	


 
};

