#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
class customer
{
  protected:
   char a[10];
   char email[15];
   long mobno;
  public:
   customer(){}
   customer(char a[10],char email[15], long mobno)
   {
    strcpy(this->a,a);
    strcpy(this->email,email);
    this->mobno = mobno;
   }
   inline void input_name()
   {
    cin>>a;
   }
   inline void dis()
   {
    cout<<a;
   }
   char* getName()
   {
    return a;
   }
   customer acceptCust(char a[]);
   void disCust(customer);
};
void customer::disCust(customer c1)
{
  cout<<"\n\t\t----------Customer details--------------";
  cout<<"\n\t\tCustomer name : "<<c1.a;
  cout<<"\n\t\tCustomer email ID : "<<c1.email;
  cout<<"\n\t\tCusomer mobile no : "<<c1.mobno;
  cout<<"\n\t\t--------------------------------"<<endl;
}
customer customer::acceptCust(char a[])
{
 cout<<"\n\t\tEnter your email ID : ";
 cin>>email;
 cout<<"\n\t\tEnter your mobile no : ";
 cin>>mobno;
 customer c1(a,email,mobno);
 return c1;
}
int i=0;
class node
{
 public:
  char fname[30];
  float a;
  node *np;
}*stnode,*tmp;
class Bill:public customer
{
 int billno;
 float total;
 float cgst,sgst;
 float finaltotal;
 public:
 Bill():customer()
 {
  billno = 23421;
  total = calculate();
  cgst = total * 0.07;
  sgst = total * 0.07;
  finaltotal = total + cgst + sgst;
 }
 void displayBill(char*);
 float calculate();
};
float Bill::calculate()
{
  node *temp;
  temp=stnode;
  total = 0;
  while(temp!=NULL)
  {
   total = total + temp->a;
   temp=temp->np;
  }
  return total;
}
void crlist(char name[],float b)
{
 node *fnode;
 i++;
 if(i==1)
 {
  stnode=new(node);
  stnode->a=b;
  strcpy(stnode->fname,name);
  stnode->np=NULL;
  tmp=stnode;
 }
 else
 {
  fnode=new (node);
  fnode->a=b;
  strcpy(fnode->fname,name);
  fnode->np=NULL;
  tmp->np=fnode;
  tmp=tmp->np;
 }
}
void drink(void);
void cookies(void);
void ice(void);
void pizza(void);
void fries(void);
void cup(void);
void cold(void);
void cake(void);
void food(void);
void fries(void);
void drink(void);
void ice(void);
void pizza(void);
void soup(void);
void menu();
//functions for combo graphics
void combo_food();
void combo_cupcake();
void combo_coldcup();
void combo_cookies();
void combo_cup();
void combo_soup();
void combo_cook();
void combo_cake();
void combo_pizza();
void combo_drink();
void combo_fries();
void combo_icecream1();
void combo_icecream2();
void dlist()
{
  node *temp;
  temp=stnode;
  if(temp==NULL)
  {
   cout<<"\n\t\tBut, you have not ordered anything..!";
   getch();
   exit(3);
  }
  while(temp!=NULL)
  {
   cout<<"\n\t\t| "<<temp->fname<<":"<<"   "<<temp->a<<" Rs. |" ;
   temp=temp->np;
  }
}
void Bill::displayBill(char a[10])
{
  customer c1 = customer::acceptCust(a);
  cout<<"\n\t\t==========Order Bill============="<<endl;
  cout<<"\n\t\t\tBillno : "<<billno;
  customer::disCust(c1);
  cout<<"\n\n\t\tList of ordered food"<<endl;
  dlist();
  cout<<"\n\t\t================================"<<endl;
  cout<<"\n\t\tTotal        : "<<total;
  cout<<"\n\n\t\tCGST         : "<<cgst;
  cout<<"\t\tSGST         : "<<sgst;
  cout<<"\n\n\t\tFinal amount : "<<finaltotal<<endl;
}
void comboChoice();
void drinkChoice();
void burgerChoice();
void pizzaChoice();
void sandwichChoice();
void friesChoice();
void saladChoice();
void soupChoice();
void cakeChoice();
void iceChoice();
void editMenu();
void main()
{
 int chmain;
 clrscr();
 customer c1;
 delay(200);
 cout<<"Welcome to Cafe coffee day !"<<endl;
 delay(500);
 cout<<"Please let us know your name"<<endl;
 c1.input_name();
 cout<<"\n"<<"So ";
 c1.dis();
 cout<<", How may i help you";
 do
 {
  cout<<"\n\t\t--------MAIN MENU--------";
  cout<<"\n\t\t| 1 : Show me combos     |\n\t\t| 2 : Let me choose meal |\n\t\t| 3 : Exit               |";
  cout<<"\n\t\t-------------------------";
  cout<<"\nDear ";
  c1.dis();
  cout<<", please enter your choice : ";
  cin>>chmain;
  switch(chmain)
  {
   case 1:
      clrscr();
       comboChoice();
       break;
   case 2:
    clrscr();
    char chm;
    do{
    menu();
    cout<<"\n\n\n\n\n\n\n\tPress '<' to go back";
    cout<<"\n\n\n\n\n\n\n\tEnter your choice to choose item : ";
    cin>> chm;
    switch(chm)
    {
     case '1':
      clrscr();
      cleardevice();
      drinkChoice();
      break;
     case '2':
      clrscr();
      cleardevice();
      sandwichChoice();
      break;
     case '3':
       clrscr();
       cleardevice();
       soupChoice();
      break;
     case '4':
       clrscr();
       cleardevice();
       cakeChoice();
      break;
     case '5':
      clrscr();
      cleardevice();
      iceChoice();
      break;
     case '6':
      clrscr();
      cleardevice();
      burgerChoice();
      break;
     case '7':
      clrscr();
      cleardevice();
      pizzaChoice();
      break;
     case '8':
      clrscr();
      cleardevice();
      friesChoice();
      break;
     case '<':
      clrscr();
      cleardevice();
      break;
     default:
      cout<<"\n\tInvalid choice.Try again..!";
    }
   }while(chm!='<');
   break;
   case 3:
     int chbill;
     clrscr();
     cleardevice();
     cout<<"\n\t\t____________________________________";
     cout<<"\n\t\tPlease tell us, do you want to confirm order?-"<<endl;
     cout<<"\n\t\t Here is your list of orders.."<<endl;
     dlist();
     cout<<"\n\t\t______________________________________";
     bill:
     cout<<"\n\n\t\t| 1 : Confirm order and generate bill |";
     cout<<"\n\t\t| 2 : Edit order                      |";
     cout<<"\n\t\t| 3 : Cancel order                    |";
     cout<<"\n\t\t_______________________________________";
     cout<<"\n\t\tEnter choice : ";
     cin>>chbill;
     switch(chbill)
     {
      case 1:
       Bill b;
       b.displayBill(c1.getName());
       break;
      case 2:
       editMenu();
       break;
      case 3:
       break;
      default:
       cout<<"\n\t\tPlease enter valid choice..";
       goto bill;
     }
    break;
   default:
    cout<<"\nInvalid choice...Please enter valid choice..!";
  }
 }while(chmain!=3);
 cout<<"\n\t\t---------THANK YOU...VISIT AGIN......";
 getch();
}
void menu()
{
  int gd=DETECT,gm,a;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  cup();
  cold();
  cookies();
  cake();
  soup();
  cout<<endl<<endl<<"____________\t\t______________\t\t_______\t\t________"<<endl;
  cout<<"1.Beverages\t\t2.Sandwiches\t\t3.Soup\t\t4.Cake"<<endl;
  cout<<"____________\t\t_____________\t\t_______\t\t________";
  ice();
  pizza();
  fries();
  cup();
  cold();
  cake();
  food();
  cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
  cout<<endl<<endl<<"____________\t\t______________\t\t_______\t\t________"<<endl;
  cout<<"5.Ice cream\t\t6.Burger\t\t7.Pizza\t\t8.Fries"<<endl;
  cout<<"____________\t\t_____________\t\t_______\t\t________";
}
void food()
{
 ellipse(250,310,370,160,40,40);
 rectangle(290,297,210,310);
 ellipse(250,297,200,340,40,40);
 line(210,300,290,300);
 line(210,307,290,307);
}
void cake()
{
 line(525,120,535,150);
 line(575,120,565,150);
 line(535,150,565,150);
 ellipse(550,120,180,360,25,7);
 ellipse(550,120,0,180,25,25);//
 circle(550,90,5);
}
void pizza(void)
{
 ellipse(400,300,0,360,58,18);
 ellipse(400,300,0,360,55,15);
 ellipse(436,300,0,360,10,5);
 ellipse(365,300,0,360,10,5);
 ellipse(400,292,0,360,10,5);
 ellipse(400,309,0,360,10,5);
}
void soup()
{
 ellipse(410,120,180,0,30,25);
 line(380,120,440,120);
 line(380,125,440,125);
 ellipse(410,100,90,240,5,5);
 ellipse(407,110,340,90,5,5);
 ellipse(420,100,90,240,5,5);
 ellipse(417,110,340,90,5,5);
 ellipse(400,100,90,240,5,5);
 ellipse(397,110,340,90,5,5);
}
void ice(void)
{
   ellipse(40,300,200,340,40,40);
   line(2,312,78,312);
   ellipse(20,305,340,200,19,15);
   ellipse(57,306,340,200,17,15);
   ellipse(40,285,360,190,17,15);
   circle(40,266,4);
   circle(57,287,4);
   circle(20,287,4);
   line(70,312,90,287);
   line(75,312,95,287);
   line(90,287,95,287);
   line(35,340,20,360);
   line(45,340,60,360);
   line(20,360,60,360);
}
void drink(void)
{
 line(300,160,310,220);
 line(360,160,350,220);
 line(310,220,350,220);
 line(300,160,360,160);
 line(300,165,360,165);
 rectangle(325,140,330,160);
 ellipse(330,190,360,0,20,10);
}
void cold(void)
{
 line(0,100,0,130);
 line(30,100,30,130);
 ellipse(15,130,180,360,14,10);
 ellipse(15,100,0,360,14,7);
 line(13,140,13,160);
 line(18,140,18,160);
 ellipse(15,162,0,360,14,7);
}
void editMenu()
{
}
void cookies(void)
{
 rectangle(220,100,280,110);
 rectangle(220,130,280,140);
 outtextxy(219,110,"@@@@@@@@");
 outtextxy(219,125,"@@@@@@@@");
 ellipse(250,120,360,0,30,3);
}
void fries(void)
{
 line(510,330,515,370);
 line(580,330,575,370);
 line(515,370,575,370);
 ellipse(545,325,190,350,35,15);
 rectangle(545,295,550,340);
 line(520,310,525,310);
 rectangle(515,305,520,335);  //
 rectangle(555,305,560,340);
 line(560,308,565,308);
 rectangle(565,305,570,337);
 rectangle(574,300,578,335);
 rectangle(535,305,540,340);
 rectangle(525,300,530,338);
}
void cup(void)
{
 ellipse(60,150,0,360,10,4);
 line(55,150,65,150);
 ellipse(55,160,0,360,10,4);
 line(50,160,60,160);
 ellipse(110,100,0,150,5,5);//
 ellipse(110,101,270,0,5,9); //heart
 ellipse(100,100,0,150,5,5);
 ellipse(100,101,150,270,5,9);//heart
 ellipse(100,130,180,0,30,30);
 ellipse(100,130,0,360,30,10);
 ellipse(100,130,0,360,25,7); //    //
 ellipse(129,145,250,80,9,9);
 ellipse(100,160,130,50,30,10);
 ellipse(111,118,90,180,5,8);    //hline
 ellipse(100,130,0,360,19,5);
}
void burgerChoice()
{
  char chbur;
  do
  {
   cout<<"\n\t\t| ---------Burgers--------  | Prices |";
   cout<<"\n\t\t| 1 : Cheese burger         |  40/-  |";
   cout<<"\n\t\t| 2 : Double cheese burger  |  60/-  |";
   cout<<"\n\t\t| 3 : Quarter pounder       |  70/-  |";
   cout<<"\n\t\t| 4 : CheeseBurger (Paneer) |  80/- |";
   cout<<"\n\t\t| < : Exit from burger menu |   -    |";
   cout<<"\n\t\t---------------------------------------";
   cout<<"\n\tEnter choice to add in order : ";
   cin>>chbur;
   switch(chbur)
   {
    case '1':
     crlist("Cheese burger",40);
     break;
    case '2':
     crlist("Double cheese burger",60);
     break;
    case '3':
     crlist("Quarter pounder",70);
     break;
    case '4':
     crlist("Cheese burger(Paneer)",80);
     break;
    case '<':
     break;
    default:
     cout<<"\nInvalid choie...Try again.!";
   }
  }while(chbur!='<');
}
/*void mainchoice()
{
 cout<<"\n\t\t---------------------------";
 cout<<"\n\t\t| 1 : Drinks    |";
 cout<<"\n\t\t| 2 : Sandwich  |";
 cout<<"\n\t\t| 3 : Soup      |";
 cout<<"\n\t\t| 4 : Cake      |";
 cout<<"\n\t\t| 5 : Ice cream |";
 cout<<"\n\t\t| 6 : Burger    |";
 cout<<"\n\t\t| 7 : Pizza     |";
 cout<<"\n\t\t| 8 : Fries     |";
 cout<<"\n\t\t| < : Exit      |";
}*/
void soupChoice()
{
 char chsoup;
 while(chsoup!='<')
 {
  cout<<"\n\t\t| ----------Soup----------  | Prices |";
  cout<<"\n\t\t| 1 : Tomato Soup           |  20/-  |";
  cout<<"\n\t\t| 2 : Chinese soup          |  30/-  |";
  cout<<"\n\t\t| 3 : Knorr soup            |  35/-  |";
  cout<<"\n\t\t| < : Exit from soup menu   |   -    |";
  cout<<"\n\t\t---------------------------------------";
  cout<<"\n\tEnter choice to add in order : ";
  cin>>chsoup;
  switch(chsoup)
  {
   case '1':
    crlist("Tomato soup",20);
    break;
   case '2':
    crlist("Chinese soup",30);
    break;
   case '3':
    crlist("Knorr soup",35);
    break;
   case '<':
    break;
   default:
    cout<<"\n\tInvalid choice..Try again.!";
  }
 }
}
void iceChoice()
{
 char chice;
 while(chice!='<')
 {
  cout<<"\n\t\t| -------Ice cream--------  | Prices |";
  cout<<"\n\t\t| 1 : Vanilla               |  20/-  |";
  cout<<"\n\t\t| 2 : Chocolate             |  25/-  |";
  cout<<"\n\t\t| 3 : Strawberry            |  25/-  |";
  cout<<"\n\t\t| 4 : Pista                 |  25/-  |";
  cout<<"\n\t\t| 5 : Butterscotch          |  30/-  |";
  cout<<"\n\t\t| < : Exit from salad menu  |   -    |";
  cout<<"\n\t\t---------------------------------------";
  cout<<"\n\tEnter choice to add in order : ";
  cin>>chice;
  switch(chice)
  {
   case '1':
    crlist("Vanilla ice cream",20);
    break;
   case '2':
    crlist("Chocolate ice cream",25);
    break;
   case '3':
    crlist("Strawberry ice cream",25);
    break;
   case '4':
    crlist("Pista ice cream",25);
    break;
   case '5':
    crlist("Butterscotch ice cream",30);
    break;
   case '<':
    break;
   default:
    cout<<"\n\tInvalid choice..Try again.!";
  }
 }
}
void saladChoice()
{
 char chsalad;
 while(chsalad!='<')
 {
  cout<<"\n\t\t| ---------Salad----------  | Prices |";
  cout<<"\n\t\t| 1 : Salad for dietitians  |  30/-  |";
  cout<<"\n\t\t| 2 : Chocolate salad       |  30/-  |";
  cout<<"\n\t\t| 3 : Jam salad(vegies)     |  45/-  |";
  cout<<"\n\t\t| < : Exit from salad menu  |   -    |";
  cout<<"\n\t\t---------------------------------------";
  cout<<"\n\tEnter choice to add in order : ";
  cin>>chsalad;
  switch(chsalad)
  {
   case '1':
    crlist("Salad for dietitians",30);
    break;
   case '2':
    crlist("Chocolate salad",30);
    break;
   case '3':
    crlist("Jam salad(vegies)",45);
    break;
   case '<':
    break;
   default:
    cout<<"\n\tInvalid choice..Try again.!";
  }
 }
}
void cakeChoice()
{
 char chcake;
 while(chcake!='<')
 {
  cout<<"\n\t\t| ---------Cakes----------  | Prices |";
  cout<<"\n\t\t| 1 : Chocolate cake        | 110/-  |";
  cout<<"\n\t\t| 2 : Black forest cake     | 130/-  |";
  cout<<"\n\t\t| 3 : Strawberry cake       | 150/-  |";
  cout<<"\n\t\t| 4 : Kaju Pista cake       | 200/-  |";
  cout<<"\n\t\t| < : Exit from cake menu   |   -    |";
  cout<<"\n\t\t---------------------------------------";
  cout<<"\n\tEnter choice to add in order : ";
  cin>>chcake;
  switch(chcake)
  {
   case '1':
    crlist("Chocolate cake",110);
    break;
   case '2':
    crlist("Black forest cake",130);
    break;
   case '3':
    crlist("Strawberry cake",150);
   case '4':
    crlist("Kaju pista cake",200);
    break;
   case '<':
    break;
   default:
    cout<<"\n\tInvalid choice..Try again.!";
  }
 }
}
void friesChoice()
{
    char chfr;
    while(chfr!='<')
    {
     cout<<"\n\t\t| ---------Fries----------  | Prices |";
     cout<<"\n\t\t| 1 : French fries          |  35/-  |";
     cout<<"\n\t\t| 2 : French fries(cheese)  |  50/-  |";
     cout<<"\n\t\t| 3 : Spicy french fries    |  40/-  |";
     cout<<"\n\t\t| < : Exit from fries menu  |   -    |";
     cout<<"\n\t\t---------------------------------------";
     cout<<"\n\tEnter choice to add in order : ";
     cin>>chfr;
     switch(chfr)
     {
      case '1':
       crlist("French fries",35);
       break;
      case '2':
       crlist("French fries(cheese)",50);
       break;
      case '3':
       crlist("Spicy french fries",40);
       break;
      case '<':
       break;
      default:
       cout<<"\n\tInvalid choice..Try again.!";
     }
   }
}
void comboChoice()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 char chcombo;
 while(chcombo!='<')
 {
   cout<<"\n\t\tEnter '<' to go back";
   combo_drink();
   combo_cup();
   combo_pizza();
   combo_soup();
   combo_cook();
   combo_fries();
   combo_cup();
   combo_coldcup();
   combo_cake();
   combo_food();
   cout<<endl<<endl<<endl<<endl<<"\t1.Mac combo \t\t2.Burger combo\t\t3.Meal combo";
   cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t4.Cold combo\t\t\t5.Breakfast combo";

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

   combo_icecream1();
   combo_icecream2();
   cout<<"\n\n\n\n\n\n\n\n\n\t\tEnter your choice for combo : ";
   cin>>chcombo;
 //   cout<<"\n\t\t--------Special combos--------";

   /* cout<<"\n\t\t          Names                   | Prices |";
    cout<<"\n\t\t| 1 : Breakfast combo             |  200/- |";
    cout<<"\n\t\t| 2 : Combo for meal              |  350/- |";
    cout<<"\n\t\t| 3 : Combo of drinks and burgers |  250/- |";
    cout<<"\n\t\t| 4 : Combo of pizzas             |  350/- |";
    cout<<"\n\t\t| < : Don't want combo            |   -    |";
    cout<<"\n\t\t------------------------------";*/
    switch(chcombo)
    {
     case '1':
      crlist("Mac combo",200);
      break;
     case '2':
      crlist("Burger combo",350);
      break;
     case '3':
      crlist("Meal combo",250);
      break;
     case '4':
      crlist("Cold combo",350);
      break;
     case '5':
      crlist("Breakfast combo",400);
     case '<':
      break;
     default:
      cout<<"\n\tInvalid choice..!Try agin..";
    }
    clrscr();
    cleardevice();
  }
}
void drinkChoice()
{
   char chdrink;
   while(chdrink!='<')
   {
      cout<<"\n\t\t| ---------Drinks---------  | Prices |";
      cout<<"\n\t\t| 1 : Hot coffee            |  35/-  |";
      cout<<"\n\t\t| 2 : Cold coffee           |  50/-  |";
      cout<<"\n\t\t| 3 : Cold coffee with crush|  70/-  |";
      cout<<"\n\t\t| 4 : Coca cola(1litre bott)|  110/- |";
      cout<<"\n\t\t| < : Exit from drinks      |   _    |";
      cout<<"\n\t\t---------------------------------------";
      cout<<"\n\tEnter choice to add in order : ";
      cin>>chdrink;
      switch(chdrink)
      {
       case '1':
	crlist("Hot coffee",35);
	break;
       case '2':
	crlist("Cold coffee",50);
	break;
       case '3':
	crlist("Cold coffee(crush)",70);
	break;
       case '4':
	crlist("Coca cola",110);
	break;
       case '<':
	break;
       default:
	cout<<"\n\tInvalid choice..!";
      }
   }
}
void pizzaChoice()
{
 char chpiz;
 while(chpiz!='<')
 {
  cout<<"\n\t\t| ---Pizza(with cheese)---  | Prices |";
  cout<<"\n\t\t| 1 : Paneer pizza          |  75/-  |";
  cout<<"\n\t\t| 2 : Vegie Cheesie pizza   |  85/-  |";
  cout<<"\n\t\t| 3 : Onion pizza           |  85/-  |";
  cout<<"\n\t\t| 4 : Extra cheese pizza    | 100/-  |";
  cout<<"\n\t\t| < : Exit from pizza menu  |   -    |";
  cout<<"\n\t\t---------------------------------------";
  cout<<"\n\tEnter choice to add in order : ";
  cin>>chpiz;
  switch(chpiz)
  {
   case '1':
    crlist("Paneer pizza",75);
    break;
   case '2':
    crlist("Vegie cheesie pizza",85);
    break;
   case '3':
    crlist("Onion pizza",85);
    break;
   case '4':
    crlist("Extra cheese pizza",100);
    break;
   case '<':
    break;
   default:
    cout<<"\n\tInvalid choice..Try again..!";
  }
 }
}
void sandwichChoice()
{
  char chsan;
  while(chsan!='<')
  {
   cout<<"\n\t\t| -------Sandwich--------  | Prices |";
   cout<<"\n\t\t| 1 : Jam sandwich          |  30/-  |";
   cout<<"\n\t\t| 2 : Chocolate sandwich    |  40/-  |";
   cout<<"\n\t\t| 3 : Vegie cheesie sandwich|  60/-  |";
   cout<<"\n\t\t| < : Exit from sanwich menu|   -    |";
   cout<<"\n\t\t---------------------------------------";
   cout<<"\n\tEnter choice to add in order : ";
   cin>>chsan;
   switch(chsan)
   {
    case '1':
     crlist("Jam sandwich",30);
     break;
    case '2':
     crlist("Chocolate sandwich",40);
     break;
    case '3':
     crlist("Vegie cheesie sandwich",60);
     break;
    case '<':
     break;
    default:
     cout<<"\n\tInvalid choice..Try again.!";
   }
  }
}
void combo_cupcake()
 {
    line(230,120,240,150);
    line(280,120,270,150);
    line(240,150,270,150);
    ellipse(256,120,180,360,25,7);
    ellipse(256,120,0,180,25,25);
    circle(255,90,5);
}
void combo_cake()
{
    line(30,120,40,150);
    line(80,120,70,150);
    line(40,150,70,150);
    ellipse(56,120,180,360,25,7);
    ellipse(56,120,0,180,25,25);
    circle(55,90,5);
}

 void combo_coldcup(void)
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
 void combo_cookies(void)
 {
   rectangle(300,100,360,115);
    rectangle(300,85,360,97);
    ellipse(330,101,60,0,30,3);

 }
 void combo_cup(void)
 {
     combo_cupcake();
      combo_cookies();
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

 void combo_food()
{
ellipse(470,120,380,160,40,40);
rectangle(510,107,430,120);
ellipse(470,107,200,340,40,40);
line(430,110,510,110);
line(430,117,510,117);
}
  // void combo_cookies(void);

  void combo_fries(void)
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

   void combo_drink(void)
{
   line(100,160,110,220);
   line(160,160,150,220);
   line(110,220,150,220);
   line(100,160,160,160);
   line(100,165,160,165);
   rectangle(125,140,130,160);
   ellipse(130,190,360,0,20,10);
}
void combo_pizza(void)
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
void combo_cook(void)
 {
   rectangle(390,350,330,360);
    rectangle(390,380,330,390);
   outtextxy(329,360,"@@@@@@@@");
   outtextxy(329,375,"@@@@@@@@");
    ellipse(360,370,360,0,30,3);
 }
 void combo_soup()
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
void combo_icecream1()
{
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
   line(130,440,170,440);  //ice cream1
}
void combo_icecream2()
{
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
   line(230,440,270,440);  //ice cream2
}