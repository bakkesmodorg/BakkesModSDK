#pragma once

#include "ObjectWrapper.h"
#include <map>
#include <string>

class BAKKESMOD_PLUGIN_IMPORT EnumWrapper: public ObjectWrapper
{
public:
	CONSTRUCTORS(EnumWrapper)

	// Get the name of this enum.
	_NODISCARD std::string GetEnumName() const;

	// Throws if invalid value
	_NODISCARD std::string GetEnumLabel(unsigned char enum_value) const;

	// Throws if invalid label
	_NODISCARD unsigned char GetEnumValue(const std::string& enum_label) const;

	// Get a count of how many values this enum contains
	_NODISCARD size_t GetEnumValueCount() const;

	// Get a map with all the possible enum values and their labels
	_NODISCARD std::map<unsigned char, std::string> GetPossibleValues() const;

	// Don't forget the first rule of BMSDK!
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;

	/*U_Types_TA_ETeam*/
	_NODISCARD static EnumWrapper GetTeamEnum();
	/*AActor_ECollisionType*/
	_NODISCARD static EnumWrapper GetActorCollisionTypes();
	/*AActor_EForceMode*/
	_NODISCARD static EnumWrapper GetActorForceModes();
	/*AActor_ENetRole*/
	_NODISCARD static EnumWrapper GetActorNetRoles();
	/*AActor_EPhysics*/
	_NODISCARD static EnumWrapper GetActorPhysics();
	/*AActor_ETravelType*/
	_NODISCARD static EnumWrapper GetActorTravelModes();
	/*AGameEvent_TrainingEditor_TA_EPlayTestType*/
	_NODISCARD static EnumWrapper GetTrainingPlayTestTypes();
	/*AGameEvent_Tutorial_TA_ERotationType*/
	_NODISCARD static EnumWrapper GetTutorialRotationTypes();
	/*AVehiclePickup_Boost_TA_EBoostType*/
	_NODISCARD static EnumWrapper GetBoostTypes();
	/*U_Types_Core_OnlinePlatform*/
	_NODISCARD static EnumWrapper GetOnlinePlatforms();
	/*U_Types_TA_EAchievementType*/
	_NODISCARD static EnumWrapper GetAchievementTypes();
	/*U_Types_TA_EBallHitType*/
	_NODISCARD static EnumWrapper GetBallHitTypes();
	/*U_Types_TA_EBlueprintType*/
	_NODISCARD static EnumWrapper GetBlueprintTypes();
	/*U_Types_TA_ECarImpactResult*/
	_NODISCARD static EnumWrapper GetCarImpactResults();
	/*U_Types_TA_EChatChannel*/
	_NODISCARD static EnumWrapper GetChatChannels();
	/*U_Types_TA_EDemolishSpeed*/
	_NODISCARD static EnumWrapper GetDemolishSpeeds();
	/*U_Types_TA_EDemolishTarget*/
	_NODISCARD static EnumWrapper GetDemolishTargets();
	/*U_Types_TA_EDifficulty*/
	_NODISCARD static EnumWrapper GetDifficulties();
	/*U_Types_TA_EHistoryType*/
	_NODISCARD static EnumWrapper GetHistoryTypes();
	/*U_Types_TA_ENetworkInputBuffer*/
	_NODISCARD static EnumWrapper GetNetworkInputBuffers();
	/*U_Types_TA_EPawnType*/
	_NODISCARD static EnumWrapper GetPawnTypes();
	/*U_Types_TA_EProductQuality*/
	_NODISCARD static EnumWrapper GetProductQualities();
	/*U_Types_TA_EStatGraphLevel*/
	_NODISCARD static EnumWrapper GetStatGraphLevels();
	/*U_Types_TA_ETrainingSaveType*/
	_NODISCARD static EnumWrapper GetTrainingSaveTypes();
	/*U_Types_TA_ETrainingType*/
	_NODISCARD static EnumWrapper GetTrainingTypes();
	/*U_Types_TA_EUnlockMethod*/
	_NODISCARD static EnumWrapper GetUnlockMethods();
	/*U_Types_TA_EVoiceFilter*/
	_NODISCARD static EnumWrapper GetVoiceFilters();
	/*UAudioDevice_ETTSSpeaker*/
	_NODISCARD static EnumWrapper GetTTSSpeakers();
	/*UClientConnectionTracker_TA_EConnectionQualityState*/
	_NODISCARD static EnumWrapper GetConnectionQualityStates();
	/*UPrimitiveComponent_ERadialImpulseFalloff*/
	_NODISCARD static EnumWrapper GetRadialImpulseFalloffs();
	/*UPrimitiveComponent_ERBCollisionChannel*/
	_NODISCARD static EnumWrapper GetRBCollisionChannels();
	/*UReplay_TA_EReplayState*/
	_NODISCARD static EnumWrapper GetReplayStates();
	/*USampleHistory_TA_EGraphSummaryType*/
	_NODISCARD static EnumWrapper GetGraphSummaryTypes();
	/*U_TrainingTypes_TA_ETrainingRoundAttempt*/
	_NODISCARD static EnumWrapper GetTrainingRoundAttempts();
	//UGFxEngine_EWeatherVariant
	_NODISCARD static EnumWrapper GetWeatherVariant();
	//U_Types_TA_EPaintFinishType
	_NODISCARD static EnumWrapper GetPaintFinishTyp();
private:
	PIMPL
	
};
