#include <iostream>
using namespace std;

  class shape
{
   public:
     virtual void display()
  {
    cout << "this is a shape" << endl;
  }
};

class polygon : public shape
{
public:
  void display() override
  {
    cout << "polygon is  shape" << endl;
  }
};

class rectangle : public polygon
{
public:
  void display() override
  {
    cout << "rectangle is polygon" << endl;
  }
};

class triangle : public polygon
    {
    public:
  void display() override
  {
    cout << "triangle is a polygon" << endl;
  }

};

class square : public rectangle
{
   public:
  void display() override
  {
    cout << "Square is a rectangle" << endl;
  }
};

int main()
{

  shape basicShape;
  polygon poly;
  rectangle rect;
  triangle tri;
  square sqr;

  cout << "callin display() from each obj" << endl;
 

  basicShape.display();

  poly.display();

  rect.display();

  tri.display();

  sqr.display();


  return 0;
}