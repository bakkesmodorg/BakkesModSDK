#pragma once

class BAKKESMOD_PLUGIN_IMPORT ReplayManagerWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(ReplayManagerWrapper)

	//BEGIN SELF IMPLEMENTED
	_NODISCARD bool IsNull() const;
	explicit operator bool() const;
	//END SELF IMPLEMENTED

	_NODISCARD bool LoadReplaysFromDemoFolder() const;
	_NODISCARD std::vector<ReplaySoccarWrapper> GetLoadedReplays() const;
	_NODISCARD bool IsLoadingReplayHeaders() const;


	/**
	 * \brief Starts a replay with a optional map and start time
	 * \param replay Replay to open
	 * \param map custom map name
	 * \param start_time  Use replay_wrapper.GetCurrentFrame() / replay_wrapper.GetRecordFPS() for a accurate start_time
	 */
	void PlayReplay(const ReplayWrapper& replay, const std::string& map = "", float start_time = 0) const;

	/**
	 * \brief Starts a replay from a file with a optional map and start time
	 * \param file_path absolute path to the replay file
	 * \param map custom map name
	 * \param start_time  Use replay_wrapper.GetCurrentFrame() / replay_wrapper.GetRecordFPS() for a accurate start_time
	 */
	void PlayReplayFile(const std::string& file_path, const std::string& map = "", float start_time = 0) const;

	/**
	 * \brief Starts a replay from a replay id with a optional map and start time
	 * \param replay_id id of the replay to open
	 * \param map custom map name
	 * \param start_time  Use replay_wrapper.GetCurrentFrame() / replay_wrapper.GetRecordFPS() for a accurate start_time
	 */
	void PlayReplayId(const std::string& replay_id, const std::string& map = "", float start_time = 0) const;

private:
	PIMPL
};
