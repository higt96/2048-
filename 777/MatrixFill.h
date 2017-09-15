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
	void vpravo()     //	��� ������ ������
	{
		for (i = 0; i <4; i++) {			//��������� ������� �������
			for (n = 3; n > 0; n--)       //��������� ����� �������
			{
				if (field[i][n] == field[i][n - 1])  //������ �������� ����������
				{
					field[i][n] = field[i][n] * 2;
					field[i][n - 1] = 0;
				}

			}
			for (s = 0; s < 3; s++)			// 3 �������
			{
				for (n = 0; n < 3; n++)     //���� ���� �� ���� �������
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
			for (s = 0; s < 2; s++)			// 2 �������
			{
				for (n = 3; n > 0; n--)   //����� �������� ����������
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
				if (field[i][n] == field[i][n + 1])				//��������
				{
					field[i][n] = field[i][n] * 2;
					field[i][n + 1] = 0;
				}

			}
				for (s = 0; s < 3; s++)	
				{
					for (n = 3; n > 0; n--)			//����
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
				for (s = 0; s < 2; s++)			// 2 �������
				{
					for (n = 0; n < 3; n++)
					{
						if (field[i][n] == field[i][n + 1])				//��������
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
		for (n = 0; n <4; n++) {    //��������� �������
			for (i = 0; i < 3; i++)    //����� � �������
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
			for (s = 0; s < 2; s++)			// 2 �������
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
			for (s = 0; s < 3; s++)			// 3 �������
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
			for (s = 0; s < 2; s++)			// 2 �������
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
		for (n = 0; n <4; n++) {  //���������� ������� ������
			for (i = 0; i < 4; i++) {
				field[i][n]=0;
			}

	}
	};

	void randomfill() {  
		int *r[16] = {};
		int o=0;
		
		for (n = 0; n <4; n++) {
			for (i = 0; i < 4; i++) {   //����� ������ �������
				if (field[i][n] == 0) {
					r[o]=&field[i][n];   //���������� ������ � �������� �� ���� �������
					o++;
				}
			}
		}
		srand(time(NULL));
		*r[rand() % o + 0]=2;  //��������� ���������� ������� �������� ������
		

	};

	
	


 
};

