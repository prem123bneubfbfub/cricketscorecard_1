#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

struct letters
{
    int x;
    int y;
    char a;
    int color;
    int bgcolor;
    char a2;
};

void setbgcolor(int n)
{
    switch(n)
    {
        case 10:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
                break;
        case 11:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
                break;
        case 12:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY);
                break;
        case 14:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
                break;
        case 13:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY);
                break;
        case 0: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
                break;
    }
}

void setcolor(int ForgC) //function to change setcolor
 {
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
                        //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
                        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
     return;
 }

 void delay(unsigned int mseconds)//function for delay
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}

struct details   //structure declared with name
{
	int bscore;
	int oscore;
	int NB;
	int dot;
	int byes;
	int wicket;
	int runs;
	int extraruns;
	int fours;
	int sixes;
	int wide;
	char name[50];
};
struct details playerst1[500];
struct details playerst2[500];
char T1[50],T2[50],v[50];
        //arrays defined for structures are playerst1,playerst2.
        //declared t1 - team 1 name   and  t2 - team 2 name   and  v - venue name
        //declared to - total overs
int to, toss, choose;
void details_of_the_match()
{
    setcolor(9);                            //setcolor - font colour will change from now to case 9 in it.
	printf("Enter the details of the match\n");
	printf("Team1- ");
	fgets(T1,50,stdin);
	printf("Team2- ");
	fgets(T2,50,stdin);
	printf("venue- ");
	fgets(v,50,stdin);
	printf("Time and Date of the match - ");
	setcolor(13);
	date();                                   //function date() has been called
	setcolor(9);
	printf("Number of overs- ");
	scanf("%d",&to);
	printf("Toss won by which team \n");
	printf("Team 1 or 2  - ");
	scanf("%d",&toss);
	printf("Press 1 for  bat or else press 2 for  bowl - ");
	scanf("%d",&choose);
	if(choose==1)
		printf("Team %d choose to bat first \n",toss);
	else if (choose==2)
		printf("Team %d choose to bowl first \n",toss);
}

                                //score_void is the function which shows the input of the values in over.
void score_value()
{
    setcolor(2);
    printf("**********??? REMEMBER ALL TYPES OF INPUTS OF THE BALL ???**********");
    printf("\n\n");
    setcolor(4);
    printf("!!!**ENTER ALL THE INPUTS ONLY FROM THE DATA GIVEN BELOW**!!!");
    printf("\n\n");
    setcolor(14);
    printf("If the batsman scores <0> run , give input as <0>.\n");
	printf("If the batsman scores <1> run , give input as <1>.\n");
	printf("If the batsman scores <2> runs, give input as <2>.\n");
	printf("If the batsman scores <3> runs, give input as <3>.\n");
	printf("If the batsman scores <4> runs, give input as <4>.\n");
	printf("If the batsman scores <6> runs, give input as <6>.\n");
	printf("If the bowler takes a   <Wicket>   , give input as < 11 >.\n");
	printf("If the bowler bowls a   < wide >   , give input as < 12 >.\n");
	printf("If you entered input as 12 , then number of runs increased in total score is equal to case n  , there are total 6 cases ");
	printf("If the bowler bowls a   <  NB  >   , give input as < 13 >.\n");
	printf("If you entered input 13 , then the number of runs increased in total score is equal to case n , there are total 6 cases ");
	printf("If the bowler supposed to make the status of the ball  as < Byes >   , give input as < 14 >.\n");
	printf("If you entered input 14 , then the number of runs increased in total score is equal to case n , there are total 7 cases ");
	printf("\n");
	printf("!!!***If the input entered is not in the above list, you will get errors and you will get compilation problems***!!!");

}

                            //wicket_out is the function which displays what type of out does the batsman was ?
