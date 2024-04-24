#include "Square.hpp"

Square::Square(Vector2f size)
{
    this->shape = RectangleShape(size);                                        // creamos una figura
    this->shape.setFillColor(Color::Green); // color de la figura
    this->speed = Vector2f(3.f, 3.f);
    this->acc = Vector2f(0.f, 1.f);
}

Square::Square(Vector2f size, int x, int y)
{
    this->shape = RectangleShape(size);                                        // creamos una figura
    this->shape.setFillColor(Color::Green); // color de la figura
    this->shape.setPosition(Vector2f(x,y));
    this->speed = Vector2f(3.f, 3.f);
    this->acc = Vector2f(0.f, 1.f);

}

void Square::update()
{

    this->speed += this->acc;
    this->shape.move(speed);

    if (this->shape.getPosition().x + this->shape.getSize().x > 1920 ||
        this->shape.getPosition().x < 0)
    {
        this->shape.setFillColor(Color::Green);
        this->speed.x *= -1;
    }
    if (this->shape.getPosition().y + this->shape.getSize().y >= 1080 )
    {
        this->speed.y *= -1;
        Vector2f position = this->shape.getPosition();
        this->shape.setPosition(position.x, 1080 - this->shape.getSize().y);

        this->shape.setFillColor(Color::Green);
    }
}

void Square::drawTo(RenderWindow &window)
{
    window.draw(this->shape);
}