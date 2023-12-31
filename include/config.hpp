#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <vector>

struct RayCastingConfig
{
  unsigned int precision;
};

struct Config
{
  RayCastingConfig rayCasting;
  std::vector<std::vector<char>> map;
};

#endif // __CONFIG_H__