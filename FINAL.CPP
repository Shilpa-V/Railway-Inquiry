/* This is a simple Railway Inquiry software which is for biginners.
   It is only to guide biginners. Here I have shown the use of arrays
   and simple database management.


     /*****************************************************************
      *								      *
      *	Application      : Railway Inquiry timetable                  *
      *	Created By       : Shilpa Meghani                             *
      *	Enrollment Number: 3003                                       *
      * E - mail ID      : Shilpa_vadgama@yahoo.co.in                 *
      *	Guided By        : Miss Apexa Joshi                           *
      *****************************************************************/

/********* Inclusion of header files **********************/

#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>

/*********** Declaration of User Defined Functions ************/
void mainmenu();
void splashscreen();
void setgraph();
void login();
void list();
void about();
void search_menu();
void search_tno();
void search_tname();
void search_station();
void search_tr();
void search_dt();
void drawbox();
void clearline(int );

/*********** Basic structure of train *****************/

struct train
{
	char tno[5];
	char tname[25];
	char from[20];
	char to[20];
	char dept[10];
	char arrival[10];
	int distance;
}tr;

/************ Detailed structure of train **************/

struct detail
{
     char tno[5];
     int count;
     char stop[20][20];
     char time[20][20];
     int day_count;
     char day[7][15];
}dt;

/*********** Global variable declarations ***********/

int gd=DETECT,gm,errorcode,x,y;
int xmax,ymax,r,c;

/************ File Handler declarations *************/
FILE *fp,*tra;

/************ Starting point of program *************/

void main()
{
	clrscr();

	/*********** writing basic train informations *********/

	if((fp=fopen("e:\\tra.DAT","r"))==NULL)
	{
		fp=fopen("e:\\tra.DAT","w");
		strcpy(tr.tno,"5143");
		strcpy(tr.tname,"Gujarat express");
		strcpy(tr.from,"Ahmedabad");
		strcpy(tr.to,"Mumbai");
		strcpy(tr.dept,"10:00");
		strcpy(tr.arrival,"19:00");
		tr.distance=300;
		fwrite(&tr,sizeof(tr),1,fp);
		strcpy(tr.tno,"3447");
		strcpy(tr.tname,"Saurashtra mail");
		strcpy(tr.from,"Jamnagar");
		strcpy(tr.to,"Mumbai");
		strcpy(tr.dept,"13:40");
		strcpy(tr.arrival,"3:00");
		tr.distance=550;
		fwrite(&tr,sizeof(tr),1,fp);
		fclose(fp);
	}

	/*********** writing detailed train informations *********/

	if((tra=fopen("e:\\details.DAT","r"))==NULL)
	{
		tra=fopen("e:\\details.DAT","w");
		strcpy(dt.tno,"5143");
		dt.count=6;

	/********* Writing stoppage informations in the file ******/

		strcpy(dt.stop[0],"Nadiad");
		strcpy(dt.stop[1],"Anand");
		strcpy(dt.stop[2],"Baroda");
		strcpy(dt.stop[3],"Surat");
		strcpy(dt.stop[4],"Valsad");
		strcpy(dt.stop[5],"Vapi");

	/********* Writing time informations in the file ********/

		strcpy(dt.time[0],"11.00");
		strcpy(dt.time[1],"12.00");
		strcpy(dt.time[2],"12.30");
		strcpy(dt.time[3],"15.00");
		strcpy(dt.time[4],"16.00");
		strcpy(dt.time[5],"16.50");
		dt.day_count=7;

	/********* Writing availability of days in the file ******/

		strcpy(dt.day[0]," Sunday");
		strcpy(dt.day[1]," Monday");
		strcpy(dt.day[2]," Tuesday");
		strcpy(dt.day[3]," Wednesday");
		strcpy(dt.day[4]," Thursday");
		strcpy(dt.day[5]," Friday");
		strcpy(dt.day[6]," Saturday");

		fwrite(&dt,sizeof(dt),1,tra);

		strcpy(dt.tno,"3447");
		dt.count=11;

		strcpy(dt.stop[0],"Than");
		strcpy(dt.stop[1],"Vankaner");
		strcpy(dt.stop[2],"Surendranagar");
		strcpy(dt.stop[3],"Viramgam");
		strcpy(dt.stop[4],"Ahmedabad");
		strcpy(dt.stop[5],"Nadiad");
		strcpy(dt.stop[6],"Anand");
		strcpy(dt.stop[7],"Baroda");
		strcpy(dt.stop[8],"Surat");
		strcpy(dt.stop[9],"Valsad");
		strcpy(dt.stop[10],"Vapi");

		strcpy(dt.time[0],"14.00");
		strcpy(dt.time[1],"15.00");
		strcpy(dt.time[2],"16.00");
		strcpy(dt.time[3],"18.00");
		strcpy(dt.time[4],"19.30");
		strcpy(dt.time[5],"21.00");
		strcpy(dt.time[6],"22.00");
		strcpy(dt.time[7],"22.30");
		strcpy(dt.time[8],"00.30");
		strcpy(dt.time[9],"1.00");
		strcpy(dt.time[10],"1.30");
		dt.day_count=3;

		strcpy(dt.day[0]," Sunday");
		strcpy(dt.day[1]," Tuesday");
		strcpy(dt.day[2]," Friday");

		fwrite(&dt,sizeof(dt),1,tra);
		fclose(tra);
	}

	splashscreen();
	login();
	mainmenu();
	textcolor(11);
	getch();
}

	/************First screen of the Project***********/

