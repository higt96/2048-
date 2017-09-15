#pragma once
class MatrixFill
{
public:
	int field[4][4];
	int i,n;

	MatrixFill()
	{
	}

	~MatrixFill()
	{
	}
	void vnyz()
	{
		for (i = 3; i != 0; i--) {
			for (n = 3; i != 0; n--) {
				if (field[i][n]=0)
				{
					field[i][n] = field[i][n - 1];
					if (field[i][n - 2] = field[i][n - 3])
					{
						field[i][n-2] = field[i][n - 3];
						field[i][n - 3] = 0;
					}


				}
				else if (field[i][n] = field[i][n - 1])
				{
					field[i][n] = field[i][n - 1]*2;
					field[i][n - 1] = 0;
				}
				
				
			}
	};

 
};

