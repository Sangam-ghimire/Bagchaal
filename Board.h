#pragma once

class Board {
public:
	static Board* s_pInstance;
	static Board* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Board();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void createBoard();
	void coordinate();

	void filtercoordinate();
	int filterX(int a);
	int filterY(int a);
	//R_X
	int getR_X() { return R_X; }
	int getR_Y() { return R_Y; };

	void setRX(int X) { R_X = X; }
	void setRY(int Y) { R_Y = Y; }

	//M_X
	int getM_X() { return M_X; }
	int getM_Y() { return M_Y; };

	void setMX(int X) { M_X = X; }
	void setMY(int Y) { M_Y = Y; }

	virtual void render();
private:
	int M_X;
	int M_Y;


	int R_X;
	int R_Y;


};
typedef Board TheBoard;