void splashscreen()
{
	textbackground(11);

	/**********To make rectangle shaped design *********/

	for(r=10;r<40;r++)
	{
		gotoxy(20,r);
		textcolor(BLUE);
		cprintf("*");
		gotoxy(59,r);
		textcolor(BLUE);
		cprintf("*");
	}

	for(c=20;c<60;c++)
	{
		gotoxy(c,10);
		textcolor(BLUE);
		cprintf("*");
		gotoxy(c,40);
		textcolor(BLUE);
		cprintf("*");
	}
	/**********Basic details of the project like name of project,
	student name, college name and guide **********************/

	gotoxy(22,14);
	textattr(LIGHTRED);
	putch(4);
	textcolor(CYAN);
	cprintf(" SUBJECT:RAILWAY INQUIRY TIME-TABLE");
	gotoxy(22,17);
	textcolor(LIGHTRED);
	putch(4);
	textcolor(CYAN);
	cprintf(" DEVELOPED BY : ");
	cprintf("Shilpa Meghani");

	gotoxy(22,20);
	textcolor(LIGHTRED);
	putch(4);
	textcolor(CYAN);
	cprintf(" ENROLLMENT NO: ");
	cprintf(" 3003");

	gotoxy(22,23);
	textcolor(LIGHTRED);
	putch(4);
	textcolor(CYAN);
	cprintf(" ACEDEMIC YEAR: ");
	cprintf(" 2011-12");

	gotoxy(22,26);
	textcolor(LIGHTRED);
	putch(4);
	textcolor(CYAN);
	cprintf(" GUIDE   : ");
	textcolor(CYAN);
	cprintf(" Miss Apexa Joshi");


	for(c=45;c>=1;c--)
	{
	gotoxy(28,35);
	textcolor(CYAN + BLINK);
	cprintf("WAIT..............");

	/********** Scrolling text *********************/

	clearline(2);
	gotoxy(c,2);
	textcolor(LIGHTRED);
	cprintf("JVIMS MCA COLLEGE - JAMNAGAR");
	delay(200);
	}
}

/*************** Login screen to check for valid user *****************/

void login()
{
	int valid,inc,ans,count=0;
	char passwd[6];
	char temp[6];
	valid=0;
	inc=0;

	while(valid==0)
	{
	clrscr();
	for(r=10;r<20;r++)
	{
		gotoxy(20,r);
		textcolor(BLUE);
		cprintf("*");
		gotoxy(59,r);
		textcolor(BLUE);
		cprintf("*");
	}

	for(c=20;c<60;c++)
	{
		gotoxy(c,10);
		textcolor(BLUE);
		cprintf("*");
		gotoxy(c,20);
		textcolor(BLUE);
		cprintf("*");
	}
	gotoxy(22,5);
	textcolor(LIGHTRED);
	cprintf("WELCOME TO AHEMEDABAD RAILWAY SERVICE");

	gotoxy(25,12);
	textcolor(CYAN);
	cprintf("Enter password:");
	inc=0;
		while(inc<5)
		{
			passwd[inc]=getch();
			inc = inc+1;
			textcolor(CYAN);
			cprintf("* ");
		}
		passwd[inc]='\0';
		strcpy(temp,passwd);
		if(strcmp(temp,"tr123")==0)
		{
			valid=1;
			break;
		}
		else
		{
			count++;
			if(count>=3)
			{
				clrscr();
				gotoxy(25,30);
				textcolor(RED);
				cprintf("Sorry, Invalid try to login....");
				delay(3000);
				exit(1);
			}
			gotoxy(15,30);
			textcolor(11);
			cprintf("You have entered a wrong Password,Please try again...");
			getch();
			valid=0;
		}
	}
}

