#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "WrapperStructs.h"
#include "ControllerWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT AIControllerWrapper : public ControllerWrapper {
public:
    CONSTRUCTORS(AIControllerWrapper)

        void DoNothing();

private:
    PIMPL
};