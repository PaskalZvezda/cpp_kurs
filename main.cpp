#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
    sf::RectangleShape player(sf::Vector2f(30.0f, 30.0f));
    player.setFillColor(sf::Color::Blue);
    player.setPosition(375.0f, 275.0f);
    float speed = 1000.0f; 
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Vector2f movement(0.0f, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            movement.x -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            movement.x += speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            movement.y -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            movement.y += speed;
        }

        float deltaTime = clock.restart().asSeconds();
        player.move(movement * deltaTime);
        window.clear(sf::Color::Black); 
        window.draw(player);           
        window.display();              
    }

    return 0;
}
