#include "Tile.h"
#include "Image.h"


Tile::Tile()
{
}


Tile::~Tile()
{
}

void Tile::init(HDC _hdc)
{
	Object::m_image->init(_hdc, "./Resource/block_0.bmp")
}

void Tile::update()
{
}

void Tile::render(HDC _hdc)
{

}
