#include "window.h"
#include "Renderer.h"
#include "Physics.h"
#include "Entity.h"
#include "EntityAI.h"
#include "EntityArrow.h"

#pragma comment(lib, "nclgl.lib")


Window w("CSC3222 Coursework", 1920, 1080, false);
Physics physics;
Renderer renderer(w, &physics);

const float ROTATION_SPEED = 0.3f;
const float ACCELERATION = 0.0005f;

bool gameStarted = false;
bool gameEnded = false;


void handleInput(float msec) {
	if (w.GetKeyboard()->KeyTriggered(KeyboardKeys::KEYBOARD_K) /*&& !gameStarted*/) {
		gameStarted = true;
		Entity *e = new Entity();
		e->getPhysicsNode().updatePosition(Vector3(88, -320, 0));
		e->getPhysicsNode().updateScale(Vector3(10, 10, 1));
		e->getPhysicsNode().updateRotation(0);
		e->getPhysicsNode().rad = (10);
		e->getPhysicsNode().mass = (10);
		e->maxHealth = 200;
		e->health = e->maxHealth;
		physics.leader = e;

		EntityRaider t;
		t.getPhysicsNode().updateScale(Vector3(10, 10, 1));
		t.getPhysicsNode().rad = (10);
		t.getPhysicsNode().mass = (10);
		t.maxHealth = 150;
		t.reloadSpeed = 6000;
		

		for (int i = 0; i < 15; ++i) {
			t.health = 100 + rand() % 51;
			t.pathTimer = (physics.RE_PATH_TIME / 15) * i;
			t.getPhysicsNode().updatePosition(Vector3(120 + 10*(i%8) , -330 - 20* (i/8), 0));

			physics.addRaider(t);
		}
		renderer.refreshRaiders();

	}
	if (physics.hasLeader()) {
		if (w.GetKeyboard()->KeyHeld(KEYBOARD_LEFT)) {
			physics.leader->getPhysicsNode().updateRotation(physics.leader->getPhysicsNode().getRotation() - ROTATION_SPEED * msec);
		}
		if (w.GetKeyboard()->KeyHeld(KEYBOARD_RIGHT)) {
			physics.leader->getPhysicsNode().updateRotation(physics.leader->getPhysicsNode().getRotation() + ROTATION_SPEED * msec);
		}

		if (w.GetKeyboard()->KeyHeld(KEYBOARD_UP)) {
			physics.leader->getPhysicsNode().acceleration = (physics.leader->getPhysicsNode().foward() * ACCELERATION);
		}
		else if (w.GetKeyboard()->KeyHeld(KEYBOARD_DOWN)) {
			physics.leader->getPhysicsNode().acceleration = (physics.leader->getPhysicsNode().foward() * -ACCELERATION);
		}
		else {
			physics.leader->getPhysicsNode().acceleration = (Vector3(0, 0, 0));
		}

		//*** HEAL ***
		if (w.GetKeyboard()->KeyTriggered(KEYBOARD_L)) {
			float health = INFINITE;
			EntityRaider *en = nullptr;
			for (vector<EntityRaider>::iterator it = physics.raiders.begin(); it != physics.raiders.end(); ++it) {
				if (it->health < health && it->state == FOLLOW) {
					health = it->health;
					en = &*it;
				}
			}
			if (en) {
				en->moves.clear();
				physics.healMap->genRoute(*en, Vector3(444, 100, 0));
				en->state = HEAL;
			}
		}

		//*** HOARD ***
		if (w.GetKeyboard()->KeyTriggered(KEYBOARD_J)) {
			for (vector<EntityRaider>::iterator it = physics.raiders.begin(); it != physics.raiders.end(); ++it) {
				if (it->arrowDamage == 10 && it->state == FOLLOW) {
					it->moves.clear();
					physics.raiderMap->genRoute(*it, Vector3(-146, 513, 0));
					it->state = HOARD;
					break;
				}
			}
		}

		//*** ARROWS ***
		if (w.GetKeyboard()->KeyTriggered(KEYBOARD_SPACE)) {
			for (vector<EntityRaider>::iterator it = physics.raiders.begin(); it != physics.raiders.end(); ++it) {
				if (it->fireTime > it->reloadSpeed) {
					it->fireTime = msec;
					EntityArrow a;
					a.damage = it->arrowDamage;
					a.getPhysicsNode().updatePosition(it->getPhysicsNode().getPosition());
					a.getPhysicsNode().updateScale(Vector3(20, 10, 1));
					Vector3 direction = physics.dragon.getPhysicsNode().getPosition() - it->getPhysicsNode().getPosition();
					direction.Normalise();
					a.getPhysicsNode().updateRotation(-physics.getAngle(direction) + 180.f);
					if (a.getPhysicsNode().getRotation() < 0) a.getPhysicsNode().updateRotation(a.getPhysicsNode().getRotation() + 360.f);
					a.getPhysicsNode().velocity = direction * 0.1f;
					a.getPhysicsNode().terminalVelocity = INFINITE;
					a.getPhysicsNode().rad = 20.f;
					physics.arrows.push_back(a);
				}
			}
		}
	}

	//*** WIN CONDITIONS ***
	if (physics.dragon.health < 0) {
		cout << "You win!" << endl;	//Sorry, I printed text to the screen in my engine though.
		gameEnded = true;
	}
	if (physics.raiders.size() == 0 && !physics.leader && gameStarted) {
		cout << "You lose!" << endl;
		gameEnded = true;
	}
}

int main() {

	
	if (!w.HasInitialised()) {
		return -1;
	}


	
	if (!renderer.HasInitialised()) {
		return -1;
	}

	w.LockMouseToWindow(true);
	w.ShowOSPointer(false);
	


	while (w.UpdateWindow() && !Window::GetKeyboard()->KeyDown(KEYBOARD_ESCAPE) && !Window::GetKeyboard()->KeyDown(KEYBOARD_X) && !(gameStarted && gameEnded)) {
		float msec = w.GetTimer()->GetTimedMS();
		handleInput(msec);
		physics.UpdatePhysics(msec);
		renderer.refreshRaiders();
		renderer.UpdateScene(msec);
		renderer.RenderScene();
	}

	return 0;
}