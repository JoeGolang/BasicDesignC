#include "SDL/SDL.h"
#include <string>
using namespace std;

SDL_Surface *load_image( string filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
void apply_cropped_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );

SDL_Surface *load_image( string filename ) 
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;
    
    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    
    //Load the image
    loadedImage = SDL_LoadBMP( filename.c_str() );
    
    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
    
    //Return the optimized image
    return optimizedImage;
}


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
    
    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

void apply_cropped_surface( int posX, int posY, int cropX, int cropY, SDL_Surface* source, SDL_Surface* destination ){
     SDL_Rect crop, location;
     
     location.x = posX; location.y = posY;
     
     crop.x = cropX; crop.y = cropY;
     crop.h = 32; crop.w = 32;
     
     SDL_BlitSurface( source, &crop, destination, &location );  
}
