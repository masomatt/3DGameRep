#include "Flight_State.h"
#include <iterator>


Flight_State::Flight_State(void)
{
	srand(0);
	for(int i = 0; i < 15; i++){
		ships.push_back(new Ship(Point3f(rand() % 200, rand()%200, rand()%200)));
	}
}

  void Flight_State::on_push() {
  }

  void Flight_State::on_key(const SDL_KeyboardEvent &event) {
    switch(event.keysym.sym) {
      case SDLK_LSHIFT:
        controls.forward = event.type == SDL_KEYDOWN;
        break;

      case SDLK_LEFT:
        controls.left = event.type == SDL_KEYDOWN;
        break;

      case SDLK_LCTRL:
        controls.back = event.type == SDL_KEYDOWN;
        break;

      case SDLK_RIGHT:
        controls.right = event.type == SDL_KEYDOWN;
        break;

	  case SDLK_UP:
		  controls.up = event.type == SDL_KEYDOWN;
		  break;

	  case SDLK_DOWN:
		  controls.down = event.type == SDL_KEYDOWN;
		  break;

      default:
        Gamestate_Base::on_key(event);
        break;
    }
  }

  void Flight_State::perform_logic() {
	  float curTime = chrono.seconds();
	  float timeStep = curTime - totalTime;
	  totalTime = curTime;

	ship.pitch(controls.up - controls.down, timeStep);
	ship.roll(controls.left - controls.right, timeStep);
	ship.accel(controls.forward - controls.back, timeStep);

	ship.updatePhysics(timeStep);
  }

  void Flight_State::render(){
	Video &vr = get_Video();

	vr.set_3d(*ship.getCamera());

	for(list<Ship*>::iterator iter = ships.begin(); iter != ships.end(); iter++){
		(*iter)->render();
	}

	ship.render();
  }