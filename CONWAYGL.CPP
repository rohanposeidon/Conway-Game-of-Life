#include<bits/stdc++.h>
extern "C" _CRTIMP int __cdecl	getch(void);
using namespace std;
char name[9]="\0",loc[11]="CONWAYGL\\";
unsigned char a[72][240];
int savpos=1,cpo[2];
ifstream ifs;
ofstream ofs;
void accept(), accept_cases(int,int,int), display(),load(), run_game(), screenshot();
int main()
{
	for (int i=0;i<72;i++)
		for (int j=0;j<240;j++)
			a[i][j]=249;
	cout<<"CONWAY'S GAME OF LIFE\n\nThe Game of Life is not your typical computer game. It is a 'cellular automaton'\nand was invented by Cambridge mathematician John Conway.\nThis game became widely known when it was mentioned in an article published by\nScientific American in 1970. It consists of a collection of cells which, based\non a few mathematical rules, can live, die or multiply. Depending on the initial\nconditions, the cells form various patterns throughout the course of the game.\n\nGeneral UI Instructions:\n1. Throughout the programme, use the keys w(^), a(<), s(v) and d(>) to navigate.\n2. Press Esc in the menu screen to exit the game.\n3. Follow instructions given at the end of the menu screen for using the\n   subsequent option from the menu.\n4. Screenshots taken are saved in the folder named \"CONWAYGL\" in the local directory.\n\nPress any key...";
	getch();
	int op=1, rposi=0;
	unsigned char t[4]={251,' ',' ',' '}, fil[6]={251,' ',' ',' ',' ',' '};
	for (unsigned char rpos=1, direc='\0';direc!=27;)
	{
		for (direc='\0';direc!=13&&direc!=27;)
		{
			system("cls");
			cout<<"CONWAY'S GAME OF LIFE\n\n\n\n\n MENU\n\n"<<t[0]<<" Accept data and Run game\n"<<t[1]<<" Resume\n"<<t[2]<<" Load\n"<<t[3]<<" Rules\n\n\n\n\n\n\n\n";
			switch (op)
			{
				case 1:
					cout<<"Use the keys w(^), a(<), s(v) and d(>) to navigate, space to resurrect a dead\ncell or kill a live cell and then enter to start the game or Esc to return here.\nAll cells are dead by default. During the game, press s to take a screenshot,\nEsc to return here and any other key to continue the animation.";
					break;
				case 2:
					cout<<"Resume the game where you left off just now after making changes if required.";
					break;
				case 3:
					cout<<"Select from a list of preinstalled games or load your own previous game after\nentering the name of the screenshot.";
					break;
				case 4:
					cout<<"Here you will find the rules based upon which the Conway's Game of Life works.";
			}	
			direc=getch();
			switch (direc)
			{
				case 'w':
					if (op!=1)
					{
						op--;
						for (int i=0;i<4;i++)
							t[i]=' ';
						t[op-1]=251;
					}
					break;
				case 's':
					if (op!=4)
					{
						op++;
						for (int i=0;i<4;i++)
							t[i]=' ';
						t[op-1]=251;
					}
			}
		}
		if (direc!=27)
			switch (op)
			{
				case 1:
					for (int i=0;i<72;i++)
						for (int j=0;j<240;j++)
							a[i][j]=249;
					accept();
					break;
				case 2:
					for (char x,y,dir='a';dir!=13&&dir!=27;)
					{
						system("cls");
						if (rpos==1)
						{
							x=251;
							y=' ';
						}
						else
						{
							x=' ';
							y=251;
						}
						cout<<"Any changes required?\n\n"<<x<<" Yes        "<<y<<" No\n\nPress Esc to return to menu.";
						dir=getch();
						switch (dir)
						{
							case 'a':
								if (rpos==2)
									rpos--;
								break;
							case 'd':
								if (rpos==1)
									rpos++;
								break;
							case 13:
								if (rpos==1)
									accept();
								else
								{
									display();
									run_game();
								}
							case 27:
								break;
						}
					}
					break;
				case 3:
					for (char dire='\0',lflag=0;dire!=13&&dire!=27;)
					{
						system("cls");
						cout<<"Choose screenshot:\n\n"<<fil[0]<<" Exploder\n"<<fil[1]<<" Glider\n"<<fil[2]<<" Glider Gun\n"<<fil[3]<<" Spaceship\n"<<fil[4]<<" Tumbler\n"<<fil[5]<<" Custom...\n\nPress Esc to return to menu.";
						dire=getch();
						switch (dire)
						{
							case 'w':
								if (rposi!=0)
								{
									rposi--;
									for (int i=0;i<6;i++)
										fil[i]=' ';
									fil[rposi]=251;
								}
								break;
							case 's':
								if (rposi!=5)
								{
									rposi++;
									for (int j=0;j<6;j++)
										fil[j]=' ';
									fil[rposi]=251;
								}
								break;
							case 13:
								system("cls");
								switch (rposi)
								{
									case 0:
										strcpy(name,"__EXP_");
										break;
									case 1:
										strcpy(name,"__GLI_");
										break;
									case 2:
										strcpy(name,"__GUN_");
										break;
									case 3:
										strcpy(name,"__SPS_");
										break;
									case 4:
										strcpy(name,"__TBR_");
										break;
									case 5:
										cout<<"Custom Load\nPress Esc to return to menu.\n\nEnter screenshot name (max. 7 alpha-numerical char., rest will be ignored):\n";
										for (int i=0,wflag=1;wflag;i++)
										{
											char ch=getch();
											ch=toupper(ch);
											if (ch==27)
											{
												ch='a';
												lflag=5;
												break;
											}
											else if (isalnum(ch)&&i<7)
											{
												name[i]=ch;
												cout<<ch;
											}
											else if (ch==8&&i>0)
											{
												system("cls");
												name[i-1]='\0';
												i-=2;
												cout<<"Custom Load\nPress Esc to return to menu.\n\nEnter screenshot name (max. 7 alpha-numerical char., rest will be ignored):\n"<<name;
											}
											else if (i==0&&ch==8)
												i=-1;
											else if (ch!=13&&ch!=8)
												i--;
											else if (i!=0)
											{
												name[i]='\0';
												wflag=0;
											}
											else
												i--;
										}
										name[7]='\0';
								}
								if (lflag==0)
								{
									load();
									strcpy(name,"\0");
								}
							case 27:
								break;
						}
					}
					break;
				case 4:
					system("cls");
					cout<<"RULES:\n\nFor a space that is 'populated':\n    "<<(char)175<<"Each cell with one or no neighbour dies, as if by solitude.\n    "<<(char)175<<"Each cell with two or three neighbours survives.\n    "<<(char)175<<"Each cell with four or more neighbours dies, as if by overpopulation.\n\nFor a space that is 'unpopulated':\n    "<<(char)175<<"Each cell with three neighbours becomes populated, as if by reproduction.\n\nPress any key...";
					getch();
			}
	}
	system("cls");
	cout<<"Press any key to exit...";
	getch();
}

