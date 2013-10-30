#pragma once

#include "zenilib.h"
#include "Ship.h"
#include <list>
#include <random>

using namespace std;

class Flight_State : public Zeni::Gamestate_Base {
struct Controls {
    Controls() : forward(false), left(false), back(false), right(false), up(false), down(false) {}

    bool forward;
    bool left;
    bool back;
    bool right;
	bool up;
	bool down;
} controls;

public:
Flight_State();

void on_push();

void on_key(const SDL_KeyboardEvent &event);

void perform_logic();

void render();

Zeni::Time_HQ time_passed;

Ship ship;
list<Ship*> ships;

Chronometer<Time> chrono;
float totalTime;

};

