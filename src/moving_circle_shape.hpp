#pragma once

#include <SFML/Graphics.hpp>

enum class Direction {
    NORTH_EAST,
    NORTH_WEST,
    SOUTH_EAST,
    SOUTH_WEST
};

class MovingCircleShape {
    public:
        const sf::Color CIRCLE_COLOR{14,154,167, 155};
        const sf::Color BORDER_COLOR{74,78,77};

        MovingCircleShape(float radius);

        void setPosition(int x, int y);
        void setSpeed(int ySpeed, int xSpeed);
        void setDirection(Direction direction);

        void update(const sf::RenderWindow& window);
        void draw(sf::RenderWindow& window) const;

    private:
        void toggleXDirection();
        void toggleYDirection();

        sf::CircleShape shape;
        Direction direction;
        int xSpeed;
        int ySpeed;
};
