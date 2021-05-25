#include "moving_circle_shape.hpp"

MovingCircleShape::MovingCircleShape(float radius) :
    shape{radius}, direction{Direction::NORTH_EAST}, xSpeed{1}, ySpeed{1}
{
    shape.setFillColor(CIRCLE_COLOR);
    shape.setOutlineColor(BORDER_COLOR);
    shape.setPosition(0, 0);
    shape.setOutlineThickness(2);
}

void MovingCircleShape::setPosition(int x, int y) {
    shape.setPosition(x, y);
}

void MovingCircleShape::setSpeed(int xSpeed, int ySpeed) {
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
}

void MovingCircleShape::setDirection(Direction direction) {
    this->direction = direction;
}

void MovingCircleShape::update(const sf::RenderWindow& window) {
    int maxX = window.getSize().x;
    int maxY = window.getSize().y;

    int xPos = shape.getPosition().x;
    int yPos = shape.getPosition().y;

    int diameter = shape.getRadius() * 2;

    if(direction == Direction::NORTH_EAST || direction == Direction::NORTH_WEST) {
        // Handle north
        if(yPos - ySpeed < 0) {
            toggleYDirection();
            yPos = yPos + ySpeed;
        } else {
            yPos = yPos - ySpeed;
        }
    } else if(direction == Direction::SOUTH_EAST || direction == Direction::SOUTH_WEST) {
        // Handle soute
        if(yPos + ySpeed + diameter > maxY) {
            toggleYDirection();
            yPos = yPos - ySpeed;
        } else {
            yPos = yPos + ySpeed;
        }
    }

    if(direction == Direction::NORTH_EAST || direction == Direction::SOUTH_EAST) {
        // Handle east
        if(xPos + xSpeed + diameter > maxX) {
            toggleXDirection();
            xPos = xPos - xSpeed;
        } else {
            xPos = xPos + xSpeed;
        }
    } else if(direction == Direction::NORTH_WEST || direction == Direction::SOUTH_WEST) {
        // Handle west
        if(xPos - xSpeed < 0) {
            toggleXDirection();
            xPos = xPos + xSpeed;
        } else {
            xPos = xPos - xSpeed;
        }
    }

    shape.setPosition(xPos, yPos);
}

void MovingCircleShape::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

void MovingCircleShape::toggleXDirection() {
    switch(direction) {
        case Direction::NORTH_EAST:
            direction = Direction::NORTH_WEST;
            break;
        case Direction::NORTH_WEST:
            direction = Direction::NORTH_EAST;
            break;
        case Direction::SOUTH_EAST:
            direction = Direction::SOUTH_WEST;
            break;
        case Direction::SOUTH_WEST:
            direction = Direction::SOUTH_EAST;
            break;
    }
}

void MovingCircleShape::toggleYDirection() {
    switch(direction) {
        case Direction::NORTH_EAST:
            direction = Direction::SOUTH_EAST;
            break;
        case Direction::NORTH_WEST:
            direction = Direction::SOUTH_WEST;
            break;
        case Direction::SOUTH_EAST:
            direction = Direction::NORTH_EAST;
            break;
        case Direction::SOUTH_WEST:
            direction = Direction::NORTH_WEST;
            break;
    }
}