void wicket_out()
{
    int x;
    printf("Choose the number which determines the type of out : ");
    wicketout();
    delay(3000);
    scanf("%d",&x);
    printf("The batsman was ");
    switch(x)
    {
        case 1 :
        printf("bowled \n");
        break;
        case 2 :
        printf("caught \n");
        break;
        case 3 :
        printf("Stumped \n");
        break;
        case 4 :
        printf("LBW \n");
        break;
        case 5 :
        printf("Run Out \n");
        break;
        case 6 :
        printf("Mankad \n");
        break;
        case 7 :
        printf("Retired hurt\n");
        break;
        case 8 :
        printf("Hit Wicket \n");
        break;
    }
}

                        //wicketout is a fn which displays to give input of the out
void wicketout()
{
    setcolor(14);
    printf("Choose the number which is given below to enter \n ");
    printf("\n");
    printf("Enter 1 for bowled \n");
    printf("Enter 2 for caught\n");
    printf("Enter 3 for stumped\n");
    printf("Enter 4 for LBW\n");
    printf("Enter 5 for Run out\n");
    printf("Enter 6 for Mankad\n");
    printf("Enter 7 for Retired Hurt\n");
    printf("Enter 8 for Hit Wicket\n");


}

                            //this fn checks wether the name belongs to that team or not
void checkb1(struct details playerst1[500],char Striker[50],char Nonstriker[50])
{
    for( int i=1;i<=11;i++)
    {
        if(strcmp(playerst1[i].name,Striker)==0)
        {
            printf("Entered name was verified , you can proceed now for bat \n");
        }
        else if (strcmp(playerst1[i].name,Nonstriker)==0)
        {
            printf("Entered name was verified , you can proceed now for bat \n");
        }
    }

}

                            //This function checks wether the input given is there in the team or not
void checkb2(struct details playerst2[500],char Striker[50],char Nonstriker[50])
{
    for(int i=1;i<=11;i++)
    {
        if(strcmp(playerst2[i].name,Striker)==0)
        {
            printf("Entered name was verified , you can proceed now for bat \n");
        }
        else if (strcmp(playerst2[i].name,Nonstriker)==0)
        {
                printf("Entered name was verified , you can proceed now for bat \n");
        }
    }
}

                            //It checks wether the entered bowlers name is there in team or not

void checkb3(struct details playerst1[500],char Bow[50])
{
    for(int i=0;i<=11;i++)
    {
        if(strcmp(playerst1[i].name,Bow)==0)
        {
                printf("Entered name was verified , you can proceed now for bow \n");
        }
        else if (strcmp(playerst1[i].name,Bow)==0)
        {
             printf("Entered name was verified , you can proceed now for bowl \n");
        }
    }
}

                    //This function is defined to check wether to check the given input is there in team or not

void checkb4(struct details playerst2[500],char Bow[50])
{
     for(int i=0;i<=11;i++)
    {
        if(strcmp(playerst2[i].name,Bow)==0)
        {
                printf("Entered name was verified , you can proceed now for bow \n");
        }
        else if (strcmp(playerst2[i].name,Bow)==0)
        {
                 printf("Entered name was verified , you can proceed now for bowl \n");
        }
    }

}

                         //ballscore1 is a fn which displays ball to ball score
void ballscore1(struct details playerst2[500],int to)
{
	for(int j=1;j<=to;j++)
	{
	    setcolor(3);
        printf("        The over %d score is :  ",j);
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
		    setcolor(2);
			printf("%d",playerst2[i].bscore);
			printf("\t");
		}
		printf("\n");
	}
}

                                //team1totalscore = total score of team1
                                //overscore1 is a fn which displays the over score
int team1totalscore=0;
void overscore1(struct details playerst2[500],int to)
{
	int j;
	int totaloverscore;
	for(j=1;j<=to;j++)
	{
	    for(int i=((6)*(j-1));i<((6)*(j));i++)
        {
        totaloverscore = playerst2[j].oscore;
        }
    printf("        The total score in over %d of team 1 is %d \n",j,totaloverscore);
    team1totalscore += totaloverscore;
	}
}

                                    //run1 is a function which displays total runs of team1
