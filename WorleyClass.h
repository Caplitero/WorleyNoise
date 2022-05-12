#pragma once

#include <iostream>
class Worley
{
	struct Lpoint
	{
		int x=0;
		int y=0;
	};

	Lpoint* Points;
	int distance(int x1, int y1, int x2, int y2) { return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); }



public :
	int* Output;
	unsigned int _width;
	unsigned int _height;
	unsigned int nr;
	
	void generateMap()
	{
		for (int i = 0; i < nr; i++)
		{
			Points[i].x = std::rand() % _width;
			Points[i].y = std::rand() % _height;
		}

		for (int y = 0; y < _height; y++)
			for (int x = 0; x < _width; x++)
			{
				unsigned int index = y * _width + x;
				int Dis_min = distance(x, y, Points[0].x, Points[0].y);
				for (int i = 1; i < nr; i++)
				{
					int newdis = distance(x, y, Points[i].x, Points[i].y);
					if (newdis < Dis_min)Dis_min = newdis;
				}

				Output[index] = Dis_min;


			}


	}

	Worley(unsigned int width, unsigned int height, unsigned int pointNr)
	{
		Points = new Lpoint[pointNr];
		Output = new int[width * height];
		_width = width;
		_height = height;
		nr = pointNr;
		
	}



};