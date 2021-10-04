// C program to build the complete
// snake game
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

// Function to generate the fruit
// within the boundary
void setup()
{
	gameover = 0;

	// Stores height and width
	x = height / 2;
	y = width / 2;
label1:
	fruitx = rand() % 20;
	if (fruitx == 0)
		goto label1;
label2:
	fruity = rand() % 20;
	if (fruity == 0)
		goto label2;
	score = 0;
}

// Function to draw the boundaries
void draw()
{
	system("cls");
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i == 0 || i == width - 1
				|| j == 0
				|| j == height - 1) {
				printf("#");
			}
			else {
				if (i == x && j == y)
					printf("0");
				else if (i == fruitx
						&& j == fruity)
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}

	// Print the score after the
	// game ends
	printf("score = %d", score);
	printf("\n");
	printf("press X to quit the game");
}
       if(i<20){
 		   m[i]=x;
 		   n[i]=y;
 		   i++;
	       }

		 if(i>=20)

		 {
	 		  for(j=con;j>=0;j--){
		 		  m[1+j]=m[j];
		 		  n[1+j]=n[j];
	 		 		  }
		   m[0]=x;
		   n[0]=y;

		   setcolor(WHITE);
		   setfillstyle(SOLID_FILL,con);
		   circle(m[0],n[0],8);
		   floodfill(m[0],n[0],WHITE);

		   setcolor(WHITE);
		   for(j=1;j<con;j++){
		  setfillstyle(SOLID_FILL,con+j%3);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
		 		      }
       delay(spd);

		  setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		   circle(m[0],n[0],8);
		   floodfill(m[0],n[0],BLACK);

		   setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],BLACK);

		   }
     stop=clock();
     t=(stop-start)/CLK_TCK;
     printf(" TIME %d sec   ",t);
     printf("SCORE %d
",con-5);
     check();

    if(x==p&&y==q) { con=con+5; if(spd>=5) spd=spd-5; else spd=5;
		 		      if(con>490) win();
     p=random(maxx); temp=p%13;  p=p-temp;
     q=random(maxy); temp=q%14;   q=q-temp;
		 		    }
    if(a==1)  y =  y-14; if(y<0) { temp=maxy%14;y=maxy-temp;}
    if(a==2)  y =  y+14; if(y>maxy) y=0;
    if(a==3)  x =  x-13; if(x<0) { temp=maxx%13;x=maxx-temp;}
    if(a==4)  x =  x+13; if(x>maxx) x=0;
    if(a==0){  y = y+14 ;  x=x+13; }
		 }

 }



// Function to take the input
void input()
{
	if (kbhit()) {
		switch (getch()) {
		case 'a':
			flag = 1;
			break;
		case 's':
			flag = 2;
			break;
		case 'd':
			flag = 3;
			break;
		case 'w':
			flag = 4;
			break;
		case 'x':
			gameover = 1;
			break;
		}
	}
}

// Function for the logic behind
// each movement
void logic()
{
	sleep(0.01);
	switch (flag) {
	case 1:
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		y++;
		break;
	case 4:
		x--;
		break;
	default:
		break;
	}

	// If the game is over
	if (x < 0 || x > height
		|| y < 0 || y > width)
		gameover = 1;

	// If snake reaches the fruit
	// then update the score
	if (x == fruitx && y == fruity) {
	label3:
		fruitx = rand() % 20;
		if (fruitx == 0)
			goto label3;

	// After eating the above fruit
	// generate new fruit
	label4:
		fruity = rand() % 20;
		if (fruity == 0)
			goto label4;
		score += 10;
	}
}

// Driver Code
void main()
{
	int m, n;

	// Generate boundary
	setup();

	// Until the game is over
	while (!gameover) {

		// Function Call
		draw();
		input();
		logic();
	}
}
