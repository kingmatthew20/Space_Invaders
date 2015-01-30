#include "../inc/Missile.hpp"

Missile::~Missile()
{
   while(!Missiles_.empty())
   {
      Missiles_.pop_front();
   }
}
void Missile::pushback()
{
   int x , y;
   x = Missiles_.front().pos_x_;
   y = Missiles_.front().pos_y_;
   Missiles_.push_back(NodeM(x , y));
}
void Missile::pushfront(int x, int y)
{
   cout << " x = " << x << "y = " << y << endl;
   Missiles_.push_front(NodeM(x , y));
}
void Missile::move_()
{
   switch(direction_)
   {
      case 0:
      {
         Missiles_.push_front(NodeM(x_ , y_+4));
         Missiles_.pop_back();
      }
      break;
   }
   cout<< "Y = " << y_ <<endl;
   x_=Missiles_.front().pos_x_;
   y_=Missiles_.front().pos_y_;
}
void Missile::SetDirection(int direction)
{
   if(direction>=0 && direction<4)
   {
      direction_ = direction;
   }
}
void Missile::draw(prg::Canvas& canvas)
{
   prg::ImageFile("space_invader_sprites.bmp").load(sprite);
   list<NodeM>::const_iterator iterator_;
   for (iterator_ = Missiles_.begin(); iterator_ != Missiles_.end(); iterator_++)
   {
      canvas.blit(sprite, 37,31,50,54,iterator_->pos_x_,iterator_->pos_y_);
   }

}
void Missile::destroy()
{
   if (y_ >= 400)
   {
      Missiles_.pop_back();
   }
   y_=Missiles_.front().pos_y_;
}
int Missile::GetX()
{
   cout<< " X = " << Missiles_.front().pos_x_ <<endl;
   return Missiles_.front().pos_x_;
}
int Missile::GetY()
{
   cout<< "Y = " << Missiles_.front().pos_y_ <<endl;
   return Missiles_.front().pos_y_;
}
