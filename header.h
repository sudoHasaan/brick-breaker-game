#include "util.h"
class Food
{
	int x, y;
	int color = 0;
	int probability = 0;

public:
	void setX(int a)
	{
		x = a;
	}
	int getX()
	{
		return x;
	}
	void setY(int a)
	{
		y = a;
	}
	int getY()
	{
		return y;
	}
	void setColor(int c)
	{
		color = c;
	}
	int getColor()
	{
		return color;
	}
	void setProb(int p)
	{
		probability = p;
	}
	int getProb()
	{
		return probability;
	}
	void displayFood()
	{
		if (probability == 1)
		{
			if (color == 1)
			{
				DrawTriangle(x, y, x + 20, y, x + 10, y + 20, colors[GREEN]);
			}
			if (color == 2)
			{
				DrawSquare(x, y, 15, colors[DEEP_PINK]);
			}
			if (color == 3)
			{
				DrawCircle(x, y, 8, colors[BLUE]);
			}
			if (color == 4)
			{
				DrawRectangle(x, y, 25, 15, colors[RED]);
			}
			if (color == 5)
			{
				DrawCircle(x, y, 8, colors[ORANGE]);
			}
		}
	}
};
class Brick
{
	int x;
	int y;
	int lives;
	int color;
	int orig;
	int score = 0;
	int height;
	int width;

public:
	Food food;
	Brick(int x = 0, int y = 0, int l = 1, int c = 0) : x(x), y(y), lives(l), color(c)
	{
	}
	void operator+=(int a)
	{
		this->score += a;
	}
	void setX(int a)
	{
		x = a;
	}
	void setY(int b)
	{
		y = b;
	}
	void setLives(int l)
	{
		lives = l;
	}
	void setColor(int c)
	{
		color = c;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getLives()
	{
		return lives;
	}
	int getColor()
	{
		return color;
	}
	int getScore()
	{
		return score;
	}
	void setWidth(int w){
		width=w;
	}
	int getWidth(){
		return width;
	}
	void setHeight(int w){
		height=w;
	}
	int getHeight(){
		return height;
	}
	void setOrig(int w){
		orig=w;
	}
	int getOrig(){
		return orig;
	}
	void rectBricks()
	{
		if (lives != 0)
		{
			DrawRoundRect(x, y, width, height, colors[WHITE], 10);
			if (color == 1)
			{
				DrawRoundRect(x+1, y+1, width-2, height-2, colors[GREEN], 10);
			}
			if (color == 2)
			{
				DrawRoundRect(x+1, y+1, width-2, height-2, colors[DEEP_PINK], 10);
			}
			if (color == 3)
			{
				DrawRoundRect(x+1, y+1, width-2, height-2, colors[NAVY], 10);
			}
			if (color == 4)
			{
				DrawRoundRect(x+1, y+1, width-2, height-2, colors[RED], 10);
			}
			if (color == 5)
			{
				DrawRoundRect(x+1, y+1, width-2, height-2, colors[ORANGE], 10);
			}
		}
	}
};
class Paddle
{
protected:
	bool increase = false;
	bool decrease = false;
	int paddleX1;
	int paddleX2;
	int paddleY;
	int color=0;
	int length = 80;

public:
	void setPaddleX1(int x = 500)
	{
		paddleX1 = x;
	}
	int getPaddleX1()
	{
		return paddleX1;
	}
	void setPaddleX2(int x = 580)
	{
		paddleX2 = x;
	}
	int getPaddleX2()
	{
		return paddleX2;
	}
	int getPaddleY()
	{
		return paddleY;
	}
	void setColor(int c)
	{
		color = c;
	}
	int getColor()
	{
		return color;
	}
	void setIncrease(bool f)
	{
		increase = f;
	}
	bool getIncrease()
	{
		return increase;
	}
	void setDecrease(bool f)
	{
		decrease = f;
	}
	bool getDecrease()
	{
		return decrease;
	}
	void setLength(int l)
	{
		length = l;
	}
	int getLength()
	{
		return length;
	}
	void setPaddleY(int a){
		paddleY=a;
	}
	void displayPaddle()
	{
		if (color == 0)
		{
			DrawRectangle(paddleX1, paddleY, length, 10, colors[BLUE]);
		}
		if (color == 1)
		{
			DrawRectangle(paddleX1, paddleY, length, 10, colors[GREEN]);
		}
		if (color == 2)
		{
			DrawRectangle(paddleX1, paddleY, length, 10, colors[DEEP_PINK]);
		}
		if (color == 3)
		{
			DrawRectangle(paddleX1, paddleY, length, 10, colors[NAVY]);
		}
		if (color == 4)
		{
			DrawRectangle(paddleX1, paddleY, length, 10, colors[RED]);
		}
		if (color == 5)
		{
			DrawRectangle(paddleX1, paddleY, length, 10, colors[ORANGE]);
		}
	}
};
class Ball
{
	int x = 500, y = 220;
	int color = 0;
	int lives = 1;
	bool slow = false;
	bool fast = false;
	bool flag1 = true, flag2 = false, flag3 = true;
	int width = 500;
	int height = 220;
	int cal = 2;
	int radius=10;
public:
	void setX(int a)
	{
		x = a;
	}
	int getX()
	{
		return x;
	}
	void setY(int a)
	{
		y = a;
	}
	int getY()
	{
		return y;
	}
	void setColor(int c)
	{
		color = c;
	}
	int getColor()
	{
		return color;
	}
	void setLives(int l)
	{
		lives = l;
	}
	int getLives()
	{
		return lives;
	}
	void setSlow(bool f)
	{
		slow = f;
	}
	bool getSlow()
	{
		return slow;
	}
	void setFast(bool f)
	{
		fast = f;
	}
	bool getFast()
	{
		return fast;
	}
	void setFlag1(bool f)
	{
		flag1 = f;
	}
	bool getFlag1()
	{
		return flag1;
	}
	void setFlag2(bool f)
	{
		flag2 = f;
	}
	bool getFlag2()
	{
		return flag2;
	}
	void setFlag3(bool f)
	{
		flag3 = f;
	}
	bool getFlag3()
	{
		return flag3;
	}
	void setW(int w)
	{
		width = w;
	}
	int getW()
	{
		return width;
	}
	void setH(int w)
	{
		height = w;
	}
	int getH()
	{
		return height;
	}
	void setCal(int w)
	{
		cal = w;
	}
	int getCal()
	{
		return cal;
	}
	int getRadius(){
		return radius;
	}
	void displayBall()
	{
		if (color == 0)
		{
			DrawCircle(x, y, radius, colors[BLUE]);
			DrawString(20, 30, "LIVES: ", colors[BLUE]);
			for (int i = 0, j = 120, k = 38; i < lives; i++, j += 30)
			{
				DrawCircle(j, k, 10, colors[BLUE]);
			}
		}
		if (color == 1)
		{
			DrawCircle(x, y, radius, colors[GREEN]);
			DrawString(20, 30, "LIVES: ", colors[GREEN]);
			for (int i = 0, j = 120, k = 38; i < lives; i++, j += 30)
			{
				DrawCircle(j, k, 10, colors[GREEN]);
			}
		}
		if (color == 2)
		{
			DrawCircle(x, y, radius, colors[DEEP_PINK]);
			DrawString(20, 30, "LIVES: ", colors[DEEP_PINK]);
			for (int i = 0, j = 120, k = 38; i < lives; i++, j += 30)
			{
				DrawCircle(j, k, 10, colors[DEEP_PINK]);
			}
		}
		if (color == 3)
		{
			DrawCircle(x, y, radius, colors[NAVY]);
			DrawString(20, 30, "LIVES: ", colors[NAVY]);
			for (int i = 0, j = 120, k = 38; i < lives; i++, j += 30)
			{
				DrawCircle(j, k, 10, colors[NAVY]);
			}
		}
		if (color == 4)
		{
			DrawCircle(x, y, radius, colors[RED]);
			DrawString(20, 30, "LIVES: ", colors[RED]);
			for (int i = 0, j = 120, k = 38; i < lives; i++, j += 30)
			{
				DrawCircle(j, k, 10, colors[RED]);
			}
		}
		if (color == 5)
		{
			DrawCircle(x, y, radius, colors[ORANGE]);
			DrawString(20, 30, "LIVES: ", colors[ORANGE]);
			for (int i = 0, j = 120, k = 38; i < lives; i++, j += 30)
			{
				DrawCircle(j, k, 10, colors[ORANGE]);
			}
		}
	}
};
class Stages {
	public:
	virtual void createStage(Brick *&brick) {}
};

class Stage1: public Stages {
	public:
	void createStage(Brick *&brick) {
		static int m = 0;
		if (m == 0)
		{
			int a = 0;
			for (int i = 730; i > 580; i -= 30)
			{
				for (int j = 5; j < 1000; j += 101)
				{
					brick[a].setWidth(95);
					brick[a].setHeight(25);
					brick[a].setX(j);
					brick[a].setY(i);
					int m = rand() % 5 + 1;
					if (m == 1)
					{
						// setting bricks
						brick[a].setLives(1);
						brick[a].setColor(1);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 2)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(2);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 3)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(3);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 4)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(4);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 5)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(5);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					a++;
				}
			}
		}
		m++;
	}
};
class Stage2: public Stages {
	public:
	void createStage(Brick *&brick) {
		static int m = 0;
		if (m == 0)
		{
			
			int a = 0;
			int j=5,k=1;
			int orig=5,n=1;
			for (int i = 730; i >= 490;n++,i-=30)
			{	
				if(n==1 || n==4 || n==7){
					orig=j;
				}
				for (; j <106*k*2 && j<1000;j += 101)
				{	
					brick[a].setWidth(95);
					brick[a].setHeight(25);
					brick[a].setX(j);
					brick[a].setY(i);
					int m = rand() % 5 + 1;
					if (m == 1)
					{
						// setting bricks
						brick[a].setLives(1);
						brick[a].setColor(1);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 2)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(2);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 3)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(3);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 4)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(4);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 5)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(5);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					a++;
					
				}
				if(n%3!=0){
					j=orig;
				}
				else{
					k+=2;
				}
			}
			k=1;
			j=5;
			n=1;
			for(int i=300;i<490;i+=30,n++){
				if(n==1 || n==4){
					orig=j;
				}
				for (; j <106*k*2 && j<712;j += 101)
				{	
					brick[a].setWidth(95);
					brick[a].setHeight(25);
					brick[a].setX(j);
					brick[a].setY(i);
					int m = rand() % 5 + 1;
					if (m == 1)
					{
						// setting bricks
						brick[a].setLives(1);
						brick[a].setColor(1);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 2)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(2);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 3)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(3);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 4)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(4);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 5)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(5);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					a++;
				}
				if(n%3!=0){
					j=orig;
				}
				else{
					k+=2;
				}
			}
		}
		m++;
	}
};
class Stage3: public Stages {
	public:
	void createStage(Brick *&brick) {
		static int m = 0;
		if (m == 0)
		{
			int a = 0;
			int k=1000;
			int l=560;
			for (int i = 600; i >= 450;i-=30,k-=90)
			{	if(a>11){
					l+=90;
				}
				for (int j=20;j<k-500;j+=90)
				{	
					brick[a].setWidth(85);
					brick[a].setHeight(25);
					brick[a].setX(j);
					brick[a].setY(i);
					int m = rand() % 5 + 1;
					if (m == 1)
					{
						// setting bricks
						brick[a].setLives(1);
						brick[a].setColor(1);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 2)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(2);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 3)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(3);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 4)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(4);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 5)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(5);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					a++;
					
				}
				for(int j=l;j<1000;j+=90){
					brick[a].setWidth(85);
					brick[a].setHeight(25);
					brick[a].setX(j);
					brick[a].setY(i);
					int m = rand() % 5 + 1;
					if (m == 1)
					{
						// setting bricks
						brick[a].setLives(1);
						brick[a].setColor(1);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 2)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(2);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 3)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(3);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 4)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(4);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 5)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(5);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					a++;
				}
			}
			k=110;
			l=830;
			for(int i=420,y=0;i>=300;i-=30,k+=90,l-=90,y++){
				for (int j=20;j<=k;j+=90){	
					brick[a].setWidth(85);
					brick[a].setHeight(25);
					brick[a].setX(j);
					brick[a].setY(i);
					int m = rand() % 5 + 1;
					if (m == 1)
					{
						// setting bricks
						brick[a].setLives(1);
						brick[a].setColor(1);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 2)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(2);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 3)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(3);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 4)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(4);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 5)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(5);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					a++;
					
				}
				for(int j=l;j<1000;j+=90){
					brick[a].setWidth(85);
					brick[a].setHeight(25);
					brick[a].setX(j);
					brick[a].setY(i);
					int m = rand() % 5 + 1;
					if (m == 1)
					{
						// setting bricks
						brick[a].setLives(1);
						brick[a].setColor(1);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 2)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(2);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 3)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(3);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 4)
					{
						// setting bricks
						brick[a].setLives(3);
						brick[a].setColor(4);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					if (m == 5)
					{
						// setting bricks
						brick[a].setLives(2);
						brick[a].setColor(5);
						brick[a].setOrig(m);
						// setting food in bricks
						int n = rand() % 5 + 1;
						brick[a].food.setColor(n);
						brick[a].food.setX(j + 20);
						brick[a].food.setY(i);
					}
					a++;
				}

			}
		}
		m++;
	}
};
class Game : public Paddle
{
public:
	int total;
	int balls = 1,level=0,x=0,y=1;
	bool gameOver = false, win = false,pause=false;
	Brick* brick;
	Ball ball[3];
	Food* food;;
	bool add=false;
	Stages* stage;
	Paddle paddle[2];
	int numP;
	int highScore;
	//-------------------------------------------------------
	//-------------------------------------------------------
	Game() {	
		total=0;
		brick=nullptr;
		stage = nullptr;
		food=nullptr;
	}
	void setMemory(){
		if (level==1) {
			total=50;
			brick=new Brick[total];
			numP=1;
			paddle[0].setPaddleY(150);
			stage = new Stage1();
			food=new Food[total];
		}
		else if (level==2) {
			total=51;
			brick=new Brick[total];
			stage=new Stage2();
			numP=1;
			paddle[0].setPaddleY(150);
			food=new Food[total];
		}
		else if (level==3) {
			stage =new Stage3();
			total=81;
			brick=new Brick[total];
			stage=new Stage3();
			numP=2;
			food=new Food[total];
			paddle[0].setPaddleY(50);
			paddle[1].setPaddleY(750);
			paddle[1].setPaddleX1(730);
		}
	}
	//Destructor
	~Game(){
		delete[] brick;
		delete [] food;
		//delete [] paddle;
	}
	// making a function to convert int to string
	string convString(int num)
	{
		string result;
		// Special case for 0
		if (num == 0)
		{
			return "0";
		}
		while (num > 0)
		{
			char digit = '0' + (num % 10);
			result = digit + result;
			num /= 10;
		}
		return result;
	}
	int lengthstr(string a){
		int b=0;
		for(int i=0;a[i]!='\0';i++){
			b++;
		}
		return b;
	}
	int convInt(string a){
		int result=0;
		for(int i=0;i<lengthstr(a);i++){
			int dig=a[i]-'0';
			result=result*10+dig;
		}
		return result;
	}
	//-------------------------------------------------------
	//-------------------------------------------------------
	// function to assign values to bricks obj array and assign power food to bricks
	//-------------------------------------------------------
	// Function to detect ball collisions with bricks and Setting probability of power food
	void collisionBricks()
	{
		for (int b = 0; b < balls; b++)
		{
			for (int i = 0; i < total; i++)
			{
				if (brick[i].getLives() != 0)
				{	bool flag = false;
					if ((ball[b].getY() + ball[b].getRadius() >= brick[i].getY()) && (ball[b].getY() - ball[b].getRadius() <= brick[i].getY() + brick[i].getHeight())) {
						if ((ball[b].getX() >= brick[i].getX()) && (ball[b].getX() <= brick[i].getX() + brick[i].getWidth())) {
							if (ball[b].getY() + ball[b].getRadius() >= brick[i].getY() + brick[i].getHeight() / 2) {
								flag=true;
								//cout<<"Collission 1\n";
							} else {
								//cout<<"Collission 2\n";
								flag=true;
							}
						}
					}
					if ((ball[b].getY() + ball[b].getRadius() >= brick[i].getY()-3) && (ball[b].getY() + ball[b].getRadius() <= brick[i].getY() + brick[i].getHeight())) {
						if ((ball[b].getX() >= brick[i].getX()-3) && (ball[b].getX() <= brick[i].getX() + brick[i].getWidth()+2)) {
							// Ball is within the vertical boundaries of the brick
							if ((ball[b].getX() + ball[b].getRadius()) <= (brick[i].getX()+3)) {
								// Ball hits the left side of the brick
								//cout<<"Collission 3\n";
								flag=true;
								break;
							} 
							else if ((ball[b].getX() + ball[b].getRadius()) >= (brick[i].getX() + brick[i].getWidth()+3)) {
								// Ball hits the right side of the brick
								//cout<<"Collission 4\n";
								flag=true;
								break;
							}
						}
					}
					if(flag)
					{

						brick[i].setLives(brick[i].getLives() - 1);
						if(b==0)
							ball[b].setColor(brick[i].getColor());
						if(brick[i].getLives()==1){
							brick[i].setColor(1);
						}
						else if(brick[i].getLives()==2){
							brick[i].setColor(2);
						}
						if (brick[i].getLives() == 0)
						{
							int n = rand() % 5 + 1;
							brick[i].food.setProb(n);
							if (brick[i].getOrig() == 1)
							{

								brick[0] += 5;
							}
							if (brick[i].getOrig() == 2)
							{
								brick[0] += 10;
							}
							if (brick[i].getOrig() == 3)
							{
								brick[0] += 15;
							}
							if (brick[i].getOrig() == 4)
							{
								brick[0] += 15;
							}
							if (brick[i].getOrig() == 5)
							{
								brick[0] += 10;
							}
						}
					}
				}
			}
		}
	}
	//-------------------------------------------------------
	//-------------------------------------------------------
	// Function to detect collision with power food
	void collisionPower()
	{
		for(int p=0;p<numP;p++){

			for (int i = 0; i < total; i++)
			{
				if (brick[i].food.getProb() == 1)
				{
					if ((brick[i].food.getY() <= paddle[p].getPaddleY()+20 && brick[i].food.getY() >= paddle[p].getPaddleY()+10) && (brick[i].food.getX() >= paddle[p].getPaddleX1() - 3 && brick[i].food.getX() <= paddle[p].getPaddleX2() + 3))
					{
						brick[i].food.setProb(0);
						if (brick[i].food.getColor() == 1)
						{
							paddle[p].setIncrease(true);
							paddle[p].setDecrease(false);
						}
						if (brick[i].food.getColor() == 2)
						{
							paddle[p].setIncrease(false);
							paddle[p].setDecrease(true);
						}
						if (brick[i].food.getColor() == 3)
						{
							for (int b = 0; b < balls; b++)
							{
								ball[b].setSlow(true);
								ball[b].setFast(false);
							}
						}
						if (brick[i].food.getColor() == 4)
						{
							for (int b = 0; b < balls; b++)
							{
								ball[b].setSlow(false);
								ball[b].setFast(true);
							}
						}
						if (brick[i].food.getColor() == 5)
						{
							add=true;	
						}
					}
				}
			}
		}
	}
	//-------------------------------------------------------
	//-------------------------------------------------------
	// function to check game over
	void checkOver()
	{
		bool flag = true;
		for (int i = 0; i < total; i++)
		{
			if (brick[i].getLives() != 0)
			{
				flag = false;
				break;
			}
		}
		win=flag;
		if (!win)
		{
			if (ball[0].getLives() == 0)
			{
				gameOver = true;
			}
		}
	}
	//------------------------------------------------------------------
	//------------------------------------------------------------------
	//------------------------------------------------------------------
	// main display function
	void gameDisplay()
	{
		static int d=0;
		if(d==0){
			setMemory();
		}
		d++;
		srand(time(0));
		// canvas boundary
		DrawLine(0, 772, 1020, 772, 10, colors[MAROON]);
		DrawLine(0, 0, 1020, 0, 10, colors[MAROON]);
		DrawLine(0, 0, 0, 840, 10, colors[MAROON]);
		DrawLine(1020, 0, 1020, 840, 10, colors[MAROON]);
		DrawLine(0, 840, 1020, 840, 10, colors[MAROON]);
		// Score Display
		DrawString(30, 800, "Score: " + convString(brick[0].getScore()), colors[WHITE]);
		DrawString(300, 800, "Muhammad Hasaan(23i-0094)", colors[WHITE]);
		DrawString(780, 800, "High Score: "+convString(highScore), colors[WHITE]);
		// Paddle Display
		for(int p=0;p<numP;p++){
			paddle[p].displayPaddle();

		}
		//Setting ball lives
		static int s=0,c=0;
		if(s==0){
			ball[0].setLives(2);
			ball[2].setFlag1(false);
			ball[2].setFlag2(true);
		}
		s++;
		//adding a ball
		if(add){
			if(c<300){
				balls=3;
				
			}
			else{
				balls=1;
				c=0;
				add=false;
				for(int i=1;i<3;i++){
					ball[i].setCal(2);
					ball[i].setH(220);
					ball[i].setW(500);
					ball[i].setFlag3(true);
					ball[i].setLives(1);
					if(i==1){
						ball[i].setFlag1(true);
						ball[i].setFlag2(false);
					}
					else{
						ball[i].setFlag1(false);
						ball[i].setFlag2(true);
					}
				}

			}
			c++;
		}
		// ball Display
		for (int i = 0; i < balls; i++)
		{
			if(ball[i].getLives()>0){
				ball[i].displayBall();
			}
		}
		// Brickes and Power food Assignment
		stage->createStage(brick);
		// Displaying Bricks and Power
		for (int i = 0; i < total; i++)
		{
			brick[i].rectBricks();
			brick[i].food.displayFood();
		}
		// Detecting ball and Bricks collisions and Power Foods
		collisionBricks();
		// Detecting Power foods
		collisionPower();
		// Game End checking
		checkOver();
	}
	//------------------------------------------------------------------
	//------------------------------------------------------------------
	//Function for ball Movements
	void ballMovements()
	{
		
		for (int b = 0; b < balls; b++)
		{
			ball[b].setY(ball[b].getH());
			ball[b].setX(ball[b].getW());
			if (ball[b].getX() > 1000)
			{
				ball[b].setFlag1(false);
				ball[b].setFlag2(true);
			}
			if (ball[b].getX() < 20)
			{
				ball[b].setFlag2(false);
				ball[b].setFlag1(true);
			}
			if (ball[b].getY() >= 760)
			{
				if(level!=3){
					ball[b].setFlag3(false);
				}
			}
			for(int p=0;p<numP;p++){
				if ((p==0 && ball[b].getY() <= paddle[p].getPaddleY()+20  && ball[b].getY() >= paddle[p].getPaddleY()+10))
				{ // paddle height

					if (ball[b].getX() >= paddle[p].getPaddleX1() - 5)
					{ // paddle x1
						if (ball[b].getX() <= paddle[p].getPaddleX2() + 5)
						{ // paddle x2
							paddle[p].setColor(ball[b].getColor());
							ball[b].setCal(ball[b].getX() - paddle[p].getPaddleX1());
							ball[b].setCal(ball[b].getCal() - (paddle[p].getLength() / 2));
							if (ball[b].getCal() < 0)
							{
								ball[b].setCal(ball[b].getCal() * -1);
								ball[b].setFlag1(false);
								ball[b].setFlag2(true);decrease=true;
								increase=false;
							}
							else
							{
								ball[b].setFlag1(true);
								ball[b].setFlag2(false);
							}
							if (paddle[p].getLength() == 80)
								ball[b].setCal(ball[b].getCal() / 5);
							if (paddle[p].getLength() == 40)
								ball[b].setCal(ball[b].getCal() / 2);
							if (paddle[p].getLength() == 160)
								ball[b].setCal(ball[b].getCal() / 10);
							ball[b].setFlag3(true);
						}
					}
				}
				else if ((p==1 && ball[b].getY() >= paddle[p].getPaddleY()-20  && ball[b].getY() <= paddle[p].getPaddleY()+10))
				{ // paddle height

					if (ball[b].getX() >= paddle[p].getPaddleX1() - 5)
					{ // paddle x1
						if (ball[b].getX() <= paddle[p].getPaddleX2() + 5)
						{ // paddle x2
							paddle[p].setColor(ball[b].getColor());
							ball[b].setCal(ball[b].getX() - paddle[p].getPaddleX1());
							ball[b].setCal(ball[b].getCal() - (paddle[p].getLength() / 2));
							if (ball[b].getCal() < 0)
							{
								ball[b].setCal(ball[b].getCal() * -1);
								ball[b].setFlag1(false);
								ball[b].setFlag2(true);decrease=true;
								increase=false;
							}
							else
							{
								ball[b].setFlag1(true);
								ball[b].setFlag2(false);
							}
							if (paddle[p].getLength() == 80)
								ball[b].setCal(ball[b].getCal() / 5);
							if (paddle[p].getLength() == 40)
								ball[b].setCal(ball[b].getCal() / 2);
							if (paddle[p].getLength() == 160)
								ball[b].setCal(ball[b].getCal() / 10);
							ball[b].setFlag3(false);
						}
					}
				}
			}
			for (int i = 0; i < total; i++)
			{
				if (brick[i].getLives() != 0)
				{
					if ((ball[b].getY() + ball[b].getRadius() >= brick[i].getY()) && (ball[b].getY() - ball[b].getRadius() <= brick[i].getY() + brick[i].getHeight())) {
						if ((ball[b].getX() >= brick[i].getX()) && (ball[b].getX() <= brick[i].getX() + brick[i].getWidth())) {
							if (ball[b].getY() + ball[b].getRadius() >= brick[i].getY() + brick[i].getHeight() / 2) {
								ball[b].setFlag3(true); 
							} else {
								ball[b].setFlag3(false);
							}
						}
					}
					if ((ball[b].getY() + ball[b].getRadius() >= brick[i].getY()-3) && (ball[b].getY() + ball[b].getRadius() <= brick[i].getY() + brick[i].getHeight())) {
						if ((ball[b].getX() >= brick[i].getX()-3) && (ball[b].getX() <= brick[i].getX() + brick[i].getWidth()+2)) {
							// Ball is within the vertical boundaries of the brick
							if ((ball[b].getX() + ball[b].getRadius()) <= (brick[i].getX()+3)) {
								// Ball hits the left side of the brick
								ball[b].setFlag1(false);
								ball[b].setFlag2(true);
								break;
							} 
							else if ((ball[b].getX() + ball[b].getRadius()) >= (brick[i].getX() + brick[i].getWidth()-3)) {
								// Ball hits the right side of the brick
								ball[b].setFlag1(true);
								ball[b].setFlag2(false);
								break;
							}
						}
					}

				}
			}
			static int a = 0;
			if (!ball[b].getSlow() && !ball[b].getFast())
			{
				if (ball[b].getFlag1())
				{
					ball[b].setW(ball[b].getW() + ball[b].getCal());
				}
				if (ball[b].getFlag2())
				{
					ball[b].setW(ball[b].getW() - ball[b].getCal());
				}
				if (ball[b].getFlag3())
				{
					ball[b].setH(ball[b].getH() + 5);
				}
				else
				{
					ball[b].setH(ball[b].getH() - 5);
				}
			}
			else if (ball[b].getSlow())
			{
				if (a < 300)
				{
					if (ball[b].getFlag1())
					{
						ball[b].setW(ball[b].getW() + ball[b].getCal() - 2);
					}
					if (ball[b].getFlag2())
					{
						ball[b].setW(ball[b].getW() - (ball[b].getCal()-2 ));
					}
					if (ball[b].getFlag3())
					{
						ball[b].setH(ball[b].getH() + 2);
					}
					else
					{
						ball[b].setH(ball[b].getH() - 2);
					}
					a++;
				}
				else
				{
					a = 0;
					ball[b].setSlow(false);
				}
			}
			else if (ball[b].getFast())
			{
				if (a < 300)
				{
					if (ball[b].getFlag1())
					{
						ball[b].setW(ball[b].getW() + ball[b].getCal()+3);
					}
					if (ball[b].getFlag2())
					{
						ball[b].setW(ball[b].getW() - (ball[b].getCal()+3));
					}
					if (ball[b].getFlag3())
					{
						ball[b].setH(ball[b].getH() + 8);
					}
					else
					{
						ball[b].setH(ball[b].getH() - 8);
					}
					a++;
				}
				else
				{
					a = 0;
					ball[b].setFast(false);
				}
			}
			if (ball[b].getY() < 20)
			{
				ball[b].setLives(ball[b].getLives() - 1);
				if (ball[b].getLives() != 0)
				{
					ball[b].setW(500);
					ball[b].setH(220);
					ball[b].setCal(2);
					ball[b].setFlag3(true);
				}
			}
			if(level==3){
				if (ball[b].getY() >= 760)
				{
					ball[b].setLives(ball[b].getLives() - 1);
					if (ball[b].getLives() != 0)
					{
						ball[b].setW(500);
						ball[b].setH(220);
						ball[b].setCal(2);
						ball[b].setFlag3(true);
					}
				}
			}
		}
	}
	//-------------------------------------------------------
	//-------------------------------------------------------
	//-------------------------------------------------------
	// Movements Function
	void gameMovements()
	{
		// Ball movements
		ballMovements();
		// Food movements
		for (int i = 0; i < total; i++)
		{
			bool flag = false;
			if (brick[i].food.getProb() == 1)
			{
				flag = true;
				if (flag)
				{
					if (brick[i].food.getY() > -20)
						brick[i].food.setY(brick[i].food.getY() - 3);
				}
			}
		}
		// Paddle powerups and new movements
		static int b = 0;
		for(int p=0;p<numP;p++){

			if (paddle[0].getIncrease())
			{
				if (b < 300)
				{
					paddle[p].setLength(160);
					b++;
				}
				else
				{
					b = 0;
					paddle[p].setIncrease(false);
				}
			}
			else if (paddle[0].getDecrease())
			{
				if (b < 300)
				{
					paddle[p].setLength(40);
					b++;
				}
				else
				{
					b = 0;
					paddle[p].setDecrease(false);
				}
			}
			else if (!paddle[0].getIncrease() && !paddle[0].getDecrease())
			{
				paddle[p].setLength(80);
			}
		}
	}
};
