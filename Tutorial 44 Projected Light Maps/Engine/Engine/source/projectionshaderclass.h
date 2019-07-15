////////////////////////////////////////////////////////////////////////////////
// Filename: projectionshaderclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _PROJECTIONSHADERCLASS_H_
#define _PROJECTIONSHADERCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <fstream>
#include <d3dcompiler.h>
#include <DirectXMath.h>
using namespace DirectX;
using namespace std;


#pragma comment(lib, "d3dcompiler.lib")

////////////////////////////////////////////////////////////////////////////////
// Class name: ProjectionShaderClass
////////////////////////////////////////////////////////////////////////////////
class ProjectionShaderClass
{
private:
	struct MatrixBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
		XMMATRIX view2;
		XMMATRIX projection2;
	};

	struct LightPositionBufferType
	{
		XMFLOAT3 lightPosition;
		float padding;
	};

	struct LightBufferType
	{
		XMFLOAT4 ambientColor;
		XMFLOAT4 diffuseColor;
	};

public:
	ProjectionShaderClass();
	ProjectionShaderClass(const ProjectionShaderClass&);
	~ProjectionShaderClass();

	bool Initialize(ID3D11Device* device, HWND hwnd);
	void Shutdown();
	bool Render(ID3D11DeviceContext* deviceContext, int indexCount, XMMATRIX worldMatrix, XMMATRIX viewMatrix,
		XMMATRIX projectionMatrix, ID3D11ShaderResourceView* texture, XMFLOAT4 ambientColor, XMFLOAT4 diffuseColor,
		XMFLOAT3 lightPosition, XMMATRIX viewMatrix2, XMMATRIX projectionMatrix2,
		ID3D11ShaderResourceView* projectionTexture);

private:
	bool InitializeShader(ID3D11Device* device, HWND hwnd, WCHAR* vsFilename, WCHAR* psFilename);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob* errorMessage, HWND hwnd, WCHAR* shaderFilename);

	bool SetShaderParameters(ID3D11DeviceContext* deviceContext, XMMATRIX worldMatrix, XMMATRIX viewMatrix,
		XMMATRIX projectionMatrix, ID3D11ShaderResourceView* texture, XMFLOAT4 ambientColor,
		XMFLOAT4 diffuseColor, XMFLOAT3 lightPosition, XMMATRIX viewMatrix2, XMMATRIX projectionMatrix2,
		ID3D11ShaderResourceView* projectionTexture);

	void RenderShader(ID3D11DeviceContext* deviceContext, int indexCount);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11SamplerState* m_sampleState;
	ID3D11Buffer* m_matrixBuffer;
	ID3D11Buffer* m_lightPositionBuffer;
	ID3D11Buffer* m_lightBuffer;
};

#endif