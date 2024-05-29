# Probe of WASM 

This project is to study Web Assembly, WASM and it's programming paradims and patterns. 

## Build 

```

git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh

cd .. 

emcc game.c -o game.js -s EXPORTED_FUNCTIONS='["_init_game", "_update_game", "_set_direction", "_get_snake_x", "_get_snake_y", "_get_food_x", "_get_food_y", "_is_game_over", "_get_snake_size"]' -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]

python3 -m http.server 6969 

```

## Goals: 

1. Using WASM without emsdk dependancy 
2. Port game.c by seperating logic from presentation/platform. 

## References 
1. https://emscripten.org/ 
2. https://www.youtube.com/watch?v=i4Tam03E-Oc 
3. https://github.com/tsoding/zozlib.js (zozlib)

