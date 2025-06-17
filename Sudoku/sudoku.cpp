/*
 * Program: Sudoku Game
 * Author: Saumya Gangwar
 * Created in: Class 11 (Year 2018)
 * Language: C
 *
 * Description:
 * This is a Sudoku game and solver built using C. The program stores a set of
 * pre-solved Sudoku grids and presents the user with a puzzle by hiding certain
 * values based on the selected difficulty level (Easy, Medium, Hard).
 * It features a user-interactive interface using basic C graphics and color
 * formatting to enhance the user experience.
 * Randomization is used to vary which numbers are visible, making each puzzle
 * slightly different every time it's played.
 * The program ensures that the final grid satisfies the constraints of Sudoku: 
 * - Each row, column, and 3x3 subgrid must contain all digits from 1 to 9 exactly once.
 *
 * Key Features:
 * - Difficulty selection (Easy, Medium, Hard)
 * - Randomized puzzle generation using predefined solved grids
 * - Hides a number of cells based on difficulty
 * - Checks for valid Sudoku entries and constraints
 * - Displays the grid before and after solving
 * - Uses C graphics and color output to visually differentiate elements
 * - User-friendly console display of Sudoku grid
 *
 * Technical Concepts Used:
 * - 2D arrays for the Sudoku grid
 * - Random number generation for cell selection
 * - Recursive backtracking for solving
 * - User input handling and validation
 *
 * Purpose:
 * This project was created in high school as a way to explore logic building,
 * puzzles, and core programming concepts in C such as arrays, loops, conditionals,
 * recursion, and randomness.
 *
 * Usage:
 * Exeutable as a CPP file, or run on Turbo C++.
 */

//Including libraries
#include<fstream.h>
#include<conio.h>
#include<iomanip.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Global variables
char st[20];//player name
int h=0;//high score
fstream ff,xx;

// Structure to save high scores
struct hscr
{
	char name[20];
	char leve[15];
	int scr;
}hs,ahs[50],ahs1;

// Structure to best time record
struct btmr
{
	char name[20];
	char leve[15];
	struct dostime_t tmr;
}mr,amr[50],amr1;

void name1();
void classic(int);
void type(char str[20]);

// Function to design border where color is taken as argument
void brdr(int c=15)   
{
char b=176;
	for(int i=1;i<=24;i++)
	{
		if((i==1)||(i==24))
		{
			for(int j=1;j<=79;j++)
			{
				textcolor(c);
				cprintf("%c",b);
			}
		}
		else
		{
			for(int j=1;j<=79;j++)
			{
				if((j==1)||(j==79))
					cprintf("%c",b);
				else
					cout<<" ";
			}
		}
	cout<<endl;
	}
}

