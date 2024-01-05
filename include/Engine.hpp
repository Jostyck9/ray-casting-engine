#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <memory>
#include "IRenderer.hpp"

class Engine
{
private:
  std::shared_ptr<IRenderer> _renderer;

public:
  Engine::Engine(std::shared_ptr<IRenderer> &renderer);

  void start();

private:
  std::pair<float, float> _getEndPosition(const std::pair<float, float> &start, float direction);
};

#endif // __ENGINE_H__