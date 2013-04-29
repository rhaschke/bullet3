#ifndef BULLET_DATA_EXTRACTOR_H
#define BULLET_DATA_EXTRACTOR_H


#include "Bullet3Serialize/Bullet2FileLoader/autogenerated/bullet2.h"
#include "Bullet3Common/b3AlignedObjectArray.h"
#include "Bullet3Common/b3Vector3.h"

class GLInstancingRenderer;
class b3GpuRigidBodyPipeline;
class b3GpuNarrowPhase;

void createScene(GLInstancingRenderer& renderer,b3GpuNarrowPhase& np, b3GpuRigidBodyPipeline& rbWorld, const char* fileName);

namespace bParse
{
	class b3BulletFile;
};

class b3BulletDataExtractor
{
	GLInstancingRenderer&		m_renderer;
	b3GpuNarrowPhase&			m_np;
	b3GpuRigidBodyPipeline&		m_rbPipeline;

	public:

	b3AlignedObjectArray<struct InstanceGroup*> m_instanceGroups;
	b3AlignedObjectArray<struct GraphicsShape*> m_graphicsShapes;

	b3BulletDataExtractor(GLInstancingRenderer&	renderer, b3GpuNarrowPhase&	np, b3GpuRigidBodyPipeline& rbPipeline);
	
	virtual ~b3BulletDataExtractor();
	
	virtual void convertAllObjects(bParse::b3BulletFile* bulletFile);
	
	//return -1 for invalid
	virtual int convertCollisionShape(  Bullet3SerializeBullet2::b3CollisionShapeData* shapeData  );

	virtual int createPlaneShape( const Bullet3SerializeBullet2::b3Vector3FloatData& planeNormal, float planeConstant, const Bullet3SerializeBullet2::b3Vector3FloatData& localScaling);
	
	virtual int createBoxShape( const Bullet3SerializeBullet2::b3Vector3FloatData& halfDimensions, const Bullet3SerializeBullet2::b3Vector3FloatData& localScaling, float collisionMargin);

	virtual int createSphereShape( float radius, const Bullet3SerializeBullet2::b3Vector3FloatData& localScaling, float collisionMargin);

	static GraphicsShape* createGraphicsShapeFromConvexHull(const b3Vector3* tmpPoints, int numPoints);
	static GraphicsShape* createGraphicsShapeFromWavefrontObj(class objLoader* obj);

};


	
#endif //BULLET_DATA_EXTRACTOR_H