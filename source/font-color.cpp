#include"font-color.hpp"
#include"global.hpp"

TTF_Font *Bold1F;
TTF_Font *Bold2F;
TTF_Font *Bold3F;
TTF_Font *Bold4F;
TTF_Font *Bold5F;
TTF_Font *DigitalF;

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
    Bold1F=TTF_OpenFont("ttf_fonts/ChunkFive-Regular.otf",50);
    if(Bold1F==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    Bold2F=TTF_OpenFont("ttf_fonts/hemi head bd it.ttf",50);
    if(Bold2F==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    Bold3F=TTF_OpenFont("ttf_fonts/OpenSans-ExtraBold.ttf",50);
    if(Bold3F==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    Bold4F=TTF_OpenFont("ttf_fonts/SourceSansPro-BlackIt.otf",50);
    if(Bold4F==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    Bold5F=TTF_OpenFont("ttf_fonts/X.Template-font-stencil.ttf",50);
    if(Bold5F==NULL)
    {
        cout<<"TTF Error: "<<TTF_GetError()<<endl;
    }

    DigitalF=TTF_OpenFont("ttf_fonts/digital-7.ttf",50);
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
    TTF_CloseFont(Bold4F);
    Bold4F=NULL;
    TTF_CloseFont(Bold5F);
    Bold5F=NULL;
    TTF_CloseFont(DigitalF);
    DigitalF=NULL;

}