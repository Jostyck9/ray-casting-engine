#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <utility>

class Player
{
private:
  std::pair<float, float> _position = {0, 0};
  float _direction = 90.f;

public:
  const std::pair<float, float> &getPosition();

  void setPosition(float x, float y);

  const float getDirection();

  void setDirection(float direction);
};

#endif // __PLAYER_H__