#include "Vec2.h"
#include "player.h"
#include "Terrain.h"

using namespace std;

player::player() {
    Pos.x = 0;
    Pos.y = 0;
}

player::GetPos() const {
    return Pos;
}

player::Move(TableauDynamique2D T, direction D) {

}

player::SetPos(Vec2 V) {
    Pos.x = V.x;
    Pos.y = V.y;
}