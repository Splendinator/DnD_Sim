#include "PhysicsNode.h"




PhysicsNode::PhysicsNode()
{
	p = new PhysicsD;
	p->position = Vector3(0, 0, 0);
	p->scale = Vector3(1, 1, 1);
	p->rotation = 0;

	
}

PhysicsNode::PhysicsNode(const PhysicsNode & pn)
{
	p = new PhysicsD;
	p->position = pn.getPosition();
	p->rotation = pn.getRotation();
	p->scale = pn.getScale();
	acceleration	   = pn.acceleration		  ;
	velocity		   = pn.velocity			  ;
	terminalVelocity   = pn.terminalVelocity	  ;
	rad				   = pn.rad					  ;
	mass			   = pn.mass				  ;

}



PhysicsNode::~PhysicsNode()
{
	//delete p;
}

void PhysicsNode::lookAt(Vector3 pos) {

	updateRotation(atan((pos.x - getPosition().x) / (pos.y - getPosition().y))*(360 / 6.28318530718 /* Convert rad to deg */));

	if (pos.y - getPosition().y < 0) updateRotation(getRotation() + 180); // Handle facing wrong way by simply turning 180.
}
