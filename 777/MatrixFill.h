#pragma once
#include <ctime>
int field[4][4];
class MatrixFill
{
public:
	
	int i, n, s;

	MatrixFill()
	{
	}

	~MatrixFill()
	{
	}
	void vpravo()     
	{
		for (i = 0; i <4; i++) {			
			for (n = 3; n > 0; n--)     
			{
				if (field[i][n] == field[i][n - 1] && field[i][n]!=0)  
				{
					field[i][n] = field[i][n] * 2;
					field[i][n - 1] = 0;
				}

			}
			for (s = 0; s < 3; s++)			
			{
				for (n = 0; n < 3; n++)     
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
			for (s = 0; s < 2; s++)			
			{
				for (n = 3; n > 0; n--)  
				{
					if (field[i][n] == field[i][n - 1] && field[i][n] != 0)
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
				if (field[i][n] == field[i][n + 1])				//îáºäíàííÿ
				{
					field[i][n] = field[i][n] * 2;
					field[i][n + 1] = 0;
				}

			}
			for (s = 0; s < 3; s++)
			{
				for (n = 3; n > 0; n--)			//çñóâ
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
			for (s = 0; s < 2; s++)			// 2 ïðîõîäè
			{
				for (n = 0; n < 3; n++)
				{
					if (field[i][n] == field[i][n + 1])				//îáºäíàííÿ
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
		for (n = 0; n <4; n++) {    //ïåðåáèðàºì ñòîâáö³
			for (i = 0; i < 3; i++)    //ðÿäêè â ñòîâáö³
			{
				if (field[i][n] == field[i + 1][n])
				{
					field[i][n] = field[i][n] * 2;
					field[i + 1][n] = 0;
				}

			}
			for (s = 0; s < 3; s++)
			{
				for (i = 3; i > 0; i--)
				{
					if (field[i][n] != 0)
					{
						if (field[i - 1][n] == 0) {
							field[i - 1][n] = field[i][n];
							field[i][n] = 0;
						}
					}
				}
			}
			for (s = 0; s < 2; s++)			// 2 ïðîõîäè
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
				if (field[i][n] == field[i - 1][n]) {
					field[i][n] = field[i][n] * 2;
					field[i - 1][n] = 0;
				}

			}
			for (s = 0; s < 3; s++)			// 3 ïðîõîäè
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
			for (s = 0; s < 2; s++)			// 2 ïðîõîäè
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
		for (n = 0; n <4; n++) {  //çàïîâíåííÿ ìàòðèö³ íóëÿìè
			for (i = 0; i < 4; i++) {
				field[i][n] = 0;
			}

		}
	};

	void randomfill() {
		int *r[16] = {};
		int o = 0;

		for (n = 0; n <4; n++) {
			for (i = 0; i < 4; i++) {   //ïîøóê ïóñòèõ êë³òèíîê
				if (field[i][n] == 0) {
					r[o] = &field[i][n];   //çàïîâíåííÿ ìàñèâó ç ññèëêàìè íà ïóñò³ êë³òèíêè
					o++;
				}
			}
		}
		srand(time(NULL));
		if(o!=0)
		*r[rand() % o + 0] = 2;  //ïðèñâîºííÿ ðàíäîìíîìó ïóñòîìó åëåìåíòó äâîéêè


	};






};
