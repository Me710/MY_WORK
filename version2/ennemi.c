#include "ennemi.h"


void initEnnemi(ennemi *e)
{
	int j;
	char ennemiL[30];
	char ennemiR[30];

	e->dir = 0;
	e->speed = 7;
	e->num = 0;

    e->image = IMG_Load("resources/image/ennemi.png");

    e->pos.x = 0;
    e->pos.y = 200;
    e->possprite.x = 0;
    e->possprite.y = 0;
    e->possprite.w = 198;
    e->possprite.h = 200;
    e->life = 100;
}

void afficherEnnemi(ennemi e, SDL_Surface *screen)
{
	SDL_BlitSurface(e.image,&e.possprite,screen,&e.pos);
}

void deplacerEnnemi(ennemi *e)
{
	int limDroite = 600;
	int limGauche = 0;

	if(e->dir == 0)
	{
		e->pos.x += e->speed;
	}
	if(e->dir == 1)
	{
		e->pos.x -= e->speed;
	}
	if(e->pos.x > limDroite)
	{
		e->dir = 1;
	}
	if(e->pos.x < limGauche)
	{
		e->dir = 0;
	}
    
}

void animerEnnemi(ennemi *e)
{
	int largeursprite = 1188;
    if(e->possprite.x == (largeursprite - e->possprite.w))
    {
    	e->possprite.x = 0;
    }
    else
    {
    	e->possprite.x += e->possprite.w;
    }

    e->possprite.y = (e->dir)*(e->possprite.h);//la ligne correspondant a la diection
}

int collisionBb(personne p, ennemi e)
{
    if((p.pos.x+p.pos.w < e.pos.x) || (p.pos.x > e.pos.x < e.pos.w) || (p.pos.y+p.pos.h < e.pos.y) || (p.pos.y > e.pos.y+e.pos.h))
	{
		return 0;
	}  
	else
	{
		return 1;
	}

}

int collisionBB(SDL_Rect posp, SDL_Rect pose)
{
	if((posp.x+posp.w < pose.x) || (posp.x > pose.x < pose.w) || (posp.y+posp.h < pose.y) || (posp.y > pose.y+pose.h))
	{
		return 0;
	}  
	else
	{
		return 1;
	}
}