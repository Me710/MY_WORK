#include "ennemi.h"


void initEnnemi(ennemi *e)
{
	int j;
	char ennemiL[30];
	char ennemiR[30];

	e->dir = 0;
	e->speed = 7;
	e->num = 0;

	for(j=0 ; j<5 ;j++)
    { 
    	sprintf(ennemiR,"resources/image/R%d.png",j);
    	e->image[0][j] = IMG_Load(ennemiR);
    	sprintf(ennemiL,"resources/image/L%d.png",j);
    	e->image[1][j] = IMG_Load(ennemiL);
    }

    e->pos.x = 0;
    e->pos.y = 200;
    e->life = 100;
}

void afficherEnnemi(ennemi e, SDL_Surface *screen)
{
	SDL_BlitSurface(e.image[e.dir][e.num],NULL,screen,&e.pos);
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
	if(e->num == 4)
	{
		e->num = 0;
	}
	else
	{
		e->num++;
	}
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