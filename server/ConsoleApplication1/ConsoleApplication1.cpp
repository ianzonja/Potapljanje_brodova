// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;


int main()
{
	int primljena_poruka[13];
	int pozicijax, pozicijay;
	int brojac = 0;
	int q = 0;
	char brod;
	int colbrod[5];
	bool boolbrod1 = true;
	bool boolbrod2 = true;
	bool boolbrod3 = true;
	bool boolbrod4 = true;
	bool boolbrod5 = true;
	bool start = false;
	bool igracigra = true;
	sf::Mouse mis;
	bool igrac_klik = false;
	int k = 0;
	int igracturn = 1;

	
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "potapljanje brodova - server");


	//START BOTUN
	sf::RectangleShape startbutton;
	startbutton.setSize(sf::Vector2f(100.f, 50.f));
	startbutton.setPosition(650.f, 30.f);
	startbutton.setFillColor(sf::Color::Red);
	startbutton.setOutlineColor(sf::Color::Black);
	startbutton.setOutlineThickness(2);

	//SHAPE KOJI CE PRATITI MISA
	sf::RectangleShape rekt_mis;
	rekt_mis.setSize(sf::Vector2f(1.f, 1.f));

	int pomocni = 0;
	int novipomocni = 0;

	//muzika
	sf::SoundBuffer saundbafer;
	sf::Sound saund;
	if (!saundbafer.loadFromFile("pisma.wav")) {
		return -1;
	}
	saund.setBuffer(saundbafer);

	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket socket;
	char buffer[8888];
	char novibuffer[2];
	size_t received;
	string text;
	char connectionType, mode;

	sf::TcpListener listener;
	listener.listen(8888);
	listener.accept(socket);



	//POLJE VODA
	sf::RectangleShape poljevoda[120];
	for (int i = 0; i < 120; i++) {
		poljevoda[i].setSize(sf::Vector2f(35.f, 35.f));

		if (i >= 0 && i < 10) {
			poljevoda[i].setPosition(sf::Vector2f(0.f + (pomocni*35), (150.f)));
			pomocni++;
		}
		if (i >= 10 && i < 20) {
			if (i == 10)
			{
				pomocni = 0;
			}
			poljevoda[i].setPosition(sf::Vector2f(0.f + (pomocni * 35), 185.f));
			pomocni++;
		}
		if (i >= 20 && i < 30) {
			if (i == 20)
			{
				pomocni = 0;
			}
			poljevoda[i].setPosition(sf::Vector2f(0.f + (pomocni * 35), 220.f));
			pomocni++;
		}
		if (i >= 30 && i < 40) {
			if (i == 30)
			{
				pomocni = 0;
			}
			poljevoda[i].setPosition(sf::Vector2f(0.f + (pomocni * 35), 255.f));
			pomocni++;
		}
		if (i >= 40 && i < 50) {
			if (i == 40)
			{
				pomocni = 0;
			}
			poljevoda[i].setPosition(sf::Vector2f(0.f + (pomocni * 35), 290.f));
			pomocni++;
		}
		if (i >= 50 && i < 60) {
			if (i == 50)
			{
				pomocni = 0;
			}
			poljevoda[i].setPosition(sf::Vector2f(0.f + (pomocni * 35), 325.f));
			pomocni++;
		}
		if (i >= 60 && i < 70) {
			if (i == 60)
			{
				pomocni = 0;
			}
			poljevoda[i].setPosition(sf::Vector2f(0.f + (pomocni * 35), 360.f));
			pomocni++;
		}
		if (i >= 70 && i < 80) {
			if (i == 70)
			{
				pomocni = 0;
			}
			poljevoda[i].setPosition(sf::Vector2f(0.f + (pomocni * 35), 395.f));
			pomocni++;
		}
		if (i >= 80 && i < 90) {
			if (i == 80)
			{
				pomocni = 0;
			}
			poljevoda[i].setPosition(sf::Vector2f(0.f + (pomocni * 35), 430.f));
			pomocni++;
		}

		if (i >= 90 && i < 100) {
			if (i == 90)
			{
				pomocni = 0;
			}
			poljevoda[i].setPosition(sf::Vector2f(0.f + (pomocni * 35), 465.f));
			pomocni++;
		}

		if (i >= 100 && i < 110) {
			if (i == 100)
			{
				pomocni = 0;
			}
			poljevoda[i].setPosition(sf::Vector2f(0.f + (pomocni * 35), 500.f));
			pomocni++;
		}

		if (i >= 110 && i < 120) {
			if (i == 110)
			{
				pomocni = 0;
			}
			poljevoda[i].setPosition(sf::Vector2f(0.f + (pomocni * 35), 535.f));
			pomocni++;
		}


		poljevoda[i].setOutlineColor(sf::Color::Black);
		poljevoda[i].setOutlineThickness(1);
		poljevoda[i].setFillColor(sf::Color::Transparent);
	}

	//POLJE RADAR
	sf::RectangleShape poljevoda1[120];
	for (int i = 0; i < 120; i++) {
		poljevoda1[i].setSize(sf::Vector2f(35.f, 35.f));

		if (i >= 0 && i < 10) {
			poljevoda1[i].setPosition(sf::Vector2f(450.f + (novipomocni * 35), (150.f)));
			novipomocni++;
		}
		if (i >= 10 && i < 20) {
			if (i == 10)
			{
				novipomocni = 0;
			}
			poljevoda1[i].setPosition(sf::Vector2f(450.f + (novipomocni * 35), 185.f));
			novipomocni++;
		}
		if (i >= 20 && i < 30) {
			if (i == 20)
			{
				novipomocni = 0;
			}
			poljevoda1[i].setPosition(sf::Vector2f(450.f + (novipomocni * 35), 220.f));
			novipomocni++;
		}
		if (i >= 30 && i < 40) {
			if (i == 30)
			{
				novipomocni = 0;
			}
			poljevoda1[i].setPosition(sf::Vector2f(450.f + (novipomocni * 35), 255.f));
			novipomocni++;
		}
		if (i >= 40 && i < 50) {
			if (i == 40)
			{
				novipomocni = 0;
			}
			poljevoda1[i].setPosition(sf::Vector2f(450.f + (novipomocni * 35), 290.f));
			novipomocni++;
		}
		if (i >= 50 && i < 60) {
			if (i == 50)
			{
				novipomocni = 0;
			}
			poljevoda1[i].setPosition(sf::Vector2f(450.f + (novipomocni * 35), 325.f));
			novipomocni++;
		}
		if (i >= 60 && i < 70) {
			if (i == 60)
			{
				novipomocni = 0;
			}
			poljevoda1[i].setPosition(sf::Vector2f(450.f + (novipomocni * 35), 360.f));
			novipomocni++;
		}
		if (i >= 70 && i < 80) {
			if (i == 70)
			{
				novipomocni = 0;
			}
			poljevoda1[i].setPosition(sf::Vector2f(450.f + (novipomocni * 35), 395.f));
			novipomocni++;
		}
		if (i >= 80 && i < 90) {
			if (i == 80)
			{
				novipomocni = 0;
			}
			poljevoda1[i].setPosition(sf::Vector2f(450.f + (novipomocni * 35), 430.f));
			novipomocni++;
		}

		if (i >= 90 && i < 100) {
			if (i == 90)
			{
				novipomocni = 0;
			}
			poljevoda1[i].setPosition(sf::Vector2f(450.f + (novipomocni * 35), 465.f));
			novipomocni++;
		}

		if (i >= 100 && i < 110) {
			if (i == 100)
			{
				novipomocni = 0;
			}
			poljevoda1[i].setPosition(sf::Vector2f(450.f + (novipomocni * 35), 500.f));
			novipomocni++;
		}

		if (i >= 110 && i < 120) {
			if (i == 110)
			{
				novipomocni = 0;
			}
			poljevoda1[i].setPosition(sf::Vector2f(450.f + (novipomocni * 35), 535.f));
			novipomocni++;
		}


		poljevoda1[i].setOutlineColor(sf::Color::Black);
		poljevoda1[i].setOutlineThickness(1);
		poljevoda1[i].setFillColor(sf::Color::Transparent);
	}

	sf::Texture radar;
	if (!(radar.loadFromFile("radar.png")))
	{
		return -1;
	}
	sf::Sprite sprite;
	sprite.setTexture(radar);
	sprite.setPosition(450.f, 150.f);
	
	sf::Texture voda;
	if(!(voda.loadFromFile("voda.png")))
	{
		return -1;
	}
	sf::Sprite spvoda;
	spvoda.setTexture(voda);
	spvoda.setPosition(0.f, 150.f);

	sf::Texture pozadina;
	if(!(pozadina.loadFromFile("pozadina.png")))
	{
		return -1;
	}
	sf::Sprite sppozadina;
	sppozadina.setTexture(pozadina);

	


	sf::Texture brod1;
	if (!(brod1.loadFromFile("ship1.png")))
	{
		return -1;
	}
	sf::Sprite spbrod1;
	spbrod1.setTexture(brod1);
	spbrod1.setPosition(0.f, 30.f);

	sf::Texture brod2;
	if (!(brod2.loadFromFile("ship2.png")))
	{
		return -1;
	}
	sf::Sprite spbrod2;
	spbrod2.setTexture(brod2);
	spbrod2.setPosition(35.f, 30.f);

	sf::Texture brod3;
	if (!(brod3.loadFromFile("ship3.png")))
	{
		return -1;
	}
	sf::Sprite spbrod3;
	spbrod3.setTexture(brod3);
	spbrod3.setPosition(70.f, 30.f);

	sf::Texture brod4;
	if (!(brod4.loadFromFile("ship4.png")))
	{
		return -1;
	}
	sf::Sprite spbrod4;
	spbrod4.setTexture(brod4);
	spbrod4.setPosition(105.f, 30.f);

	sf::Texture brod5;
	if (!(brod5.loadFromFile("ship5.png")))
	{
		return -1;
	}
	sf::Sprite spbrod5;
	spbrod5.setTexture(brod5);
	spbrod5.setPosition(140.f, 30.f);

	
		sf::Texture botbrod1;
		if (!(botbrod1.loadFromFile("ship1.png")))
		{
			return -1;
		}
		sf::Sprite botspbrod1;
		botspbrod1.setTexture(botbrod1);

		sf::Texture botbrod2;
		if (!(botbrod2.loadFromFile("ship2.png")))
		{
			return -1;
		}
		sf::Sprite botspbrod2;
		botspbrod2.setTexture(botbrod2);

		sf::Texture botbrod3;
		if (!(botbrod3.loadFromFile("ship3.png")))
		{
			return -1;
		}
		sf::Sprite botspbrod3;
		botspbrod3.setTexture(botbrod3);

		sf::Texture botbrod4;
		if (!(botbrod4.loadFromFile("ship4.png")))
		{
			return -1;
		}
		sf::Sprite botspbrod4;
		botspbrod4.setTexture(botbrod4);

		sf::Texture botbrod5;
		if (!(botbrod5.loadFromFile("ship5.png")))
		{
			return -1;
		}
		sf::Sprite botspbrod5;
		botspbrod5.setTexture(botbrod5);


	// draw it
	// run the main loop
	rand();

	saund.play();
	while (window.isOpen())
	{
		novibuffer[0] = ' ';
		novibuffer[1] = ' ';
		
			primljena_poruka[0] = (buffer[0] - 48) * 100 + (buffer[1] - 48) * 10 + buffer[2] - 48;
			primljena_poruka[1] = (buffer[3] - 48) * 100 + (buffer[4] - 48) * 10 + buffer[5] - 48;
			primljena_poruka[2] = (buffer[6] - 48) * 100 + (buffer[7] - 48) * 10 + buffer[8] - 48;
			primljena_poruka[3] = (buffer[9] - 48) * 100 + (buffer[10] - 48) * 10 + buffer[11] - 48;
			primljena_poruka[4] = (buffer[12] - 48) * 100 + (buffer[13] - 48) * 10 + buffer[14] - 48;
			primljena_poruka[5] = (buffer[15] - 48) * 100 + (buffer[16] - 48) * 10 + buffer[17] - 48;
			primljena_poruka[6] = (buffer[18] - 48) * 100 + (buffer[19] - 48) * 10 + buffer[20] - 48;
			primljena_poruka[7] = (buffer[21] - 48) * 100 + (buffer[22] - 48) * 10 + buffer[23] - 48;
			primljena_poruka[8] = (buffer[24] - 48) * 100 + (buffer[25] - 48) * 10 + buffer[26] - 48;
			primljena_poruka[9] = (buffer[27] - 48) * 100 + (buffer[28] - 48) * 10 + buffer[29] - 48;
			primljena_poruka[10] = (buffer[30] - 48) * 100 + (buffer[31] - 48) * 10 + buffer[32] - 48;
			primljena_poruka[11] = (buffer[33] - 48) * 100 + (buffer[34] - 48) * 10 + buffer[35] - 48;
			primljena_poruka[12] = (buffer[36] - 48) * 100 + (buffer[37] - 48) * 10 + buffer[38] - 48;
		

		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sf::Vector2i pozicijamis1 = sf::Mouse::getPosition(window); //prava pozicija misa ostale su pomocne
		//POSTAVLJANJE BRODOVA PRIJE STARTA (TU JE SREDEN COLLISION, BOT I SVE OSTALO)

		if (start == false) {
			for (int i = 0; i < 5; i++) {
				colbrod[i] = 0;
			}
			sf::Vector2i pozicija = sf::Mouse::getPosition(window);
			sf::Vector2i novapozicija;
			sf::Vector2i pozicijamis = sf::Mouse::getPosition(window); //prava pozicija misa ostale su pomocne
			if (mis.isButtonPressed(sf::Mouse::Left))
			{
				if (boolbrod1 == true)
				{
					if (rekt_mis.getGlobalBounds().intersects(spbrod1.getGlobalBounds())) {
						spbrod1.setPosition(pozicijamis.x,pozicijamis.y);
					}
				}
				if (boolbrod2 == true)
				{
					if (rekt_mis.getGlobalBounds().intersects(spbrod2.getGlobalBounds())) {
						spbrod2.setPosition(pozicijamis.x, pozicijamis.y);
					}
				}
				if (boolbrod3 == true)
				{
					if (rekt_mis.getGlobalBounds().intersects(spbrod3.getGlobalBounds())) {
						spbrod3.setPosition(pozicijamis.x, pozicijamis.y);
					}
				}
				if (boolbrod4 == true)
				{
					if (rekt_mis.getGlobalBounds().intersects(spbrod4.getGlobalBounds())) {
						spbrod4.setPosition(pozicijamis.x, pozicijamis.y);
					}
				}
				if (boolbrod5 == true)
				{
					if (rekt_mis.getGlobalBounds().intersects(spbrod5.getGlobalBounds())) {
						spbrod5.setPosition(pozicijamis.x, pozicijamis.y);
					}
				}
			}
			if (mis.isButtonPressed(sf::Mouse::Left))
			{
				if (pozicijamis.x >= 650 && pozicijamis.x <= 750 && pozicijamis.y >= 30 && pozicijamis.y <= 80 && boolbrod1 == false && boolbrod2 == false && boolbrod3 == false && boolbrod4 == false && boolbrod5 == false)
				{
					//cout << "USAOOOOOO" << endl;
					start = true;
					for (int i = 0; i < 120; i++) {
						if (poljevoda[i].getGlobalBounds().intersects(spbrod1.getGlobalBounds()) || poljevoda[i].getGlobalBounds().intersects(spbrod2.getGlobalBounds()) || poljevoda[i].getGlobalBounds().intersects(spbrod3.getGlobalBounds()) || poljevoda[i].getGlobalBounds().intersects(spbrod4.getGlobalBounds()) || poljevoda[i].getGlobalBounds().intersects(spbrod5.getGlobalBounds())) {
							if (i >= 0 && i <= 9) {
								text += "00";
								text += to_string(i);
							}
							else if (i >= 10 && i <= 99) {
								text += "0";
								text += to_string(i);
							}
							else text += to_string(i);
						}
					}
					socket.send(text.c_str(), text.length() + 1);
					socket.receive(buffer, sizeof(buffer), received);
				}
			}




			for (int i = 0; i < 120; i++) {
				if (mis.isButtonPressed(sf::Mouse::Left)) {
					if (poljevoda[i].getGlobalBounds().intersects(spbrod1.getGlobalBounds()) || poljevoda[i].getGlobalBounds().intersects(spbrod2.getGlobalBounds()) || poljevoda[i].getGlobalBounds().intersects(spbrod3.getGlobalBounds()) || poljevoda[i].getGlobalBounds().intersects(spbrod4.getGlobalBounds()) || poljevoda[i].getGlobalBounds().intersects(spbrod5.getGlobalBounds()))
					{

						poljevoda[i].setOutlineColor(sf::Color::Yellow);
						poljevoda[i].setOutlineThickness(1);
					}
				}
				if (!(poljevoda[i].getGlobalBounds().intersects(spbrod1.getGlobalBounds()) || poljevoda[i].getGlobalBounds().intersects(spbrod2.getGlobalBounds()) || poljevoda[i].getGlobalBounds().intersects(spbrod3.getGlobalBounds()) || poljevoda[i].getGlobalBounds().intersects(spbrod4.getGlobalBounds()) || poljevoda[i].getGlobalBounds().intersects(spbrod5.getGlobalBounds())))
				{
					poljevoda[i].setOutlineColor(sf::Color::Black);
					poljevoda[i].setOutlineThickness(1);
				}
			}

			if (!mis.isButtonPressed(sf::Mouse::Left))
			{
				for (int i = 0; i < 120; i++) {
					if (poljevoda[i].getGlobalBounds().intersects(spbrod1.getGlobalBounds()))
					{
						colbrod[0]++;
					}
					if (poljevoda[i].getGlobalBounds().intersects(spbrod2.getGlobalBounds()))
					{
						colbrod[1]++;
					}
					if (poljevoda[i].getGlobalBounds().intersects(spbrod3.getGlobalBounds()))
					{
						colbrod[2]++;
					}
					if (poljevoda[i].getGlobalBounds().intersects(spbrod4.getGlobalBounds()))
					{
						colbrod[3]++;
					}
					if (poljevoda[i].getGlobalBounds().intersects(spbrod5.getGlobalBounds()))
					{
						colbrod[4]++;
					}
				}

				if (boolbrod1 == true) {
					if (colbrod[0] != 3) {
						spbrod1.setPosition(sf::Vector2f(0.f, 30.f));
						boolbrod1 = true;
					}
					else {
						if (pozicijamis.x >= 0 && pozicijamis.x <= 324 && pozicijamis.y >= 150 && pozicijamis.y <= 487) {
							boolbrod1 = false;
						}
						else {
							spbrod1.setPosition(sf::Vector2f(0.f, 30.f));
							boolbrod1 = true;
						}
					}
				}
				if (boolbrod2 == true) {
					if (colbrod[1] != 3) {
						spbrod2.setPosition(sf::Vector2f(35.f, 30.f));
						boolbrod2 = true;
					}
					else {
						if (pozicijamis.x >= 0 && pozicijamis.x <= 324 && pozicijamis.y >= 150 && pozicijamis.y <= 487) {
							boolbrod2 = false;
						}
						else {
							spbrod2.setPosition(sf::Vector2f(35.f, 30.f));
							boolbrod2 = true;
						}
					}
				}
				if (boolbrod3 == true) {
					if (colbrod[2] != 3) {
						spbrod3.setPosition(sf::Vector2f(70.f, 30.f));
						boolbrod3 = true;
					}
					else {
						if (pozicijamis.x >= 0 && pozicijamis.x <= 324 && pozicijamis.y >= 150 && pozicijamis.y <= 473) {
							boolbrod3 = false;
						}
						else {
							spbrod3.setPosition(sf::Vector2f(70.f, 30.f));
							boolbrod3 = true;
						}
					}
				}
				if (boolbrod4 == true) {
					if (colbrod[3] != 2) {
						spbrod4.setPosition(sf::Vector2f(105.f, 30.f));
						boolbrod4 = true;
					}
					else {
						if (pozicijamis.x >= 0 && pozicijamis.x <= 324 && pozicijamis.y >= 150 && pozicijamis.y <= 512) {
							boolbrod4 = false;
						}
						else {
							spbrod4.setPosition(sf::Vector2f(105.f, 30.f));
							boolbrod4 = true;
						}
					}
				}
				if (boolbrod5 == true) {
					if (colbrod[4] != 2) {
						spbrod5.setPosition(sf::Vector2f(140.f, 30.f));
						boolbrod5 = true;
					}
					else {
						if (pozicijamis.x >= 0 && pozicijamis.x <= 324 && pozicijamis.y >= 150 && pozicijamis.y <= 512) {
							boolbrod5 = false;
						}
						else {
							spbrod5.setPosition(sf::Vector2f(140.f, 30.f));
							boolbrod5 = true;
						}
					}
				}
			
			}


			int u;

			//BOT POSTAVLJA

		}
		//Polje radar pozuti ako prode mis
		rekt_mis.setPosition(pozicijamis1.x, pozicijamis1.y);
		for (int i = 0; i < 120; i++) {
			if (poljevoda1[i].getGlobalBounds().intersects(rekt_mis.getGlobalBounds()))
			{
				poljevoda1[i].setOutlineColor(sf::Color::Yellow);
			}
			else {
				poljevoda1[i].setOutlineColor(sf::Color::Black);
			}
		}
		if (start == true)
		{
			if (igracturn == 1) {
				text = '0';
				socket.send(text.c_str(), text.length() + 1);
				socket.receive(novibuffer, sizeof(novibuffer), received);
				igrac_klik = false;
				if (igracigra == true) {
					if (mis.isButtonPressed(sf::Mouse::Left)) {
						for (int i = 0; i < 120; i++) {
							if (poljevoda1[i].getGlobalBounds().intersects(rekt_mis.getGlobalBounds())) {
								for (int j = 0; j < 13; j++) {
									if (primljena_poruka[j] == i) {
										poljevoda1[i].setFillColor(sf::Color::Red);
										break;
									}
									else poljevoda1[i].setFillColor(sf::Color::White);
								}
							}
						}
						text = '1';
						igracturn = 0;
						socket.send(text.c_str(), text.length() + 1);
						socket.receive(novibuffer, sizeof(novibuffer), received);
					}
				}
			}
			else {
				text = '1';
				socket.send(text.c_str(), text.length() + 1);
				socket.receive(novibuffer, sizeof(novibuffer), received);
			}
		}
		if (novibuffer[0] == '1') igracturn = 1;
		if (novibuffer[0] == '0') igracturn = 0;

		// draw the map
		window.clear();
		window.draw(sppozadina);
		window.draw(spvoda);
		window.draw(sprite);
		for (int i = 0; i < 120; i++) {
			window.draw(poljevoda[i]);
			window.draw(poljevoda1[i]);
		}
		window.draw(startbutton);
		window.draw(spbrod1);
		window.draw(spbrod2);
		window.draw(spbrod3);
		window.draw(spbrod4);
		window.draw(spbrod5);
		window.display();
	}
	return 0;
}