void accept()
{
	cpo[0]=36;
	cpo[1]=120;
	if (a[36][120]!=254)
		a[36][120]='_';
	else
		a[36][120]='?';
	char ch;
	for (ch='\0';ch!=13&&ch!=27;)
	{
		display();
		do
		{
			ch=getch();
			switch (ch)
			{
				case 'w':
					accept_cases(0,24,-1);
					break;
				case 'a':
					accept_cases(1,80,-1);
					break;
				case 's':
					accept_cases(0,47,+1);
					break;
				case 'd':
					accept_cases(1,159,+1);
					break;
				case ' ':
					if (a[cpo[0]][cpo[1]]!=254&&a[cpo[0]][cpo[1]]!='?')
						a[cpo[0]][cpo[1]]=254;
					else
						a[cpo[0]][cpo[1]]=249;
			}
		}
		while (ch!='w'&&ch!='a'&&ch!='s'&&ch!='d'&&ch!=13&&ch!=' '&&ch!=27);
	}
	for (int i=24;i<48;i++)
		for (int j=80;j<160;j++)
		{
			if (a[i][j]=='?')
				a[i][j]=254;
			if (a[i][j]=='_')
				a[i][j]=249;
		}
	if (ch==13)
	{
		display();
		run_game();
	}
}

void accept_cases(int A, int B, int C)
{
	if (cpo[A]!=B)
	{
		if (a[cpo[0]][cpo[1]]!=254&&a[cpo[0]][cpo[1]]!='?')
			a[cpo[0]][cpo[1]]=249;
		if (a[cpo[0]][cpo[1]]=='?')
			a[cpo[0]][cpo[1]]=254;
		cpo[A]+=C;
		if (a[cpo[0]][cpo[1]]!=254)
			a[cpo[0]][cpo[1]]='_';
		if (a[cpo[0]][cpo[1]]==254)
			a[cpo[0]][cpo[1]]='?';
	}
}

void display()
{
	system("cls");
	for (int i=24;i<48;i++)
	{
		for (int j=80;j<160;j++)
			cout<<a[i][j];
		cout<<'\n';
	}
}

void load()
{
	strcat(name,"_");
	char fname[100]="\0";
	strcpy(fname,loc);
	strcat(fname,name);
	ifs.open(fname,ios::binary);
	if (!ifs)
	{
		name[strlen(name)-1]='\0';
		cout<<"\nScreenshot \""<<name<<"\" does not exist!\nPress any key...";
		getch();
		ifs.close();
	}
	else
	{
		cout<<"\nLoad successful!\nPress any key...";
		getch();
		ifs.read((char*)&a,sizeof(a));
		display();
		ifs.close();
		run_game();
	}
}

