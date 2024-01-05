#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <utility>

class Player
{
private:
  std::pair<float, float> _position = {2, 2};
  float _direction = 90.f;
  float _fov = 60;

public:
  Player();

  const std::pair<float, float> &getPosition();

  void setPosition(float x, float y);

  const float getDirection();

  void setDirection(float direction);

  const float getFOV();

  void setFOV(float fov);
};

#endif // __PLAYER_H__