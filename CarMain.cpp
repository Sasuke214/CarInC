#include<graphics.h>
void CreateNMoveEnemyCar(int x,int y,int moveFactor,colors body,colors head)
{
    setcolor(BLACK);
    rectangle(x,y+moveFactor,x+20,-30+y+moveFactor);
    setfillstyle(1,body);
    floodfill(x+1,-20+y+moveFactor-1,BLACK);

    setcolor(BLACK);
    rectangle(x+5,y+moveFactor,x+15,5+y+moveFactor);
    setfillstyle(1,head);
    floodfill(x+6,5+y+moveFactor-1,BLACK);

}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    int page=0,t_y=-300;
    //car variables
    int C_x=0,M_Speed=5;
    int enemyNormal=0,enemyFast=0,enemySlow=0;
    while(1)
    {
    setactivepage(page);
    setvisualpage(1-page);
    cleardevice();



    //for background
    setcolor(CYAN);
    rectangle(0,0,1000,1000);
    setfillstyle(1,CYAN);
    floodfill(1,1,CYAN);
    //creating track
    setcolor(WHITE);
    rectangle(200,-1,400,500);
    setfillstyle(1,8);
    floodfill(201,0,WHITE);
    //line in roads
    for(int i=0;i<450;i+=105)
    {
        rectangle(290,10+i+t_y,310,50+i+t_y);
        setfillstyle(1,WHITE);
        floodfill(291,11+i+t_y,WHITE);
    }

    t_y+=15;
    if(t_y>500)
        t_y=-500;


    //for life and points
    settextstyle(10,0,2);
    outtextxy(10,10,"LIFE:");
    outtextxy(10,40,"POINTS:");
    //drawing circle for life
    setfillstyle(1,WHITE);
    circle(90,20,6);
    floodfill(91,21,WHITE);
    circle(110,20,6);
    floodfill(111,21,WHITE);
    circle(130,20,6);
    floodfill(131,21,WHITE);

    outtextxy(100,40,"0");


    //CAr
    setcolor(BLACK);
    setfillstyle(1,RED);
    rectangle(300+C_x,400,340+C_x,460);
    floodfill(301+C_x,401,BLACK);

    //Front
    setfillstyle(1,BROWN);
    rectangle(305+C_x,385,335+C_x,400);
    floodfill(306+C_x,386,BLACK);

    setfillstyle(1,GREEN);
    rectangle(305+C_x,405,335+C_x,455);
    floodfill(306+C_x,406,BLACK);

    //wheels
    setfillstyle(1,BLACK);
    pieslice(305+C_x,392,90,270,6);
    pieslice(337+C_x,392,270,90,5);

    //enemyCar
    CreateNMoveEnemyCar(305,-50,enemyFast,RED,GREEN);
    CreateNMoveEnemyCar(300,-100,enemyNormal,BLUE,BROWN);
    CreateNMoveEnemyCar(250,-30,enemySlow,YELLOW,CYAN);
//
    enemyNormal+=5;
    enemyFast+=8;
    enemySlow+=3;


    if(GetAsyncKeyState(VK_LEFT))
        C_x-=M_Speed;
    else if(GetAsyncKeyState(VK_RIGHT))
        C_x+=M_Speed;

    page=1-page;
    delay(50);
    }

    getch();

}
