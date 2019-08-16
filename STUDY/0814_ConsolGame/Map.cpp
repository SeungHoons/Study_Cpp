#include "Map.h"



Map::Map()
{
}


Map::~Map()
{
}

void Map::init(int _height, int _width)
{
	maxHeight = _height;
	maxWidth = _width;

	block = new BLOCK*[_height];
	for (int i = 0; i < _height; i++)
	{
		block[i] = new BLOCK[_width];
	}

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			if (i == 0 || i == _height - 1)
			{
				block[i][j] = WALL;
			}
			else if (j == 0 || j == _width - 1)
			{
				block[i][j] = WALL;
			}
			else
			{
				block[i][j] = EMPTY;
			}
			
		}
	}
}

void Map::setBlock(int _height, int _width, int _block)
{
	block[_height][_width] = (BLOCK)_block;
}

void Map::printMap()
{
	for (int i = 0; i < maxHeight; i++)
	{
		for (int j = 0; j < maxWidth; j++)
		{
			if (mapPlayer->height == i && mapPlayer->width == j)
			{
				cout << "¡Ý";
			}
			else
			{

				switch (block[i][j])
				{
				case EMPTY:
					cout << "  ";
					break;
				case WALL:
					cout << "¡á";
					break;
				case PLAYER:
					cout << "¢Â";
					break;
				case ITEM:
					cout << "¡Ù";
					break;
				case ENEMY:
					cout << "¢Î";
					break;
				default:
					break;
				}
			}
		}
		cout << "\n";
	}

}
