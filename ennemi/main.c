#include "ennemi.h"

int main(char argc, char argv[])
{
	ennemi e;
	int continuer = 1,i,j;
	int largeur_fenetre = 1280;
	int hauteur_fenetre = 640;
	SDL_Surface *screen = NULL;
	SDL_Surface *background = NULL;
	SDL_Rect pos;
	SDL_Event event;
	int volum = 50;

	personne p;
	int collision = 0;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	
	screen = SDL_SetVideoMode(largeur_fenetre, hauteur_fenetre, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("ENNEMI", NULL);

	background = IMG_Load("resources/image/background.png");
	pos.x = 0;
	pos.y = 0;

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }

    Mix_Chunk  *music1;
    Mix_AllocateChannels(2);
    Mix_Music *music;
    music1 = Mix_LoadWAV("resources/sound/ClicDeSouris.wav");
    music= Mix_LoadMUS("resources/sound/music.mp3");
    Mix_VolumeMusic(volum);
    Mix_PlayMusic(music,-1);

	initEnnemi(&e);
	initPerso(&p);
	SDL_EnableKeyRepeat(10,10);

	while(continuer)
	{ 
		//collision = collisionBb(p,e);
		if(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
				continuer = 0;
				break;
				case SDL_KEYDOWN:
				    p.key=1;
				    switch (event.key.keysym.sym) 
                    {
                    	case SDLK_q:
                    	continuer = 0;
                    	break;
                    	case SDLK_RIGHT:
                    	p.dir=0;
                    	p.pos.x+=p.speed;
                    	break;
                    	case SDLK_LEFT:
                    	p.dir=1;
                    	p.pos.x-=p.speed;
                    	break;
                    }
				break;
				default:
				p.key=0;
				p.num=0;
				break;
			}
		}

		/*if(collision == 1)
		{
			e.num = 3;
			Mix_PlayChannel(-1, music1, 0);
		}*/
        
        updateEnnemi(&e,p);
       //deplacer et animer l'ennemi
        //deplacerPerso(&p);
        animerPerso(&p);
		deplacerIA(&e);
		//deplacerEnnemi(&e);
		//animerEnnemi(&e);
		SDL_Delay(40);

       //afficher
		SDL_BlitSurface(background,NULL,screen,&pos);
		afficherEnnemi(e,screen);
		afficherPerso(p,screen);
		
		SDL_Flip(screen);  
	}

	
	SDL_FreeSurface(background);
	SDL_FreeSurface(screen);
	Mix_FreeChunk(music1);
	Mix_FreeMusic(music);
	libererennemi(e);
	libererperso(p);

    SDL_Quit();
	return 0;
}
