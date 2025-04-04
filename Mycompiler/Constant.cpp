#include "Constant.h"

Constant* Constant::True = new Constant(&Word::True, Type::Bool);
Constant* Constant::False = new Constant(&Word::False, Type::Bool);
