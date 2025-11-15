//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include <iostream>
#include<fstream>
#include <string>
#include <cmath> // for basic math functions such as cos, sin, sqrt
#include <unistd.h>
#include"header.h"
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
Game obj;
void GameDisplay() /**/
{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	static int a=0;
	if(((obj.win || obj.gameOver)&&(a==0))){
		fstream fout;
		fout.open("Score.txt",ios::out|ios::app);
		fout<<obj.convString(obj.brick->getScore())<<endl;
		a++;
		fout.close();
	}
	if(obj.y==1){
		int maxScore=0;
            fstream score_file("Score.txt", ios::in);
            string line;
            if (score_file) {
                while (!score_file.eof()) {
                    getline(score_file, line);
					int a=obj.convInt(line);
                    if (a>maxScore) {
                        maxScore=a;
                    }
                }
            }
        score_file.close();
		obj.highScore=maxScore;
	}
	glClear(GL_COLOR_BUFFER_BIT); // Update the colors
	if(obj.y==1){
		glClearColor(0, 0, 0.22, 0);
		DrawRectangle(330,300,300,200,colors[GRAY]);
		DrawString(345, 420, "LEVEL 1(Press B)", colors[BLACK]);
		DrawString(345, 380, "LEVEL 2(Press C)", colors[BLACK]);
		DrawString(345, 340, "LEVEL 3(Press D)", colors[BLACK]);
		if(obj.x==1){
			obj.level=1;
			obj.y=2;
		}
		else if(obj.x==2){
			obj.level=2;
			obj.y=2;
		}
		else if(obj.x==3){
			obj.level=3;
			obj.y=2;
		}
	}
	else if (obj.gameOver)
	{
		glClearColor(0, 0, 0, 0);	  // Red==Green==Blue==1 --> White Colour
		DrawString(400, 450, "GAME OVER\n", colors[RED]);
		if(obj.brick->getScore()>obj.highScore){
			DrawString(370, 400, "New High SCORE: " + obj.convString(obj.brick->getScore()), colors[RED]);
		}
		else{
			DrawString(400, 400, "SCORE: " + obj.convString(obj.brick->getScore()), colors[RED]);
		}
	}
	else if (obj.win)
	{
		glClearColor(0, 0, 0, 0);
		DrawString(400, 450, "YOU WON\n", colors[RED]);
		//DrawString(440, 550, "SCORE: " + obj.convString(obj.brick->getScore()), colors[RED]);
		if(obj.brick->getScore()>obj.highScore){
			DrawString(370, 400, "New High SCORE: " + obj.convString(obj.brick->getScore()), colors[RED]);
		}
		else{
			DrawString(400, 400, "SCORE: " + obj.convString(obj.brick->getScore()), colors[RED]);
		}
		
	}
	else if(obj.y==2 && !obj.pause)
	{
		//cout<<"yes\n";
		glClearColor(0, 0, 0, 0);
		obj.gameDisplay();
	}
	else if(obj.pause){
		glClearColor(0, 0, 0.22, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		DrawRectangle(330,400,300,100,colors[GRAY]);
		DrawString(360, 450, "Press R to resume", colors[RED]);
	}

	glutSwapBuffers(); // do not modify this line..
}
/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y)
{

	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
	{
		if(obj.paddle[1].getPaddleX1() > 3){
			obj.paddle[1].setPaddleX1(obj.paddle[1].getPaddleX1()-30);
			obj.paddle[1].setPaddleX2(obj.paddle[1].getPaddleX1()+obj.paddle[1].getLength());	
		}
	}
	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
	{
		if(obj.paddle[1].getPaddleX2() < 1015){
			obj.paddle[1].setPaddleX1(obj.paddle[1].getPaddleX1()+30);
			obj.paddle[1].setPaddleX2(obj.paddle[1].getPaddleX1()+obj.paddle[1].getLength());	
		}
	}
	else if (key == GLUT_KEY_UP /*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{
		
	}

	else if (key == GLUT_KEY_DOWN /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y)
{
	if (key == 27 /* Escape key ASCII*/)
	{
		exit(1); // exit the program when escape key is pressed.
	}
	if (key == 'b' || key == 'B') // Key for placing the bomb
	{
		// do something if b is pressed
		obj.x=1;
	}
	if(key=='c'|| key == 'B'){
		obj.x=2;
	}
	if(key=='d' || key=='D'){
		obj.x=3;
	}
	if(key=='p' || key=='P'){
		obj.pause=true;
	}
	if(key=='r' || key=='R'){
		obj.pause=false;
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y)
{
	
	glutPostRedisplay();
}
void MouseMoved(int x, int y)
{
	if(!obj.pause){
		if (x < 1015 - obj.paddle[0].getLength() && x > 3)
		{
			obj.paddle[0].setPaddleX1(x);
			obj.paddle[0].setPaddleX2(x + obj.paddle[0].getLength());
		}
		glutPostRedisplay();

	}
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
	}
	glutPostRedisplay();
}
void Timer(int m)
{
	if(obj.pause==false){
		if(obj.x!=0){
			glutPostRedisplay();	
			obj.gameMovements();
		}
	}
		// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1.0, Timer, 0);
	
}
/*
 * our gateway main function
 * */
int main(int argc, char *argv[])
{

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer();							  // seed the random number generator...
	glutInit(&argc, argv);						  // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50);				  // set the initial position of our window
	glutInitWindowSize(width, height);			  // set the size of our window
	glutCreateWindow("OOP Project");			  // set the title of our game window
	SetCanvasSize(width, height);				  // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	// glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	
	glutDisplayFunc(GameDisplay);	   // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys);   // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	obj.level=obj.x;
	glutTimerFunc(1000.0, Timer, 0);

	// glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved);	  // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */


