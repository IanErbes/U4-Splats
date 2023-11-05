#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

int main() {

    sf::RenderWindow App(sf::VideoMode(800, 600), "Ejercicio 3 Splats");

    std::vector<sf::Sprite> circulos;

    sf::Texture textura_circulo_rojo;
    textura_circulo_rojo.loadFromFile("rcircle.png");

    sf::Texture textura_circulo_azul;
    textura_circulo_azul.loadFromFile("rcircleb.png");

    while (App.isOpen()) {
        sf::Event evt;
        while (App.pollEvent(evt)) {
            
            switch (evt.type) {
               
            case sf::Event::Closed:
                App.close();
            }

            if (evt.type == sf::Event::MouseButtonPressed) {
                if (evt.mouseButton.button == sf::Mouse::Left) {

                    sf::Sprite sprite_circulo_rojo(textura_circulo_rojo);
                    sprite_circulo_rojo.setPosition(sf::Vector2f(evt.mouseButton.x, evt.mouseButton.y));
                    circulos.push_back(sprite_circulo_rojo);
                }
                else if (evt.mouseButton.button == sf::Mouse::Right) {

                    sf::Sprite sprite_circulo_azul(textura_circulo_azul);
                    sprite_circulo_azul.setPosition(sf::Vector2f(evt.mouseButton.x, evt.mouseButton.y));
                    circulos.push_back(sprite_circulo_azul);
                }
            }
        }

        App.clear();

        for (const sf::Sprite& circulos : circulos) {
            App.draw(circulos);
        }

        App.display();
    }

    return 0;
}
