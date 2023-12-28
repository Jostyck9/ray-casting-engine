#include <SFML/Graphics.hpp>

int main()
{
  auto window = sf::RenderWindow{{200u, 200u}, "CMake SFML Project"};
  window.setFramerateLimit(144);

  auto shape = sf::CircleShape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen())
  {
    for (auto event = sf::Event{}; window.pollEvent(event);)
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }
}