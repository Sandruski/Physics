#include "PhysBody3D.h"
#include "glmath.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// TODO 4: Fill in PhysBody methods. Remember to use 
// get/setOpenGLMatrix methods

// ---------------------------------------------------------
PhysBody3D::PhysBody3D(btRigidBody* body) :body(body) {}

// ---------------------------------------------------------
PhysBody3D::~PhysBody3D()
{
	if (body != nullptr)
		delete body;
	body = nullptr;
}

// ---------------------------------------------------------
void PhysBody3D::GetTransform(float* matrix) const
{
	btTransform transform = body->getWorldTransform();
	transform.getOpenGLMatrix(matrix);
}

// ---------------------------------------------------------
void PhysBody3D::SetTransform(const float* matrix) const
{
	btTransform transform;
	transform.setFromOpenGLMatrix(matrix);
	body->setWorldTransform(transform);
}

// ---------------------------------------------------------
void PhysBody3D::SetPos(float x, float y, float z)
{
	mat4x4 trans = IdentityMatrix;
	trans.translate(x, y, z);

	btTransform transform;
	transform.setFromOpenGLMatrix(&trans);
}
