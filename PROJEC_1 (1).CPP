
#include<first.h>
#include<combo.h>
#include<choice.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<food.h>
#include<graphics.h>
#include<fstream.h>
class customer       //class for customer
{
  protected:
   char a[10];
   char email[25],add[30];
   long mobno;
  public:
   customer(){}                   //default constructor
   customer(char a[10],char email[25], long mobno)  //parametrised constructor
   {
    strcpy(this->a,a);
    strcpy(this->email,email);
    this->mobno = mobno;
   }
   inline void input_name() //inline function for accept name
   {
    cin>>a;
   }
   inline void dis()  //inline function to show name
   {
    cout<<a;
   }
   char* getName()     //get function to return name
   {
    return a;
   }
   customer acceptCust(char a[]);
   void disCust(customer);
    void ent(customer,int,float,float,float,float);
};
class node            //class node for liked list
{
 public:
  char fname[30];
  float a;
  node *np;
}*stnode,*tmp;
//functio display details from file(file handling)
void customer::ent(customer c1,int billno,float total,float cgst,float sgst, float finaltotal)
{
   fstream file;
   file.open("Customer",ios::out);    //function for read operation
  file<<"\n\t\t----------Customer details--------------";
  file<<"\n\t\tCustomer name : "<<c1.a;
  file<<"\n\t\tCustomer email ID : "<<c1.email;
  file<<"\n\t\tCusomer mobile no : "<<c1.mobno;

  file<<"\n\t\t==========Order Bill============="<<endl;
  file<<"\n\t\tBillno : "<<billno;
  file<<"\n\n\t\tList of ordered food"<<endl;
  file<<"\t\t================================"<<endl;

  node *temp;
  temp=stnode;

  while(temp!=NULL)
  {
   file<<"\n\t\t| "<<temp->fname<<":"<<"   "<<temp->a<<" Rs. |" ;
   temp=temp->np;
  }
  file<<"\n\t\t================================"<<endl;
  file<<"\n\t\tTotal        :Rs. "<<total;
  file<<"\n\n\t\tCGST         :Rs."<<cgst;
  file<<"\t\tSGST         :Rs. "<<sgst;
  file<<"\n\n\t\tFinal amount : "<<finaltotal<<endl;

    file.close();         //close file
}

void customer::disCust(customer c1)   //function to show customer details
{
  cout<<"\n\t\t----------Customer details--------------";
  cout<<"\n\t\tCustomer name : "<<c1.a;
  cout<<"\n\t\tCustomer email ID : "<<c1.email;
  cout<<"\n\t\tCusomer mobile no : "<<c1.mobno;
  cout<<"\n\t\t--------------------------------"<<endl;
}
customer customer::acceptCust(char a[]) //function to accept details customer
{
 clrscr();
 cleardevice();
 cout<<"\n\t\tEnter your email ID : ";
 cin>>email;
 cout<<"\n\t\tEnter your mobile no : ";
 cin>>mobno;
  cout<<"\n\t\tEnter your address : ";
   cin>>add;
 customer c1(a,email,mobno);
 return c1;
}
int i=0;

class Bill:public customer     //class bill inheriting customer class
{
 int billno;
 float total;
 float cgst,sgst;
 float finaltotal;
 public:
 Bill():customer()        //default constructor
 {
  char a1[30],a2[30];
  billno = 23421;
  total = calculate();
  cgst = total * 0.07;
  sgst = total * 0.07;
  finaltotal = total + cgst + sgst;
 }
 void displayBill(char*);
 float calculate();
};
float Bill::calculate()      //function to calculate bill
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
void crlist(char name[],float b)      //function to generate list of orders
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

void del()              //function to edit order
{   int key;
    cout<<"\t\tEnter the id of order you want to delete:";
    cin>>key;
    struct node *prev, *cur;

    /* Check if head node contains key */
    while (stnode != NULL && key==1)
    {
	// Get reference of head node
	prev = stnode;

	// Adjust head node link
	stnode = stnode->np;

	// Delete prev since it contains reference to head node
	free(prev);

	// No need to delete further
	return;
	}

    prev = NULL;
    cur  = stnode;

    /* For each node in the list */
     for(i=1;cur != NULL;i++)
    {
	// Current node contains key
	if (i == key)
	{
	    // Adjust links for previous node
	    if (prev != NULL)
		prev->np = cur->np;

	    // Delete current node
	    free(cur);

	    // No need to delete further
	    return;
	}

	prev = cur;
	cur = cur->np;
    }
}

