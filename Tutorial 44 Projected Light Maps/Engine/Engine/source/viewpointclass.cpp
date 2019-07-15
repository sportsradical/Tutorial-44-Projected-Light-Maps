////////////////////////////////////////////////////////////////////////////////
// Filename: viewpointclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "viewpointclass.h"


ViewPointClass::ViewPointClass()
{
}


ViewPointClass::ViewPointClass(const ViewPointClass& other)
{
}


ViewPointClass::~ViewPointClass()
{
}


void ViewPointClass::SetPosition(float x, float y, float z)
{
	m_position = XMFLOAT3(x, y, z);
	return;
}


void ViewPointClass::SetLookAt(float x, float y, float z)
{
	m_lookAt = XMFLOAT3(x, y, z);
	return;
}


void ViewPointClass::SetProjectionParameters(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
{
	m_fieldOfView = fieldOfView;
	m_aspectRatio = aspectRatio;
	m_nearPlane = nearPlane;
	m_farPlane = farPlane;
	return;
}


void ViewPointClass::GenerateViewMatrix()
{
	XMFLOAT3 up, position, lookAt;
	XMVECTOR upVector, positionVector, lookAtVector;

	// Setup the vector that points upwards.
	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;
	// Load it into a XMVECTOR structure.
	upVector = XMLoadFloat3(&up);

	// Setup the position of the camera in the world.
	position.x = m_position.x;
	position.y = m_position.y;
	position.z = m_position.z;

	// Load it into a XMVECTOR structure.
	positionVector = XMLoadFloat3(&position);

	// Setup where the camera is looking by default.
	lookAt.x = 0.0f;
	lookAt.y = 0.0f;
	lookAt.z = 1.0f;

	// Load it into a XMVECTOR structure.
	lookAtVector = XMLoadFloat3(&lookAt);

	// Translate the rotated camera position to the location of the viewer.
	lookAtVector = XMVectorAdd(positionVector, lookAtVector);

	// Create the view matrix from the three vectors.
	m_viewMatrix = XMMatrixLookAtLH(positionVector, lookAtVector, upVector);
}


void ViewPointClass::GenerateProjectionMatrix()
{
	// Create the projection matrix for the view point.
	m_projectionMatrix = XMMatrixPerspectiveFovLH(m_fieldOfView, m_aspectRatio, m_nearPlane, m_farPlane);
	return;
}


void ViewPointClass::GetViewMatrix(XMMATRIX& viewMatrix)
{
	viewMatrix = m_viewMatrix;
	return;
}


void ViewPointClass::GetProjectionMatrix(XMMATRIX& projectionMatrix)
{
	projectionMatrix = m_projectionMatrix;
	return;
}