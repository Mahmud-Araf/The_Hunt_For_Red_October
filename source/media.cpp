/*This are the textures that are used in the game*/
/*All the necessary variable used here are stored in global*/

#include"media.hpp"


//texture part
SDL_Texture *mainmenuBG;
SDL_Texture *startgameB1;
SDL_Texture *startgameB2;
SDL_Texture *exitB1;
SDL_Texture *exitB2;
SDL_Texture *gameBG1;
SDL_Texture *gameBG2;
SDL_Texture *player_subObj;
SDL_Texture *player_torpObj;
SDL_Texture *player_missile1Obj;
SDL_Texture *player_missile2Obj;
SDL_Texture *enemy_subObj;
SDL_Texture *enemy_torpObj;
SDL_Texture *enemy_shipObj;
SDL_Texture *enemy_mineObj;
SDL_Texture *explo_surfaceObj;
SDL_Texture *explo_waterObj;

//sound part

Mix_Music *gamemusic;
Mix_Chunk *missileL1_chunk;
Mix_Chunk *missileL2_chunk;
Mix_Chunk *torpL_chunk;
Mix_Chunk *explosion_surface_chunk;
Mix_Chunk *explosion_water_chunk;


SDL_Texture* loadTexture(std::string path) 
{
      SDL_Texture* newTexture = NULL;
 
      SDL_Surface* loadedSurface = IMG_Load(path.c_str());

      if (loadedSurface == NULL) 
      {
        cout<<"Surface Load Error: "<<path.c_str()<<endl
        <<IMG_GetError()<<endl;
      } 
      else 
      {
            newTexture = SDL_CreateTextureFromSurface(gameRenderer,loadedSurface);
            SDL_FreeSurface(loadedSurface);
            loadedSurface=NULL;
            if (newTexture == NULL) 
            {
                  cout<<"Texture Load Error: "<<path.c_str()<<endl
                  <<IMG_GetError()<<endl;
            }
      }
      return newTexture;
}

SDL_Texture* loadTexturewithKey(std::string path,int r,int g,int b) 
{
      SDL_Texture* newTexture = NULL;
 
      SDL_Surface* loadedSurface = IMG_Load(path.c_str());

      if (loadedSurface == NULL) 
      {
        cout<<"Surface Load Error: "<<path.c_str()<<endl
        <<IMG_GetError()<<endl;
      } 
      else 
      {     
            SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, r, g, b));
            
            newTexture = SDL_CreateTextureFromSurface(gameRenderer,loadedSurface);
            SDL_FreeSurface(loadedSurface);
            loadedSurface=NULL;
            if (newTexture == NULL) 
            {
                  cout<<"Texture Load Error: "<<path.c_str()<<endl
                  <<IMG_GetError()<<endl;
            }
      }
      return newTexture;
}

