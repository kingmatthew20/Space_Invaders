#include "../inc/PauseGameState.hpp"
PauseGameState::~PauseGameState()
{

}

bool PauseGameState::onCreate()
{
   return true;
}

bool PauseGameState::onDestroy()
{
    return true;
}

void PauseGameState::onEntry()
{
    prg::application.addKeyListener( *this );
}

void PauseGameState::onExit()
{
    prg::application.removeKeyListener( *this );
}

void PauseGameState::onUpdate()
{

}

void PauseGameState::onRender( prg::Canvas& canvas )
{
   const std::string text = "PAUSED R to resume and ESC to quit.";
    prg::uint text_dims[2];
    prg::Font::LARGE.computePrintDimensions(text_dims,text);
    prg::Font::LARGE.print(canvas,
                prg::application.getScreenWidth() / 2-text_dims[0]/2,
                prg::application.getScreenHeight() / 2-text_dims[1]/2,
                prg::Colour::RED,
                text);
}
bool PauseGameState::onKey( const prg::IKeyEvent::KeyEvent& key_event )
{
     if (key_event.key_state==KeyEvent::KB_DOWN) {
        switch( key_event.key)
        {
        case 'r': case 'R':
            {
               prg::application.setState("main_game_state");
            }
            break;
        case KeyEvent::KB_ESC_KEY:
                prg::application.exit();
            break;
        }
     }
    return true;
}
