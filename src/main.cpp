#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>

#include "moving_circle_shape.hpp"

const sf::Color BACKGROUND_COLOR{246,205,97};

std::unique_ptr<MovingCircleShape> createRandomCircle(const sf::RenderWindow& window);

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(200, 200), "Chaos in moving circles", sf::Style::Fullscreen, settings);
    window.setVerticalSyncEnabled(true);


    std::srand(std::time(nullptr));
    std::vector<std::unique_ptr<MovingCircleShape>> circleShapes;
    for(int i = 0; i< 2500; i++) {
           circleShapes.push_back(createRandomCircle(window));
    }

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(BACKGROUND_COLOR);

        for(auto& circle: circleShapes) {
            circle->update(window);
            circle->draw(window);
        }

        window.display();
    }

    return 0;
}

std::unique_ptr<MovingCircleShape> createRandomCircle(const sf::RenderWindow& window) {
    int radius = std::rand() % 20;
    int speed = std::rand() % 2 + 1;
    int startx = std::rand() % (window.getSize().x - 2* radius);
    int starty = std::rand() % (window.getSize().y - 2* radius);

    Direction direction;
    int directionInt = std::rand() % 4;
    switch(directionInt) {
    case 0:
        direction = Direction::NORTH_EAST;
        break;
    case 1:
        direction = Direction::SOUTH_EAST;
        break;
    case 2:
        direction = Direction::SOUTH_WEST;
        break;
    case 3:
        direction = Direction::NORTH_WEST;
        break;
    }

    auto circleShape = std::make_unique<MovingCircleShape>(radius);
    circleShape->setPosition(startx, starty);
    circleShape->setSpeed(speed, speed);
    circleShape->setDirection(direction);

    return circleShape;
}