bool loadMedia()
{
    bool success=true;

    mainmenuBG=loadTexture("assets/obj & background/mainmenu.png");
    if(mainmenuBG==NULL)
    {
        cout<<"Failed to load mainmenu background"<<endl;
        success=false;
    }

    startgameB1=loadTexture("assets/button/start game1.png");
    if(startgameB1==NULL)
    {
        cout<<"Failed to load startgame button 1 background"<<endl;
        success=false;
    }

    startgameB2=loadTexture("assets/button/start game2.png");
    if(startgameB2==NULL)
    {
        cout<<"Failed to load startgame button 2 background"<<endl;
        success=false;
    }

    exitB1=loadTexture("assets/button/exit1.png");
    if(exitB1==NULL)
    {
        cout<<"Failed to load exit button 1 background"<<endl;
        success=false;
    }

    exitB2=loadTexture("assets/button/exit2.png");
    if(exitB2==NULL)
    {
        cout<<"Failed to load exit button 2 background"<<endl;
        success=false;
    }

    gameBG1=loadTexture("assets/obj & background/background1.png");
    if(gameBG1==NULL)
    {
        cout<<"Failed to load game background"<<endl;
        success=false;
    }

    gameBG2=loadTexture("assets/obj & background/background2.png");
    if(gameBG2==NULL)
    {
        cout<<"Failed to load game background"<<endl;
        success=false;
    }


    player_subObj=loadTexture("assets/obj & background/redoctober.png");
    if(player_subObj==NULL)
    {
        cout<<"Failed to load player submarine"<<endl;
        success=false;
    }


    player_torpObj=loadTexture("assets/obj & background/red_october_torpedo.png");
    if(player_torpObj==NULL)
    {
        cout<<"Failed to load player torpedo"<<endl;
        success=false;
    }
    SDL_SetTextureColorMod(player_torpObj, 200, 255, 255);


    player_missile1Obj=loadTexture("assets/obj & background/missile1.png");
    if(player_missile1Obj==NULL)
    {
        cout<<"Failed to load player missile1"<<endl;
        success=false;
    }


    player_missile2Obj=loadTexture("assets/obj & background/missile2.png");
    if(player_missile2Obj==NULL)
    {
        cout<<"Failed to load player missile2"<<endl;
        success=false;
    }


    enemy_subObj=loadTexture("assets/obj & background/alfaclass.png");
    if(enemy_subObj==NULL)
    {
        cout<<"Failed to load enemy submarine"<<endl;
        success=false;
    }


    enemy_torpObj=loadTexture("assets/obj & background/enemytorpedo.png");
    if(enemy_torpObj==NULL)
    {
        cout<<"Failed to load enemy torpedo"<<endl;
        success=false;
    }


    enemy_shipObj=loadTexturewithKey("assets/obj & background/slava.png",255,255,255);
    if(enemy_shipObj==NULL)
    {
        cout<<"Failed to load enemy ship"<<endl;
        success=false;
    }
    

    enemy_mineObj=loadTexture("assets/obj & background/sea mine.png");
    if(enemy_mineObj==NULL)
    {
        cout<<"Failed to load enemy mine"<<endl;
        success=false;
    }

    
    explo_surfaceObj=loadTexture("assets/obj & background/explosion_sprite.png");
    if(explo_surfaceObj==NULL)
    {
        cout<<"Failed to load explosion1"<<endl;
        success=false;
    }


    explo_waterObj=loadTexture("assets/obj & background/uw_explosion_sprite.png");
    if(explo_waterObj==NULL)
    {
        cout<<"Failed to load explosion2"<<endl;
        success=false;
    }



    gamemusic=Mix_LoadMUS("assets/audio/gmusic.mp3");
    if(gamemusic==NULL)
    {
        cout<<"Failed to load game music"<<endl;
        success=false;
    }
     

    missileL1_chunk=Mix_LoadWAV("assets/audio/missilel1.wav");
    if(missileL1_chunk==NULL)
    {
        cout<<"Failed to load missile launch 1 chunk"<<endl;
        success=false;
    }


    missileL2_chunk=Mix_LoadWAV("assets/audio/missilel2.wav");
    if(missileL2_chunk==NULL)
    {
        cout<<"Failed to load missile launch 2 chunk"<<endl;
        success=false;
    }


    torpL_chunk=Mix_LoadWAV("assets/audio/torpedolaunch.wav");
    if(torpL_chunk==NULL)
    {
        cout<<"Failed to load torpedo launch chunk"<<endl;
        success=false;
    }


    explosion_surface_chunk=Mix_LoadWAV("assets/audio/surface_exp.wav");
    if(explosion_surface_chunk==NULL)
    {
        cout<<"Failed to load explosion1 chunk"<<endl;
        success=false;
    }


    explosion_water_chunk=Mix_LoadWAV("assets/audio/underwater_exp.wav");
    if(explosion_water_chunk==NULL)
    {
        cout<<"Failed to load explosion2 chunk"<<endl;
        success=false;
    }

    return success;

}

void closeMedia()
{
    //free texture
    SDL_DestroyTexture(mainmenuBG);
    mainmenuBG=NULL;
    SDL_DestroyTexture(startgameB1);
    startgameB1=NULL; 
    SDL_DestroyTexture(startgameB2);
    startgameB2=NULL; 
    SDL_DestroyTexture(exitB1);
    exitB1=NULL;
    SDL_DestroyTexture(exitB2);
    exitB2=NULL;
    SDL_DestroyTexture(gameBG1);
    gameBG1=NULL;
    SDL_DestroyTexture(gameBG2);
    gameBG2=NULL;
    SDL_DestroyTexture(player_subObj);
    player_subObj=NULL;
    SDL_DestroyTexture(player_torpObj);
    player_torpObj=NULL;
    SDL_DestroyTexture(player_missile1Obj);
    player_missile1Obj=NULL;
    SDL_DestroyTexture(player_missile2Obj);
    player_missile2Obj=NULL;
    SDL_DestroyTexture(enemy_subObj);
    enemy_subObj=NULL;
    SDL_DestroyTexture(enemy_torpObj);
    enemy_torpObj=NULL;
    SDL_DestroyTexture(enemy_shipObj);
    enemy_shipObj=NULL;
    SDL_DestroyTexture(enemy_mineObj);
    enemy_mineObj=NULL;
    SDL_DestroyTexture(explo_surfaceObj);
    explo_surfaceObj=NULL;
    SDL_DestroyTexture(explo_waterObj);
    explo_waterObj=NULL;
    
    //free sound
    Mix_FreeMusic(gamemusic);
    gamemusic=NULL;
    Mix_FreeChunk(missileL1_chunk);
    missileL1_chunk=NULL;
    Mix_FreeChunk(missileL2_chunk);
    missileL2_chunk=NULL;
    Mix_FreeChunk(torpL_chunk);
    torpL_chunk=NULL;
    Mix_FreeChunk(explosion_surface_chunk);
    explosion_surface_chunk=NULL;
    Mix_FreeChunk(explosion_water_chunk);
    explosion_water_chunk=NULL;
}