void dlist()        //function to display list of oreders
{
  node *temp;
  temp=stnode;     //get reference of head node
  int c=1;
  while(temp!=NULL)     //loop starting from head node
  {
   cout<<"\n\t\t|"<<c<<"."<<temp->fname<<":"<<"   "<<temp->a<<" Rs. |" ;
   temp=temp->np;       //Increament (reference to the next node)
   c++;
  }
}
void Bill::displayBill(char a[10])        //function for display bill
{
  clrscr();
  cleardevice();
  customer c1 = customer::acceptCust(a);
  clrscr();
  cleardevice();
  cout<<"\n\t\t==========Order Bill============="<<endl;
  cout<<"\n\t\t\tBillno : "<<billno;
  customer::disCust(c1);
  cout<<"\n\n\t\tList of ordered food"<<endl;
  dlist();
  cout<<"\n\t\t================================"<<endl;
  cout<<"\n\t\tTotal        :Rs."<<total;
  cout<<"\n\n\t\tCGST         :Rs. "<<cgst;
  cout<<"\tSGST      : Rs."<<sgst;
  cout<<"\n\n\t\tFinal amount : "<<finaltotal<<endl;

  customer::ent(c1,billno,total,cgst,sgst,finaltotal);
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
 start:          //label for goto statement
 dis();
 int chmain;
 clrscr();
 customer c1;
 delay(200);
 cout<<"Welcome to Cafe coffee day !"<<endl;
 delay(500);
 cout<<"Please let us know your name"<<endl;
 c1.input_name();           //accept name of customer
 cout<<"\n"<<"So ";
 c1.dis();
 cout<<", How may i help you";
 do
 {
  cout<<"\n\t\t--------MAIN MENU--------";           //Main menu
  cout<<"\n\t\t| 1 : Show me combos     |\n\t\t| 2 : Let me choose meal |\n\t\t|";
  if(i==0)
  cout<<" 3 : Exit  \t\t|";
  else
{  cout<<" 3 : Show me my order(s)|";
  cout<<"\n\t\t|     and take me to the |";
  cout<<"\n\t\t|     billing section    |";
}  cout<<"\n\t\t-------------------------";
  cout<<"\nDear ";
  c1.dis();
  cout<<", please enter your choice : ";
  cin>>chmain;
  switch(chmain)
  {
   case 1:
       comboChoice();       //calling function for combo choice
       break;
   case 2:
    char chm;
    do{
    menu();                 //calling menu function
    cout<<"\n\n\n\n\n\n\n\n\n\n\nSelect catagory (press < to go back): ";
    cin>> chm;
    switch(chm)
    {
     case '1':             //for drinks
     clrscr();
     cleardevice();
      drinkChoice();
      break;
     case '2':              //for sandwiches
     clrscr();
      cleardevice();
      sandwichChoice();
      break;
     case '3':             //for soups
     clrscr();
       cleardevice();
       soupChoice();
      break;
     case '4':            //for cakes
     clrscr();
       cleardevice();
       cakeChoice();
      break;
     case '5':          //for ice cream
     clrscr();
       cleardevice();
      iceChoice();
      break;
     case '6':         //for burger
     clrscr();
      cleardevice();
     burgerChoice();
      break;
     case '7':         //for pizza
     clrscr();
      cleardevice();
      pizzaChoice();
      break;
     case '8':          //for fries
     clrscr();
      cleardevice();
      friesChoice();
      break;
     case '<':      //go back to main menu
     clrscr();
      cleardevice();
	    break;
     default:
       clrscr();
       cout<<"\n\tInvalid choice.Try again..!";

    }
   }while(chm!='<');
   break;
   case 3:      //exit option
   if(i>0)
   {
     int chbill;
     clrscr();
     cleardevice();
     bill:
     cout<<"\n\t\t____________________________________";
     cout<<"\n\t\tPlease tell us, do you want to confirm order?-"<<endl;
     cout<<"\n\t\t Here is your list of orders.."<<endl;
     dlist();
     cout<<"\n\t\t______________________________________";
     cout<<"\n\n\t\t| 1 : Confirm order and generate bill |";
     cout<<"\n\t\t| 2 : Edit order                      |";
     cout<<"\n\t\t| 3 : Cancel order                    |";
     cout<<"\n\t\t_______________________________________";
     cout<<"\n\t\tEnter choice : ";
     cin>>chbill;
     switch(chbill)
     {
      case 1:                //for generating bill
       cleardevice();
       Bill b;
       b.displayBill(c1.getName());
       break;
      case 2:                  //for deleting some order from list
       del();
       clrscr();
       cleardevice();
       goto bill;
       case 3:             //Cancel order
       break;
      default:
       clrscr();
       cleardevice();
       cout<<"\n\t\tPlease enter valid choice..";
      goto bill;

     }
  }
  else
     goto start;
    break;
   default:
    clrscr();
    cleardevice();
    cout<<"\nInvalid choice...Please enter valid choice..!";

  }
 }while(chmain!=3);
 cout<<"\n\t\t---------THANK YOU...VISIT AGIN......";
 getch();
}

void burgerChoice()      //function for burger choices
{
  char chbur;
 disbur();
do
  {
   cout<<"\t\t\t\t\t";
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

void soupChoice()        //function for soup choices
{
 char chsoup;
  soupdis();
 while(chsoup!='<')
 {
   cout<<"\t\t\t\t\t";
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
void iceChoice()     //function for ice cream choices
{
 char chice;
  creamdis();
 while(chice!='<')
 {
   cout<<"\t\t\t\t\t";
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
void saladChoice()         //function for salad choices
{
 char chsalad;
  saladdis();
 while(chsalad!='<')
 {
   cout<<"\t\t\t\t\t";
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
void cakeChoice()       //function for cake choices
{
 char chcake;
 cakedis();
 while(chcake!='<')
 {
   cout<<"\t\t\t\t\t";
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
void friesChoice()       //function for fries choices
{
    char chfr;
    friesdis();
    while(chfr!='<')
    {
     cout<<"\t\t\t\t\t";
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
void comboChoice()         //function for combo choices
{
 char chcombo;
 combo();
 while(chcombo!='<')
 {
    cin>>chcombo;
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
  }
  cleardevice();
}
void drinkChoice()      //function for drink choices
{
   char chdrink;
   dridis();
   while(chdrink!='<')
   {
       cout<<"\t\t\t\t\t";
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
void pizzaChoice()          //function for pizza choices
{
 char chpiz;
  pizzadis();
 while(chpiz!='<')
 {
   cout<<"\t\t\t\t\t";
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
void sandwichChoice()        //function for sandwich choices
{
  char chsan;
  sandwichdis();
  while(chsan!='<')
  {
    cout<<"\t\t\t\t\t";
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
