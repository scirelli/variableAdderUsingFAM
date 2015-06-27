// INCLUDES ///////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <conio.h>
#include <windows.h>
#include <time.h>

// GLOBALS ////////////////////////////////////////////////

CONSOLE_SCREEN_BUFFER_INFO con_info;   // holds screen info
HANDLE hconsole;         // handle to console


// FUNCTIONS //////////////////////////////////////////////
void Init_Graphics(void);
inline void Set_Color(int fcolor, int bcolor);
inline void Draw_String(int x,int y, char *string);
void IntroOpening(void);
void Animation(void);

void Init_Graphics(void)
{
	// this function initializes the console graphics engine

	COORD console_size = {80,25}; // size of console
	srand((unsigned)time(NULL));

	// open i/o channel to console screen
	hconsole=CreateFile("CONOUT$",GENERIC_WRITE | GENERIC_READ,
         FILE_SHARE_READ | FILE_SHARE_WRITE,
         0L, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0L);

	// make sure we are in 80x25
	SetConsoleScreenBufferSize(hconsole,console_size);

	// get details for console screen                       
	GetConsoleScreenBufferInfo(hconsole,&con_info);

} // end Init_Graphics

inline void Set_Color(int fcolor, int bcolor=0) 
{
	// this function sets the color of the console output
	SetConsoleTextAttribute(hconsole,(WORD)((bcolor << 4) | fcolor));

} 

inline void Draw_String(int x,int y, char *string)
{
	// this function draws a string at the given x,y

	COORD cursor_pos; // used to pass coords

	// set printing position
	cursor_pos.X = x;
	cursor_pos.Y = y;
	SetConsoleCursorPosition(hconsole,cursor_pos);

	// print the string in current color
	printf("%s",string);

} // end Draw_String

///////////////////////////////////////////////////////////

inline void Clear_Screen(void)
{
	// this function clears the screen

	// set color to white on black
	Set_Color(15,0);

	// clear the screen
	for (int index=0; index<=25; index++)
		Draw_String(0, 24,"\n");

} // end Clear_Screen


void Intro(void)
{
	// SECTION: initialization
	int stillRunning=1;
	//char key;

	// set up the console text graphics system
	Init_Graphics();
	// clear the screen
	Clear_Screen();
	//Animation();
	IntroOpening();
	
	while(stillRunning == 1)
	{
		if (kbhit())
		{
			/*
			key = toupper(getch());
			// is player trying to exit, if so exit
			if (key=='Q' || key==27)
				stillRunning = 0;
			
			if(key== 'C')
				Clear_Screen();
			*/
			Clear_Screen();
			Set_Color(15,0);
			stillRunning = 0;
			Draw_String(0,0,"");//keeps cursor at the left of the screen
		}
	}


	// SECTION: synchronize to a constant frame rate
	Sleep(30);   

 	
	//Clear_Screen();

	//printf("\nG A M E  O V E R \n\n");

} // end main

void Animation(void)
{
	//int stillRunning=1;
	//char key;

	Set_Color(15,0);
	Draw_String(20, 3, " @");
	Draw_String(20, 4, "-|-");
	Draw_String(20, 5, "/'\\");
	Sleep(60);
	Draw_String(20, 4, "\\|/");
	
	return;
}

void IntroOpening(void)
{
	Set_Color(4,0);
	Draw_String(20, 4, "####################################\n");//36 chars 32
	
	Draw_String(20, 5, "##");
	Set_Color(10,0);
	Draw_String(36, 5, "Hi!");
	Set_Color(4,0);
    Draw_String(38, 5, "                ##\n");	
	
	Draw_String(20, 6, "##");
	Set_Color(10,0);
	Draw_String(27, 6, "Does this impress you?");
    Set_Color(4,0);
	Draw_String(54, 6, "##\n");
	
	Draw_String(20, 7, "##                                ##\n");

	Draw_String(20, 8, "##");
    Set_Color(10,0);
	Draw_String(34, 8, "NO?!?!");
	Set_Color(4,0);
	Draw_String(54, 8, "##\n");
	
	Draw_String(20, 9, "##                                ##\n");
	
    Draw_String(20,10, "##");
	Set_Color(10,0);
	Draw_String(25,10, "Ok well then press any key");           
	Set_Color(4,0);
	Draw_String(54,10, "##\n");
	
	
	Draw_String(20,11, "##                                ##\n");
	Draw_String(20,12, "##                                ##\n");
	Draw_String(20,13, "##                                ##\n");
	Draw_String(20,14, "####################################\n");
	
	Draw_String(0,0,"");//keeps cursor at the left of the screen
	
	return;
}