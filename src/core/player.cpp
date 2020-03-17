#include "player.h"

using namespace std;

player::player() {
    Pos.x = 0;
    Pos.y = 0;
}

Vec2 player::GetPos() const {
    return Pos;
}

Vec2 player::Move(Terrain T, direction D) {

}

void player::SetPos(Vec2 V) {
    Pos.x = V.x;
    Pos.y = V.y;
}