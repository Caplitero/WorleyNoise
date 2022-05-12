#pragma once

#include <SFML/Graphics.hpp>
#include "WorleyClass.h"
class Window {

	sf::RenderWindow* window = nullptr;
	sf::VertexArray buffer;
	Worley *map;

	void redo()
	{
		map->generateMap();
		unsigned int width =  window->getSize().x;
		unsigned int height = window->getSize().y;
		
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				unsigned int index = y * width + x;
				buffer[index].position = sf::Vector2f(x, y);
				
				buffer[index].color = sf::Color(255, 255, 255, map->Output[index]);
			}

		}






	}

	void update()
	{
		window->clear();
		window->draw(buffer);
		window->display();
	}

	void close(){

		delete window;
	}

	void loop()
	{
		sf::Event event;
		while (window->isOpen())
		{
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window->close();

				}

				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Q)
					{
						
						redo();
					}
				}


			}
			update();


		}
		close();


	}


public :

	
	void start(unsigned int Width, unsigned int Height, const char* Title)
	{

		window = new sf::RenderWindow(sf::VideoMode(Width, Height), Title);
		buffer.setPrimitiveType(sf::Points);
		buffer.resize(Width * Height);
		map = new Worley(Width, Height, 50);
		loop();

	}

};