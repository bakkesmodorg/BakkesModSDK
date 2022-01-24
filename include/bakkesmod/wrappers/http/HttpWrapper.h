#pragma once
#include "bakkesmod/core/http_structs.h"

class BAKKESMOD_PLUGIN_IMPORT HttpWrapper
{
public:
	// Don't expect callbacks to be run in the game thread.
	// Wrap them in GameWrapper->Execute if you call wrapper functions in the callback!.


	/// <summary>
	/// This one gives you a callback with the response as a string
	/// Returns a http code of 418 on error
	/// </summary>
	/// <param name="request_data">The request options</param>
	/// <param name="on_complete">Callback that runs when the request finishes (or on error)</param>
	static void SendCurlRequest(CurlRequest request_data, CurlRequestDoneStringReturn on_complete);




	/// <summary>
	/// This one gives you a pointer to the raw data in the response, do as you wish with it.
	/// The pointer is only valid in your callback. copy the data if you intend to use it later
	///	Returns a http code of 418 on error
	/// </summary>
	/// <param name="request_data">The request options</param>
	/// <param name="on_complete">Callback that runs when the request finishes (or on error)</param>
	static void SendCurlRequest(CurlRequest request_data, CurlRequestDoneBinaryReturn on_complete);

	

	/// <summary>
	/// This one saves the response to a file and gives you a callback with the path to the file (it will just be the file_output you called it with)
	///	Returns a http code of 418 on error
	/// </summary>
	/// <param name="request_data">The request options</param>
	/// <param name="file_output">Where the file will be saved</param>
	/// <param name="on_complete">Callback that runs when the request finishes (or on error)</param>
	static void SendCurlRequest(CurlRequest request_data, const std::wstring& file_output, CurlRequestDoneFileReturn on_complete);




	/// <summary>
	/// Adds the Content-Type and Accept headers if not already set.
	/// Content-Type: application/json
	/// Accept: application/json
	/// Returns a http code of 418 on error
	/// </summary>
	/// <param name="request_data">The request options</param>
	/// <param name="on_complete">Callback that runs when the request finishes (or on error)</param>
	static void SendCurlJsonRequest(CurlRequest request_data, CurlRequestDoneStringReturn on_complete);
	
};
