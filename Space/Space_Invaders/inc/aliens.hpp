#ifndef ALIENS_HPP
#define ALIENS_HPP
#include <prg_interactive.hpp>
#include <list>
#include <iostream>

class NodeA;

class Aliens
{
   public:
      Aliens();
      ~Aliens();
      void pushfront(int x, int y);
      void pushback();
      void alien1(prg::Canvas &canvas);
      void alien2(prg::Canvas &canvas);
      void alien3(prg::Canvas &canvas);
      void move_();
      void SetDirection(int direction);
      void movement();
      int GetX();

   private:
      std::list<NodeA> aliens_;
      prg::Image sprite;
      int x_ , y_;
      unsigned int direction_;
};
class NodeA
{
   public:
    NodeA(int x, int y)
    {
       pos_x_=x;
       pos_y_=y;
    }
    int getX() const
    {
    return pos_x_;
    }
    int getY() const
    {
      return pos_y_;
    }
   private:
   friend class Aliens;
   int pos_x_;
   int pos_y_;
};
#endif // ALIENS_HPP
