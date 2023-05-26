#pragma once

class BAKKESMOD_PLUGIN_IMPORT MeshComponentWrapper : public PrimitiveComponentWrapper
{
public:
	CONSTRUCTORS(MeshComponentWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

private:
	PIMPL
	
};
