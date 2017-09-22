#pragma once
#include <ctime>
int field[4][4];
int step = 0;
int previousstep=0;
class MatrixFill
{
private:
	int steph;
public:
	
	
	
	MatrixFill()
	{
	}

	~MatrixFill()
	{
	}
	void vpravo()     
	{	
		steph=0;
		for (int i = 0; i < 4; i++) {
			for (int d = 0; d < 2; d++) {
				for (int s = 0; s < 3; s++) {
					vpravozm(i, steph);
				}
				for (int s = 0; s < 2; s++) {
					vpravoob(i, steph);
				}

			}
		}
		if (steph == 1) {step++;
		}

	};

	void vpravoob(int i, int& steph) {
		for (int n = 3; n > 0; n--)
		{
			if (field[i][n] == field[i][n - 1] && field[i][n] != 0)
			{
				field[i][n] = field[i][n] * 2;
				field[i][n - 1] = 0;
				steph = 1;
				
			}
		}
		
	}
		
	void vpravozm(int i, int& steph) {
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
		
	}
	void vlivo()
	{
		steph = 0;
		for (int i = 0; i < 4; i++) {
			for (int d = 0; d < 2; d++) {
				for (int s = 0; s < 3; s++) {
					vlivozm(i, steph);
				}
				for (int s = 0; s < 2; s++) {
					vlivoob(i, steph);
				}

			}
		}
		if (steph == 1) {
			step++;
		}

	};

	void vlivoob(int i, int& steph) {
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
	void vlivozm(int i, int& steph) {
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
					vverhzm(n, steph);
				}
				for (int s = 0; s < 2; s++) {
					vverhob(n, steph);
				}

			}
		}
		if (steph == 1) {
			step ++;
		}			
	};

	void vverhob(int n, int& steph) {
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
	void vverhzm(int n, int& steph) {
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
					vnyzzm(n, steph);
				}
				for (int s = 0; s < 2; s++) {
					vnyzob(n, steph);
				}

			}
		}
		if (steph == 1) {
			step++;
		}

	};
	void vnyzob(int n, int& steph) {
		for (int i = 3; i > 0; i--)
		{
			if (field[i][n] == field[i - 1][n] && field[i][n] != 0) {
				field[i][n] = field[i][n] * 2;
				field[i - 1][n] = 0;
				steph = 1;
			}

		}
	}
	void vnyzzm(int n, int& steph) {
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
				
			}

		}
		//step = 0;
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
		if (o != 0 && (previousstep<step || previousstep==0)){
			if (step > 40) {
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

		previousstep=step;
	};






};