void run1(struct details playerst2[500],int to)
{
	int totalruns=0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
				totalruns += playerst2[i].runs;
		}
	}
	printf("        The total runs of team 1 is %d \n",totalruns);
}

                                        //six1 is a fn which displays the total sixes of team 1
void six1(struct details playerst2[500],int to)
{
	int totalsixes =0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
			totalsixes += playerst2[i].sixes;
		}
	}
	printf("        The total number of sixes of team 1 is %d \n",totalsixes);
}

                                        //four1 is a fn which displays the total fours of team 1
void four1(struct details playerst2[500],int to)
{
	int totalfours=0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
				totalfours += playerst2[i].fours;
		}
	}
	printf("        The total number of fours of team 1 is %d \n",totalfours);
}

                                        //totalwickets1 is a variable which defines the total wickets of team 1
                                        //wickets1 is a fn which diplays the total number of wickets
int totalwickets1=0;
void wickets1(struct details playerst2[500],int to)
{
	totalwickets1=0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
				totalwickets1 += playerst2[i].wicket;
		}
	}
	printf("        The total number of wickets of team 1 is %d \n",totalwickets1);
}

                                        //dotball1 is a fn which determines the total number of dotballs of team 1
void dotball1(struct details playerst2[500],int to)
{
	int totaldotballs=0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
			totaldotballs += playerst2[i].dot;
		}
	}
	printf("        The total number of dot balls of team 1 is %d \n",totaldotballs);
}

                                    //wides1 is a fn which determines the total number of wides of team 1
void wides1(struct details playerst2[500],int to)
{
	int totalwides=0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
			totalwides += playerst2[i].wide;
		}
	}
	printf("        The total number of wides of team 1 is %d \n",totalwides);
}

                                    //NOBALL1 is a fn which determines the total number of no balls of team 1
void NOBALL1(struct details playerst2[500],int to)
{
	int totalnoballs =0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
				totalnoballs = totalnoballs + playerst2[i].NB;
		}
	}
	printf("        The total number of no balls of team 1 is %d \n",totalnoballs);
}

                                        //extrarun1 is a fn which determines the total exxtra runs of team 1
void extrarun1(struct details playerst2[500],int to)
{
	int totalextraruns=0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
			totalextraruns += playerst2[i].extraruns;
		}
	}
	printf("        The total number of extra runs of team 1 is %d \n",totalextraruns);
}

                                    //ballscore2 is a fn which determines the ball to ball score of team2
void ballscore2(struct details playerst1[500],int to)
{
	for(int j=1;j<=to;j++)
	{
	    setcolor(3);
		printf("        The over %d score is : ",j);
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
		    setcolor(2);
			printf("%d",playerst1[i].bscore);
			printf("\t");
		}
		printf("\n");
	}
}

                                    //team2totalscore is a fn which determines the total score of team2
                                    //overscore2 is a fn which determines the score of the over of team2
int team2totalscore=0;
void overscore2(struct details playerst1[500],int to)
{
	int totaloverscore;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
			totaloverscore = playerst1[j].oscore;
		}
		printf("        The total score in over %d of team 2 is %d \n",j,totaloverscore);
		team2totalscore += totaloverscore;
	}
}

                                    //run2 is a fn which determines the runs of the team 2
void run2(struct details playerst1[500],int to)
{
	int totalruns=0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
			totalruns += playerst1[i].runs;
		}
	}
	printf("        The total runs of team 2 is %d \n",totalruns);
}

                                    //six2 is a fn which determines the total sixes of team 2
void six2(struct details playerst1[500], int to)
{
	int totalsixes=0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
			totalsixes = totalsixes + playerst1[i].sixes;
		}
	}
	printf("        The total number of sixes of team 2 is %d \n",totalsixes);
}

                                    //four2 is a fn which determines the total fours of team2
void four2(struct details playerst1[500],int to)
{
	int totalfours=0;
	for(int j=1;j<=to;j++)
	{
		for(int i=((6)*(j-1));i<((6)*(j));i++)
		{
				totalfours += playerst1[i].fours;
		}
	}
	printf("        The total number of fours of team 2 is %d \n",totalfours);
}

                                        //totalwickets2 is a fn which determines total no of wickets of team 2
