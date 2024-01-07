#include "Player.hpp"

const std::pair<float, float> &Player::getPosition()
{
  return this->_position;
}

void Player::setPosition(float x, float y)
{
  this->_position.first = x;
  this->_position.second = y;
}

const float Player::getDirection()
{
  return this->_direction;
}

void Player::setDirection(float direction)
{
  this->_direction = direction;
}
