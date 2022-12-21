#include<iostream>
#include<math.h>
using namespace std;
class time
{
	int h,m,s;
	public:
		time(int h=0,int m=0, int s=0)
		{
			time::h=h;
			time::m=m;
			time::s=s;
		}
		time(time &obj)
		{
			h=obj.h;
			m=obj.m;
			s=obj.s;
		}	
		void input()
		{
			cout<<"Enter Hour , Minute , Second :"<<endl;
			cin>>h>>m>>s;
			cout<<endl;
		}
		void show()
		{
			cout<<h<<"hr :"<<m<<"min :"<<s<<"sec "<<endl;
		}
		friend time add (time ob1, time ob2);
		friend time sub2s(time ob1, time ob2);
		friend void comp(time ob1, time ob2);
};
	time add(time ob1,time ob2)
	{ 
		time o,temp;
		
		o.s=ob1.s + ob2.s;
		temp.s= o.s/60;
		o.s =o.s % 60;
		
		o.m=ob1.m + ob2.m + temp.s;
		temp.m= o.m / 60;
		o.m =o.m % 60;
		
		o.h=ob1.h + ob2.h + temp.m;
		  
		
		if(o.h > 24) 
		{
		o.h=o.h / 24;
		o.m=o.m + o.h % 24;
	    }
		
		return o;
	}
	
	time sub2s(time ob1, time ob2)
	{
		time o;
		int temp = 0;
		int x= ob1.h*60*60 + ob1.m*60 +ob1.s ;
		int y= ob2.h*60*60 + ob2.m*60 +ob2.s ;
		int d= (x-y);
		
		o.h=d/3600;
		temp=d%3600;
		
		o.m=temp / 60;
		temp=o.m%60;
		
		o.s=temp;
		
		return o;	
		
	}
	
	
	void comp(time ob1,time ob2)
	{
		int a=ob1.h + ob1.m + ob1.s ;
		int b=ob2.h + ob2.m + ob2.s ;
		if(a<b)
		  cout<<"Time 1 is Small "<<endl;
		else
		  cout<<"Time 2 is Small "<<endl;
	}
	
int main()
{
	cout << "MOHAMMAD SHAHID RAZA" << endl;
	cout << "A35404821013" << endl;
	cout << "Week 6 Question 1 output:"<<endl;
	time ob1(3,4,6);
	time ob2(1,2,2), ob ;
	ob = add (ob1,ob2); ob.show();	
	ob = sub2s(ob1,ob2); ob.show();
	comp(ob1,ob2);
	
	cout<<endl<<endl;
	
	time obj1(ob), obj2(ob), obj3;
	obj1.input();  obj2.input();
	obj3 = add (obj1,obj2); obj3.show();	
	obj3 = sub2s(obj1,obj2); obj3.show();
	comp(obj1,obj2);
	
}	
