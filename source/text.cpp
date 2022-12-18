#include"text.hpp"
#include"global.hpp"

TTF_Font *Bold1F;
TTF_Font *Bold2F;
TTF_Font *Bold3F;
TTF_Font *DigitalF;

SDL_Color white={255,255,255};
SDL_Color black={0,0,0};
SDL_Color red={255,0,0};


void loadTextSurface(std::string path,TTF_Font *font,SDL_Color color,int x,int y)
{
    SDL_Texture *newTexture=NULL;

    SDL_Rect area; 
    int w,h;

    SDL_Surface *loadedSurface=TTF_RenderText_Solid(font,path.c_str(),color);

    if(!loadedSurface)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    newTexture=SDL_CreateTextureFromSurface(gameRenderer,loadedSurface);

    w=loadedSurface->w;
    h=loadedSurface->h;

    SDL_FreeSurface(loadedSurface);
    
    area={x,y,w,h};

    SDL_RenderCopy(gameRenderer,newTexture,0,&area);
}


void loadTextSurfacewithRect(std::string path,TTF_Font *font,SDL_Color color, SDL_Rect area)
{
    SDL_Texture *newTexture=NULL;

    SDL_Surface *loadedSurface=TTF_RenderText_Solid(font,path.c_str(),color);

    if(!loadedSurface)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    newTexture=SDL_CreateTextureFromSurface(gameRenderer,loadedSurface);

    SDL_FreeSurface(loadedSurface);
    
    SDL_RenderCopy(gameRenderer,newTexture,0,&area);
}

void loadTextSurfacewithBG(std::string path,TTF_Font *font,SDL_Color color,int x,int y)
{
    SDL_Texture *newTexture=NULL;

    SDL_Rect area,bg; int w,h;

    SDL_Surface *loadedSurface=TTF_RenderText_Solid(font,path.c_str(),color);

    if(!loadedSurface)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    newTexture=SDL_CreateTextureFromSurface(gameRenderer,loadedSurface);

    w=loadedSurface->w;
    h=loadedSurface->h;

    SDL_FreeSurface(loadedSurface);
    
    area={x-w/2,y,w,h};

    bg=area;

    SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);

    SDL_RenderFillRect(gameRenderer,&bg);

    SDL_RenderCopy(gameRenderer,newTexture,0,&area);
}

void font_init()
{
    Bold1F=TTF_OpenFont("assets/ttf_fonts/ChunkFive-Regular.otf",50);
    if(Bold1F==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    Bold2F=TTF_OpenFont("assets/ttf_fonts/hemi head bd it.ttf",50);
    if(Bold2F==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    Bold3F=TTF_OpenFont("assets/ttf_fonts/SourceSansPro-BlackIt.otf",50);
    if(Bold3F==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    DigitalF=TTF_OpenFont("assets/ttf_fonts/digital-7.ttf",100);
    if(DigitalF==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }
}


void closeFont()
{
    
    TTF_CloseFont(Bold1F);
    Bold1F=NULL;
    TTF_CloseFont(Bold2F);
    Bold2F=NULL;
    TTF_CloseFont(Bold3F);
    Bold3F=NULL;
    TTF_CloseFont(DigitalF);
    DigitalF=NULL;

}