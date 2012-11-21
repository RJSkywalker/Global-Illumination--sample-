////definitions of the Scene Class functions

#include "StdAfx.h"

#include "Scene.h"

Scene::Scene()
{
	m_pPrimitives = NULL;

	
}

Scene::~Scene()
{
	delete m_pPrimitives;

}

void Scene::SetupScene()
{
	m_pPrimitives = new Object* [5]; 
	
	Scene::numPrimitives = 5;

	//GzCoord centre = {48,-35,38};
	GzCoord centre = {18.1,-8.18,-5.6};
	float radius = 10;
	m_pPrimitives[0] = new CSphere(centre,radius);
	GzColor reflectance = {0.35, 0.45, 0.1};
	//GzColor refractance = {0.25, 0.25, 
	static_cast<CSphere*>(m_pPrimitives[0])->setKr(reflectance);


//	centre[X] = 14;
//	centre[Y] = -16;
//	centre[Z] = 25;

	centre[X] = 15.0;
	centre[Y] = 0.0;
	centre[Z] = -5.0;
	radius = 10;

	m_pPrimitives[1] = new CSphere(centre, radius); 

	reflectance[X] = 0.22;
	reflectance[Y] = 0.34;
	reflectance[Z] = 0.78;
	static_cast<CSphere*>(m_pPrimitives[1])->setKr(reflectance);

	GzCoord normal = {0,1,1};

	m_pPrimitives[2] = new CPlane(normal,-2);

	reflectance[X] = 0.12;
	reflectance[Y] = 0.24;
	reflectance[Z] = 0.88;

	static_cast<CPlane*>(m_pPrimitives[2])->setKr(reflectance);
	normal[X] = 1;
	normal[Y] = 1;
	normal[Z] = 1;

	m_pPrimitives[3] = new CPlane(normal,5);
	
	reflectance[X] = 0.32;
	reflectance[Y] = 0.29;
	reflectance[Z] = 0.48;
	static_cast<CPlane*>(m_pPrimitives[3])->setKr(reflectance);

	SceneMesh tri;

	tri.vertexList[0][X] = 2.4;
	tri.vertexList[0][Y] = 2.25;
	tri.vertexList[0][Z] = 1.00;

	tri.vertexList[1][X] = -1.29;
	tri.vertexList[1][Y] = 1.25;
	tri.vertexList[1][Z] = 0.55;

	tri.vertexList[2][X] = 0.273;
	tri.vertexList[2][Y] = -0.324;
	tri.vertexList[2][Z] = 2.54;

	tri.normalList[0][X] = 0.90;
	tri.normalList[0][Y] = -0.43;
	tri.normalList[0][Z] = 0;

	tri.normalList[0][X] = 0.83;
	tri.normalList[1][Y] = -0.43;
	tri.normalList[2][Z] = -0.347;

	tri.normalList[0][X] = 0.92;
	tri.normalList[1][Y] = 0.095;
	tri.normalList[2][Z] = -0.382;

	tri.uvList[0][X] = 0.0;
	tri.uvList[0][Y] = 0.0;

	tri.uvList[1][X] = 0.25;
	tri.uvList[1][Y] = 0.0;

	tri.uvList[2][X] = 0.25;
	tri.uvList[2][Y] = 0.25;

	m_pPrimitives[4] = new CTriangle(tri);

	static_cast<CTriangle*>(m_pPrimitives[4])->setKr(reflectance);
	
}

int Scene::numPrimitives = 0;