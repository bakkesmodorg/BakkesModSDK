#pragma once
#include "ReplayViewerDataWrapper.h"


// Adding the empty bases, so we are future-proof in case we want to use something from the bases later
class BAKKESMOD_PLUGIN_IMPORT HudWrapper : public ActorWrapper
{
public:
    CONSTRUCTORS(HudWrapper)
private:
    PIMPL
};

class BAKKESMOD_PLUGIN_IMPORT HUDXWrapper: public HudWrapper
{
public:
    CONSTRUCTORS(HUDXWrapper)
private:
    PIMPL
};

class BAKKESMOD_PLUGIN_IMPORT HUDTABaseWrapper: public HUDXWrapper
{
public:
    CONSTRUCTORS(HUDTABaseWrapper)
private:
    PIMPL
};

class BAKKESMOD_PLUGIN_IMPORT HUDTAWrapper: public HUDTABaseWrapper
{
public:
    CONSTRUCTORS(HUDTAWrapper)
private:
    PIMPL
};

class BAKKESMOD_PLUGIN_IMPORT SpectatorHUDWrapper : public HUDTAWrapper
{
public:
    CONSTRUCTORS(SpectatorHUDWrapper)

    _NODISCARD bool IsNull() const;
    explicit operator bool() const;

    _NODISCARD ReplayViewerDataWrapper GetViewerData() const;
    _NODISCARD float GetZoomSpeed() const;
    _NODISCARD float GetZoomClickTime() const;
    _NODISCARD PriWrapper GetTargetPlayerPRI() const;
    _NODISCARD unsigned int GetbZoomIn() const;
    _NODISCARD unsigned int GetbZoomOut() const;
    _NODISCARD unsigned int GetbReplayTimeSkipped() const;
    _NODISCARD float GetZoomInTime() const;
    _NODISCARD float GetZoomOutTime() const;

    _NODISCARD CarWrapper GetFocusCar();
    _NODISCARD PriWrapper GetPRIFromPlayerIDString(const std::string& playerIdString);
    void ViewCycle(int direction);
    void ViewPrev();
    void ViewNext();
    void ViewFly();
    void ViewAutoCam();
    void ViewDefault();
    void SetFocusActorString(const std::string& focusActorString);
    void ViewPlayer(int team, int player);
    void OpenReplayFXMenu();
    void OpenCameraMenu();
    void CycleCamera();
    void OpenFocusMenu();
    void CycleFocus();
    void UpdateHudVisibility();
    void CycleHUD();
    void ZoomOut(unsigned int bPressed);
    void ZoomIn(unsigned int bPressed);
    void AdjustZoom(float deltaFov);

private:
    PIMPL
};
