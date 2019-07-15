////////////////////////////////////////////////////////////////////////////////
// Filename: viewpointclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _VIEWPOINTCLASS_H_
#define _VIEWPOINTCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <DirectXMath.h>
using namespace DirectX;



////////////////////////////////////////////////////////////////////////////////
// Class name: ViewPointClass
////////////////////////////////////////////////////////////////////////////////
class ViewPointClass
{
public:
	ViewPointClass();
	ViewPointClass(const ViewPointClass&);
	~ViewPointClass();

	void SetPosition(float x, float y, float z);
	void SetLookAt(float x, float y, float z);
	void SetProjectionParameters(float fieldOfView, float aspectRatio, float nearPlane, float farPlane);

	void GenerateViewMatrix();
	void GenerateProjectionMatrix();

	void GetViewMatrix(XMMATRIX&);
	void GetProjectionMatrix(XMMATRIX&);

private:
	XMFLOAT3 m_position, m_lookAt;
	XMMATRIX m_viewMatrix, m_projectionMatrix;
	float m_fieldOfView, m_aspectRatio, m_nearPlane, m_farPlane;
};

#endif