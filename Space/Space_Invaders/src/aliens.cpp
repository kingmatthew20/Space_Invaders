#include "../inc/aliens.hpp"

Aliens::Aliens()
{

}

Aliens::~Aliens()
{
   while(!aliens_.empty())
   {
      aliens_.pop_back();
   }
}
void Aliens::pushfront(int x, int y)
{
   aliens_.push_front(NodeA(x , y));
}
void Aliens::pushback()
{
   int x, y;
   x = aliens_.front().pos_x_;
   y = aliens_.front().pos_y_;
   aliens_.push_back(NodeA(x , y));
}
void Aliens::alien1(prg::Canvas &canvas)
{
   std::list<NodeA>::const_iterator iterator_;
   prg::ImageFile("space_invader_sprites.bmp").load(sprite);
   for(iterator_ = aliens_.begin(); iterator_ != aliens_.end(); iterator_++)
   {
      canvas.blit(sprite, 33, 74, 55, 90, iterator_->pos_x_, iterator_->pos_y_);
   }
}
void Aliens::alien2(prg::Canvas &canvas)
{
   std::list<NodeA>::const_iterator iterator_2;
   prg::ImageFile("space_invader_sprites.bmp").load(sprite);
   for(iterator_2 = aliens_.begin(); iterator_2 != aliens_.end(); iterator_2++)
   {
      canvas.blit(sprite, 4, 106, 20, 122, iterator_2->pos_x_, iterator_2->pos_y_);
   }
}
void Aliens::alien3(prg::Canvas &canvas)
{
   std::list<NodeA>::const_iterator iterator_3;
   prg::ImageFile("space_invader_sprites.bmp").load(sprite);
   for(iterator_3 = aliens_.begin(); iterator_3 != aliens_.end(); iterator_3++)
   {
      canvas.blit(sprite, 33, 138, 56, 154, iterator_3->pos_x_, iterator_3->pos_y_);
   }
}
void Aliens::move_()
{
   switch(direction_)
   {
      case 0:
      {
         pushfront(x_ +10, y_);
         aliens_.pop_back();
      }
      break;
      case 1:
      {
         pushfront(x_ -10, y_);
         aliens_.pop_back();
      }
      break;
      case 2:
      {
         pushfront(x_ , y_ -10);
         aliens_.pop_back();
      }
   }
   x_ = aliens_.front().pos_x_;
   y_ = aliens_.front().pos_y_;
}
void Aliens::SetDirection(int direction)
{
   if(direction>= 0 && direction< 4)
   {
      direction_ = direction;
   }
}
void Aliens::movement()
{
   std::list<NodeA>::const_iterator iterator_4;
   for(iterator_4 = aliens_.begin(); iterator_4 != aliens_.end(); iterator_4++)
   {
      if(x_ == 0)
      {
         SetDirection(0);
      }
      else if (x_ == 800)
      {
         SetDirection(1);
      }
   }
   x_ = aliens_.front().pos_x_;
   y_ = aliens_.front().pos_y_;
}
int Aliens::GetX()
{
   return aliens_.front().pos_x_;
}
