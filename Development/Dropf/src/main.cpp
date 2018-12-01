#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "droplet.h"
#include "cloud.h"
//TODO: Comment all this code and re-organise from 8 months ago ^^
//TODO: Clean up event tree so its more readable and there's less random stuff like needing to create flag booleans

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 400), "Rainmaker 0.3");
    
    Cloud cloud;
    bool flag1 = false;
    bool flag2 = false;

    // TEXT EXPERIMENTS IN THIS BOX

    sf::Font font;
    if (!font.loadFromFile("Helvetica-Regular.ttf")) std::cout << "Error loading font!\n";

    sf::Text text1; text1.setFont(font); text1.setString("Rain maker 3.0"); text1.setCharacterSize(140);
    text1.setFillColor(sf::Color(13, 33, 50, 50)); text1.setPosition(5, 5); text1.setStyle(sf::Text::Bold | sf::Text::Italic);

    // TEXT EXPERIMENTS IN THIS BOX

    // SOUND EXPERIMENTS IN THIS BOX

    sf::SoundBuffer buffer1;
    if (!buffer1.loadFromFile("thunder.ogg")) std::cout << "Error when loading sound1!\n";
    sf::Sound sound1;
    sound1.setBuffer(buffer1);

    sf::SoundBuffer buffer2;
    if (!buffer2.loadFromFile("thunder2.ogg")) std::cout << "Error when loading sound2!\n";
    sf::Sound sound2;
    sound2.setBuffer(buffer2);

    sf::Music music;
    if (!music.openFromFile("rainmusic.ogg")) std::cout << "Error when loading music!\n";
    music.setLoop(true);
    music.setVolume(5);
    music.play();

    //std::cout << ":::: NOTE ::::\nIf it says: \"AL lib: (EE) MMDevApiMsgProc: Unexpected message: 49607\" Don't worry.";
    // SOUND EXPERIMENTS IN THIS BOX

    sf::Clock timer;
    float fFrameTime = 1.f / 60.f;
    float fElapsedTime;
    int counter = 0;

    while (window.isOpen())
    {
        
        fElapsedTime = timer.getElapsedTime().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space)
                {
                    music.setVolume(5);
                    cloud.reset();
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) flag1 = true; //Does rain
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))             //Does thunder
                {
                    if (counter % 2) sound1.play();
                    else sound2.play();
                    counter++;
                    flag2 = true;
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))flag1 = false;  //Stops doing rain
                if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))flag2 = false; //Stops flash of thunder
            }

        }
        if (fElapsedTime > fFrameTime)
        {
            
            cloud.update();
            if (flag1) 
            {
                music.setVolume((cloud.append(sf::Mouse::getPosition(window)) / 10) + 5); 
            }
            timer.restart();
        }

        if (flag2) window.clear(sf::Color(255, 255, 200, 255)); //makes lighting happen by only rendering white screen
        else                                                    //renders everything because thunder isnt happening
        {
            window.clear(sf::Color(20, 40, 55, 255));
            for (int i = 0; i < 20; i++)
            {
                text1.setPosition(1 * i, 2 * i);
                text1.setFillColor(sf::Color(13 * i, 33, 50, 50));
                window.draw(text1);
            }
            window.draw(cloud);
        }
        window.display();
    }

    return 0;
}