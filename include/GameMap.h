#pragma once
#include <vector>

enum class TileType {
  TT_NONE,
  TT_GRASS,
  TT_WATER,
  TT_ROAD,
  TT_RAILROAD,
  TT_BUILDING,
  TT_FOREST,
  TT_MOUNTAIN,
  TT_SAND,
  TT_SWAMP
};

class Tile {
public:
  int height;
  bool buildable, hasPath, hasTrack;
  TileType type;

  void render(void) const;
};

class GameMap {
private:
  std::vector<std::vector<Tile>> grid;
public:
  const Tile& getTile(int, int) const;
  void render(void) const;
  void setTile(int, int, const Tile&);
};