int totalwickets2=0;
void wickets2(struct details playerst1[500],int to)
{
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
				totalwickets2 += playerst1[i].wicket;
		}
	}
	printf("        The total number of wickets of team 2 is %d \n",totalwickets2);
}

                                   //dotball2 is a fn which determines the total dot balls of team 2
void dotball2(struct details playerst1[500],int to)
{
	int totaldotballs=0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
			totaldotballs= totaldotballs + playerst1[i].dot;
		}
	}
	printf("        The total number of dot balls of team 2  is %d \n",totaldotballs);
}

                                    //wides2 is  a fn which determines the total wides of team 2
void wides2(struct details playerst1[500],int to)
{
	int totalwides=0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
			totalwides += playerst1[i].wide;
		}
	}
	printf("        The total number of wides team 2 is %d \n",totalwides);
}

                                    //NOBALL2 is a fn which determines the total no of nobals of team 2
void NOBALL2(struct details playerst1[500],int to)
{
	int totalnoballs=0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
			totalnoballs = totalnoballs + playerst1[i].NB;
		}
	}
	printf("        The total number of no balls of team 2 is %d \n",totalnoballs);
}

                                //extrarun2 is a fn which determines the total extra runs of the team2
void extrarun2(struct details playerst1[500],int to)
{
	int totalextraruns=0;
	for(int j=1;j<=to;j++)
	{
		for(int i=(6)*(j-1);i<((6)*(j));i++)
		{
			totalextraruns += playerst1[i].extraruns;
		}
	}
	printf("        The total number of extra runs of team 2 is %d \n",totalextraruns);
}

                                        //date is a fn which determines the date,time
int date()
{
    time_t currentTime;
    time(&currentTime);
    printf("%s",ctime(&currentTime));
}

                                        //bow - string which enters the name of the bowler
                                        //striker - string which enters the name of the batsman
                                        //non striker - string which enters the name of the batsman
                                        //system("cls") -> it clears the screen
                                        //setcolor(l) -> it sets the font colour

