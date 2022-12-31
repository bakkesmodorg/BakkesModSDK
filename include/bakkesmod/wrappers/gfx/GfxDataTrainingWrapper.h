#pragma once
template<class T> class ArrayWrapper;
template<typename T> class StructArrayWrapper;
#include "../WrapperStructs.h"
#include "../Engine/ObjectWrapper.h"
//#include "../StructArrayWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT GfxDataTrainingWrapper : public ObjectWrapper {
public:
	CONSTRUCTORS(GfxDataTrainingWrapper)
		explicit operator bool();
	bool IsNull();

	bool CanUseMirroring();
	bool CanUsePlaylistOverride();
	bool CanUseShuffle();
	bool CanUseTrainingUIV2();
	bool HasCompletedTraining(const std::string& inType, const std::string& inDifficulty);
	bool HasCompletedTutorial(int InType);
	bool HasPerfectedTraining(const std::string& inType, const std::string& inDifficulty);
	bool UpdateDataFromProgress();
	void EndTrainingEditorPlaytest();
	void eventOnRemoved();
	void eventOnShellSet();
	void PlayFreeplayMap(const std::string& Map);
	void PlayTraining(const std::string& Type, const std::string& trainingDifficulty);
	void PlayTutorial(bool bAdvanced);
	void PlayV2Tutorial(int type, bool bAutoEntered);
	void ResetTrainingProgress();
	void SetCurrentPlaylist(const std::string& playlist);
	void SetTrainingEditorGameEvent(TrainingEditorWrapper inGameEvent);
	void SetTrainingGameEvent(TutorialWrapper inGameEvent);
	void StartAtPlaylistIndex(int inPlaylistIndex);

	std::string GetTrainingType();
	int GetCurrentScore();
	int GetCurrentRound();
	int GetTotalRounds();
	UnrealStringWrapper GetDifficulty();
	std::string GetSelectedFreeplayMap();
	UnrealStringWrapper GetTutorialTip();
	StructArrayWrapper<TrainingRoundProgress> GetProgressPerShot();
	int GetCurrentPlaylistindex();

private:
	PIMPL
};