/******* Displays main menu after login to move through the project ********/

void mainmenu()
{

	char choice;
	setgraph();
	setcolor(11);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(3, HORIZ_DIR, 5);
	outtextxy(xmax,45,"Railway Inquiry Timetable");
	setlinestyle(0,0,2);
	setcolor(2);
	rectangle(105,155,535,345);
	rectangle(100,150,540,350);
	floodfill(102,152,2);
	setcolor(11);
	settextstyle(3, HORIZ_DIR, 1);

	outtextxy(195,190,"1: LIST TRAINS");
	outtextxy(204,225,"2: TRAIN INQUIRY");
	outtextxy(190,260,"3: ABOUT US");
	outtextxy(162,295,"4: EXIT");

	do
	{
		clearline(25);
		clearline(27);
		gotoxy(30,25);
		printf("Choice(1-4) : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				closegraph();
				clrscr();
				list();
				break;

			case 2:
				closegraph();
				clrscr();
				search_menu();
				break;

			case 3:
				closegraph();
				clrscr();
				about();
				break;
			case 4:
				exit(1);
			default:
				gotoxy(30,27);
				printf("Invalid choice..");
				getch();
		}
	}while(choice!=4);
}

void search_menu()
{

	char choice;
	setgraph();
	setcolor(11);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(3, HORIZ_DIR, 5);
	outtextxy(xmax,45,"Different Search Options");
	setlinestyle(0,0,2);
	setcolor(2);
	rectangle(105,155,535,345);
	rectangle(100,150,540,350);
	floodfill(102,152,2);
	setcolor(11);
	settextstyle(3, HORIZ_DIR, 1);

	gotoxy(17,12);
	printf("1. Search By Train Number");
	gotoxy(17,14);
	printf("2. Search By Train Name");
	gotoxy(17,16);
	printf("3. List of trains for specified Station");
	gotoxy(17,18);
	printf("4. Back to mainmenu");
	gotoxy(17,20);
	printf("5. Exit");


	gotoxy(48,25);

	do
	{
		clearline(25);
		clearline(27);
		gotoxy(30,25);
		printf("Choice(1-5) : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				closegraph();
				clrscr();
				search_tno();
				break;

			case 2:
				closegraph();
				clrscr();
				search_tname();
				break;

			case 3:
				closegraph();
				clrscr();
				search_station();
				break;
			case 4:
				mainmenu();
				break;
			case 5:
				exit(1);
			default:
				gotoxy(30,27);
				printf("Invalid choice..");
				getch();
		}
	}while(choice!=4);
}


/*********** Displays details about Ahmedabad Railway Service ***********/

void about()
{
	for(r=8;r<18;r++)
	{
		gotoxy(20,r);
		textcolor(BLUE);
		cprintf("||");
		gotoxy(59,r);
		textcolor(BLUE);
		cprintf("||");
	}

	for(c=20;c<61;c++)
	{
		gotoxy(c,8);
		textcolor(BLUE);
		cprintf("=");
		gotoxy(c,18);
		textcolor(BLUE);
		cprintf("=");
	}

	gotoxy(28,10);
	textcolor(CYAN);
	cprintf(" IRCTC - Inidian Railway");
	gotoxy(27,12);
	textcolor(CYAN);
	cprintf(" AHMEDABAD RAILWAY SERVICE ");
	gotoxy(29,14);
	textcolor(CYAN);
	cprintf(" CONTACT:079 - 2456122 ");

	gotoxy(30,20);
	textcolor(CYAN+BLINK);
	cprintf("ALWAYS AT YOUR SERVICE");
	getch();
	mainmenu();

}