int main()
{
	char Bow[50],Striker[50],Nonstriker[50];
	system("cls");
	details_of_the_match();               //it calls the function details_of_the_match
	system("cls");
	setcolor(7);                          //it calls the function setcolor
	printf("Enter the names of the players of team %s",T1);
	setcolor(11);                         //it calls the function setcolor
	for(int i=0;i<11;i++)
	{
		printf("Player %d , Name - ",i+1);
		scanf("%s",playerst1[i].name);
	}
	printf("\n");
	setcolor(7);                           //it calls the function setcolor
	printf("Enter the names of the players of team %s",T2);
	setcolor(11);                          //it calls the function  setcolor
	for(int i=0;i<11;i++)
	{
		printf("Player %d , Name - ",i+1);
		scanf("%s",playerst2[i].name);
	}
	system("cls");                          //it clears the screen
	score_value();                          //it calls the function score_value
	delay(15000);                            //delay is a function which delays the screen time
	system("cls");                          //it clears the screen

                                    //sumbscore - it carries the ball to ball score and it carries the extraruns also
	int i;
	switch(1)
	{
	case 1 :
		printf("Enter strikers name:");
		scanf("%s",Striker);
		checkb1(playerst1,Striker,Nonstriker);
        printf("Enter Nonstrikers name:");
        scanf("%s",Nonstriker);
        checkb1(playerst1,Striker,Nonstriker);
		for(int j=1;j<=to;j++)
		{
			printf("Enter bowlers name:");
			scanf("%s",Bow);
			checkb4( playerst2, Bow);
			printf("Give the score input for the over %d \n",j);
			int sumbscore=0;
			for(int i=((6)*(j-1));i<((6)*(j));i++)
			{
				scanf("%d",&playerst2[i].bscore);
				if(playerst2[i].bscore == 1 || playerst2[i].bscore == 2 || playerst2[i].bscore == 3)
				{
					sumbscore  += playerst2[i].bscore;
					playerst2[i].runs = playerst2[i].bscore;
				}
				else if(playerst2[i].bscore == 4 || playerst2[i].bscore == 6)
				{
					if(playerst2[i].bscore == 4)
					{
						sumbscore += playerst2[i].bscore;
						playerst2[i].fours=1;
					}
					else if (playerst2[i].bscore == 6)
					{
						sumbscore += playerst2[i].bscore;
						playerst2[i].sixes = 1;
					}
				}
				else if (playerst2[i].bscore == 0)
				  	{
				  		playerst2[i].dot = 1;
				  	}
				else if (playerst2[i].bscore == 11)
				  	{
				  	    playerst2[i].bscore = 0;
				  		printf("The batsman on strike was out \n");
				  		printf("Enter the name of new batsman : ");
				  		scanf("%s",Striker);
				  		checkb1(playerst1,Striker,Nonstriker);
				  		playerst2[i].wicket = 1;
				  		wicket_out();                          //it calls the function
				  	}
				else if (playerst2[i].bscore==12)
				{
					printf("The status of the ball is wide \n");
					printf("Choose the case where the status of the ball is matching : ");
					int x ;
					scanf("%d",&x);
					switch(x)
					{
						case 1 :
						printf("The status of the ball is ( wide )\n");
						playerst2[i].wide = 1;
						playerst2[i].extraruns = 1;
						sumbscore = sumbscore + 1;
						i=i-1;
						break;
						case 2 :
						printf("The status of the ball is ( wide + 1 )\n");
						playerst2[i].wide = 1;
						playerst2[i].extraruns = 2;
						sumbscore = sumbscore + 2;
						i=i-1;
						break;
						case 3 :
						printf("The status of the ball is ( wide + 2 )\n");
						playerst2[i].wide = 1 ;
						playerst2[i].extraruns = 3;
						sumbscore = sumbscore + 3;
						i=i-1;
						break;
						case 4 :
						printf("The status of the ball is ( wide + 3 )\n");
						playerst2[i].wide = 1;
						playerst2[i].extraruns = 4;
						sumbscore = sumbscore + 4;
						i=i-1;
						break;
						case 5 :
						printf("The status of the ball is ( wide + 4 )\n");
						playerst2[i].wide = 1;
						playerst2[i].extraruns  = 5;
						sumbscore = sumbscore + 5;
						i=i-1;
						break;
						case 6 :
						printf("The status of the ball is ( wide + 5 )\n");
						playerst2[i].wide = 1;
						playerst2[i].extraruns = 6;
						sumbscore = sumbscore + 6;
						i=i-1;
						break;
						case 7 :
						printf("The status of the ball is ( wide + 6 )\n");
						playerst2[i].wide = 1 ;
						playerst2[i].extraruns = 7;
						sumbscore = sumbscore + 7;
						i=i-1;
						break;
					}
				}
				else if( playerst2[i].bscore == 13)
				{
					printf("The status of the ball is No Ball \n");
					printf("Choose the case where the status of the ball is matching : ");
					int x ;
					scanf("%d",&x);
					switch(x)
					{
						case 1 :
						printf("The status of the ball is ( NB ) \n");
						playerst2[i].NB = 1;
						playerst2[i].extraruns = 1;
						sumbscore = sumbscore + 1;
						i=i-1;
						break;
						case 2 :
						printf("The status of the ball is ( NB + 1 )\n");
						playerst2[i].NB = 1;
						playerst2[i].extraruns = 2;
						sumbscore = sumbscore + 2;
						i=i-1;
						break;
						case 3 :
						printf("The status of the ball is ( NB + 2 )\n");
						playerst2[i].NB = 1;
						playerst2[i].extraruns = 3;
						sumbscore = sumbscore + 3;
						i=i-1;
						break;
						case 4 :
						printf("The status of the ball is ( NB + 3 )\n");
						playerst2[i].NB = 1;
						playerst2[i].extraruns = 4;
						sumbscore = sumbscore + 4;
						i=i-1;
						break;
						case 5 :
						printf("The status of the ball is ( NB + 4 )\n");
						playerst2[i].NB = 1;
						playerst2[i].extraruns = 5;
						sumbscore = sumbscore + 5;
						i=i-1;
						break;
						case 6 :
						printf("The status of the ball is ( NB + 6 )\n");
						playerst2[i].NB = 1;
						playerst2[i].extraruns = 7;
						sumbscore = sumbscore + 7;
						i=i-1;
						break;
					}
				}
                else if (playerst2[i].bscore == 14)
                {
				  	printf("The status of the ball is byes \n");
				  	printf("Choose a number equal to the status of the ball : ");
				  	int x;
				  	scanf("%d",&x);
				  	switch(x)
				  	{
				  		case 1 :
				  		printf("The status of the ball is 1Bye\n");
				  		playerst2[i].extraruns = 1;
				  		sumbscore = sumbscore + 1;
				  		playerst2[i].bscore = 1;
				  		break;
				  		case 2 :
				  		printf("The status of the ball is 2Byes\n");
				  		playerst2[i].extraruns = 2;
				  		sumbscore = sumbscore + 2;
				  		playerst2[i].bscore = 2;
				  		break;
				  		case 3 :
				  		printf("The status of the ball is 3Byes\n");
				  		playerst2[i].extraruns = 3;
				  		sumbscore = sumbscore + 3;
				  		playerst2[i].bscore = 3;
				  		break;
				  		case 4 :
				  		printf("The status of the ball is 4Byes\n");
				  		playerst2[i].extraruns = 4;
				  		sumbscore = sumbscore + 4;
				  		playerst2[i].bscore = 4;
				  		break;
				  		case 5 :
				  		printf("The status of the ball is 5Byes\n");
				  		playerst2[i].extraruns = 5;
				  		sumbscore = sumbscore + 5;
				  		break;
				  		case 6 :
				  		printf("The status of the ball is 6Byes\n");
				  		playerst2[i].extraruns = 6;
				  		sumbscore = sumbscore + 6;
				  		playerst2[i].bscore = 6;
				  		break;
				  		case 7 :
				  		printf("The status of the ball is 7Byes\n");
				  		playerst2[i].extraruns = 7;
				  		sumbscore = sumbscore + 7;
				  		playerst2[i].bscore = 7;
				  		break;
				  	}
                }
			}
			playerst2[j].oscore = sumbscore;
	}
	system("cls");                                  //it clears the screen

	case 2 :
	    printf("Enter strikers name:");
        scanf("%s",Striker);
        checkb2(playerst2,Striker,Nonstriker);
		printf("Enter Nonstrikers name:");
		scanf("%s",Nonstriker);
		checkb2(playerst2,Striker,Nonstriker);
		for(int j=1;j<=to;j++)
		{
			printf("Enter bowlers name:");
			scanf("%s",Bow);
			checkb3(playerst1,Bow);
			int sumbscore=0;
			printf("Enter the score of over %d  \n",j);
			for(int i=((6)*(j-1));i<((6)*(j));i++)
			{
				scanf("%d",&playerst1[i].bscore);
				if(playerst1[i].bscore == 1 || playerst1[i].bscore == 2 || playerst1[i].bscore == 3)
				{
					sumbscore += playerst1[i].bscore;
					playerst1[i].runs = playerst1[i].bscore;
				}
				else if(playerst1[i].bscore == 4 || playerst1[i].bscore == 6)
				{
					if(playerst1[i].bscore = 4)
					{
						sumbscore += playerst1[i].bscore;
						playerst1[i].fours=1;
					}
					else if (playerst1[i].bscore = 6)
					{
						sumbscore += playerst1[i].bscore;
						playerst1[i].sixes = 1;
					}
				}
				else if (playerst1[i].bscore == 0)
				  	{
				  		playerst1[i].dot = 1;
				  	}
                 else if (playerst1[i].bscore == 11)
				  	{
				  	    playerst1[i].bscore = 0;
				  		printf("The batsman on strike was out \n");
				  		printf("Enter the name of new batsman : ");
				  		scanf("%s",Striker);
				  		checkb2(playerst2,Striker,Nonstriker);
				  		playerst1[i].wicket = 1;
				  		wicket_out();
				  	}
				else if ( playerst1[i].bscore == 12)
				{
					printf("The status of the ball is wide \n");
					printf("Choose the case where the status of the ball is matching : ");
					int x ;
					scanf("%d",&x);
					switch(x)
					{
                        case 1 :
						printf("The status of the ball is ( wide )\n");
						playerst1[i].wide = 1;
						playerst1[i].extraruns = 1;
						sumbscore = sumbscore + 1;
						i=i-1;
						break;
						case 2 :
						printf("The status of the ball is ( wide + 1 )\n");
						playerst1[i].wide = 1;
						playerst1[i].extraruns = 2;
						sumbscore = sumbscore + 2;
						i=i-1;
						break;
						case 3 :
						printf("The status of the ball is ( wide + 2 )\n");
						playerst1[i].wide = 1 ;
						playerst1[i].extraruns = 3;
						sumbscore = sumbscore + 3;
						i=i-1;
						break;
						case 4 :
						printf("The status of the ball is ( wide + 3 )\n");
						playerst1[i].wide = 1;
						playerst1[i].extraruns = 4;
						sumbscore = sumbscore + 4;
						i=i-1;
						break;
						case 5 :
						printf("The status of the ball is ( wide + 4 )\n");
						playerst1[i].wide = 1;
						playerst1[i].extraruns  = 5;
						sumbscore = sumbscore + 5;
						i=i-1;
						break;
						case 6 :
						printf("The status of the ball is ( wide + 5 )\n");
						playerst1[i].wide = 1;
						playerst1[i].extraruns = 6;
						sumbscore = sumbscore + 6;
						i=i-1;
						break;
						case 7 :
						printf("The status of the ball is ( wide + 6 )\n");
						playerst1[i].wide = 1 ;
						playerst1[i].extraruns = 7;
						sumbscore = sumbscore + 7;
						i=i-1;
						break;
					}
				}
				else if( playerst1[i].bscore == 13)
				{
					printf("The status of the ball is No Ball \n");
					printf("Choose the case where the status of the ball is matching : ");
					int x ;
					scanf("%d",&x);
					switch(x)
					{
						case 1 :
						printf("The status of the ball is ( NB ) \n");
						playerst1[i].NB = 1;
						playerst1[i].extraruns = 1;
						sumbscore = sumbscore + 1;
						i=i-1;
						break;
						case 2 :
						printf("The status of the ball is ( NB + 1 )\n");
						playerst1[i].NB = 1;
						playerst1[i].extraruns = 2;
						sumbscore = sumbscore + 2 ;
						i=i-1;
						break;
						case 3 :
						printf("The status of the ball is ( NB + 2 )\n");
						playerst1[i].NB = 1;
						playerst1[i].extraruns = 3;
						sumbscore = sumbscore + 3;
						i=i-1;
						break;
						case 4 :
						printf("The status of the ball is ( NB + 3 )\n");
						playerst1[i].NB = 1;
						playerst1[i].extraruns = 4;
						sumbscore = sumbscore + 4;
						i=i-1;
						break;
						case 5 :
						printf("The status of the ball is ( NB + 4 )\n");
						playerst1[i].NB = 1;
						playerst1[i].extraruns = 5;
						sumbscore = sumbscore + 5;
						i=i-1;
						break;
						case 6 :
						printf("The status of the ball is ( NB + 6 )\n");
						playerst1[i].NB = 1;
						playerst1[i].extraruns = 7;
						sumbscore = sumbscore + 7;
						i=i-1;
						break;

					}
				}
				else if (playerst1[i].bscore == 14)
                {
				  	printf("The status of the ball is byes \n");
				  	printf("Choose a number equal to the status of the ball :");
				  	int x;
				  	scanf("%d",&x);
				  	switch(x)
				  	{
				  		case 1 :
				  		printf("The status of the ball is 1Byes\n");
				  		playerst1[i].extraruns = 1;
				  		sumbscore = sumbscore + 1;
				  		playerst1[i].bscore = 1;
				  		break;
				  		case 2 :
				  		printf("The status of the ball is 2Byes\n");
				  		playerst1[i].extraruns = 2;
				  		sumbscore = sumbscore + 2;
				  		playerst1[i].bscore = 2;
				  		break;
				  		case 3 :
				  		printf("The status of the ball is 3Byes\n");
				  		playerst1[i].extraruns = 3;
				  		sumbscore = sumbscore + 3;
				  		playerst1[i].bscore = 3;
				  		break;
				  		case 4 :
				  		printf("The status of the ball is 4Byes\n");
				  		playerst1[i].extraruns = 4;
				  		sumbscore = sumbscore + 4;
				  		playerst1[i].bscore = 4;
				  		break;
				  		case 5 :
				  		printf("The status of the ball is 5Byes\n");
				  		playerst1[i].extraruns = 5;
				  		sumbscore = sumbscore + 5;
				  		playerst1[i].bscore = 5;
				  		break;
				  		case 6 :
				  		printf("The status of the ball is 6Byes\n");
				  		playerst1[i].extraruns = 6;
				  		sumbscore = sumbscore + 6;
				  		playerst1[i].bscore = 6;
				  		break;
				  		case 7 :
				  		printf("The status of the ball is 7Byes\n");
				  		playerst1[i].extraruns = 7;
				  		sumbscore = sumbscore + 7;
				  		playerst1[i].bscore = 7;
				  		break;
				  	}
                }
			}
			playerst1[j].oscore = sumbscore;
		}
	}

	delay(2000);                              //it delays the screen time by 20 sec
	system("cls");                            //it clears the screen
	setcolor(4);                               //it calls the setcolour
     printf("       The score details of Team 1 is \n");
     printf("\n");
	 ballscore1(playerst2,to);
	 setcolor(14);                             //it calls the setcolour
	 overscore1(playerst2,to);
	 printf("       The total score of Team <1> is %d \n ",team1totalscore);
	 run1(playerst2,to);
	 six1(playerst2,to);
	 four1(playerst2,to);
	 wickets1(playerst2,to);
	 dotball1(playerst2,to);
	 wides1(playerst2,to);
	 NOBALL1(playerst2,to);
	 extrarun1(playerst2,to);
	 setcolor(4);
	 printf("       Score details of first innings is  ([%d]+[%d]) \n",team1totalscore,totalwickets1);
	 setcolor(14);
	 printf("\n\n\n\n\n");
	 setcolor(4);
	 printf("       The score details of Team 2 is \n ");
	 printf("\n");
	 setcolor(14);
	 ballscore2(playerst1,to);
	 overscore2(playerst1,to);
	 printf("       The total score of Team <2> is %d\n",team2totalscore);
	 run2(playerst1,to);
	 six2(playerst1,to);
	 four2(playerst1,to);
	 wickets2(playerst1,to);
	 dotball2(playerst1,to);
	 wides2(playerst1,to);
	 NOBALL2(playerst1,to);
	 extrarun2(playerst1,to);
	 setcolor(4);
	 printf("       Score details of second innings is ([%d]+[%d]) \n",team2totalscore,totalwickets2);
	 printf("\n\n\n");
	 delay(20000);
	 system("cls");
                        //it clears the screen
         //it calls the function

                    // if loop prints the winners
	if(team1totalscore > team2totalscore)
	{
	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        setcolor(1);
		printf("                      $$--Congratulations--<-- TEAM1 -->--$$");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
	else if ( team1totalscore < team2totalscore)
	{
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        setcolor(1);
		printf("                       $$--Congratulations--<-- TEAM2 -->--$$");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
	else if ( team1totalscore = team2totalscore)
	{
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        setcolor(1);
		printf("                        $$--Match is --  <-- DRAW -->--$$");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
	return 0;

}