void run_game()
{
	for (char opn='\0';opn!=27;)
	{
		opn=getch();
		while (opn=='s')
		{
			system("cls");
			cout<<"Screen Shot\nPress Esc to return to game.\n\nEnter screenshot name (max. 7 alpha-numerical char., rest will be ignored):\n";
			int i,wflag;
			for (i=0,wflag=1;wflag&&wflag!=5;i++)
			{
				char ch=getch();
				ch=toupper(ch);
				if (ch==27)
				{
					ch='a';
					wflag=5;
					break;
				}
				else if (isalnum(ch)&&i<7)
				{
					name[i]=ch;
					cout<<ch;
				}
				else if (ch==8&&i>0)
				{
					system("cls");
					name[i-1]='\0';
					i-=2;
					cout<<"Screen Shot\nPress Esc to return to game.\n\nEnter screenshot name (max. 7 alpha-numerical char., rest will be ignored):\n"<<name;
				}
				else if (i==0&&ch==8)
					i=-1;
				else if (ch!=13&&ch!=8)
					i--;
				else if (i!=0)
				{
					name[i]='\0';
					wflag=0;
					char fname[100]="\0";
					strcpy(fname,loc);
					strcat(fname,name);
					strcat(fname,"_");
					ifs.open(fname);
					if (!ifs)
					{
						name[i]='\0';
						wflag=0;
					}
					else
						for (char x,y,dir='a';dir!=13;)
						{
							system("cls");
							if (savpos==1)
							{
								x=251;
								y=' ';
							}
							else
							{
								x=' ';
								y=251;
							}
							cout<<"Screen Shot\nPress Esc to return to game.\n\nEnter screenshot name (max. 7 alpha-numerical char., rest will be ignored):\n"<<name<<"\n\nYou are about to overwrite file \""<<name<<"\". Continue?\n(Select yes to overwrite or no to return to game.)\n"<<x<<" Yes        "<<y<<" No\n";
							dir=getch();
							switch (dir)
							{
								case 'a':
									if (savpos==2)
										savpos--;
									break;
								case 'd':
									if (savpos==1)
										savpos++;
									break;
								case 13:
									if (savpos==2)
										wflag=5;
									else
									{
										name[i]='\0';
										wflag=0;
									}
							}
						}
					ifs.close();
				}
				else
					i--;
			}
			name[7]='\0';
			if (wflag!=5)
			{
				screenshot();
				name[strlen(name)-1]='\0';
				cout<<"\nSaved successfuly as \""<<name<<"\".\nPress any key...";
				strcpy(name,"\0");
				getch();
				display();
				opn=getch();
			}
			else
			{
				display();
				opn=getch();
			}
		}
		if (opn=='s'&&savpos==2)
		{
			display();
			continue;
		}
		if (opn==27)
			break;
		int i,j;
		for (i=1;i<71;i++)
			for (j=1;j<239;j++)
			{
				int c=0;
				if (a[i-1][j-1]==254||a[i-1][j-1]=='b')
					c++;
				if (a[i][j-1]==254||a[i][j-1]=='b')
					c++;
				if (a[i+1][j-1]==254||a[i+1][j-1]=='b')
					c++;
				if (a[i-1][j]==254||a[i-1][j]=='b')
					c++;
				if (a[i+1][j]==254||a[i+1][j]=='b')
					c++;
				if (a[i-1][j+1]==254||a[i-1][j+1]=='b')
					c++;
				if (a[i][j+1]==254||a[i][j+1]=='b')
					c++;
				if (a[i+1][j+1]==254||a[i+1][j+1]=='b')
					c++;
				if ((a[i][j]==249||a[i][j]=='a')&&c==3)
					a[i][j]='a';
				else if (a[i][j]==254)
					switch (c)
					{
						case 2:
						case 3:
							break;
						default:
							a[i][j]='b';
					}
			}
		for (i=0;i<72;i++)
			for (j=0;j<240;j++)
			{
				if (a[i][j]=='a')
					a[i][j]=254;
				if (a[i][j]=='b')
					a[i][j]=249;
			}
		display();
	}
}

void screenshot()
{
	char fname[100]="\0";
	strcpy(fname,loc);
	strcat(fname,name);
	ofs.open(fname);
	for (int i=24;i<48;i++)
	{
		for (int j=80;j<160;j++)
			if (a[i][j]==249)
				ofs.put('.');
			else
				ofs.put('o');
		ofs.put('\n');
	}
	ofs.close();
	strcpy(fname,loc);
	strcat(name,"_");
	strcat(fname,name);
	ofs.open(fname,ios::binary);
	ofs.write((char*)&a,sizeof(a));
	ofs.close();
}