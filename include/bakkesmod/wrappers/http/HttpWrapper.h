#pragma once
#include "bakkesmod/core/http_structs.h"

class BAKKESMOD_PLUGIN_IMPORT HttpWrapper
{
public:
	// Don't expect callbacks to be run in the game thread.
	// Wrap them in GameWrapper->Execute if you call wrapper functions in the callback!.

	// This one gives you a callback with the response as a string
	static void SendCurlRequest(CurlRequest request_data, CurlRequestDoneStringReturn on_complete);

	// This one gives you a pointer to the raw data in the response, do as you wish with it.
	// The pointer is only valid in your callback. copy the data if you intend to use it later
	static void SendCurlRequest(CurlRequest request_data, CurlRequestDoneBinaryReturn on_complete);

	// This one saves the response to a file and gives you a callback with the path to the file (it will just be the file_output you called it with)
	static void SendCurlRequest(CurlRequest request_data, const std::wstring& file_output, CurlRequestDoneFileReturn on_complete);

	// Adds the Content-Type and Accept headers if not already set
	static void SendCurlJsonRequest(CurlRequest request_data, CurlRequestDoneStringReturn on_complete);
	
};
