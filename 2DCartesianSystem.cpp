#include <iostream>
#include<cmath>
using namespace std;

template <class T>                        //template class
class vector{
    T*  arr;
    int sz, maxSize;

    public:
        vector(){
            maxSize = 1;
            sz = 0;
            arr = new T[maxSize];
        }

        void push_back(T temp){
            if(sz == maxSize){
                T* t = new T[maxSize*2];
                for(int i=0;i<maxSize;i++){
                    arr[i] = t[i];
                }
                maxSize = maxSize*2;
                arr = t;
            }        
            arr[sz++] = temp;
        }

        T & operator[]( int index ){                   //operator overloading
        return arr[ index ];
    	}

    	const T & operator[]( int index ) const{
        	return arr[ index ];
    	}	

        int size(){
			return sz;
		}
};

float ar=0.0;          //global variable

struct coor
{
    int x,y;
    coor() {
    }
};

class point
{   int numofpt;
    public:
    float a,b,c;
    int nop;
    vector<float> ab;                //template using
    coor pt[100];                    //using structure pointer
    point()
    {
        cout<<"enter number of points ";
        cin>>nop;
        cout<<"enter points(in ordered form) "<<endl;
        numofpt = nop;
        for(int i=0;i<nop;i++){
            cin >> pt[i].x >> pt[i].y;                  //structure using
        }
    }  
    void slope()                                  //function overriding
    {
        cout<<"slopes are ";
        for(int i=0;i<nop-1;i++)
        {
            ab.push_back(((float)(pt[i].y-pt[i+1].y)/(float)(pt[i].x-pt[i+1].x)));         //vector template
            cout<<ab[i]<<",";
        }
        cout<<endl;
    } 
    void area() ;
    virtual void getdata()                                                //virtual fuction
    { 
        cout<<"virtual function is called"<<endl;
    }
    friend void getlhse(class point p);                                 //friend function
};

void point::area() 
{
    float ans=0;
    for(int i=0;i<nop;i++)
    {
        if(i<nop-1)
        {
           ans=ans+(pt[i].x*pt[i+1].y)-(pt[i].y*pt[i+1].x) ;
        }
        else
        {
            ans=ans+(pt[i].x*pt[0].y)-(pt[i].y*pt[0].x) ;
        }
    }
    if (ans<0)   {ans=ans*-1;}
    cout<<"area is "<<0.5*ans<<endl;
    ar=ans;
}

void getlhse(class point p)
{
    int count=0,ans=0;
    for(int i=0;i<p.nop-1;i++)
    {
        for(int j=0;j<p.nop-1;j++)
        {
            if(p.ab[i]==p.ab[j])count++;
        }
    }
    cout<<"number of lines having equal slope in given polygon is "<<count;
}

class triangle:public point                                              //inheritance
{
    public:
    int slp=0;
    float m1,m2;
    void slope() {
        if((pt[0].x-pt[1].x)!=0 && (pt[1].x-pt[2].x)!=0 )
        {
            m1=((float)(pt[0].y-pt[1].y)/(float)(pt[0].x-pt[1].x));
            m2=((float)(pt[1].y-pt[2].y)/(float)(pt[1].x-pt[2].x));
            cout<<"slopes are "<<m1<<","<<m2<<endl;
            if(m1*m2==-1)
            {
                slp=-1;
            }
        }
        else if((pt[0].x-pt[1].x)==0 && (pt[1].y-pt[2].y)==0)
        {
           cout<<"slopes are 1/0,0\n";
           slp=-1;   
        }
        else if((pt[0].y-pt[1].y) && (pt[1].x-pt[2].x))
        {
            cout<<"slopes are 0,1/0\n";
            slp=-1;
        }
     }
     void getdata() {
        
        
        if( a==0 || b==0 || c==0 )
        {
            cout<<"points not forming an triangle "<<endl;
        }
        else if( slp==-1 && ( a==b || b==c || c==a ) )
        {
            cout<<"right angled isosceles triangle "<<endl;
        }
        else if( slp==-1 )
        {
            cout<<"right angle triangle "<<endl;
        }
        else if( a==b || b==c || c==a )
        {
            cout<<"isosceles triangle "<<endl;
        }
        else if( a==b && b==c && c==a )
        {
            cout<<"equilateral triangle "<<endl;
        }
        else 
        {
            cout<<"forming an triangle "<<endl;
        }
    }
    void sides() ;
};

void triangle::sides() {

    a=sqrt(((pt[0].x-pt[1].x)*(pt[0].x-pt[1].x))+((pt[0].y-pt[1].y)*(pt[0].y-pt[1].y))) ;
    b=sqrt(((pt[1].x-pt[2].x)*(pt[1].x-pt[2].x))+((pt[1].y-pt[2].y)*(pt[1].y-pt[2].y))) ;
    c=sqrt(((pt[0].x-pt[2].x)*(pt[0].x-pt[2].x))+((pt[0].y-pt[2].y)*(pt[0].y-pt[2].y))) ;

    cout<<"sides form by given points : "<<a<<","<<b<<","<<c<<endl;
}

int main() {
    point o1;
    o1.slope();
    o1.area();
    o1.getdata();
    getlhse(o1);
cout<<endl;
    int p,q;
    triangle o;
    o.sides();
    o.area();
    o.slope();
    o.getdata();
    p=ar;
cout<<endl;
    triangle o2;
    o2.sides();
    o2.area();
    o2.slope();
    o2.getdata();
    q=ar;
    cout<<endl;

    if(p>q)         cout<<"triangle 1 is bigger than triangle 2\n";
    else if(q>p)    cout<<"triangle 2 is bigger than triangle 1\n";
    else if(q==p)   cout<<"both triangle have equal area\n";
    return 0;
}
