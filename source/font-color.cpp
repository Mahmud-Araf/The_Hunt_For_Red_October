#include"font-color.hpp"
#include"global.hpp"

TTF_Font *Bold1;
TTF_Font *Bold2;
TTF_Font *Bold3;
TTF_Font *Norm1;
TTF_Font *Digital;

SDL_Color white={255,255,255};
SDL_Color black={0,0,0};
SDL_Color red={255,0,0};



void loadTextSurface(std::string path,TTF_Font *font,SDL_Color color,SDL_Rect area)
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

void font_init()
{
    Bold1=TTF_OpenFont("ttf_fonts/ChunkFive-Regular.otf",50);
    if(Bold1==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    Bold2=TTF_OpenFont("ttf_fonts/OpenSans-ExtraBold.ttf",50);
    if(Bold2==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    Bold3=TTF_OpenFont("ttf_fonts/X.Template-font-stencil.ttf",50);
    if(Bold3==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    Norm1=TTF_OpenFont("ttf_fonts/SourceSansPro-ExtraLight.otf",50);
    if(Norm1==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    Digital=TTF_OpenFont("ttf_fonts/digital-7.ttf",50);
    if(Digital==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }
}


void closeFont()
{
    
    TTF_CloseFont(Bold1);
    Bold1=NULL;
    TTF_CloseFont(Bold2);
    Bold2=NULL;
    TTF_CloseFont(Bold3);
    Bold3=NULL;
    TTF_CloseFont(Norm1);
    Norm1=NULL;
    TTF_CloseFont(Digital);
    Digital=NULL;

}