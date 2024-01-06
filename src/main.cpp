#include <memory>
#include "IRenderer.hpp"
#include "SFMLRenderer.hpp"
#include "Engine.hpp"
#include "Settings.hpp"

int main()
{
  auto settings = std::make_shared<Settings>();
  std::shared_ptr<IRenderer> renderer = std::make_shared<SFMLRenderer>(settings);
  Engine engine(renderer, settings);

  engine.start();
}