/*********** To initiate graphic mode in the system *****************/

void setgraph()
{

	clrscr();
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	errorcode=graphresult();
	if(errorcode!=grOk)
	{
		printf("Graphics Error=%s",grapherrormsg(errorcode));
		printf("Enter any key to halt....");
		getch();
		exit(1);
	}
	xmax=getmaxx()/2;
	ymax=getmaxy()/2;

}

void drawbox()
{
	 for(c=5;c<76;c++)
	 {
		gotoxy(c,3);
		textcolor(CYAN);
		cprintf("*");
		gotoxy(c,24);
		textcolor(CYAN);
		cprintf("*");
	 }
	 for(r=3;r<25;r++)
	 {
		gotoxy(5,r);
		textcolor(CYAN);
		cprintf("*");
		gotoxy(76,r);
		textcolor(CYAN);
		cprintf("*");
	 }
}



/********* Searches train by train number ****************/

void search_tno()
{
	 char ch,tn[5];
	 int i,flag=0;
	 clrscr();
	 ch='Y';
	 do
	 {
		 clrscr();
		 drawbox();
		 gotoxy(25,2);
		 cprintf("Enter train number to search:");
		 scanf("%s",tn);
		 rewind(fp);
		 rewind(tra);
		 while(fread(&tr,sizeof(tr),1,fp)==1)
		 {
			 if(strcmp(tr.tno,tn)==0)
			 {
				flag=1;
				break;
			 }
		 }
		 if(flag==1)
		 {      search_tr();
			while(fread(&dt,sizeof(dt),1,tra)==1)
			{
				if(strcmp(dt.tno,tn)==0)
				{
				       search_dt();
				       break;
				}
			}
		 }
		 else
		 {
			gotoxy(25,25);
			textcolor(LIGHTRED+BLINK);
			cprintf("This train number is not valid..");
			getch();
		 }
		 clearline(2);
		 clearline(25);
		 gotoxy(20,25);
		 textcolor(CYAN);
		 cprintf("Do you want to search more records(Y/N)?");
		 ch=getche();
		 flag=0;
	 }while(toupper(ch)=='Y');
	 getch();
	 search_menu();
}

void search_tr()
{
	gotoxy(30,4);
	textcolor(CYAN);
	cprintf("Basic details of the train");
	for(c=6;c<76;c++)
	{
		gotoxy(c,5);
		cprintf("-");
	}
	gotoxy(10,6);
	cprintf("Train number:%s",tr.tno);
	gotoxy(10,7);
	cprintf("Train name:%s",tr.tname);
	gotoxy(50,6);
	cprintf("Station From:%s",tr.from);
	gotoxy(50,7);
	cprintf("Station To:%s",tr.to);
	gotoxy(10,8);
	cprintf("Departure:%s",tr.dept);
	gotoxy(10,9);
	cprintf("Arrival:%s",tr.arrival);
	gotoxy(50,8);
	cprintf("Distance(Km):%d",tr.distance);
	for(c=6;c<76;c++)
	{
		gotoxy(c,10);
		cprintf("-");
	}
	gotoxy(17,11);
	cprintf("Stoppages");
	gotoxy(55,11);
	cprintf("Available");
	for(c=6;c<76;c++)
	{
		gotoxy(c,12);
		cprintf("-");
	}
	for(r=13;r<24;r++)
	{
		gotoxy(40,r);
		cprintf("|");
	}
}

void search_dt()
{
	int i;
	r=13;
	for(i=0;i<dt.count;i++)
	{
		gotoxy(10,r);
		cprintf("%s",dt.stop[i]);
		gotoxy(30,r);
		cprintf("%s",dt.time[i]);
		r++;
	}
	r=13;
	for(i=0;i<dt.day_count;i++)
	{
		gotoxy(50,r);
		cprintf("%s",dt.day[i]);
		r++;
	 }
}


/********* Searches train by train name ****************/

