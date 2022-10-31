/*This are the textures that are used in the game*/
/*All the necessary variable used here are stored in global*/

#include"media.hpp"


//texture part
SDL_Texture *introBG;
SDL_Texture *gameBG;
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
Mix_Chunk *missileL1;
Mix_Chunk *missileL2;
Mix_Chunk *torpL;
Mix_Chunk *E_surface;
Mix_Chunk *E_water;


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

bool loadMedia()
{
    bool success=true;

    introBG=loadTexture("assets/intro.png");
    if(introBG==NULL)
    {
        cout<<"Failed to load intro background"<<endl;
        success=false;
    }
    gameBG=loadTexture("assets/background.png");
    if(gameBG==NULL)
    {
        cout<<"Failed to load game background"<<endl;
        success=false;
    }
    player_subObj=loadTexture("assets/redoctober.png");
    if(player_subObj==NULL)
    {
        cout<<"Failed to load player submarine"<<endl;
        success=false;
    }
    player_torpObj=loadTexture("assets/red_october_torpedo.png");
    if(player_torpObj==NULL)
    {
        cout<<"Failed to load player torpedo"<<endl;
        success=false;
    }
    player_missile1Obj=loadTexture("assets/missile1.png");
    if(player_missile1Obj==NULL)
    {
        cout<<"Failed to load player missile1"<<endl;
        success=false;
    }
    player_missile2Obj=loadTexture("assets/missile2.png");
    if(player_missile2Obj==NULL)
    {
        cout<<"Failed to load player missile2"<<endl;
        success=false;
    }
    enemy_subObj=loadTexture("assets/alfaclass.png");
    if(enemy_subObj==NULL)
    {
        cout<<"Failed to load enemy submarine"<<endl;
        success=false;
    }
    enemy_torpObj=loadTexture("assets/enemytorpedo.png");
    if(enemy_torpObj==NULL)
    {
        cout<<"Failed to load enemy torpedo"<<endl;
        success=false;
    }
    enemy_shipObj=loadTexture("assets/slava.png");
    if(enemy_shipObj==NULL)
    {
        cout<<"Failed to load enemy ship"<<endl;
        success=false;
    }
    enemy_mineObj=loadTexture("assets/sea mine.png");
    if(enemy_mineObj==NULL)
    {
        cout<<"Failed to load enemy mine"<<endl;
        success=false;
    }
    explo_surfaceObj=loadTexture("assets/explosion.png");
    if(explo_surfaceObj==NULL)
    {
        cout<<"Failed to load explosion1"<<endl;
        success=false;
    }
    explo_waterObj=loadTexture("assets/underwaterexplosion.png");
    if(explo_waterObj==NULL)
    {
        cout<<"Failed to load explosion2"<<endl;
        success=false;
    }



    gamemusic=Mix_LoadMUS("assets/gmusic.mp3");
    if(gamemusic==NULL)
    {
        cout<<"Failed to load game music"<<endl;
        success=false;
    }

    missileL1=Mix_LoadWAV("assets/missilel1.wav");
    if(missileL1==NULL)
    {
        cout<<"Failed to load missile launch 1 chunk"<<endl;
        success=false;
    }
    missileL2=Mix_LoadWAV("assets/missilel2.wav");
    if(missileL2==NULL)
    {
        cout<<"Failed to load missile launch 2 chunk"<<endl;
        success=false;
    }
    torpL=Mix_LoadWAV("assets/torpedolaunch.wav");
    if(torpL==NULL)
    {
        cout<<"Failed to load torpedo launch chunk"<<endl;
        success=false;
    }

    E_surface=Mix_LoadWAV("assets/surface_exp.wav");
    if(E_surface==NULL)
    {
        cout<<"Failed to load explosion1 chunk"<<endl;
        success=false;
    }
    E_water=Mix_LoadWAV("assets/underwater_exp.wav");
    if(E_water==NULL)
    {
        cout<<"Failed to load explosion2 chunk"<<endl;
        success=false;
    }

    return success;

}

void closeMedia()
{
    //free texture
    SDL_DestroyTexture(introBG);
    introBG=NULL;
    SDL_DestroyTexture(gameBG);
    gameBG=NULL;
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
    Mix_FreeChunk(missileL1);
    missileL1=NULL;
    Mix_FreeChunk(missileL2);
    missileL2=NULL;
    Mix_FreeChunk(torpL);
    torpL=NULL;
    Mix_FreeChunk(E_surface);
    E_surface=NULL;
    Mix_FreeChunk(E_water);
    E_water=NULL;
}