//Function that designs the very first introduction page of game "SUDOKU"
void frnt()
{
char a1=218,a2=191,a3=192,a4=217,a5=179,a6=196,a7=180,a8=193,a9=194,a10=195,a12=47,a13=92,a14=248;
	delay(100);
	for(int i=3;i<=15;i++)
	{
	gotoxy(77,i);
		if((i>=3)&&(i<=14))
		{
			textcolor(15);
			cprintf("%c",a5);
		}
		if(i==15)
		{
			textcolor(3);
			cprintf("%c",a14);
		}
	}
	delay(100);
	for(i=3;i<=12;i++)
	{
	gotoxy(76,i);
		if((i>=3)&&(i<=11))
		{
			textcolor(15);
			cprintf("%c",a5);
		}
		if(i==12)
		{
			textcolor(3);
			cprintf("%c",a14);
		}
	}
	delay(100);
	for(i=3;i<=9;i++)
	{
	gotoxy(75,i);
		if((i>=3)&&(i<=8))
		{
			textcolor(15);
			cprintf("%c",a5);
		}
		if(i==9)
		{
			textcolor(3);
			cprintf("%c",a14);
		}
	}
	delay(100);
	for(i=3;i<=7;i++)
	{
	gotoxy(74,i);
		if((i>=3)&&(i<=6))
		{
			textcolor(15);
			cprintf("%c",a5);
		}
		if(i==7)
		{
			textcolor(3);
			cprintf("%c",a14);
		}
	}
	delay(100);
	for(i=3;i<=8;i++)
	{
	gotoxy(73,i);
		if((i>=3)&&(i<=7))
		{
			textcolor(15);
			cprintf("%c",a5);
		}
		if(i==8)
		{
			textcolor(3);
			cprintf("%c",a14);
		}
	}
	delay(100);
	for(i=3;i<=5;i++)
	{
	gotoxy(72,i);
		if((i>=3)&&(i<=4))
		{
			textcolor(15);
			cprintf("%c",a5);
		}
		if(i==5)
		{
			textcolor(3);
			cprintf("%c",a14);
		}
	}
	for(i=3;i<=22;i++)
	{
	gotoxy(3,i);
	textcolor(3);
		if(i==6)
		{
			for(int j=3;j<=54;j++)
			{
				if(j==8)
				{
					cprintf("%c",a1);
					delay(50);
				}
				else if(j==9)
				{
					cprintf("%c",a2);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==7)
		{
			for(int j=3;j<=54;j++)
			{
				if(j==8)
				{
					cprintf("%c",a3);
					delay(50);
				}
				else if(j==9)
				{
					cprintf("%c",a4);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==8)
		{
			for(int j=3;j<=54;j++)
			{
				if(j==10)
				{
					cprintf("%c",a1);
					delay(50);
				}
				else if((j==11)||(j==12))
				{
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==13)
				{
					cprintf("%c",a2);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==9)
		{
			for(int j=3;j<=54;j++)
			{
				if(j==7)
				{
					cprintf("%c",a1);
					delay(50);
				}
				else if((j==9)||(j==8))
				{
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==10)
				{
					cprintf("%c",a7);
					delay(50);
				}
				else if(j==13)
				{
					cprintf("%c",a5);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==10)
		{
			for(int j=3;j<=54;j++)
			{
				if(j==7)
				{
					cprintf("%c",a5);
					delay(50);
				}
				else if(j==10)
				{
					cprintf("%c",a3);
					delay(50);
				}
				else if(j==11)
				{
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==12)
				{
					cprintf("%c",a9);
					delay(50);
				}
				else if(j==13)
				{
					cprintf("%c",a4);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==11)
		{
			for(int j=3;j<=54;j++)
			{
				if(j==5)
				{
					cprintf("%c",a1);
					delay(50);
				}
				else if((j==9)||(j==8)||(j==6)||(j==10))
				{
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==7)
				{
					cprintf("%c",a8);
					delay(50);
				}
				else if(j==11)
				{
					cprintf("%c",a2);
					delay(50);
				}
				else if(j==12)
				{
					cprintf("%c",a5);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==12)
		{
			for(int j=3;j<=54;j++)
			{
				if(j==5)
				{
					cprintf("%c",a5);
					delay(50);
				}
				else if(j==11)
				{
					cprintf("%c",a10);
					delay(50);
				}
				else if(j==12)
				{
					cprintf("%c",a8);
					delay(50);
				}
				else if((j==13)||(j==14))
				{
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==15)
				{
					cprintf("%c",a2);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==13)
		{
			for(int j=3;j<=54;j++)
			{
				if((j==5)||(j==11)||(j==15))
				{
					cprintf("%c",a5);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==14)
		{
			for(int j=3;j<=54;j++)
			{
				if(j==5)
				{
					cprintf("%c",a3);
					delay(50);
				}
				else if((j==7)||(j==8)||(j==6)||(j==10))
				{
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==9)
				{
					cprintf("%c",a9);
					delay(50);
				}
				else if(j==11)
				{
					cprintf("%c",a4);
					delay(50);
				}
				else if(j==15)
				{
					cprintf("%c",a5);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==15)
		{
			for(int j=3;j<=54;j++)
			{
				if(j==5)
				{
					cprintf("%c",a2);
					delay(50);
				}
				else if((j==9)||(j==15))
				{
					cprintf("%c",a5);
					delay(50);
				}
				else if(j==4)
				{
					cprintf("%c",a1);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==16)
		{
			for(int j=3;j<=54;j++)
			{
				if((j==4)||(j==9))
				{
					cprintf("%c",a3);
					delay(50);
				}
				else if((j==14)||(j==13)||(j==11))
				{
					cprintf("%c",a6);
					delay(50);
				}
				else if((j==5)||(j==15))
				{
					cprintf("%c",a4);
					delay(50);
				}
				else if((j==10)||(j==12))
				{
					cprintf("%c",a9);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==17)
		{
			for(int j=3;j<=54;j++)
			{
				if(j==10)
				{
					cprintf("%c",a5);
					delay(50);
				}
				else if((j==13)||(j==14)||(j==15)||(j==16)||(j==17))
				{
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==12)
				{
					cprintf("%c",a10);
					delay(50);
				}
				else if(j==18)
				{
					cprintf("%c",a2);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==18)
		{
			for(int j=3;j<=54;j++)
			{
				if((j==6)||(j==31))
				{
					cprintf("%c",a1);
					delay(50);
				}
				else if((j==9)||(j==8)||(j==7)||(j==19)||(j==20)||(j==21))
				{
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==10)
				{
					cprintf("%c",a8);
					delay(50);
				}
				else if(j==11)
				{
					cprintf("%c",a9);
					delay(50);
				}
				else if(j==12)
				{
					cprintf("%c",a4);
					delay(50);
				}
				else if(j==18)
				{
					cprintf("%c",a10);
					delay(50);
				}
				else if((j==22)||(j==32))
				{
					cprintf("%c",a2);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==19)
		{
			for(int j=3;j<=54;j++)
			{
				if((j==26)||(j==43))
				{
					cprintf("%c",a1);
					delay(50);
				}
				else if((j==22)||(j==18)||(j==11)||(j==6))
				{
					cprintf("%c",a5);
					delay(50);
				}
				else if(j==31)
				{
					cprintf("%c",a3);
					delay(50);
				}
				else if((j==27)||(j==44))
				{
					cprintf("%c",a2);
					delay(50);
				}
				else if(j==32)
				{
					cprintf("%c",a4);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==20)
		{
			for(int j=3;j<=54;j++)
			{
				if((j==6)||(j==26)||(j==43))
				{
					cprintf("%c",a3);
					delay(50);
				}
				else if((j==9)||(j==8)||(j==7)||(j==23)||(j==24))
				{
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==10)
				{
					cprintf("%c",a9);
					delay(50);
				}
				else if(j==18)
				{
					cprintf("%c",a5);
					delay(50);
				}
				else if(j==22)
				{
					cprintf("%c",a10);
					delay(50);
				}
				else if((j==28)||(j==35)||(j==52))
				{
					cprintf("%c",a1);
					delay(50);
				}
				else if((j==25)||(j==29)||(j==36)||(j==53))
				{
					cprintf("%c",a2);
					delay(50);
				}
				else if((j==27)||(j==11)||(j==44))
				{
					cprintf("%c",a4);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==21)
		{
			for(int j=3;j<=54;j++)
			{
				if((j==25)||(j==10))
				{
					cprintf("%c",a5);
					delay(50);
				}
				else if((j==19)||(j==20)||(j==21))
				{
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==18)
				{
					cprintf("%c",a10);
					delay(50);
				}
				else if(j==22)
				{
					cprintf("%c",a7);
					delay(50);
				}
				else if(j==39)
				{
					cprintf("%c",a1);
					delay(50);
				}
				else if(j==40)
				{
					cprintf("%c",a2);
					delay(50);
				}
				else if((j==29)||(j==36)||(j==53))
				{
					cprintf("%c",a4);
					delay(50);
				}
				else if((j==28)||(j==35)||(j==52))
				{
					cprintf("%c",a3);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==22)
		{
			for(int j=3;j<=54;j++)
			{
				if((j==23)||(j==24)||((j>=11)&&(j<=17)))
				{
					cprintf("%c",a6);
					delay(50);
				}
				else if((j==10)||(j==22)||(j==39))
				{
					cprintf("%c",a3);
					delay(50);
				}
				else if((j==18)||(j==25)||(j==40))
				{
					cprintf("%c",a4);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
	}
	delay(1000);
	textcolor(15);
	for(i=4;i<=13;i++)
	{
		gotoxy(18,i);
		if(i==4)
		{
			for(int j=18;j<=27;j++)
			{
				if(j==20)
					cprintf("%c",a1);
				else if(j==27)
					cprintf("%c",a2);
				else if((j>=21)&&(j<=26))
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
		if(i==5)
		{
			for(int j=18;j<=27;j++)
			{
				if(j==20)
					cprintf("%c",a5);
				else if(j==23)
					cprintf("%c",a1);
				else if(j==27)
					cprintf("%c",a4);
				else if((j>=24)&&(j<=26))
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
		if(i==6)
		{
			for(int j=18;j<=27;j++)
			{
				if((j==20)||(j==23))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==7)
		{
			for(int j=18;j<=27;j++)
			{
				if(j==20)
					cprintf("%c",a5);
				else if(j==26)
					cprintf("%c",a2);
				else if(j==23)
					cprintf("%c",a3);
				else if((j==24)||(j==25))
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
		if(i==8)
		{
			for(int j=18;j<=27;j++)
			{
				if((j==20)||(j==26))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==9)
		{
			for(int j=18;j<=27;j++)
			{
				if(j==26)
					cprintf("%c",a5);
				else if(j==20)
					cprintf("%c",a3);
				else if(j==24)
					cprintf("%c",a2);
				else if((j>=21)&&(j<=23))
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
		if(i==10)
		{
			for(int j=18;j<=27;j++)
			{
				if((j==26)||(j==24))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==11)
		{
			for(int j=18;j<=27;j++)
			{
				if(j==26)
					cprintf("%c",a5);
				else if(j==18)
					cprintf("%c",a1);
				else if(j==24)
					cprintf("%c",a4);
				else if((j>=19)&&(j<=23))
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
		if(i==12)
		{
			for(int j=18;j<=27;j++)
			{
				if((j==18)||(j==26))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==13)
		{
			for(int j=18;j<=27;j++)
			{
				if(j==26)
					cprintf("%c",a4);
				else if(j==18)
					cprintf("%c",a3);
				else if((j>=19)&&(j<=25))
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
	}
	delay(100);
	for(i=7;i<=13;i++)
	{
		gotoxy(28,i);
		if(i==7)
		{
			for(int j=28;j<=36;j++)
			{
				if((j==28)||(j==33))
					cprintf("%c",a1);
				else if((j==31)||(j==36))
					cprintf("%c",a2);
				else if((j==29)||(j==30)||(j==34)||(j==35))
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
		if((i==8)||(i==9)||(i==10))
		{
			for(int j=28;j<=36;j++)
			{
				if((j==28)||(j==31)||(j==33)||(j==36))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==11)
		{
			for(int j=28;j<=36;j++)
			{
				if(j==32)
					cprintf("%c",a6);
				else if(j==31)
					cprintf("%c",a3);
				else if(j==33)
					cprintf("%c",a4);
				else if((j==28)||(j==36))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==12)
		{
			for(int j=28;j<=36;j++)
			{
				if((j==28)||(j==36))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==13)
		{
			for(int j=28;j<=36;j++)
			{
				if(j==28)
					cprintf("%c",a3);
				else if((j>=29)&&(j<=35))
					cprintf("%c",a6);
				else if(j==36)
					cprintf("%c",a4);
				else
					cout<<" ";
			}
		}
	}
	delay(100);
	for(i=7;i<=13;i++)
	{
		gotoxy(38,i);
		if(i==7)
		{
			for(int j=38;j<=43;j++)
			{
				if(j==38)
					cprintf("%c",a9);
				else if((j==39)||(j==40)||(j==41)||(j==42))
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
		if((i==8)||(i==12))
		{
			for(int j=38;j<=43;j++)
			{
				if((j==38)||(j==43))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==9)
		{
			for(int j=38;j<=43;j++)
			{
				if((j==38)||(j==43))
					cprintf("%c",a5);
				else if(j==40)
					cprintf("%c",a1);
				else if(j==41)
					cprintf("%c",a2);
				else
					cout<<" ";
			}
		}
		if(i==10)
		{
			for(int j=38;j<=43;j++)
			{
				if((j==38)||(j==40)||(j==41)||(j==43))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==11)
		{
			for(int j=38;j<=43;j++)
			{
				if((j==38)||(j==43))
					cprintf("%c",a5);
				else if(j==40)
					cprintf("%c",a3);
				else if(j==41)
					cprintf("%c",a4);
				else
					cout<<" ";
			}
		}
		if(i==13)
		{
			for(int j=38;j<=43;j++)
			{
				if(j==38)
					cprintf("%c",a8);
				else if((j==39)||(j==40)||(j==41)||(j==42))
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
	}
	delay(100);
	for(i=7;i<=13;i++)
	{
		gotoxy(45,i);
		if(i==7)
		{
			for(int j=45;j<=51;j++)
			{
				if(j==45)
					cprintf("%c",a1);
				else if(j==51)
					cprintf("%c",a2);
				else if((j>=46)&&(j<=50))
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
		if(i==8)
		{
			for(int j=45;j<=51;j++)
			{
				if((j==45)||(j==51))
					cprintf("%c",a5);
				else if(j==47)
					cprintf("%c",a1);
				else if(j==48)
					cprintf("%c",a6);
				else if(j==49)
					cprintf("%c",a2);
				else
					cout<<" ";
			}
		}
		if((i==9)||(i==10)||(i==11))
		{
			for(int j=45;j<=51;j++)
			{
				if((j==45)||(j==47)||(j==49)||(j==51))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==12)
		{
			for(int j=45;j<=51;j++)
			{
				if((j==45)||(j==51))
					cprintf("%c",a5);
				else if(j==47)
					cprintf("%c",a3);
				else if(j==48)
					cprintf("%c",a6);
				else if(j==49)
					cprintf("%c",a4);
				else
					cout<<" ";
			}
		}
		if(i==13)
		{
			for(int j=45;j<=51;j++)
			{
				if(j==45)
					cprintf("%c",a3);
				else if(j==51)
					cprintf("%c",a4);
				else if((j>=46)&&(j<=50))
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
	}
	delay(100);
	for(i=7;i<=13;i++)
	{
		gotoxy(53,i);
		if(i==7)
		{
			for(int j=53;j<=59;j++)
			{
				if((j==53)||(j==55))
					cprintf("%c",a9);
				else if(j==54)
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
		if((i==8)||(i==9)||(i==10)||(i==11)||(i==12))
		{
			for(int j=53;j<=59;j++)
			{
				if((j==53)||(j==55))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==13)
		{
			for(int j=53;j<=59;j++)
			{
				if((j==53)||(j==55))
					cprintf("%c",a8);
				else if(j==54)
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
	}
	textcolor(3);
	gotoxy(58,7);
		cprintf("%c",a12);
	gotoxy(57,8);
		cprintf("%c",a12);
	gotoxy(56,9);
		cprintf("%c",a12);
	gotoxy(56,10);
		cprintf("%c",a13);
	gotoxy(57,11);
		cprintf("%c",a13);
	gotoxy(58,12);
		cprintf("%c",a13);
	gotoxy(59,13);
		cprintf("%c",a13);
	delay(100);
	textcolor(15);
	for(i=7;i<=13;i++)
	{
		gotoxy(60,i);
		if(i==7)
		{
			for(int j=60;j<=68;j++)
			{
				if((j==60)||(j==65))
					cprintf("%c",a1);
				else if((j==63)||(j==68))
					cprintf("%c",a2);
				else if((j==61)||(j==62)||(j==66)||(j==67))
					cprintf("%c",a6);
				else
					cout<<" ";
			}
		}
		if((i==8)||(i==9)||(i==10))
		{
			for(int j=60;j<=68;j++)
			{
				if((j==60)||(j==63)||(j==65)||(j==68))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==11)
		{
			for(int j=60;j<=68;j++)
			{
				if(j==64)
					cprintf("%c",a6);
				else if(j==63)
					cprintf("%c",a3);
				else if(j==65)
					cprintf("%c",a4);
				else if((j==60)||(j==68))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==12)
		{
			for(int j=60;j<=68;j++)
			{
				if((j==60)||(j==68))
					cprintf("%c",a5);
				else
					cout<<" ";
			}
		}
		if(i==13)
		{
			for(int j=60;j<=68;j++)
			{
				if(j==60)
					cprintf("%c",a3);
				else if((j>=61)&&(j<=67))
					cprintf("%c",a6);
				else if(j==68)
					cprintf("%c",a4);
				else
					cout<<" ";
			}
		}
	}
	delay(1000);
	char n[2];
	gotoxy(3,3);
	textcolor(14+BLINK);
	cprintf("PRESS ENTER KEY TO CONTINUE");
	gets(n);
	if(n[0]=='\0')
	{
		gotoxy(3,3);
		for(i=0;i<40;i++)
			cout<<" ";
		gotoxy(3,3);
		cprintf("LOADING");
		delay(1000);
		cprintf("..");
		delay(1000);
		cprintf(".");
		delay(1000);
		cprintf("...");
		delay(1000);
	}
	textcolor(15);
}

// Function to design page showcasing mentor details
void guidr() 
{
	clrscr();
	char b=248;
	for(int i=1;i<=24;i++)
	{
		if((i==1)||(i==24))
		{
			for(int j=1;j<=79;j++)
			{
				if(j%2==0)
					textcolor(BLUE);
				else
					textcolor(WHITE);
				cprintf("%c",b);
			}
		}
		else
		{
			if(i%2==0)
				textcolor(WHITE);
			else
				textcolor(BLUE);
			for(int j=1;j<=79;j++)
			{
				if((j==1)||(j==79))
				{
					gotoxy(j,i);
					cprintf("%c",b);
				}
			}
		}
	cout<<endl;
	}
	char a1=179,a2=180,a4=192,a5=193,a6=194,a7=195,a8=196,a10=248,a13=218,a15=217;
	randomize();
	for(i=3;i<=22;i++)
	{
		if(i==8)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==6)
				{
					textcolor(random(15)+1);
					cprintf("%c",a13);
					delay(50);
				}
				else if((j>=7&&j<=10)||j==19||j==21||(j>=24&&j<=26)||(j>=30&&j<=33)||(j>=37&&j<=39)||(j>=46&&j<=48))
				{
					textcolor(random(15)+1);
					cprintf("%c",a8);
					delay(50);
				}
				else if(j==11||j==34)
				{
					textcolor(random(15)+1);
					cprintf("%c",a2);
					delay(50);
				}
				else if(j==12||j==17||j==20||j==23||j==29||j==36||j==45||j==51||j==55)
				{
					textcolor(random(15)+1);
					cprintf("%c",a6);
					delay(50);
				}
			}
		}
		if(i==9)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==6||j==12||j==17||j==20||j==23||j==29||j==27||j==36||j==40||j==45||j==51||j==49||j==55)
				{
					textcolor(random(15)+1);
					cprintf("%c",a1);
					delay(50);
				}
				else if(j==57)
				{
					textcolor(random(15)+1);
					cprintf("%c",a10);
					delay(50);
				}
			}
		}
		if(i==10)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==6||j==12||j==17||j==20||j==23||j==27||j==36||j==40)
				{
					textcolor(random(15)+1);
					cprintf("%c",a1);
					delay(50);
				}
				else if(j==29||j==45)
				{
					textcolor(random(15)+1);
					cprintf("%c",a7);
					delay(50);
				}
				else if(j==32||j==55)
				{
					textcolor(random(15)+1);
					cprintf("%c",a2);
					delay(50);
				}
				else if((j>=46&&j<=48)||j==30||j==31||(j>=52&&j<=54)||(j>=58&&j<=60))
				{
					textcolor(random(15)+1);
					cprintf("%c",a8);
					delay(50);
				}
				else if(j==51)
				{
					textcolor(random(15)+1);
					cprintf("%c",a4);
					delay(50);
				}
			}
		}
		if(i==11)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==6||j==12||j==17||j==20||j==23||j==29||j==27||j==40||j==36||j==45||j==49||j==55)
				{
					textcolor(random(15)+1);
					cprintf("%c",a1);
					delay(50);
				}
				else if(j==10)
				{
					textcolor(random(15)+1);
					cprintf("%c",a13);
					delay(50);
				}
				else if(j==11)
				{
					textcolor(random(15)+1);
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==57)
				{
					textcolor(random(15)+1);
					cprintf("%c",a10);
					delay(50);
				}
			}
		}
		if(i==12)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==7||j==8||j==9||j==15||j==14||j==13||j==16||j==21||j==19||j==24||j==25||j==26||(j>=30&&j<=33)||(j>=37&&j<=39)||(j>=46&&j<=48)||j==54)
				{
					textcolor(random(15)+1);
					cprintf("%c",a8);
					delay(50);
				}
				else if(j==11)
				{
					textcolor(random(15)+1);
					cprintf("%c",a1);
					delay(50);
				}
				else if(j==20||j==23||j==29||j==36||j==45)
				{
					textcolor(random(15)+1);
					cprintf("%c",a5);
					delay(50);
				}
				else if(j==6||j==12||j==53)
				{
					textcolor(random(15)+1);
					cprintf("%c",a4);
					delay(50);
				}
				else if(j==34)
				{
					textcolor(random(15)+1);
					cprintf("%c",a2);
					delay(50);
				}
				else if(j==10||j==55||j==17)
				{
					textcolor(random(15)+1);
					cprintf("%c",a15);
					delay(50);
				}
			}
		}
		if(i==13)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==11)
				{
					textcolor(random(15)+1);
					cprintf("%c",a1);
					delay(50);
				}
			}
		}
		if(i==14)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==11)
				{
					textcolor(random(15)+1);
					cprintf("%c",a5);
					delay(50);
				}
			}
		}
	}
	textcolor(15);
	delay(100);
	gotoxy(47,14);
	cprintf("MR. SHAKTIRISH KUMAR AGRAWAL");
	cout<<endl;
	gotoxy(52,16);
	cprintf("PGT, COMPUTER SCIENCE");
	textcolor(8);
	gotoxy(3,23);
	cprintf("[any key] to proceed");
	getch();
	clrscr();
	textcolor(15);
}

// Function to design page showcasing Developer details
void dandd()  
{
	char b=248;
	for(int i=1;i<=24;i++)
	{
		if((i==1)||(i==24))
		{
			for(int j=1;j<=79;j++)
			{
				if(j%2==0)
					textcolor(RED);
				else
					textcolor(WHITE);
				cprintf("%c",b);
			}
		}
		else
		{
			if(i%2==0)
				textcolor(WHITE);
			else
				textcolor(RED);
			for(int j=1;j<=79;j++)
			{
				if((j==1)||(j==79))
				{
					gotoxy(j,i);
					cprintf("%c",b);
				}
			}
		}
		cout<<endl;
	}
	char a1=179,a2=180,a3=191,a4=192,a5=193,a6=194,a7=195,a8=196,a11=47,a12=92,a13=218,a14=191,a15=217;
	randomize();
	for(i=3;i<=22;i++)
	{
		if(i==9)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==12||j==18||j==21||j==24||j==38||j==45||j==51||j==54||j==58)
				{
					textcolor(random(15)+1);
					cprintf("%c",a13);
					delay(50);
				}
				if(j==6||j==7||j==10||j==13||j==15||j==17||j==19||j==25||j==28||j==29||j==35||j==36||j==39||j==46||j==52||j==55||j==56||j==59||j==63||j==62||j==68)
				{
					textcolor(random(15)+1);
					cprintf("%c",a8);
					delay(50);
				}
				if(j==11||j==14||j==20||j==26||j==40||j==47||j==60)
				{
					textcolor(random(15)+1);
					cprintf("%c",a2);
					delay(50);
				}
				if(j==5||j==16||j==9||j==23||j==27||j==34||j==41||j==44||j==48||j==61||j==67||j==70||j==72)
				{
					textcolor(random(15)+1);
					cprintf("%c",a6);
					delay(50);
				}
				if(j==8||j==22||j==53||j==57)
				{
					textcolor(random(15)+1);
					cprintf("%c",a3);
					delay(50);
				}
			}
		}
		if(i==10)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==18||j==5||j==8||j==16||j==27||j==30||(j>=21&&j<=23)||j==34||j==37||j==41||j==44||j==48||j==51||j==53||j==61||j==64||j==67||j==69||j==70||j==72)
				{
					textcolor(random(15)+1);
					cprintf("%c",a1);
					delay(50);
				}
				if(j==10||j==25||j==46||j==39||j==59)
				{
					textcolor(random(15)+1);
					cprintf("%c",a2);
					delay(50);
				}
				if(j==9||j==19||j==24||j==38||j==45||j==54||j==58)
				{
					textcolor(random(15)+1);
					cprintf("%c",a7);
					delay(50);
				}
				if(j==56||j==55||j==13)
				{
					textcolor(random(15)+1);
					cprintf("%c",a8);
					delay(50);
				}
				if(j==12)
				{
					textcolor(random(15)+1);
					cprintf("%c",a4);
					delay(50);
				}
				if(j==14||j==20)
				{
					textcolor(random(15)+1);
					cprintf("%c",a14);
					delay(50);
				}
				if(j==57)
				{
					textcolor(random(15)+1);
					cprintf("%c",a15);
					delay(50);
				}
				if(j==32)
				{
					textcolor(random(15)+1);
					cprintf("&");
					delay(50);
				}
			}
		}
		if(i==11)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==5||j==16||j==21||j==27||j==34||j==54||j==61)
				{
					textcolor(random(15)+1);
					cprintf("%c",a5);
					delay(50);
				}
				if(j==6||j==7||j==10||j==13||j==15||j==17||j==19||j==25||j==28||j==29||j==35||j==36||j==39||j==46||j==49||j==52||j==59||j==63||j==62)
				{
					textcolor(random(15)+1);
					cprintf("%c",a8);
					delay(50);
				}
				if(j==11||j==26||j==40||j==47||j==50||j==60)
				{
					textcolor(random(15)+1);
					cprintf("%c",a2);
					delay(50);
				}
				if(j==9||j==18||j==22||j==24||j==38||j==45||j==48||j==51||j==58)
				{
					textcolor(random(15)+1);
					cprintf("%c",a4);
					delay(50);
				}
				if(j==12)
				{
					textcolor(random(15)+1);
					cprintf("%c",a7);
					delay(50);
				}
				if(j==8||j==14||j==20||j==23||j==53)
				{
					textcolor(random(15)+1);
					cprintf("%c",a15);
					delay(50);
				}
				if(j==43)
				{
					textcolor(random(15)+1);
					cprintf("%c",a11);
					delay(50);
				}
				if(j==42)
				{
					textcolor(random(15)+1);
					cprintf("%c",a12);
					delay(50);
				}
				if(j==72)
				{
					textcolor(random(15)+1);
					cprintf("%c",a2);
					delay(50);
				}
				if(j==67)
				{
					textcolor(random(15)+1);
					cprintf("%c",a7);
					delay(50);
				}
				if(j==68||j==71)
				{
					textcolor(random(15)+1);
					cprintf("%c",a8);
					delay(50);
				}
				if(j==70)
				{
					textcolor(random(15)+1);
					cprintf("%c",a4);
					delay(50);
				}
			}
		}
		if(i==12)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==69||j==67||j==72)
				{
					textcolor(random(15)+1);
					cprintf("%c",a1);
					delay(50);
				}
			}
		}
		if(i==13)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==68)
				{
					textcolor(random(15)+1);
					cprintf("%c",a8);
					delay(50);
				}
				if(j==67)
				{
					textcolor(random(15)+1);
					cprintf("%c",a5);
					delay(50);
				}
				if(j==72)
				{
					textcolor(random(15)+1);
					cprintf("%c",a15);
					delay(50);
				}
				if(j==71)
				{
					textcolor(random(15)+1);
					cprintf("%c",a7);
					delay(50);
				}
			}
		}
	}
	textcolor(WHITE);
	gotoxy(73,11);
	cprintf(":-");
	delay(100);
	gotoxy(59,15);
	cprintf("SAUMYA GANGWAR");
	textcolor(8);
	gotoxy(3,23);
	cprintf("[any key] to proceed");
	getch();
	clrscr();
	textcolor(15);
}

// Function to design border of 'About' page
void about() 
{
	char a1=218,a2=191,a3=192,a4=217,a5=179,a6=196;
	textcolor(14);
	for(int i=15;i<=65;i++)
	{
		for(int j=7;j<=18;j++)
		{
			gotoxy(i,j);
			cout<<" ";
		}
	}
	for(i=7;i<=18;i++)
	{
		if(i==7)
		{
			for(int j=15;j<=65;j++)
			{
				gotoxy(j,i);
				if(j==15)
				{
					textcolor(14);
					cprintf("%c",a1);
				}
				if(j==65)
				{
					textcolor(14);
					cprintf("%c",a2);
				}
				else
				{
					textcolor(14);
					cprintf("%c",a6);
				}
			}
		}
		if((i>=8)&&(i<=17))
		{
			for(int j=15;j<=65;j++)
			{
				gotoxy(j,i);
				if((j==15)||(j==65))
				{
					textcolor(14);
					cprintf("%c",a5);
				}
				else
					cout<<" ";
			}
		}
		if(i==18)
		{
			for(int j=15;j<=65;j++)
			{
				gotoxy(j,i);
				if(j==15)
				{
					textcolor(14);
					cprintf("%c",a3);
				}
				if(j==65)
				{
					textcolor(14);
					cprintf("%c",a4);
				}
				else
				{
					textcolor(14);
					cprintf("%c",a6);
				}
			}
		}
	}
}

// Function to define 'Back' option
void back()  
{
	clrscr();
	brdr();
	gotoxy(32,12);
	cout<<"SORRY.. YOU LOOSE..!!";
}

// Function to define when solved successfully
void win()  
{
	clrscr();
	brdr();
	gotoxy(30,12);
	cout<<"CONGRATS...YOU WON..!!!";
}

// Function to define how to take inputs
void input(int te1,int &sg,char z1[9][9],char t[9][9],int p[81][2],int f,int z,int a,int a1,int a2,int a3)    //options of commands within 9x9 square grid
{
	struct dostime_t aa,bb,cc;
	_dos_gettime(&aa);
	int te2;
	if(te1==6)
		te2=1;
	else if(te1==5)
		te2=2;
	else if(te1==4)
		te2=3;
	sg=0;
	gotoxy(f,z);
	M:
	char y=getch();
	if((y>='1')&&(y<='9'))
	{
		for(int i=10,i1=0;i<=42;i+=4,i1++)
		{
			for(int j=4,j1=0;j<=20;j+=2,j1++)
			{
				if((i==f)&&(j==z))
				{
					int p7=0;
					for(int k=0;k<81;k++)
					{
						if((p[k][0]==f)&&(p[k][1]==z))
							p7++;
						else if((p7==0)&&(k==80))
						{
							z1[j1][i1]=y;
							sg+=5;
						}
					}
				}
			}
		}
	}
	if(y=='c')
	{
		int u=0;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(!(z1[i][j]==t[i][j]))
					u++;
			}
		}
		if(u==0)
		{
			win();
			delay(1000);
			xx.open("btmr.txt",ios::binary|ios::app);
			strcpy(mr.name,st);
			if(te1==6)
				strcpy(mr.leve,"BEGINNER");
			if(te1==5)
				strcpy(mr.leve,"INTERMEDIATE");
			if(te1==4)
				strcpy(mr.leve,"EXPERT");
			_dos_gettime(&bb);
			if(bb.second>=aa.second)
				cc.second=bb.second-aa.second;
			else if(bb.second<aa.second)
			{
				bb.second+=60;
				cc.second=bb.second-aa.second;
				bb.minute-=1;
			}
			if(bb.minute>=aa.minute)
				cc.minute=bb.minute-aa.minute;
			else if(bb.minute<aa.minute)
			{
				bb.minute+=60;
				cc.minute=bb.minute-aa.minute;
				bb.hour-=1;
			}
			cc.hour=bb.hour-aa.hour;
			mr.tmr=cc;
			xx.write((char *)&mr,sizeof(mr));
			xx.close();
		}
		else
		{
			sg-=(3*u);
			if(sg<0)
				sg=0;
			back();
			delay(1000);
		}
		clrscr();
		ff.open("hscr.txt",ios::binary|ios::app);
		strcpy(hs.name,st);
		if(te1==6)
			strcpy(hs.leve,"BEGINNER");
		if(te1==5)
			strcpy(hs.leve,"INTERMEDIATE");
		if(te1==4)
			strcpy(hs.leve,"EXPERT");
		hs.scr=sg;
		ff.write((char *)&hs,sizeof(hs));
		ff.close();
		classic(te2);
	}
	if((f==a)&&(z==a1))
	{
		if(y=='r')
		{
			f+=4;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='t')
		{
			for(int tt=0;tt<10;tt++)
			{
				gotoxy(36+tt,22);
				cout<<" ";
			}
			_dos_gettime(&bb);
			if(bb.second>=aa.second)
				cc.second=bb.second-aa.second;
			else if(bb.second<aa.second)
			{
				bb.second+=60;
				cc.second=bb.second-aa.second;
				bb.minute-=1;
			}
			if(bb.minute>=aa.minute)
				cc.minute=bb.minute-aa.minute;
			else if(bb.minute<aa.minute)
			{
				bb.minute+=60;
				cc.minute=bb.minute-aa.minute;
				bb.hour-=1;
			}
			cc.hour=bb.hour-aa.hour;
			textcolor(8);
			gotoxy(36,22);
			cprintf("%d",cc.hour);
			cout<<":";
			cprintf("%d",cc.minute);
			cout<<":";
			cprintf("%d",cc.second);
			gotoxy(f,z);
			goto M;
		}
		else if(y=='d')
		{
			z+=2;
			gotoxy(f,z);
			goto M;
		}
		else if((y>='1')&&(y<='9'))
		{
			int ne=0;
			for(int i=0;i<81;i++)
			{
				if((p[i][0]==f)&&(p[i][1]==z))
					ne++;
			}
			if(ne==0)
			{
				cout<<y;
				gotoxy(f,z);
			}
			goto M;
		}
		else if(y=='b')
		{
			back();
			delay(1000);
			classic(te2);
		}
		else if(y=='e')
			exit(0);
		goto M;
	}
	else if((f==a2)&&(z==a1))
	{
		if(y=='l')
		{
			f-=4;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='t')
		{
			for(int tt=0;tt<10;tt++)
			{
				gotoxy(36+tt,22);
				cout<<" ";
			}
			_dos_gettime(&bb);
			if(bb.second>=aa.second)
				cc.second=bb.second-aa.second;
			else if(bb.second<aa.second)
			{
				bb.second+=60;
				cc.second=bb.second-aa.second;
				bb.minute-=1;
			}
			if(bb.minute>=aa.minute)
				cc.minute=bb.minute-aa.minute;
			else if(bb.minute<aa.minute)
			{
				bb.minute+=60;
				cc.minute=bb.minute-aa.minute;
				bb.hour-=1;
			}
			cc.hour=bb.hour-aa.hour;
			textcolor(8);
			gotoxy(36,22);
			cprintf("%d",cc.hour);
			cout<<":";
			cprintf("%d",cc.minute);
			cout<<":";
			cprintf("%d",cc.second);
			gotoxy(f,z);
			goto M;
		}
		else if(y=='d')
		{
			z+=2;
			gotoxy(f,z);
			goto M;
		}
		else if((y>='1')&&(y<='9'))
		{
			int ne=0;
			for(int i=0;i<81;i++)
			{
				if((p[i][0]==f)&&(p[i][1]==z))
					ne++;
			}
			if(ne==0)
			{
				cout<<y;
				gotoxy(f,z);
			}
			goto M;
		}
		else if(y=='b')
		{
			back();
			delay(1000);
			classic(te2);
		}
		else if(y=='e')
			exit(0);
		goto M;
	}
	else if((f==a2)&&(z==a3))
	{
		if(y=='l')
		{
			f-=4;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='t')
		{
			for(int tt=0;tt<10;tt++)
			{
				gotoxy(36+tt,22);
				cout<<" ";
			}
			_dos_gettime(&bb);
			if(bb.second>=aa.second)
				cc.second=bb.second-aa.second;
			else if(bb.second<aa.second)
			{
				bb.second+=60;
				cc.second=bb.second-aa.second;
				bb.minute-=1;
			}
			if(bb.minute>=aa.minute)
				cc.minute=bb.minute-aa.minute;
			else if(bb.minute<aa.minute)
			{
				bb.minute+=60;
				cc.minute=bb.minute-aa.minute;
				bb.hour-=1;
			}
			cc.hour=bb.hour-aa.hour;
			gotoxy(36,22);
			textcolor(8);
			cprintf("%d",cc.hour);
			cout<<":";
			cprintf("%d",cc.minute);
			cout<<":";
			cprintf("%d",cc.second);
			gotoxy(f,z);
			goto M;
		}
		else if(y=='u')
		{
			z-=2;
			gotoxy(f,z);
			goto M;
		}
		else if((y>='1')&&(y<='9'))
		{
			int ne=0;
			for(int i=0;i<81;i++)
			{
				if((p[i][0]==f)&&(p[i][1]==z))
					ne++;
			}
			if(ne==0)
			{
				cout<<y;
				gotoxy(f,z);
			}
			goto M;
		}
		else if(y=='b')
		{
			back();
			delay(1000);
			classic(te2);
		}
		else if(y=='e')
			exit(0);
		goto M;
	}
	if((f==a)&&(z==a3))
	{
		if(y=='r')
		{
			f+=4;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='t')
		{
			for(int tt=0;tt<10;tt++)
			{
				gotoxy(36+tt,22);
				cout<<" ";
			}
			_dos_gettime(&bb);
			if(bb.second>=aa.second)
				cc.second=bb.second-aa.second;
			else if(bb.second<aa.second)
			{
				bb.second+=60;
				cc.second=bb.second-aa.second;
				bb.minute-=1;
			}
			if(bb.minute>=aa.minute)
				cc.minute=bb.minute-aa.minute;
			else if(bb.minute<aa.minute)
			{
				bb.minute+=60;
				cc.minute=bb.minute-aa.minute;
				bb.hour-=1;
			}
			cc.hour=bb.hour-aa.hour;
			gotoxy(36,22);
			textcolor(8);
			cprintf("%d",cc.hour);
			cout<<":";
			cprintf("%d",cc.minute);
			cout<<":";
			cprintf("%d",cc.second);
			gotoxy(f,z);
			goto M;
		}
		else if(y=='u')
		{
			z-=2;
			gotoxy(f,z);
			goto M;
		}
		else if((y>='1')&&(y<='9'))
		{
			int ne=0;
			for(int i=0;i<81;i++)
			{
				if((p[i][0]==f)&&(p[i][1]==z))
					ne++;
			}
			if(ne==0)
			{
				cout<<y;
				gotoxy(f,z);
			}
			goto M;
		}
		else if(y=='b')
		{
			back();
			delay(1000);
			classic(te2);
		}
		else if(y=='e')
			exit(0);
		goto M;
	}
	else if(f==a)
	{
		if(y=='r')
		{
			f+=4;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='t')
		{
			for(int tt=0;tt<10;tt++)
			{
				gotoxy(36+tt,22);
				cout<<" ";
			}
			_dos_gettime(&bb);
			if(bb.second>=aa.second)
				cc.second=bb.second-aa.second;
			else if(bb.second<aa.second)
			{
				bb.second+=60;
				cc.second=bb.second-aa.second;
				bb.minute-=1;
			}
			if(bb.minute>=aa.minute)
				cc.minute=bb.minute-aa.minute;
			else if(bb.minute<aa.minute)
			{
				bb.minute+=60;
				cc.minute=bb.minute-aa.minute;
				bb.hour-=1;
			}
			cc.hour=bb.hour-aa.hour;
			gotoxy(36,22);
			textcolor(8);
			cprintf("%d",cc.hour);
			cout<<":";
			cprintf("%d",cc.minute);
			cout<<":";
			cprintf("%d",cc.second);
			gotoxy(f,z);
			goto M;
		}
		else if(y=='d')
		{
			z+=2;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='u')
		{
			z-=2;
			gotoxy(f,z);
			goto M;
		}
		else if((y>='1')&&(y<='9'))
		{
			int ne=0;
			for(int i=0;i<81;i++)
			{
				if((p[i][0]==f)&&(p[i][1]==z))
					ne++;
			}
			if(ne==0)
			{
				cout<<y;
				gotoxy(f,z);
			}
			goto M;
		}
		else if(y=='b')
		{
			back();
			delay(1000);
			classic(te2);
		}
		else if(y=='e')
			exit(0);
		goto M;
	}
	else if(f==a2)
	{
		if(y=='l')
		{
			f-=4;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='t')
		{
			for(int tt=0;tt<10;tt++)
			{
				gotoxy(36+tt,22);
				cout<<" ";
			}
			_dos_gettime(&bb);
			if(bb.second>=aa.second)
				cc.second=bb.second-aa.second;
			else if(bb.second<aa.second)
			{
				bb.second+=60;
				cc.second=bb.second-aa.second;
				bb.minute-=1;
			}
			if(bb.minute>=aa.minute)
				cc.minute=bb.minute-aa.minute;
			else if(bb.minute<aa.minute)
			{
				bb.minute+=60;
				cc.minute=bb.minute-aa.minute;
				bb.hour-=1;
			}
			cc.hour=bb.hour-aa.hour;
			gotoxy(36,22);
			textcolor(8);
			cprintf("%d",cc.hour);
			cout<<":";
			cprintf("%d",cc.minute);
			cout<<":";
			cprintf("%d",cc.second);
			gotoxy(f,z);
			goto M;
		}
		else if(y=='d')
		{
			z+=2;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='u')
		{
			z-=2;
			gotoxy(f,z);
			goto M;
		}
		else if((y>='1')&&(y<='9'))
		{
			int ne=0;
			for(int i=0;i<81;i++)
			{
				if((p[i][0]==f)&&(p[i][1]==z))
					ne++;
			}
			if(ne==0)
			{
				cout<<y;
				gotoxy(f,z);
			}
			goto M;
		}
		else if(y=='b')
		{
			back();
			delay(1000);
			classic(te2);
		}
		else if(y=='e')
			exit(0);
		goto M;
	}
	else if(z==a1)
	{
		if(y=='r')
		{
			f+=4;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='t')
		{
			for(int tt=0;tt<10;tt++)
			{
				gotoxy(36+tt,22);
				cout<<" ";
			}
			_dos_gettime(&bb);
			if(bb.second>=aa.second)
				cc.second=bb.second-aa.second;
			else if(bb.second<aa.second)
			{
				bb.second+=60;
				cc.second=bb.second-aa.second;
				bb.minute-=1;
			}
			if(bb.minute>=aa.minute)
				cc.minute=bb.minute-aa.minute;
			else if(bb.minute<aa.minute)
			{
				bb.minute+=60;
				cc.minute=bb.minute-aa.minute;
				bb.hour-=1;
			}
			cc.hour=bb.hour-aa.hour;
			gotoxy(36,22);
			textcolor(8);
			cprintf("%d",cc.hour);
			cout<<":";
			cprintf("%d",cc.minute);
			cout<<":";
			cprintf("%d",cc.second);
			gotoxy(f,z);
			goto M;
		}
		else if(y=='d')
		{
			z+=2;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='l')
		{
			f-=4;
			gotoxy(f,z);
			goto M;
		}
		else if((y>='1')&&(y<='9'))
		{
			int ne=0;
			for(int i=0;i<81;i++)
			{
				if((p[i][0]==f)&&(p[i][1]==z))
					ne++;
			}
			if(ne==0)
			{
				cout<<y;
				gotoxy(f,z);
			}
			goto M;
		}
		else if(y=='b')
		{
			back();
			delay(1000);
			classic(te2);
		}
		else if(y=='e')
			exit(0);
		goto M;
	}
	else if(z==a3)
	{
		if(y=='r')
		{
			f+=4;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='t')
		{
			for(int tt=0;tt<10;tt++)
			{
				gotoxy(36+tt,22);
				cout<<" ";
			}
			_dos_gettime(&bb);
			if(bb.second>=aa.second)
				cc.second=bb.second-aa.second;
			else if(bb.second<aa.second)
			{
				bb.second+=60;
				cc.second=bb.second-aa.second;
				bb.minute-=1;
			}
			if(bb.minute>=aa.minute)
				cc.minute=bb.minute-aa.minute;
			else if(bb.minute<aa.minute)
			{
				bb.minute+=60;
				cc.minute=bb.minute-aa.minute;
				bb.hour-=1;
			}
			cc.hour=bb.hour-aa.hour;
			gotoxy(36,22);
			textcolor(8);
			cprintf("%d",cc.hour);
			cout<<":";
			cprintf("%d",cc.minute);
			cout<<":";
			cprintf("%d",cc.second);
			gotoxy(f,z);
			goto M;
		}
		else if(y=='l')
		{
			f-=4;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='u')
		{
			z-=2;
			gotoxy(f,z);
			goto M;
		}
		else if((y>='1')&&(y<='9'))
		{
			int ne=0;
			for(int i=0;i<81;i++)
			{
				if((p[i][0]==f)&&(p[i][1]==z))
					ne++;
			}
			if(ne==0)
			{
				cout<<y;
				gotoxy(f,z);
			}
			goto M;
		}
		else if(y=='b')
		{
			back();
			delay(1000);
			classic(te2);
		}
		else if(y=='e')
			exit(0);
		goto M;
	}
	else
	{
		if(y=='r')
		{
			f+=4;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='t')
		{
			for(int tt=0;tt<10;tt++)
			{
				gotoxy(36+tt,22);
				cout<<" ";
			}
			_dos_gettime(&bb);
			if(bb.second>=aa.second)
				cc.second=bb.second-aa.second;
			else if(bb.second<aa.second)
			{
				bb.second+=60;
				cc.second=bb.second-aa.second;
				bb.minute-=1;
			}
			if(bb.minute>=aa.minute)
				cc.minute=bb.minute-aa.minute;
			else if(bb.minute<aa.minute)
			{
				bb.minute+=60;
				cc.minute=bb.minute-aa.minute;
				bb.hour-=1;
			}
			cc.hour=bb.hour-aa.hour;
			gotoxy(36,22);
			textcolor(8);
			cprintf("%d",cc.hour);
			cout<<":";
			cprintf("%d",cc.minute);
			cout<<":";
			cprintf("%d",cc.second);
			gotoxy(f,z);
			goto M;
		}
		else if(y=='d')
		{
			z+=2;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='l')
		{
			f-=4;
			gotoxy(f,z);
			goto M;
		}
		else if(y=='u')
		{
			z-=2;
			gotoxy(f,z);
			goto M;
		}
		else if((y>='1')&&(y<='9'))
		{
			int ne=0;
			for(int i=0;i<81;i++)
			{
				if((p[i][0]==f)&&(p[i][1]==z))
					ne++;
			}
			if(ne==0)
			{
				cout<<y;
				gotoxy(f,z);
			}
			goto M;
		}
		else if(y=='b')
		{
			back();
			delay(1000);
			classic(te2);
		}
		else if(y=='e')
			exit(0);
		goto M;
	}
}

// Function defining screen on which u play sudoku + sudoku grid
void easy(int &sg,int te)   
{
char a1=218,a2=191,a3=192,a4=217,a5=179,a6=196,a7=180,a8=193,a9=194,a10=195,a11=197;
	clrscr();
	brdr(15);
	gotoxy(60,3);
	if(te==6)
		cout<<".......BEGINNER";
	else if(te==5)
		cout<<"...INTERMEDIATE";
	else if(te==4)
		cout<<".........EXPERT";
	gotoxy(60,21);
	cprintf("[c] , if completed");
	gotoxy(65,22);
	cprintf("[b] for BACK");
	gotoxy(65,23);
	cprintf("[e] for EXIT");
	delay(100);
	gotoxy(8,3);
	cout<<a1<<a6<<a6<<a6<<a9<<a6<<a6<<a6<<a9<<a6<<a6<<a6<<a9<<a6<<a6<<a6<<a9<<a6<<a6<<a6<<a9<<a6<<a6<<a6<<a9<<a6<<a6<<a6<<a9<<a6<<a6<<a6<<a9<<a6<<a6<<a6<<a2;
	delay(50);
	gotoxy(8,4);
	cout<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5;
	delay(50);
	gotoxy(8,5);
	cout<<a10<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a7;
	delay(50);
	gotoxy(8,6);
	cout<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5;
	delay(50);
	gotoxy(8,7);
	cout<<a10<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a7;
	delay(50);
	gotoxy(8,8);
	cout<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5;
	delay(50);
	gotoxy(8,9);
	cout<<a10<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a7;
	delay(50);
	gotoxy(8,10);
	cout<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5;
	delay(50);
	gotoxy(8,11);
	cout<<a10<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a7;
	delay(50);
	gotoxy(8,12);
	cout<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5;
	delay(50);
	gotoxy(8,13);
	cout<<a10<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a7;
	delay(50);
	gotoxy(8,14);
	cout<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5;
	delay(50);
	gotoxy(8,15);
	cout<<a10<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a7;
	delay(50);
	gotoxy(8,16);
	cout<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5;
	delay(50);
	gotoxy(8,17);
	cout<<a10<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a7;
	delay(50);
	gotoxy(8,18);
	cout<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5;
	delay(50);
	gotoxy(8,19);
	cout<<a10<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a11<<a6<<a6<<a6<<a7;
	delay(50);
	gotoxy(8,20);
	cout<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5<<"   "<<a5;
	delay(50);
	gotoxy(8,21);
	cout<<a3<<a6<<a6<<a6<<a8<<a6<<a6<<a6<<a8<<a6<<a6<<a6<<a8<<a6<<a6<<a6<<a8<<a6<<a6<<a6<<a8<<a6<<a6<<a6<<a8<<a6<<a6<<a6<<a8<<a6<<a6<<a6<<a8<<a6<<a6<<a6<<a4;
	gotoxy(10,22);
	textcolor(8);
	cprintf("[t] for timer");
	delay(50);
	gotoxy(49,7);
	textcolor(3);
	cprintf("HINTS....");
	textcolor(15);
	gotoxy(56,9);
	cprintf("[l] to move LEFT");
	gotoxy(56,11);
	cprintf("[r] to move RIGHT");
	gotoxy(56,13);
	cprintf("[u] to move UP");
	gotoxy(56,15);
	cprintf("[d] to move DOWN");
	gotoxy(10,4);
	delay(100);
	char p1[9][9]={{'8','2','7','1','5','4','3','9','6'},{'9','6','5','3','2','7','1','4','8'},{'3','4','1','6','8','9','7','5','2'},{'5','9','3','4','6','8','2','7','1'},{'4','7','2','5','1','3','6','8','9'},{'6','1','8','9','7','2','4','3','5'},{'7','8','6','2','3','5','9','1','4'},{'1','5','4','7','9','6','8','2','3'},{'2','3','9','8','4','1','5','6','7'}};
	char p2[9][9]={{'2','4','6','8','5','7','9','1','3'},{'1','8','9','6','4','3','2','7','5'},{'5','7','3','2','9','1','4','8','6'},{'4','1','8','3','2','9','5','6','7'},{'6','3','7','4','8','5','1','2','9'},{'9','5','2','1','7','6','3','4','8'},{'7','6','4','5','3','2','8','9','1'},{'3','2','1','9','6','8','7','5','4'},{'8','9','5','7','1','4','6','3','2'}};
	char p3[9][9]={{'9','1','5','7','2','3','4','6','8'},{'7','6','3','8','9','4','5','2','1'},{'2','4','8','5','1','6','7','9','3'},{'4','8','2','6','7','5','3','1','9'},{'1','5','9','3','8','2','6','7','4'},{'6','3','7','9','4','1','2','8','5'},{'5','9','1','2','3','7','8','4','6'},{'8','2','6','4','5','9','1','3','7'},{'3','7','4','1','6','8','9','5','2'}};
	char p4[9][9]={{'4','1','7','5','2','3','6','9','8'},{'2','5','3','9','8','6','1','4','7'},{'9','8','6','1','7','4','3','2','5'},{'6','9','1','8','5','7','4','3','2'},{'5','3','2','4','6','9','8','7','1'},{'7','4','8','2','3','1','5','6','9'},{'3','7','9','6','1','5','2','8','4'},{'8','6','5','7','4','2','9','1','3'},{'1','2','4','3','9','8','7','5','6'}};
	char p5[9][9]={{'1','9','8','5','2','6','3','4','7'},{'7','2','5','3','4','1','6','9','8'},{'3','4','6','9','7','8','2','1','5'},{'9','8','1','2','5','7','4','6','3'},{'5','6','4','1','3','9','8','7','2'},{'2','3','7','6','8','4','1','5','9'},{'4','7','3','8','1','5','9','2','6'},{'8','1','9','7','6','2','5','3','4'},{'6','5','2','4','9','3','7','8','1'}};
	char p6[9][9]={{'3','9','4','1','7','2','5','8','6'},{'1','5','7','3','8','6','2','4','9'},{'2','8','6','9','4','5','7','1','3'},{'5','3','8','7','9','4','6','2','1'},{'9','4','1','2','6','3','8','7','5'},{'7','6','2','8','5','1','3','9','4'},{'4','1','3','5','2','8','9','6','7'},{'6','2','9','4','3','7','1','5','8'},{'8','7','5','6','1','9','4','3','2'}};
	randomize();
	char t[9][9];
	int c=random(6);
		if(c==0)
		{
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
					t[i][j]=p1[i][j];
			}
		}
		else if(c==1)
		{
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
					t[i][j]=p2[i][j];
			}
		}
		else if(c==2)
		{
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
					t[i][j]=p3[i][j];
			}
		}
		else if(c==3)
		{
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
					t[i][j]=p4[i][j];
			}
		}
		else if(c==4)
		{
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
					t[i][j]=p5[i][j];
			}
		}
		else if(c==5)
		{
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
					t[i][j]=p6[i][j];
			}
		}
	char z1[9][9];
	int p[80][2],o=0;
	for(int k=0,r=4;k<9;k++,r+=2)
	{
		for(int i=0;i<te;i++)
		{
			int v;
			int va[9];
			v=random(9);
			int ch=0;
			P:
			ch++;
			for(int j=0;j<=i;j++)
			{
				if(v==va[j])
				{
					if(ch==1)
						v=0;
					else if(ch>1)
						v++;
					goto P;
				}
				else if((v!=va[j])&&(j==i))
				{
					if(v==0)
					{
						gotoxy(10,r);
						textcolor(3);
						cprintf("%c",t[k][v]);
						p[o][0]=10;
						p[o++][1]=r;
						z1[k][v]=t[k][v];
					}
					else if(v==1)
					{
						gotoxy(14,r);
						textcolor(3);
						cprintf("%c",t[k][v]);
						p[o][0]=14;
						p[o++][1]=r;
						z1[k][v]=t[k][v];
					}
					else if(v==2)
					{
						gotoxy(18,r);
						textcolor(3);
						cprintf("%c",t[k][v]);
						p[o][0]=18;
						p[o++][1]=r;
						z1[k][v]=t[k][v];
					}
					else if(v==3)
					{
						gotoxy(22,r);
						textcolor(3);
						cprintf("%c",t[k][v]);
						p[o][0]=22;
						p[o++][1]=r;
						z1[k][v]=t[k][v];
					}
					else if(v==4)
					{
						gotoxy(26,r);
						textcolor(3);
						cprintf("%c",t[k][v]);
						p[o][0]=26;
						p[o++][1]=r;
						z1[k][v]=t[k][v];
					}
					else if(v==5)
					{
						gotoxy(30,r);
						textcolor(3);
						cprintf("%c",t[k][v]);
						p[o][0]=30;
						p[o++][1]=r;
						z1[k][v]=t[k][v];
					}
					else if(v==6)
					{
						gotoxy(34,r);
						textcolor(3);
						cprintf("%c",t[k][v]);
						p[o][0]=34;
						p[o++][1]=r;
						z1[k][v]=t[k][v];
					}
					else if(v==7)
					{
						gotoxy(38,r);
						textcolor(3);
						cprintf("%c",t[k][v]);
						p[o][0]=38;
						p[o++][1]=r;
						z1[k][v]=t[k][v];
					}
					else if(v==8)
					{
						gotoxy(42,r);
						textcolor(3);
						cprintf("%c",t[k][v]);
						p[o][0]=42;
						p[o++][1]=r;
						z1[k][v]=t[k][v];
					}
				}
			}
			va[i]=v;
		}
	}
	input(te,sg,z1,t,p,10,4,10,4,42,20);
}

// Function defining screen that gave you some options of level that you choose
void classic(int l1)  
{
char a1=218,a2=191,a3=192,a4=217,a5=179,a6=196;
	clrscr();
	brdr(15);
	gotoxy(20,8);
	textcolor(3);
	if(l1==1)
		cprintf("BEGINNER.....");
	if(l1==2)
		cprintf("INTERMEDIATE.");
	if(l1==3)
		cprintf("EXPERT.......");
	textcolor(8);
	gotoxy(65,23);
	cprintf("[b] for back");
	textcolor(15);
	gotoxy(20,11);
	cprintf("1. NEW GAME");
	gotoxy(20,13);
	cprintf("2. HIGH SCORE");
	gotoxy(20,15);
	cprintf("3. ABOUT");
	gotoxy(20,17);
	cprintf("4. EXIT");
	gotoxy(50,11);
	cprintf("ENTER YOUR CHOICE..");
	textcolor(1);
	gotoxy(55,12);
	cprintf("%c",a1);
	gotoxy(56,12);
	cprintf("%c",a6);
	gotoxy(57,12);
	cprintf("%c",a6);
	gotoxy(58,12);
	cprintf("%c",a2);
	gotoxy(55,13);
	cprintf("%c",a5);
	gotoxy(58,13);
	cprintf("%c",a5);
	gotoxy(55,14);
	cprintf("%c",a3);
	gotoxy(56,14);
	cprintf("%c",a6);
	gotoxy(57,14);
	cprintf("%c",a6);
	gotoxy(58,14);
	cprintf("%c",a4);
	gotoxy(56,13);
	textcolor(15);
	char l;
	P:
	char t=getch();
	cout<<t;
	switch(t)
	{
		case 'b':
		case 'B':clrscr();
			 type(st);
		case '1':if(l1==1)
				easy(h,6);
			 if(l1==2)
				easy(h,5);
			 if(l1==3)
				easy(h,4);
			 break;
		case '2':for(int i=35;i<=50;i++)
			 {
				for(int j=10;j<=14;j++)
				{
					gotoxy(i,j);
					cout<<" ";
				}
			 }
			 for(i=10;i<=14;i++)
			 {
				if(i==10)
				{
					for(int j=35;j<=50;j++)
					{
						gotoxy(j,i);
						if(j==35)
						{
							textcolor(15);
							cprintf("%c",a1);
						}
						if(j==50)
						{
							textcolor(15);
							cprintf("%c",a2);
						}
						else
						{
							textcolor(15);
							cprintf("%c",a6);
						}
					}
				}
				if((i==11)||(i==12)||(i==13))
				{
					for(int j=35;j<=50;j++)
					{
						gotoxy(j,i);
						if((j==35)||(j==50))
						{
							textcolor(15);
							cprintf("%c",a5);
						}
						else
							cout<<" ";
					}
				}
				if(i==14)
				{
					for(int j=35;j<=50;j++)
					{
						gotoxy(j,i);
						if(j==35)
						{
							textcolor(15);
							cprintf("%c",a3);
						}
						if(j==50)
						{
							textcolor(15);
							cprintf("%c",a4);
						}
						else
						{
							textcolor(15);
							cprintf("%c",a6);
						}
					}
				}
			 }
			 gotoxy(37,11);
			 textcolor(14);
			 cprintf("High score:");
			 int k=0,tpm1;
			 ff.open("hscr.txt",ios::binary|ios::in);
			 ff.seekg(0);
			 while(ff.read((char *)&hs,sizeof(hs)))
			 {
				 k++;
				 ahs[k-1]=hs;
			 }
			 ff.close();
			 for(int tm=0;tm<k-1;tm++)
			 {
				ahs1=ahs[tm];
				tpm1=tm;
				for(int j=tm+1;j<k;j++)
				{
					if(ahs[j].scr>ahs1.scr)
					{
						ahs1=ahs[j];
						tpm1=j;
					}
				}
				ahs[tpm1]=ahs[tm];
				ahs[tm]=ahs1;
			 }
			 gotoxy(40,12);
			 if(l1==1)
			 {
				for(int mo=0;mo<k;mo++)
				{
					if(strcmpi(ahs[mo].leve,"beginner")==0)
					{
						cout<<ahs[mo].scr;
						goto T;
					}
					else if(mo==k-1)
					{
						cout<<"0";
						goto T;
					}
				}
			 }
			 else if(l1==2)
			 {
				for(int mo=0;mo<k;mo++)
				{
					if(strcmpi(ahs[mo].leve,"intermediate")==0)
					{
						cout<<ahs[mo].scr;
						goto T;
					}
					else if(mo==k-1)
					{
						cout<<"0";
						goto T;
					}
				}
			 }
			 else if(l1==3)
			 {
				for(int mo=0;mo<k;mo++)
				{
					if(strcmpi(ahs[mo].leve,"expert")==0)
					{
						cout<<ahs[mo].scr;
						goto T;
					}
					else if(mo==k-1)
					{
						cout<<"0";
						goto T;
					}
				}
			 }
			 T:
			 getch();
			 classic(l1);
			 break;
		case '3':about();
			 gotoxy(16,11);
			 textcolor(15);
			 cprintf("This puzzle consist of ");
			 textcolor(14);
			 cprintf("9X9 ");
			 textcolor(15);
			 cprintf("grid containing");
			 gotoxy(16,12);
			 cprintf("given clues in various places. The object ");
			 gotoxy(16,13);
			 cprintf("is to fill all empty places so that no. from");
			 gotoxy(16,14);
			 cprintf("1 to 9 appear once in each ");
			 textcolor(14);
			 cprintf("row, column, 3X3 box.");
			 getch();
			 classic(l1);
			 break;
		case '4':exit(0);
		default:gotoxy(60,20);
			textcolor(1+BLINK);
			cprintf("WRONG INPUT");
			delay(1000);
			textcolor(1);
			gotoxy(60,21);
			cprintf("ENTER AGAIN");
			gotoxy(56,13);
			cout<<" ";
			gotoxy(57,13);
			cout<<" ";
			gotoxy(56,13);
			delay(1000);
			for(i=59;i<=70;i++)
			{
				for(int j=20;j<=21;j++)
				{
					gotoxy(i,j);
					cout<<" ";
				}
			}
			gotoxy(56,13);
			goto P;
	}
}

// Function defining screen on which you enter the level of sudoku you want to play
void type(char str[20])   
{
	M:
	char a1=218,a2=191,a3=192,a4=217,a5=179,a6=196,a14=248;
	clrscr();
	brdr(7);
	for(int i=2;i<=23;i++)
	{
		if(i==2)
		{
			for(int j=25;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==27)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==3)
		{
			for(int j=25;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==45)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==6)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if((j==5)||(j==10)||(j==22))
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==7)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if((j==15)||(j==19))
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==8)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==4)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==9)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==7)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==10)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==12)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==11)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==9)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==12)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==7)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==13)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==8)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==14)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if((j==5)||(j==10))
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==15)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==9)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==16)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if((j==6)||(j==10))
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==17)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if((j==8)||(j==12))
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==18)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==7)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==19)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==9)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==20)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==7)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==21)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==9)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==22)
		{
			for(int j=3;j<=77;j++)
			{
				gotoxy(j,i);
				if(j==8)
				{
					textcolor(4);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
	}
	delay(100);
	textcolor(4);
	gotoxy(3,3);
	cprintf("HEY..!! ");
	cout<<str;
	gotoxy(3,4);
	cprintf("WHICH LEVEL OF SUDOKU WOULD YOU LIKE TO PLAY....??");
	delay(1000);
	for(i=9;i<=20;i++)
	{
		gotoxy(40,i);
		if(i==10)
		{
			textcolor(15);
			cprintf("1. BEGINNER");
		}
		if(i==12)
		{
			textcolor(15);
			cprintf("2. INTERMEDIATE");
		}
		if(i==14)
		{
			textcolor(15);
			cprintf("3. EXPERT");
		}
		if(i==16)
		{
			textcolor(15);
			cprintf("4. BEST SCORES");
		}
		if(i==18)
		{
			textcolor(15);
			cprintf("5. BEST TIME RECORDS");
		}
	}
	gotoxy(8,6);
	textcolor(15);
	cprintf("ENTER YOUR CHOICE ....");
	textcolor(4);
	gotoxy(4,23);
	cprintf("[e] for exit");
	gotoxy(18,7);
	cprintf("%c",a1);
	gotoxy(19,7);
	cprintf("%c",a6);
	gotoxy(20,7);
	cprintf("%c",a6);
	gotoxy(21,7);
	cprintf("%c",a2);
	gotoxy(18,8);
	cprintf("%c",a5);
	gotoxy(21,8);
	cprintf("%c",a5);
	gotoxy(18,9);
	cprintf("%c",a3);
	gotoxy(19,9);
	cprintf("%c",a6);
	gotoxy(20,9);
	cprintf("%c",a6);
	gotoxy(21,9);
	cprintf("%c",a4);
	gotoxy(19,8);
	P:
	char g=getch();
	switch(g)
	{
		case '1':classic(1);
			 break;
		case '2':classic(2);
			 break;
		case '3':classic(3);
			 break;
		case '4':about();
			 gotoxy(35,10);
			 cout<<"BEST SCORES";
			 int k=0,tpm1;
			 ff.open("hscr.txt",ios::binary|ios::in);
			 ff.seekg(0);
			 while(ff.read((char *)&hs,sizeof(hs)))
			 {
				 k++;
				 ahs[k-1]=hs;
			 }
			 ff.close();
			 for(int tm=0;tm<k-1;tm++)
			 {
				ahs1=ahs[tm];
				tpm1=tm;
				for(int j=tm+1;j<k;j++)
				{
					if(ahs[j].scr>ahs1.scr)
					{
						ahs1=ahs[j];
						tpm1=j;
					}
				}
				ahs[tpm1]=ahs[tm];
				ahs[tm]=ahs1;
			 }
			 for(int zq=0;zq<k;zq++)
			 {
				if(zq<5)
				{
					gotoxy(20,12+zq);
					cout<<zq+1<<". "<<setw(10)<<ahs[zq].name<<setw(15)<<ahs[zq].leve<<setw(10)<<ahs[zq].scr<<endl;
				}
			 }
			 getch();
			 textcolor(WHITE);
			 goto M;
		case '5':about();
			 gotoxy(32,10);
			 cout<<"BEST TIME RECORDS";
			 int o=0,tpm11;
			 xx.open("btmr.txt",ios::binary|ios::in);
			 xx.seekg(0);
			 while(xx.read((char *)&mr,sizeof(mr)))
			 {
				 o++;
				 amr[o-1]=mr;
			 }
			 xx.close();
			 for(tm=0;tm<o-1;tm++)
			 {
				amr1=amr[tm];
				tpm11=tm;
				for(int j=tm+1;j<o;j++)
				{
					if(amr[j].tmr.hour<amr1.tmr.hour)
					{
						amr1=amr[j];
						tpm11=j;
					}
					else if(amr[j].tmr.hour==amr1.tmr.hour)
					{
						if(amr[j].tmr.minute<amr1.tmr.minute)
						{
							amr1=amr[j];
							tpm11=j;
						}
						else if(amr[j].tmr.minute==amr1.tmr.minute)
						{
							if(amr[tm].tmr.second<=amr1.tmr.second)
							{
								amr1=amr[j];
								tpm11=j;
							}
						}
					}
				}
				amr[tpm11]=amr[tm];
				amr[tm]=amr1;
			 }
			 for(zq=0;zq<o;zq++)
			 {
				if(zq<5)
				{
					gotoxy(20,12+zq);
					textcolor(WHITE);
					cout<<zq+1<<". "<<setw(10)<<amr[zq].name<<setw(15)<<amr[zq].leve<<"  \t";
					cprintf("%d",amr[zq].tmr.hour);
					cout<<":";
					cprintf("%d",amr[zq].tmr.minute);
					cout<<":";
					cprintf("%d",amr[zq].tmr.second);
					cout<<endl;
				}
			 }
			 getch();
			 textcolor(WHITE);
			 goto M;
		CASE 'E':
		case 'e':exit(0);
			break;
		default:gotoxy(19,11);
				textcolor(RED+BLINK);
				cout<<"wrong choice";
				delay(1000);
				textcolor(RED);
				gotoxy(19,12);
				cprintf("ENTER AGAIN");
				gotoxy(19,8);
				cout<<" ";
				gotoxy(20,8);
				cout<<" ";
				gotoxy(19,8);
				delay(1000);
				for(int i=19;i<=35;i++)
				{
					for(int j=11;j<=12;j++)
					{
						gotoxy(i,j);
						cout<<" ";
					}
				}
				gotoxy(19,8);
				goto P;
			textcolor(15);
	}
}

// Function to design the second page on which player have to enter name + name input
void name()  
{
char a1=218,a2=191,a3=192,a4=217,a5=179,a6=196,a7=180,a10=195,a12=47,a13=92,a14=248,a15=220;
	clrscr();
	for(int i=3;i<=24;i++)
	{
	gotoxy(3,i);
		if(i==3)
		{
			for(int j=3;j<=80;j++)
			{
				if(j==6)
				{
					textcolor(15);
					cprintf("%c",a1);
					delay(50);
				}
				else if(j==7)
				{
					textcolor(15);
					cprintf("%c",a2);
					delay(50);
				}
				else if(j==8)
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else if(j==11)
				{
					textcolor(15);
					cprintf("%c",a3);
					delay(50);
				}
				else if(j==12)
				{
					textcolor(15);
					cprintf("%c",a4);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==4)
		{
			for(int j=3;j<=80;j++)
			{
				if((j==5)||(j==12))
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else if(j==6)
				{
					textcolor(15);
					cprintf("%c",a3);
					delay(50);
				}
				else if(j==7)
				{
					textcolor(15);
					cprintf("%c",a4);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==5)
		{
			for(int j=3;j<=80;j++)
			{
				if((j==5)||(j==7))
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==6)
		{
			for(int j=3;j<=80;j++)
			{
				if((j==6)||(j==9))
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else if(j==3)
				{
					textcolor(15);
					cprintf("%c",a1);
					delay(50);
				}
				else if(j==4)
				{
					textcolor(15);
					cprintf("%c",a2);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==7)
		{
			for(int j=3;j<=80;j++)
			{
				if(j==5)
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else if(j==3)
				{
					textcolor(15);
					cprintf("%c",a3);
					delay(50);
				}
				else if(j==4)
				{
					textcolor(15);
					cprintf("%c",a4);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==8)
		{
			for(int j=3;j<=80;j++)
			{
				if(j==7)
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==9)
		{
			for(int j=3;j<=80;j++)
			{
				if(j==4)
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==10)
		{
			for(int j=3;j<=80;j++)
			{
				if((j==5)||(j==8))
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==14)
		{
			for(int j=3;j<=80;j++)
			{
				if(j==4)
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				if((j==71)||(j==75))
				{
					textcolor(RED+BLINK);
					cprintf("o");
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==12)
		{
			for(int j=3;j<=10;j++)
			{
				if(j==4)
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==13)
		{
			for(int j=3;j<=10;j++)
			{
				if(j==8)
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==11)
		{
			for(int j=3;j<=10;j++)
			{
				if(j==5)
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==15)
		{
			for(int j=3;j<=80;j++)
			{
				if((j==7)||(j==6))
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				if((j==70)||(j==73))
				{
					textcolor(15);
					cprintf("%c",a5);
					delay(50);
				}
				if((j>=70)&&(j<=72))
				{
					textcolor(10);
					cprintf("_");
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==16)
		{
			for(int j=3;j<=80;j++)
			{
				if((j==8)||(j==68))
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else if(j==71)
				{
					textcolor(10);
					cprintf("%c",a12);
					delay(50);
				}
				else if(j==77)
				{
					textcolor(10);
					cprintf("%c",a13);
					delay(50);
				}
				else if((j>=73)&&(j<=75))
				{
					textcolor(10);
					cprintf("_");
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==17)
		{
			for(int j=3;j<=80;j++)
			{
				if((j==5)||(j==66))
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else if(j==6)
				{
					textcolor(15);
					cprintf("%c",a1);
					delay(50);
				}
				else if(j==7)
				{
					textcolor(15);
					cprintf("%c",a2);
					delay(50);
				}
				else if(j==70)
				{
					textcolor(10);
					cprintf("%c",a12);
					delay(50);
				}
				else if(j==78)
				{
					textcolor(10);
					cprintf("%c",a13);
					delay(50);
				}
				else if(j==68)
				{
					textcolor(10);
					cprintf("%c",a1);
					delay(50);
				}
				else if((j==69)||(j==79))
				{
					textcolor(10);
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==80)
				{
					textcolor(10);
					cprintf("%c",a2);
					delay(50);
				}
				else if((j==72)||(j==76))
				{
					textcolor(10);
					cprintf("%c",a5);
					delay(50);
				}
				else if((j==73)||(j==75))
				{
					textcolor(RED);
					cprintf("%c",a14);
					delay(50);
				}
				else if(j==74)
				{
					textcolor(2);
					cprintf("%c",a6);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==18)
		{
			for(int j=3;j<=80;j++)
			{
				if((j==4)||(j==8)||(j==67))
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else if(j==65)
				{
					textcolor(15);
					cprintf("%c",a1);
					delay(50);
				}
				else if(j==66)
				{
					textcolor(15);
					cprintf("%c",a2);
					delay(50);
				}
				else if(j==6)
				{
					textcolor(15);
					cprintf("%c",a3);
					delay(50);
				}
				else if(j==7)
				{
					textcolor(15);
					cprintf("%c",a4);
					delay(50);
				}
				else if(j==72)
				{
					textcolor(10);
					cprintf("%c",a3);
					delay(50);
				}
				else if(j==76)
				{
					textcolor(10);
					cprintf("%c",a4);
					delay(50);
				}
				else if((j>=73)&&(j<=75))
				{
					textcolor(10);
					cprintf("%c",a6);
					delay(50);
				}
				else if((j==68)||(j==70)||(j==78)||(j==80))
				{
					textcolor(10);
					cprintf("%c",a5);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==19)
		{
			for(int j=3;j<=80;j++)
			{
				if((j==17)||(j==64)||(j==67))
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else if(j==62)
				{
					textcolor(15);
					cprintf("%c",a6);
					delay(50);
				}
				else if((j==69)||(j==79))
				{
					textcolor(10);
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==70)
				{
					textcolor(10);
					cprintf("%c",a7);
					delay(50);
				}
				else if(j==71)
				{
					textcolor(10);
					cprintf("%c",a13);
					delay(50);
				}
				else if(j==72)
				{
					textcolor(10);
					cprintf("_");
					delay(50);
				}
				else if(j==73)
				{
					textcolor(10);
					cprintf("%c",a15);
					delay(50);
				}
				else if(j==78)
				{
					textcolor(10);
					cprintf("%c",a10);
					delay(50);
				}
				else if((j==14)||(j==61))
				{
					textcolor(15);
					cprintf("%c",a1);
					delay(50);
				}
				else if((j==15)||(j==63))
				{
					textcolor(15);
					cprintf("%c",a2);
					delay(50);
				}
				else if(j==65)
				{
					textcolor(15);
					cprintf("%c",a3);
					delay(50);
				}
				else if(j==68)
				{
					textcolor(10);
					cprintf("%c",a3);
					delay(50);
				}
				else if(j==66)
				{
					textcolor(15);
					cprintf("%c",a4);
					delay(50);
				}
				else if(j==80)
				{
					textcolor(10);
					cprintf("%c",a4);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==20)
		{
			for(int j=3;j<=80;j++)
			{
				if((j==6)||(j==12)||(j==20)||(j==30)||(j==55)||(j==58))
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else if((j==10)||(j==62)||(j==66))
				{
					textcolor(15);
					cprintf("%c",a6);
					delay(50);
				}
				else if((j==70)||(j==78))
				{
					textcolor(10);
					cprintf("%c",a5);
					delay(50);
				}
				else if((j>=71)&&(j<=77))
				{
					textcolor(10);
					cprintf("_");
					delay(50);
				}
				else if((j==9)||(j==57)||(j==65)||(j==65))
				{
					textcolor(15);
					cprintf("%c",a1);
					delay(50);
				}
				else if((j==11)||(j==58)||(j==67))
				{
					textcolor(15);
					cprintf("%c",a2);
					delay(50);
				}
				else if((j==14)||(j==61))
				{
					textcolor(15);
					cprintf("%c",a3);
					delay(50);
				}
				else if((j==15)||(j==63))
				{
					textcolor(15);
					cprintf("%c",a4);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==21)
		{
			for(int j=3;j<=80;j++)
			{
				if((j==16)||(j==25)||(j==63)||(j==70))
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else if((j==10)||(j==66))
				{
					textcolor(15);
					cprintf("%c",a6);
					delay(50);
				}
				else if((j==75)||(j==73))
				{
					textcolor(10);
					cprintf("%c",a5);
					delay(50);
				}
				else if((j==9)||(j==57)||(j==65))
				{
					textcolor(15);
					cprintf("%c",a3);
					delay(50);
				}
				else if((j==11)||(j==67)||(j==58))
				{
					textcolor(15);
					cprintf("%c",a4);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
		if(i==22)
		{
			for(int j=3;j<=80;j++)
			{
				if((j==7)||(j==11)||(j==52)||(j==60))
				{
					textcolor(14);
					cprintf("%c",a14);
					delay(50);
				}
				else if((j==14)||(j==15))
				{
					textcolor(15);
					cprintf("%c",a6);
					delay(50);
				}
				else if((j==71)||(j==72)||(j==77)||(j==76))
				{
					textcolor(10);
					cprintf("%c",a6);
					delay(50);
				}
				else if(j==73)
				{
					textcolor(10);
					cprintf("%c",a4);
					delay(50);
				}
				else if(j==75)
				{
					textcolor(10);
					cprintf("%c",a3);
					delay(50);
				}
				else if(j==16)
				{
					textcolor(15);
					cprintf("%c",a2);
					delay(50);
				}
				else if(j==13)
				{
					textcolor(15);
					cprintf("%c",a1);
					delay(50);
				}
				else
					cout<<" ";
			}
		}
	}
	name1();
}

// Function to design screen on which you enter name
void name1()
{
char a1=218,a2=191,a3=192,a4=217,a5=179,a6=196,a7=180,a8=193,a9=194,a10=195,a12=47,a13=92,a14=248;
	delay(1000);
	for(int i=3;i<=9;i++)
	{
		if(i==3)
		{
			for(int j=16;j<=23;j++)
			{
				gotoxy(j,i);
				if((j==18)||(j==22))
				{
					textcolor(RED);
					cprintf("o");
				}
				else
					cout<<" ";
			}
		}
		if(i==4)
		{
			for(int j=16;j<=23;j++)
			{
				gotoxy(j,i);
				if((j==18)||(j==22))
				{
					textcolor(10);
					cprintf("%c",a8);
				}
				else if(j==17)
				{
					textcolor(10);
					cprintf("%c",a1);
				}
				else if(j==23)
				{
					textcolor(10);
					cprintf("%c",a2);
				}
				else if((j>=19)&&(j<=21))
				{
					textcolor(10);
					cprintf("%c",a6);
				}
				else
					cout<<" ";
			}
		}
		if(i==5)
		{
			for(int j=13;j<=27;j++)
			{
				gotoxy(j,i);
				if(j==16)
				{
					textcolor(10);
					cprintf("%c",a1);
				}
				else if(j==17)
				{
					textcolor(10);
					cprintf("%c",a7);
				}
				else if(j==23)
				{
					textcolor(10);
					cprintf("%c",a10);
				}
				else if(j==24)
				{
					textcolor(10);
					cprintf("%c",a2);
				}
				else if(j==20)
				{
					textcolor(10);
					cprintf("_");
				}
				else if((j==19)||(j==21))
				{
					textcolor(RED);
					cprintf("%c",a14);
				}
				else
					cout<<" ";
			}
		}
		if(i==6)
		{
			for(int j=13;j<=27;j++)
			{
				gotoxy(j,i);
				if(j==16)
				{
					textcolor(10);
					cprintf("%c",a3);
				}
				else if(j==17)
				{
					textcolor(10);
					cprintf("%c",a7);
				}
				else if(j==23)
				{
					textcolor(10);
					cprintf("%c",a10);
				}
				else if(j==24)
				{
					textcolor(10);
					cprintf("%c",a4);
				}
				else
					cout<<" ";
			}
		}
		if(i==7)
		{
			for(int j=13;j<=27;j++)
			{
				gotoxy(j,i);
				if(j==23)
				{
					textcolor(10);
					cprintf("%c",a4);
				}
				else if(j==17)
				{
					textcolor(10);
					cprintf("%c",a3);
				}
				else if((j==22)||(j==18)||(j==20))
				{
					textcolor(10);
					cprintf("%c",a6);
				}
				else if((j==19)||(j==21))
				{
					textcolor(10);
					cprintf("%c",a9);
				}
				else
					cout<<" ";
			}
		}
		if(i==8)
		{
			for(int j=13;j<=27;j++)
			{
				gotoxy(j,i);
				if(j==15)
				{
					textcolor(10);
					cprintf("%c",a1);
				}
				else if(j==25)
				{
					textcolor(10);
					cprintf("%c",a2);
				}
				else if((j==19)||(j==21))
				{
					textcolor(10);
					cprintf("%c",a8);
				}
				else if((j==20)||((j>=16)&&(j<=18))||((j>=22)&&(j<=24)))
				{
					textcolor(10);
					cprintf("%c",a6);
				}
				else
					cout<<" ";
			}
		}
		if(i==9)
		{
			for(int j=13;j<=27;j++)
			{
				gotoxy(j,i);
				if((j>=15)&&(j<=25))
				{
					textcolor(10);
					cprintf("_");
				}
				else if(j==14)
				{
					textcolor(10);
					cprintf("%c",a12);
				}
				else if(j==26)
				{
					textcolor(10);
					cprintf("%c",a13);
				}
				else
					cout<<" ";
			}
		}
	}
	delay(100);
	for(i=5;i<=8;i++)
	{
		if(i==5)
		{
			for(int j=27;j<=55;j++)
			{
				gotoxy(j,i);
				if((j==27)||(j==28))
				{
					textcolor(15);
					cprintf("_");
				}
				else if(j==29)
				{
					textcolor(15);
					cprintf("%c",a1);
				}
				else if(j==55)
				{
					textcolor(15);
					cprintf("%c",a2);
				}
				else if((j>=30)&&(j<=54))
				{
					textcolor(15);
					cprintf("%c",a6);
				}
				else
					cout<<" ";
			}
		}
		if(i==6)
		{
			for(int j=27;j<=55;j++)
			{
				gotoxy(j,i);
				if(j==27)
				{
					textcolor(15);
					cprintf("%c",a13);
				}
				else if(j==55)
				{
					textcolor(15);
					cprintf("%c",a5);
				}
				else
					cout<<" ";
			}
		}
		if(i==7)
		{
			for(int j=27;j<=55;j++)
			{
				gotoxy(j,i);
				if(j==28)
				{
					textcolor(15);
					cprintf("%c",a13);
				}
				else if(j==55)
				{
					textcolor(15);
					cprintf("%c",a5);
				}
				else
					cout<<" ";
			}
		}
		if(i==8)
		{
			for(int j=29;j<=55;j++)
			{
				gotoxy(j,i);
				if(j==29)
				{
					textcolor(15);
					cprintf("%c",a3);
				}
				else if(j==55)
				{
					textcolor(15);
					cprintf("%c",a4);
				}
				else if((j>=30)&&(j<=54))
				{
					textcolor(15);
					cprintf("%c",a6);
				}
				else
					cout<<" ";
			}
		}
	}
	gotoxy(31,7);
	textcolor(10);
	delay(1000);
	cprintf("HYE....");
	delay(1000);
	for(i=31;i<=48;i++)
	{
		gotoxy(i,7);
		cout<<" ";
	}
	gotoxy(31,7);
	cprintf("I AM ROBO.");
	delay(1000);
	for(i=31;i<=48;i++)
	{
		gotoxy(i,7);
		cout<<" ";
	}
	gotoxy(31,7);
	cprintf("WHAT'S YOUR NAME...???");
	delay(100);
	for(i=11;i<=18;i++)
	{
		if(i==11)
		{
			for(int j=53;j<=62;j++)
			{
				gotoxy(j,i);
				if((j>=56)&&(j<=59))
				{
					textcolor(2);
					cprintf("_");
				}
				else
					cout<<" ";
			}
		}
		if(i==12)
		{
			for(int j=53;j<=62;j++)
			{
				gotoxy(j,i);
				if(j==55)
				{
					textcolor(2);
					cprintf("%c",a12);
				}
				if(j==60)
				{
					textcolor(2);
					cprintf("%c",a13);
				}
				else
					cout<<" ";
			}
		}
		if(i==13)
		{
			for(int j=30;j<=62;j++)
			{
				gotoxy(j,i);
				if(j==30)
				{
					textcolor(2);
					cprintf("%c",a1);
				}
				if((j>=31)&&(j<=50))
				{
					textcolor(2);
					cprintf("%c",a6);
				}
				if(j==51)
				{
					textcolor(2);
					cprintf("%c",a2);
				}
				if(j==54)
				{
					textcolor(2);
					cprintf("<");
				}
				if((j==56)||(j==59))
				{
					textcolor(8);
					cprintf("%c",a14);
				}
				if((j==57)||(j==58))
				{
					textcolor(2);
					cprintf("_");
				}
				if(j==61)
				{
					textcolor(2);
					cprintf(">");
				}
				else
					cout<<" ";
			}
		}
		if(i==14)
		{
			for(int j=30;j<=62;j++)
			{
				gotoxy(j,i);
				if((j==51)||(j==30))
				{
					textcolor(2);
					cprintf("%c",a5);
				}
				if((j==52)||(j==53)||((j>=56)&&(j<=59)))
				{
					textcolor(2);
					cprintf("_");
				}
				if(j==55)
				{
					textcolor(2);
					cprintf("%c",a13);
				}
				if(j==60)
				{
					textcolor(2);
					cprintf("%c",a12);
				}
				else
					cout<<" ";
			}
		}
		if(i==15)
		{
			for(int j=30;j<=62;j++)
			{
				gotoxy(j,i);
				if(j==30)
				{
					textcolor(2);
					cprintf("%c",a5);
				}
				if((j==53)||(j==54))
				{
					textcolor(2);
					cprintf("%c",a12);
				}
				if(j==57)
				{
					textcolor(RED);
					cprintf("<");
				}
				if(j==58)
				{
					textcolor(RED);
					cprintf(">");
				}
				if(j==61)
				{
					textcolor(2);
					cprintf("%c",a13);
				}
				else
					cout<<" ";
			}
		}
		if(i==16)
		{
			for(int j=30;j<=62;j++)
			{
				gotoxy(j,i);
				if(j==30)
				{
					textcolor(2);
					cprintf("%c",a5);
				}
				if((j==51)||((j>=54)&&(j<=56))||((j>=59)&&(j<=61)))
				{
					textcolor(2);
					cprintf("_");
				}
				if((j==52)||(j==53))
				{
					textcolor(2);
					cprintf("%c",a12);
				}
				if(j==57)
				{
					textcolor(RED);
					cprintf("%c",a12);
				}
				if(j==62)
				{
					textcolor(2);
					cprintf("%c",a13);
				}
				if(j==58)
				{
					textcolor(RED);
					cprintf("%c",a13);
				}
				else
					cout<<" ";
			}
		}
		if(i==17)
		{
			for(int j=30;j<=62;j++)
			{
				gotoxy(j,i);
				if(j==30)
				{
					textcolor(2);
					cprintf("%c",a3);
				}
				if(j==51)
				{
					textcolor(2);
					cprintf("%c",a4);
				}
				if((j>=31)&&(j<=50))
				{
					textcolor(2);
					cprintf("%c",a6);
				}
				else
					cout<<" ";
			}
		}
	}
	PR:
	gotoxy(35,15);
	textcolor(15);
	gets(st);
	int fd=0;
	for(i=0;i<strlen(st);i++)
	{
		if(!(isalpha(st[i])||isspace(st[i])))
			fd++;
	}
	if((fd>0)||(st[0]=='\0'))
	{
		gotoxy(35,15);
		cout<<"[wrong input]";
		delay(1000);
		gotoxy(35,15);
		for(int j=0;j<16;j++)
			cout<<" ";
		goto PR;
	}
	type(st);
}

// Main Function to start
void main()
{
	clrscr();
	brdr();
	frnt();
	guidr();
	dandd();
	name();
	getch();
}
