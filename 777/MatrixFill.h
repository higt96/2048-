#pragma once
#include <ctime>
int field[4][4];
class MatrixFill
{
private:
	int steph;
public:
	int step = 0;
	
	
	MatrixFill()
	{
	}

	~MatrixFill()
	{
	}
	int vpravo()     
	{
		
		/*for (i = 0; i <4; i++) {			
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
		*/
		steph=0;
		int l=0;
		for (int i = 0; i < 4; i++) {
			for (int d = 0; d < 2; d++) {
				for (int s = 0; s < 3; s++) {
					l+=vpravozm(i);
				}
				for (int s = 0; s < 2; s++) {
					l+= vpravoob(i);
				}

			}
		}
		if (l > 1) {step=1;
		}
return step;
	};

	int vpravoob(int i) {
		for (int n = 3; n > 0; n--)
		{
			if (field[i][n] == field[i][n - 1] && field[i][n] != 0)
			{
				field[i][n] = field[i][n] * 2;
				field[i][n - 1] = 0;
				steph = 1;
				
			}
		}
		return steph;
	}
		
	int vpravozm(int i) {
		for (int n = 0; n < 3; n++)
		{
			if (field[i][n] != 0)
			{
				if (field[i][n + 1] == 0) {
					field[i][n + 1] = field[i][n];
					field[i][n] = 0;
					steph=1;
					
				}
			}
		}
		return steph;
	}
	void vlivo()
	{
		steph = 0;
		for (int i = 0; i < 4; i++) {
			for (int d = 0; d < 2; d++) {
				for (int s = 0; s < 3; s++) {
					vlivozm(i);
				}
				for (int s = 0; s < 2; s++) {
					vlivoob(i);
				}

			}
		}
		if (steph == 1) {
			step += 1;
		}

	};

	void vlivoob(int i) {
		for (int n = 0; n < 3; n++)
		{
			if (field[i][n] == field[i][n + 1] && field[i][n] != 0)				
			{
				field[i][n] = field[i][n] * 2;
				field[i][n + 1] = 0;
				steph = 1;
			}

		}
	};
	void vlivozm(int i) {
		for (int n = 3; n > 0; n--)			
		{
			if (field[i][n] != 0)
			{
				if (field[i][n - 1] == 0) {
					field[i][n - 1] = field[i][n];
					field[i][n] = 0;
					steph = 1;
				}
			}
		}
	};

	void vverh()
	{
		steph = 0;
		for (int n = 0; n <4; n++) {
			for (int d = 0; d < 2; d++) {
				for (int s = 0; s < 3; s++) {
					vverhzm(n);
				}
				for (int s = 0; s < 2; s++) {
					vverhob(n);
				}

			}
		}
		if (steph == 1) {
			step += 1;
		}			
	};

	void vverhob(int n) {
		for (int i = 0; i < 3; i++)  
		{
			if (field[i][n] == field[i + 1][n] && field[i][n] != 0)
			{
				field[i][n] = field[i][n] * 2;
				field[i + 1][n] = 0;
				steph = 1;
			}

		}
	}
	void vverhzm(int n) {
		for (int i = 3; i > 0; i--)
		{
			if (field[i][n] != 0)
			{
				if (field[i - 1][n] == 0) {
					field[i - 1][n] = field[i][n];
					field[i][n] = 0;
					steph = 1;
				}
			}
		}
	}

	void vnyz()
	{
		steph = 0;
		for (int n = 0; n <4; n++) {
			for (int d = 0; d < 2; d++) {
				for (int s = 0; s < 3; s++) {
					vnyzzm(n);
				}
				for (int s = 0; s < 2; s++) {
					vnyzob(n);
				}

			}
		}
		if (steph == 1) {
			step += 1;
		}

	};
	void vnyzob(int n) {
		for (int i = 3; i > 0; i--)
		{
			if (field[i][n] == field[i - 1][n] && field[i][n] != 0) {
				field[i][n] = field[i][n] * 2;
				field[i - 1][n] = 0;
				steph = 1;
			}

		}
	}
	void vnyzzm(int n) {
		for (int i = 0; i < 3; i++)
		{
			if (field[i][n] != 0)
			{
				if (field[i + 1][n] == 0) {
					field[i + 1][n] = field[i][n];
					field[i][n] = 0;
					steph = 1;
				}
			}
		}
	}

	void clearm() {
		for (int n = 0; n <4; n++) {  
			for (int i = 0; i < 4; i++) {
				field[i][n] = 0;
				step=0;
			}

		}
	};

	void randomfill() {
		int *r[16] = {};
		int o = 0;

		for (int n = 0; n <4; n++) {
			for (int i = 0; i < 4; i++) {  
				if (field[i][n] == 0) {
					r[o] = &field[i][n];  
					o++;
				}
			}
		}
		srand(time(NULL)+step);
		if (o != 0) {
			if (step >= 0) {
				int x = rand() % 2+1;
				if (x== 1) {
					*r[rand() % o] = 2;
				}
				else if (x == 2) {
					*r[rand() % o] = 4;
				}
			}
			else *r[rand() % o] = 2;
		}


	};






};
