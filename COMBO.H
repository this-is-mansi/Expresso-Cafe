#include<iostream.h>
#include<graphics.h>
void cup_cake()
{
    line(230,120,240,150);
    line(280,120,270,150);
    line(240,150,270,150);
    ellipse(256,120,180,360,25,7);
    ellipse(256,120,0,180,25,25);
    circle(255,90,5);
}
void c_cake()
{
    line(30,120,40,150);
    line(80,120,70,150);
    line(40,150,70,150);
    ellipse(56,120,180,360,25,7);
    ellipse(56,120,0,180,25,25);
    circle(55,90,5);
}
void c_coldcup(void)
{
   line(450,160,450,220);
   line(500,160,500,220);
   ellipse(475,220,180,0,25,10);
   ellipse(475,160,0,360,25,10);
   line(500,170,520,170);
   line(500,210,520,210);
   line(520,170,520,210);
   line(512,175,512,205);
   line(500,175,512,175);
   line(500,205,512,205);
}
void c_cookies(void)
{
   rectangle(300,100,360,115);
   rectangle(300,85,360,97);
   ellipse(330,101,60,0,30,3);
}
void c_cup(void)
{
  cup_cake();
  c_cookies();

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

   ellipse(320,160,0,360,19,5);
   ellipse(320,160,0,360,10,2); //inner
   setcolor(WHITE);
}
void c_food()
{
 ellipse(470,120,380,160,40,40);
 rectangle(510,107,430,120);
 ellipse(470,107,200,340,40,40);
 line(430,110,510,110);
 line(430,117,510,117);
}
void cookies(void);

void c_fries(void)
{
  line(520,130,525,170);
  line(590,130,585,170);
  line(525,170,585,170);
  ellipse(555,125,190,350,35,15);
  rectangle(555,105,560,140);
  line(560,110,567,110);
  rectangle(545,105,550,140);
  rectangle(567,105,573,139);
  line(540,110,545,110);
  rectangle(575,100,580,136);
  rectangle(584,105,588,132);
  line(580,110,584,110);
  rectangle(525,105,530,134);
  line(530,110,535,110);
  rectangle(535,100,540,137);
}
void c_drink(void)
{
   line(100,160,110,220);
   line(160,160,150,220);
   line(110,220,150,220);
   line(100,160,160,160);
   line(100,165,160,165);
   rectangle(125,140,130,160);
   ellipse(130,190,360,0,20,10);
}
void c_pizza(void)
{
   ellipse(140,120,0,360,58,18);
   ellipse(140,120,0,360,55,15);
  // line(95,150,205,150);
//   line(150,135,150,165);
   ellipse(176,120,0,360,10,5);
   ellipse(105,120,0,360,10,5);
   ellipse(140,112,0,360,10,5);
   ellipse(140,129,0,360,10,5);
}
void c_cook(void)
 {
   rectangle(390,350,330,360);
   rectangle(390,380,330,390);
   outtextxy(329,360,"@@@@@@@@");
   outtextxy(329,375,"@@@@@@@@");
   ellipse(360,370,360,0,30,3);
}
void c_soup()
{
   ellipse(390,430,180,0,30,25);
   line(360,430,420,430);
   line(360,435,420,435);
   ellipse(390,410,90,240,5,5);
   ellipse(387,420,340,90,5,5);

   ellipse(400,410,90,240,5,5);
   ellipse(397,420,340,90,5,5);

   ellipse(380,410,90,240,5,5);
   ellipse(377,420,340,90,5,5);
}
void combo()
{
   int gd=DETECT,gm,a;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   c_drink();
   c_cup();
   c_pizza();
   c_soup();
   c_cook();
   c_fries();
   c_coldcup();
//  cake();
   c_food();
	cout<<"Enter choice(press < to go back):";
	//First combo--
	outtextxy(50,60,"Combo #1:Mac combo");
	outtextxy(30,232,"Cheese pizza : 120");
	outtextxy(30,246,"One Coke : 80");
	outtextxy(30,285,"Total : 200");
	line(20,280,125,280);
	line(125,280,125,300);
	ellipse(168,270,0,360,25,20);
	outtextxy(153,260,"Save");
	outtextxy(157,276,"20%");
	//Second combo --
	outtextxy(230,60,"Combo #2:Club combo");
	outtextxy(230,234,"One Club: 150");
	outtextxy(230,248,"One cappuccino: 150");
	outtextxy(230,262,"One Cup cake: 50");
	outtextxy(240,285,"Total : 350");
	line(220,280,400,280);
	ellipse(255,200,0,360,30,25);
	outtextxy(240,190,"Save");
	outtextxy(245,205,"25 %");
	//Third combo--
	outtextxy(440,60,"Combo #3:Meal combo");
	outtextxy(430,240,"2 French fries : 120");
	outtextxy(430,254,"Cold coffee(crush):80");
	outtextxy(430,268,"Cheese burger:50");
	line(420,280,600,280);
	outtextxy(450,285,"Total : 250");
	//Fourth combo--
	outtextxy(80,330,"Combo #4:Cold combo");
	outtextxy(27,350,"2 Cold coffee:");
	outtextxy(50,364,"100 Rs");
	outtextxy(27,378,"2 Icecream:");
	outtextxy(50,392,"150 Rs");
	outtextxy(25,432,"Total : 250");
	//Fifth combo--
	outtextxy(350,330,"Combo #5:Deit combo");
	outtextxy(478,364,"Tuna bread:50");
	outtextxy(478,378,"tomato soup:150");
	outtextxy(478,392,"Wine:200");
	outtextxy(500,418,"Total:400");
   rectangle(20,50,200,300);

   rectangle(220,50,400,300);
   rectangle(420,50,600,300);
   rectangle(20,320,300,460);
   rectangle(320,320,600,460);

   line(440,360,440,390);
   line(470,360,470,390);
   ellipse(455,390,180,360,14,10);
   ellipse(455,360,0,360,14,7);
   line(453,400,453,420);
   line(458,400,458,420);
   ellipse(455,422,0,360,14,7);    // till here glass

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

   ellipse(250,380,200,340,40,40);
   line(212,392,288,392);
   ellipse(230,385,340,200,19,15);
   ellipse(267,386,340,200,17,15);
   ellipse(250,367,360,190,17,15);
   circle(250,346,4);
   circle(267,367,4);
   circle(230,367,4);
   line(280,392,300,367);
   line(285,392,302,367);
   line(245,420,230,440);
   line(255,420,270,440);
   line(230,440,270,440);  //ice cream
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               