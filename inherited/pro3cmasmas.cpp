#include <iostream>
#include <cmath>
using namespace std;

const double PI=3.141592654;

class Shape
{
protected:
    double x, y;
public:
    Shape(): x(1.0),y(1.0){}
    Shape(double a, double b): x(a),y(b){}
    virtual void display()=0;
    virtual void getDimensions()=0;
    virtual double area()=0;
    virtual double perimeter()=0;
   virtual double volume()=0;
};

class Rectangle: public Shape
{
public:
    Rectangle():Shape(){}
    Rectangle(double a, double b):Shape(a,b){}
    void display();
    void getDimensions()
    {
        cout<<"Input for Rectangle - "
            <<"enter length and width: ";
        cin>>x>>y;
    }
    double area()
        {return x*y;}
    double perimeter()
        {return (2*x)+(2*y);}
    double volume()
        {return 0;}
};

class Circle: public Shape
{
private:
    double radius;
public:
    Circle(): radius(1.0){}
    Circle(double r): radius(r){}
    void display();
    void getDimensions()
    {
        cout<<"Input for Circle - enter radius: ";
        cin>>radius;
    }
    double area()
        {return PI*radius*radius;}
    double perimeter()
        {return 2*PI*radius;}
    double volume()
        {return 0;}
 };

class Triangle: public Shape
 {
private:
    double z;
public:
    Triangle():z(1.0), Shape(){}
    Triangle(double f, double g, double w):z(w), Shape(f,g){}
    void display();
    void getDimensions()
    {
        cout<<"Input for Triangle - "
            <<"enter side 1, side 2, side 3: ";
        cin>>x>>y>>z;
    }
    double area()
    {
        double half, underroot;
        half = perimeter()/2;
        underroot = half*(half-x)*(half-y)*(half-z);
        return sqrt(underroot);
    }
    double perimeter()
        {return x+y+z;}
    double volume()
        {return 0;}
};

class Box: public Shape
{
private:
    double p;
public:
    Box():p(1.0), Shape(){}
    Box(double a, double b, double c): Shape(a,b), p(c){}
    void display();
    void getDimensions()
    {
        cout<<"Input for Box - "
            <<"enter length, width, and height: ";
        cin>>x>>y>>p;
    }
    double area()
        {return (2*x*y)+(2*x*p)+(2*y*p);}
    double perimeter()
        {return 0;}
    double volume()
        {return x*y*p;}
};

class Can: public Shape
{
public:
    Can():Shape(){}
    Can(double r, double h):Shape(r,h){}
    void display();
    void getDimensions()
    {
        cout<<"Input for Can - "
            <<"enter radius and height: ";
        cin>>x>>y;
    }
    double area()
    {
        double base;
        base = PI*x*x;
        return (2*PI*x*y)+(2*PI*x*x);
    }
    double perimeter()
        {return 0;}
    double volume()
        {return PI*x*x*y;}
};

class Cone: public Shape
{
public:
    Cone():Shape(){}
    Cone(double r, double h):Shape(r, h){}
    void display();
    void getDimensions()
    {
        cout<<"Input for Cone - "
            <<"enter radius and height: ";
        cin>>x>>y;
    }
    double area()
    {
        double underroot;
        underroot = sqrt((x*x)+(y*y));
        return (PI*x*x)+(PI*x*underroot);
    }
    double perimeter()
        {return 0;}
    double volume()
        {return (1/3)*PI*x*x*y;}
};

class Ball: public Shape
{
private:
    double radius;
public:
    Ball():radius(1.0){}
    Ball(double r):radius(r){}
    void display();
    void getDimensions()
    {
        cout<<"Input for Ball - "
            <<"enter radius: ";
        cin>>radius;
    }
    double area()
        {return 4*PI*radius*radius;}
    double perimeter()
        {return 0;}
    double volume()
        {return (4/3)*PI*radius*radius*radius;}
};


