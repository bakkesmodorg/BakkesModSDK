#pragma once

struct LocalizedCameraMode
{
    std::string name;
    bool disabled;
    std::string label;
    std::string description;
};

class BAKKESMOD_PLUGIN_IMPORT ReplayViewerDataWrapper : ObjectWrapper
{
public:
    CONSTRUCTORS(ReplayViewerDataWrapper)

    _NODISCARD bool IsNull() const;
    explicit operator bool() const;

    _NODISCARD int GetCurrentFrame() const;
    _NODISCARD std::vector<LocalizedCameraMode> GetCameraModes() const;
    _NODISCARD std::string GetDefaultCameraMode() const;
    _NODISCARD std::string GetCameraMode() const;
    _NODISCARD std::string GetFocusActorString() const;
    _NODISCARD std::string GetLastFocusActorString() const;
    _NODISCARD unsigned int GetbHighlightFocusActor() const;
    _NODISCARD unsigned int GetbShowReplayHUD() const;
    _NODISCARD unsigned int GetbShowMatchInfoHUD() const;
    _NODISCARD unsigned int GetbShowPlayerNames() const;
    _NODISCARD unsigned int GetbPausedForScrub() const;
    _NODISCARD unsigned int GetbChangesMade() const;
    _NODISCARD float GetSlomo() const;
    _NODISCARD float GetFOV() const;
    _NODISCARD int GetViewRoll() const;
    _NODISCARD ReplayWrapper GetReplay() const;
    _NODISCARD int GetPendingSkipToFrame() const;

    void SaveReplayAndExit();
    void SetPausedForScrub(unsigned int bPaused);
    void SetFOV(float inFov);
    void SetShowPlayerNames(unsigned int bVisible);
    void SetShowMatchInfoHUD(unsigned int bVisible);
    void SetShowReplayHUD(unsigned int bVisible);
    void SetSlomo(float newSlomo);
    void TimerSkipToFrame();
    void AdvanceTime(float deltaTime);
    void AdvanceToFrame(int frame);
    void SetCameraMode(const std::string& modeName);
    void SetFocusActorString(const std::string& inFocusActorString);
    void RefreshDisabledModes();
    void InitCameraModes();
    void UpdateReplayData();

private:
    PIMPL
};
