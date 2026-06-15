#include "SpriteSheet.h"

Sprite::Sprite()
{
	image=NULL;
}
Sprite::~Sprite()
{
	al_destroy_bitmap(image);
}
void Sprite::InitSprites(int width, int height)
{
	x = 80;
	y = 80;


	maxFrame = 3;
	curFrame = 0;
	frameCount = 0;
	frameDelay = 6;
	frameWidth = 32;
	frameHeight = 32;
	animationColumns = 4;
	animationDirection = 1;
	

	image = al_load_bitmap("hero1.bmp");
	al_convert_mask_to_alpha(image, al_map_rgb(255,255,255));
}

void Sprite::UpdateSprites(int moveX, int moveY, int dir)
{
    int oldx = x;
    int oldy = y;

    animationDirection = dir;

    x += moveX;
    y += moveY;

    // Check all four corners of the sprite.
    if (collided(x, y) ||
        collided(x + frameWidth - 1, y) ||
        collided(x, y + frameHeight - 1) ||
        collided(x + frameWidth - 1, y + frameHeight - 1))
    {
        x = oldx;
        y = oldy;
    }

    if (++frameCount > frameDelay)
    {
        frameCount = 0;

        if (++curFrame > maxFrame)
            curFrame = 0;
    }
}
void Sprite::StandStill()
{
	curFrame = 0;
	animationDirection = 1;
}
bool Sprite::CollisionEndBlock()
{
	if (endValue(x + frameWidth / 2, y + frameHeight / 2))
		return true;
	else
		return false;
}

void Sprite::DrawSprites(int xoffset, int yoffset)
{
	int fx = (curFrame % animationColumns) * frameWidth;
	int fy = (curFrame / animationColumns) * frameHeight;

	int flags = 0;

	// Flip the ant when moving left.
	if (animationDirection == 2)
	{
		flags = ALLEGRO_FLIP_HORIZONTAL;
	}

	al_draw_bitmap_region(
		image,
		fx,
		fy,
		frameWidth,
		frameHeight,
		x - xoffset,
		y - yoffset,
		flags
	);
}




void Sprite::ResetPosition(float startX, float startY)
{
    x = startX;
    y = startY;
    curFrame = 0;
}