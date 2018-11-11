#pragma once

#include "OGLRenderer.h"
#include "Camera.h"
#include "SceneNode.h"
#include "Frustum.h"
#include <algorithm>
#include "Physics.h"



class Renderer : public OGLRenderer {
public:
	Renderer(Window &parent, Physics* p);
	virtual ~Renderer(void);

	virtual void UpdateScene(float msec);
	virtual void RenderScene();

	Physics* p;

	void setLeader(Entity *e);
	void refreshRaiders();


protected:
	void	BuildNodeLists(SceneNode* from);
	void	SortNodeLists();
	void	ClearNodeLists();
	void	DrawNodes();
	void	DrawNode(SceneNode*n);


	SceneNode leader;
	SceneNode leader2;
	vector<SceneNode> raiders;
	vector<SceneNode> arrows;

	SceneNode* root;
	Camera*	camera;
	Mesh*	map;
	Mesh*	raider;
	Mesh*	dragon;
	Mesh*	breathWeapon;
	Mesh* arrow;

	Mesh*	debug;
	Entity debugEntity;

	Frustum frameFrustum;

	vector<SceneNode*> transparentNodeList;
	vector<SceneNode*> nodeList;
};

