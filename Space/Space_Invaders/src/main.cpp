#include <stdexcept>
#include <iostream>

#include <prg_interactive.hpp>
#include "../inc/main_game_state.hpp"
#include "../inc/PauseGameState.hpp"

int main()
{

   try
   {
      MainGameState main_game_state;
      PauseGameState pause_game_state;
      prg::application.addState( "main_game_state", main_game_state);
      prg::application.addState("pause_game_state", pause_game_state);
      prg::application.run( 800, 400, "Matthew King-Mason", "N3067685" );
   }
    catch( std::exception& error ) {
        prg::Log::Message error_message( prg::Log::Message::LT_Error );

        error_message   << "The program has terminated for the following reason: "
                        << error.what();

        prg::logger.add( error_message );
    }

    return 0;
}