void search_tname()
{
	 char ch,tname[25];
	 int i,flag=0;
	 clrscr();
	 ch='Y';
	 do
	 {
		 clrscr();
		 drawbox();
		 gotoxy(25,2);
		 cprintf("Enter train name to search:");
		 fflush(stdin);
		 scanf("%[^\n]s",tname);
		 rewind(fp);
		 rewind(tra);
		 while(fread(&tr,sizeof(tr),1,fp)==1)
		 {
			 if(strcmp(tr.tname,tname)==0)
			 {
				flag=1;
				break;
			 }
		 }
		 if(flag==1)
		 {      search_tr();
			while(fread(&dt,sizeof(dt),1,tra)==1)
			{
				if(strcmp(dt.tno,tr.tno)==0)
				{
				       search_dt();
				       break;
				}
			}
		 }
		 else
		 {
			gotoxy(25,25);
			textcolor(LIGHTRED+BLINK);
			cprintf("This train name is not valid..");
			getch();
		 }
		 clearline(2);
		 clearline(25);
		 gotoxy(20,25);
		 textcolor(CYAN);
		 cprintf("Do you want to search more records(Y/N)?");
		 ch=getche();
		 flag=0;
	 }while(toupper(ch)=='Y');
	 getch();
	 search_menu();
}

/********* Searches trains for specific station ****************/

void search_station()
{
	 char ch,stname[25];
	 int i,flag=0,r=7;
	 int tnum[20];
	 char tnm[20][20];
	 clrscr();
	 ch='Y';
	 do
	 {
		 clrscr();
		 drawbox();
		 gotoxy(25,2);
		 cprintf("Enter name of the station:");
		 fflush(stdin);
		 scanf("%[^\n]s",stname);
		 rewind(fp);
		 rewind(tra);
		 while(fread(&dt,sizeof(dt),1,tra)==1)
		 {
			for(i=0;i<dt.count;i++)
			if(strcmp(stname,dt.stop[i])==0)
			{
				 rewind(fp);
				 while(fread(&tr,sizeof(tr),1,fp)==1)
				 {
				 if(strcmp(dt.tno,tr.tno)==0)
				 {
					gotoxy(30,5);
					cprintf( "Trains for %s",stname);
					gotoxy(6,6);
					for(i=6;i<76;i++)
						cprintf("*");
					gotoxy(10,r);
					cprintf("%s",tr.tname);
					flag=1;
					c++;
				 }
				 }
			}
			i=0;

		 }

		if(flag==0)
		{
			gotoxy(25,25);
			textcolor(LIGHTRED+BLINK);
			cprintf("No train for this station .");
			getch();
		 }
		 clearline(2);
		 clearline(25);
		 gotoxy(20,25);
		 textcolor(CYAN);
		 cprintf("Do you want to search more records(Y/N)?");
		 ch=getche();
		 flag=0;
	 }while(toupper(ch)=='Y');
	 getch();
	 search_menu();
}





/*************** List all available trains *******************/

void list()
{
	int i,j;
	gotoxy(33,2);
	textcolor(CYAN + BLINK);
	cprintf(" TRAIN DETAILS ");
	gotoxy(2,4);
	textcolor(LIGHTRED);
	for(i=0;i<39;i++)
	cprintf("=*");
	gotoxy(2,6);
	textcolor(LIGHTRED);
	for(i=0;i<39;i++)
	cprintf("=*");
	gotoxy(2,5);
	textcolor(11);
	cprintf("Train No");
	gotoxy(12,5);
	textcolor(11);
	cprintf("Train Name");
	gotoxy(30,5);
	textcolor(11);
	cprintf("From");
	gotoxy(42,5);
	textcolor(11);
	cprintf("To");
	gotoxy(49,5);
	textcolor(11);
	cprintf("Arrival");
	gotoxy(58,5);
	textcolor(11);
	cprintf("Departure");
	gotoxy(69,5);
	textcolor(11);
	cprintf("Distance(km)");
	rewind(fp);

	while(fread(&tr,sizeof(tr),1,fp)==1)
	{
		printf("\n %s  ||%s  ||%s  ||%s  ||%s  ||%s  ||%5d",tr.tno,tr.tname,tr.from,tr.to,tr.dept,tr.arrival,tr.distance);
		printf("\n ------------------------------------------------------------------------------");
	}
	getch();
	mainmenu();
}

/************** To clear single line in the screen *****************/

void clearline(int yco)
{
	int i,j;
	gotoxy(1,yco);
	for(i=0;i<74;i++)
	{
	printf("%c",' ');
	}
}