int main()
{
    int cnt=0, cnt2=0, choice;
    char yorn;

    Shape *sPtr[20];

    while(cnt<20)
    {
        cnt++;
        cnt2++;
        cout<<"\nIt is time to enter your shape selection"
            <<" and dimensions.\n"
            <<"Enter the number of the shape type: \n"
            <<"\t1 - Rectangle\n"
            <<"\t2 - Circle\n"
            <<"\t3 - Triangle\n"
            <<"\t4 - Box\n"
            <<"\t5 - Can\n"
            <<"\t6 - Cone\n"
            <<"\t7 - Ball\n"
            <<"=> ";
        cin>>choice;
        while (choice<1||choice>7)
        {
            cout<<"Invalid selection. Re-enter: \n"
                <<"=> ";
            cin>>choice;
        }
        switch (choice)
        {
        case 1:
        {
            sPtr[cnt]=new Rectangle;
            sPtr[cnt]->getDimensions();
            break;
        }
        case 2:
        {
            sPtr[cnt]=new Circle;
            sPtr[cnt]->getDimensions();
            break;
        }
        case 3:
        {
            sPtr[cnt] = new Triangle;
            sPtr[cnt]->getDimensions();
            break;
        }
        case 4:
        {
            sPtr[cnt] = new Box;
            sPtr[cnt]->getDimensions();
            break;
        }
        case 5:
        {
            sPtr[cnt] = new Can;
            sPtr[cnt]->getDimensions();
            break;
        }
        case 6:
        {
            sPtr[cnt] = new Cone;
            sPtr[cnt]->getDimensions();
            break;
        }
        case 7:
        {
            sPtr[cnt] = new Ball;
            sPtr[cnt]->getDimensions();
            break;
        }
        }

        cout<<"\nSelect another shape? (y or n): ";
        cin>>yorn;
        if(yorn=='n'||yorn=='N')
            cnt=20;
    }
    for(int i=0; i<cnt2; i++)
    {
        sPtr[i]->display();
        sPtr[i].perimeter();
    sPtr[i].area();
sPtr[i].volume();
}
    }
    return 0;
}

void Rectangle::display()
{
    cout<<"\nRectangle: "
        <<"\nDimensions: "
        <<"Length: "<<x<<"\nWidth: "<<y
        <<"\nArea: "<<area()
        <<"\nPerimeter: "<<perimeter();
}

void Circle::display()
{
    cout<<"\nCircle: "
        <<"\nDimensions: "
        <<"\nRadius: "<<radius
        <<"\nArea: "<<area()
        <<"\nPerimeter: "<<perimeter();
}

void Triangle::display()
{
    cout<<"\nTriangle: "
        <<"\nDimensions: "
        <<"\nSide 1: "<<x
        <<"\nSide 2: "<<y
        <<"\nSide 3: "<<z
        <<"\nArea: "<<area()
        <<"\nPerimeter: "<<perimeter();
}

void Box::display()
{
    cout<<"\nBox: "
        <<"\nDimensions: "
        <<"\nLength: "<<x
        <<"\nWidth: "<<y
        <<"\nHeight: "<<p
        <<"\nSurface area: "<<area()
        <<"\nVolume: "<<volume();
}

void Can::display()
{
    cout<<"\nBox: "
        <<"\nDimensions: "
        <<"\nRadius: "<<x
        <<"\nHeight: "<<y
        <<"\nSurface area: "<<area()
        <<"\nVolume: "<<volume();
}

void Cone::display()
{
    cout<<"\nCone: "
        <<"\nDimensions: "
        <<"\nRadius: "<<x
        <<"\nHeight: "<<y
        <<"\nSurface area: "<<area()
        <<"\nVolume: "<<volume();
}

void Ball::display()
{
    cout<<"\nBall: "
        <<"\nDimensions: "
        <<"\nRadius: "<<radius
        <<"\nSurface area: "<<area()
        <<"\nVolume: "<<volume();
}
