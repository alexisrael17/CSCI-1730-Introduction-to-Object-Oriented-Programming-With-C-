
#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;
class Shape
{
   public:
       virtual float get_perimeter() = 0;
       virtual float get_area() = 0;
       virtual ~Shape() {};
       string name;
};
class Rectangle : public Shape
{
   private :
       float width,height;
   public:
       Rectangle()

       {
       }
       Rectangle(float w,float h)
       {
           width = w;
           height = h;
           name = "Rectangle";
       }
       float get_perimeter()
       {
           float perimeter;
           perimeter = 2*(width+height);
           return perimeter;
       }
       float get_area()
       {
           float area;
           area = width*height;
           return area;
       }
       ~Rectangle()
       {
           cout<<"Destroying Rectangle object\n";
       }

};
class Circle : public Shape
{
   private :
       float radius;
   public:
       Circle()
       {
       }
       Circle(float r)
       {
           radius = r;
           name = "Circle";
       }
       float get_perimeter()
       {
           float perimeter;
           perimeter = 2*3.141*radius;
           return perimeter;
       }
       float get_area()
       {
           float area;
           area = 3.141*radius*radius;
           return area;
       }
       ~Circle()
       {
           cout<<"Destroying Circle object\n";
       }
};
class Square : public Rectangle
{
   public:
       Square()
       {
       }
       Square(float side):Rectangle(side,side){
   name = "Square";
       }

       ~Square()
       {
          cout<<"Destroying Square object\n";
       }

};
class Triangle : public Shape
{
   private:
       float side1,side2,side3;
   public:
       Triangle()
       {
       }
       Triangle(float s1,float s2,float s3)
       {
           side1 =s1;
           side2 =s2;
           side3 =s3;
           name = "Triangle";
       }
       float get_perimeter()
       {
           float perimeter;
           perimeter = side1+side2+side3;
           return perimeter;
       }
       float get_area()
       {
           float area;
           float s;
           s= (side1+side2+side3)/2;
           area = sqrt(s*(s-side1)*(s-side2)*(s-side3));
           return area;
       }
       ~Triangle()
       {
           cout<<"Destroying Triangle object\n";
       }
};

class IsoscelesTriangle : public Triangle
{
   public:
       IsoscelesTriangle()
       {
       }
       IsoscelesTriangle(float side1,float side2):Triangle(side1,side1,side2)
       {
           name = "Isosceles";
       }
       ~IsoscelesTriangle()
       {
           cout<<"Destroying IsoscelesTriangle object\n";
       }
};

class EquilateralTriangle : public Triangle
{
   public:
       EquilateralTriangle()
       {
       }
       EquilateralTriangle(float side1):Triangle(side1,side1,side1)
       {
           name = "Isosceles";
       }
       ~EquilateralTriangle()
       {
           cout<<"Destroying EquilateralTriangle object\n";
       }
};


int main()
{
   std::vector<Shape*> shapes;
   //shapes Rectangle(3.5, 4.5);
   shapes.push_back(new Rectangle(3.5, 4.5));
  // shapes.push_back(new Circle(2));
   //shapes.push_back(new Triangle(4,5,6));
   //shapes.push_back(new Square(4));
   //shapes.push_back(new IsoscelesTriangle(4, 5));
   //shapes.push_back(new EquilateralTriangle(4));
   for (int i=0;i<shapes.size();i++)
   {
   std::cout << "The area for this "<<shapes[i]->name<<" is " << shapes[i]->get_area() << std::endl;
   std::cout << "The perimeter for this "<<shapes[i]->name<<" is " << shapes[i]->get_perimeter() << std::endl;
   }

   for (int i=0;i<shapes.size();i++)
   {
       delete shapes[i];
   }

   return 0;
}
