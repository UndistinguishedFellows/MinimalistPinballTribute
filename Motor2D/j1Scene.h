#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"

struct SDL_Texture;

class Chain;

class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

	// Called before render is available
	bool Awake(pugi::xml_node& config);

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

	

private:
	SDL_Texture* debug_tex;
	//p2List<p2List<int>*>* chains;
	p2List<Chain*>* chains;

	PhysBody* bumper1;
	PhysBody* bumper2;
	PhysBody* bumper3;

	SDL_Texture* mesa;
	SDL_Texture* bumper;

	int bumper1Collision;
	int bumper2Collision;
	int bumper3Collision;
};

#endif // __j1SCENE_H__