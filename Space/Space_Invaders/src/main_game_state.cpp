#include "../inc/main_game_state.hpp"
MainGameState::~MainGameState()
{
}
bool MainGameState::onCreate()
{
   spaceship_.pushfront(200,0);
   alien1_.pushfront(80,100);
   alien1_.pushfront(0,100);
   alien2_.pushfront(0,200);
   alien3_.pushfront(0,300);
   return true;
}
bool MainGameState::onDestroy()
{
   return true;
}
void MainGameState::onEntry()
{
   prg::application.addKeyListener( *this );
}
void MainGameState::onExit()
{
   prg::application.removeKeyListener( *this );
}
void MainGameState::onUpdate()
{
   spaceship_.Move();
   spaceship_.Edge();
   missile_.move_();
   missile_.destroy();
   if(frame == 10)
   {
      alien1_.move_();
      alien2_.move_();
      alien3_.move_();
      frame = 0;
   }
   frame++;
   alien1_.movement();
   //missile_.GetX();
   //missile_.GetY();
}
void MainGameState::onRender( prg::Canvas& canvas )
{
   spaceship_.Draw(canvas);
   missile_.draw(canvas);
   alien1_.alien1(canvas);
   alien2_.alien2(canvas);
   alien3_.alien3(canvas);
}
bool MainGameState::onKey( const prg::IKeyEvent::KeyEvent& key_event )
{
   if(key_event.key_state==KeyEvent::KB_DOWN)
   {
      switch( key_event.key)
      {
         case 'z': case 'Z':
         {
            spaceship_.SetDirection(0);
         }
         break;
         case 'x': case 'X':
         {
            if (missile_.sizl()<5)
            {
               missile_.pushfront(spaceship_.GetX()+10, 29);
               missile_.SetDirection(0);
            }
            else
            {

            }
         }
         break;
         case 'c': case 'C':
         {
            spaceship_.SetDirection(1);
         }
         break;
         case 'p': case 'P':
         {
            prg::application.setState( "pause_game_state" );
         }
         break;
         case KeyEvent::KB_ESC_KEY:
         {
            prg::application.exit();
            return false;
         }
         break;
       }
   }
   if (key_event.key_state==KeyEvent::KB_UP)
   {
      spaceship_.SetDirection(2);
   }
   return true;
}
