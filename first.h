                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          #include<conio.h>
#include<graphics.h>
#include<iostream.h>
void f_cup(void);
void boundaryfill(int x,int y,int f_color,int b_color)
{
 if((getpixel(x,y)!=b_color)&&(getpixel(x,y)!=f_color))
 {
  putpixel(x,y,f_color);
  boundaryfill(x+1,y,f_color,b_color);
  boundaryfill(x-1,y,f_color,b_color);
  boundaryfill(x,y+1,f_color,b_color);
  boundaryfill(x,y-1,f_color,b_color);
 }
}
 void f_cup(void)
 {
   setcolor(BROWN);
  ellipse(280,180,0,360,10,4);
  line(275,180,285,180);
    ellipse(275,190,0,360,10,4);
  line(270,190,280,190);
  ellipse(330,130,0,150,5,5);
  ellipse(330,131,270,0,5,9); //heart
  ellipse(320,130,0,150,5,5);
  ellipse(320,131,150,270,5,9);//heart
   ellipse(320,160,180,0,30,30);
   ellipse(320,160,0,360,30,10);
   ellipse(320,160,0,360,25,7); //
   ellipse(349,175,250,80,9,9);
   ellipse(320,190,130,50,30,10);
   ellipse(331,148,90,180,5,8);    //hline
    boundaryfill(320,160,14,6);

    ellipse(320,160,0,360,19,5);
    ellipse(320,160,0,360,10,2); //inner
   setcolor(WHITE);
 }


void allfood()
{
setcolor(10);
 line(240,360,240,390);
   line(270,360,270,390);
   ellipse(255,390,180,360,14,10);
   ellipse(255,360,0,360,14,7);
   line(253,400,253,420);
   line(258,400,258,420);
   ellipse(255,422,0,360,14,7);    // till here glass



   ellipse(230,455,0,360,58,18);
   ellipse(230,455,0,360,55,15);
   ellipse(266,455,0,360,10,5);
   ellipse(195,455,0,360,10,5);
   ellipse(230,448,0,360,10,5);
   ellipse(230,462,0,360,10,5); //pizza


   ellipse(150,380,200,340,40,40);
   line(112,392,188,392);
   ellipse(130,385,340,200,19,15);
   ellipse(167,386,340,200,17,15);
   ellipse(150,367,360,190,17,15);
   circle(150,346,4);
   circle(167,367,4);
   circle(130,367,4);
   line(180,392,200,367);
   line(185,392,205,367);
   line(200,367,205,367);
   line(145,420,130,440);
   line(155,420,170,440);
   line(130,440,170,440);  //ice cream


   ellipse(90,450,180,0,30,25);
   line(60,450,120,450);
   line(60,455,120,455);
   settextstyle(3,0,1);
   ellipse(90,430,90,240,5,5);
   ellipse(87,440,340,90,5,5);

     ellipse(100,430,90,240,5,5);
   ellipse(97,440,340,90,5,5);

     ellipse(80,430,90,240,5,5);
   ellipse(77,440,340,90,5,5);            // soup

 settextstyle(5,0,0);
}


void strip()
{
setcolor(RED);
rectangle(150,290,439,330);
rectangle(155,295,435,325);
setcolor(WHITE);
settextstyle(7,0,0);
f_cup();
outtextxy(162,287,"What we provide");
line(300,343,300,470);
settextstyle(7,0,3);
setcolor(10);
outtextxy(310,359,"  Rolls,  Pizzas,  Burgers,");
outtextxy(310,384,"    Sandwitches,  soups, ");
outtextxy(310,409,"     Hot & cold drinks");
outtextxy(310,434,"    ice creams, & more. . .");

//  boundaryfill(155,310,13,15);
}

void dis()
{

 int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
     setcolor(13);
   settextstyle(10,0,0);
   outtextxy(105,10," CAFE        DAY");
   setcolor(4);
   line(132,75,270,75);
   settextstyle(5,0,0);
   line(385,75,515,75);
   outtextxy(235,45,"  COFFEE");

    allfood();
  { setcolor(GREEN);

     outtextxy(130,70,"     every successfull  ");
     outtextxy(150,200,"substaintial amount of");
  settextstyle(5,1,0);
     outtextxy(80,110,"Behind");
     settextstyle(5,2,0);
     outtextxy(500,110,"Person");
     settextstyle(4,0,8);

     setcolor(WHITE);
     outtextxy(150,100,"is      a");
  settextstyle(5,0,5);
   outtextxy(200,230,"COFFEE");

  }

 strip();
getch();
closegraph();

}
                                                                                                                                                                                                                       